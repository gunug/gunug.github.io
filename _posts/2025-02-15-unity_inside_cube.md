---
layout: post
title: unity inside cube
category: unity
tags: simple-code
---

# unity inside cube

```csharp
using UnityEngine;

public class CubeInside : MonoBehaviour
{
    public Material cube_mat; // 사용자 정의 머티리얼을 할당받기 위한 변수

    void Start()
    {
        MeshFilter meshFilter = gameObject.AddComponent<MeshFilter>();
        MeshRenderer meshRenderer = gameObject.AddComponent<MeshRenderer>();

        Mesh mesh = new Mesh();
        mesh.name = "InwardCube";

        Vector3[] vertices = {
            new Vector3(0.5f, 0.5f, 0.5f),
            new Vector3(-0.5f, 0.5f, 0.5f),
            new Vector3(-0.5f, -0.5f, 0.5f),
            new Vector3(0.5f, -0.5f, 0.5f),
            new Vector3(0.5f, 0.5f, -0.5f),
            new Vector3(-0.5f, 0.5f, -0.5f),
            new Vector3(-0.5f, -0.5f, -0.5f),
            new Vector3(0.5f, -0.5f, -0.5f),
        };

        int[] triangles = {
            0, 2, 1, 0, 3, 2,    // Front
            4, 5, 6, 4, 6, 7,    // Back
            0, 1, 5, 0, 5, 4,    // Top
            2, 3, 7, 2, 7, 6,    // Bottom
            0, 4, 7, 0, 7, 3,    // Right
            1, 2, 6, 1, 6, 5     // Left
        };

        mesh.vertices = vertices;
        mesh.triangles = triangles;
        mesh.RecalculateNormals();

        meshFilter.mesh = mesh;

        // Cube Material이 유효한지 확인한 후 메터리얼 할당
        if (cube_mat != null)
        {
            meshRenderer.material = cube_mat;
        }
        else
        {
            Debug.LogWarning("Material이 할당되지 않았습니다.");
        }
    }
}
```

```csharp
using UnityEngine;

[RequireComponent(typeof(MeshFilter), typeof(MeshRenderer))]
public class GenerateCylinder : MonoBehaviour
{
    public int numOfSides = 20;
    public float topRadius_start = 0.5f;
    public float bottomRadius_start = 1f;
    public float height_start = 2f;
    public float topRadius_end = 0.5f;
    public float bottomRadius_end = 1f;
    public float height_end = 2f;
    public float topRadius = 0.5f; //current top radius
    public float bottomRadius = 1f; //current bottom radius
    public float height = 2f; //current height
    [Range(0, 1)]
    public float LerpValue = 0.5f;
    public Material cylinderMaterial;

    void Awake(){
        DrawMesh();
    }
    void Update()
    {
        //DrawMesh();
        topRadius = Mathf.Lerp(topRadius_start, topRadius_end, LerpValue);
        bottomRadius = Mathf.Lerp(bottomRadius_start, bottomRadius_end, LerpValue);
        height = Mathf.Lerp(height_start, height_end, LerpValue);
        DrawMesh();
    }
    MeshFilter mf;
    Mesh mesh;
    private bool isFirst = true;
    private void DrawMesh(){
        //매쉬 초기화
        if (mesh == null){
            mesh = new Mesh();
            mf = GetComponent<MeshFilter>();
            mf.mesh = mesh;
        }
        mesh.Clear();
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

        if(isFirst){
            isFirst = false;
            // 메터리얼 할당
            MeshRenderer renderer = GetComponent<MeshRenderer>();
            renderer.material = cylinderMaterial;
        }
    }
}
```