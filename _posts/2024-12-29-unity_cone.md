---
layout: post
title: unity cone cylinder
category: unity3d
tags: simple-code
---

# unity cone 콘(원뿔), cylinder 실린더(원기둥) 만들기

```csharp
using UnityEngine;

[RequireComponent(typeof(MeshFilter), typeof(MeshRenderer))]
public class GenerateCone : MonoBehaviour
{
    public int numOfSides = 20;
    public float radius = 1f;
    public float height = 2f;
    public Material coneMaterial; // Inspector에서 material을 할당받기 위한 변수

    void Start()
    {
        // Get the MeshFilter component and create a new Mesh
        MeshFilter mf = GetComponent<MeshFilter>();
        Mesh mesh = new Mesh();
        mf.mesh = mesh;

        int vertexCount = numOfSides + 2;
        int triangleCount = numOfSides * 3 + numOfSides * 3; // 측면과 밑면 삼각형

        Vector3[] vertices = new Vector3[vertexCount];
        Vector3[] normals = new Vector3[vertexCount];
        int[] triangles = new int[triangleCount];

        // Vertex at the tip of the cone
        vertices[0] = Vector3.up * height;

        // Vertices around the base and the center of the base
        vertices[vertexCount - 1] = Vector3.zero; // 밑면의 중앙

        float angleStep = 360.0f / numOfSides;
        for (int i = 0; i < numOfSides; i++)
        {
            float angle = Mathf.Deg2Rad * angleStep * i;
            vertices[i + 1] = new Vector3(Mathf.Cos(angle) * radius, 0, Mathf.Sin(angle) * radius);
        }

        // Creating triangles for the sides
        for (int i = 0; i < numOfSides; i++)
        {
            triangles[i * 3] = 0;
            triangles[i * 3 + 1] = i + 1;
            triangles[i * 3 + 2] = (i + 2 > numOfSides) ? 1 : i + 2;
        }

        // Creating triangles for the base
        int baseIndex = numOfSides * 3; // 측면 삼각형 이후의 인덱스 시작점
        for (int i = 0; i < numOfSides; i++)
        {
            triangles[baseIndex + i * 3] = vertexCount - 1; // 밑면의 중앙
            triangles[baseIndex + i * 3 + 1] = (i + 2 > numOfSides) ? 1 : i + 2;
            triangles[baseIndex + i * 3 + 2] = i + 1;
        }

        // Assign vertices and triangles to the mesh
        mesh.vertices = vertices;
        mesh.triangles = triangles;
        mesh.RecalculateNormals();

        // Get the MeshRenderer component and apply the material
        MeshRenderer renderer = GetComponent<MeshRenderer>();
        renderer.material = coneMaterial; // 전달받은 material을 적용
    }
}
```

---

```csharp
using UnityEngine;

[RequireComponent(typeof(MeshFilter), typeof(MeshRenderer))]
public class GenerateCylinder : MonoBehaviour
{
    public int numOfSides = 20;
    public float topRadius = 0.5f;
    public float bottomRadius = 1f;
    public float height = 2f;
    public Material cylinderMaterial;

    void Start()
    {
        MeshFilter mf = GetComponent<MeshFilter>();
        Mesh mesh = new Mesh();
        mf.mesh = mesh;

        // 총 vertex의 수: 윗면, 아랫면에 각각 numOfSides개의 vertex와 중앙점 2개
        int vertexCount = numOfSides * 2 + 2;

        // 측면 삼각형: numOfSides * 2 (두 개의 삼각형으로 이루어짐) 
        // 윗면, 아랫면: 각각 numOfSides개의 삼각형
        int triangleCount = numOfSides * 2 * 3 + numOfSides * 3 + numOfSides * 3;

        Vector3[] vertices = new Vector3[vertexCount];
        int[] triangles = new int[triangleCount];

        // 윗면과 아랫면 중앙점
        vertices[vertexCount - 2] = new Vector3(0, height, 0); // Top center
        vertices[vertexCount - 1] = Vector3.zero; // Bottom center

        float angleStep = 360.0f / numOfSides;
        for (int i = 0; i < numOfSides; i++)
        {
            float angle = Mathf.Deg2Rad * angleStep * i;
            float x = Mathf.Cos(angle);
            float z = Mathf.Sin(angle);

            // 윗면 vertex
            vertices[i] = new Vector3(x * topRadius, height, z * topRadius);
            // 아랫면 vertex
            vertices[i + numOfSides] = new Vector3(x * bottomRadius, 0, z * bottomRadius);
        }

        // 측면 삼각형 생성
        for (int i = 0; i < numOfSides; i++)
        {
            int next = (i + 1) % numOfSides;
            int current = i;

            // 첫 번째 삼각형
            triangles[i * 6] = current;
            triangles[i * 6 + 1] = next;
            triangles[i * 6 + 2] = current + numOfSides;

            // 두 번째 삼각형
            triangles[i * 6 + 3] = next;
            triangles[i * 6 + 4] = next + numOfSides;
            triangles[i * 6 + 5] = current + numOfSides;
        }

        // 윗면 삼각형 생성 (반시계 방향)
        int topIndexStart = numOfSides * 6; // 다음 삼각형 배열 시작점
        for (int i = 0; i < numOfSides; i++)
        {
            int next = (i + 1) % numOfSides;
            triangles[topIndexStart + i * 3] = i;
            triangles[topIndexStart + i * 3 + 1] = numOfSides * 2;
            triangles[topIndexStart + i * 3 + 2] = next;
        }

        // 아랫면 삼각형 생성 (시계 방향)
        int bottomIndexStart = topIndexStart + numOfSides * 3;
        for (int i = 0; i < numOfSides; i++)
        {
            int next = (i + 1) % numOfSides;
            triangles[bottomIndexStart + i * 3] = i + numOfSides;
            triangles[bottomIndexStart + i * 3 + 1] = next + numOfSides;
            triangles[bottomIndexStart + i * 3 + 2] = vertexCount - 1;
        }

        // 매쉬에 할당
        mesh.vertices = vertices;
        mesh.triangles = triangles;
        mesh.RecalculateNormals();

        // 메터리얼 할당
        MeshRenderer renderer = GetComponent<MeshRenderer>();
        renderer.material = cylinderMaterial;
    }
}
```