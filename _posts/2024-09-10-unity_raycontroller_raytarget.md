---
layout: post
title: unity RayController RayTarget
category: unity
tags:
---

# unity RayController RayTarget

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1725908183.jpg" />
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1725908225.jpg" />

## RayController.cs
```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RayController : MonoBehaviour
{
    public LineRenderer lineRenderer;
    public GameObject start_cube;
    public GameObject end_cube;
    private Vector3 start_pos;
    private Vector3 end_pos;
    // Start is called before the first frame update
    void Start()
    {
        lineRenderer = gameObject.AddComponent<LineRenderer>();
        lineRenderer.startWidth = 0.1f;
        lineRenderer.endWidth = 0.1f;
        lineRenderer.positionCount = 2;
        lineRenderer.startColor = Color.red;
        lineRenderer.endColor = Color.red;
        lineRenderer.SetPosition(0, transform.position);
        lineRenderer.SetPosition(1, transform.position + transform.forward * 10);
    }
    private RaycastHit hit;
    private bool isPressed = false;
    public void ButtonPressed()
    {
        isPressed = true;
    }
    public void ButtonReleased()
    {
        isPressed = false;
    }
    void Update()
    {
        start_pos = start_cube.transform.position;
        end_pos = end_cube.transform.position;
        lineRenderer.SetPosition(0, start_pos);
        lineRenderer.SetPosition(1, end_pos);

        if (Physics.Raycast(start_pos, end_pos, out hit))
        {
            //Debug.Log("hit point : " + hit.point + ", distance : " + hit.distance + ", name : " + hit.collider.name);
            //check has object raytarget
            if (hit.collider.gameObject.GetComponent<RayTarget>())
            {
                if(isPressed)
                    hit.collider.gameObject.GetComponent<RayTarget>().RayPress(start_cube.gameObject);
                else{
                    hit.collider.gameObject.GetComponent<RayTarget>().RayRelease();
                }
            }
        }
    }
}

```

## RayTarget.cs
```csharp
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class RayTarget : MonoBehaviour
{
    public bool isDraggable = false;
    private bool isDragging = false;
    private GameObject controller_object;
    private float controller_distance = 10.0f;
    public UnityEvent pressEvents;
    public UnityEvent releaseEvents;
    public void Start()
    {
        GetComponent<MeshRenderer>().material.color = Color.yellow;
    }
    public void Update()
    {
        //RayOut();
        if(isDragging && isDraggable){
            Vector3 destinationPosition =
            CalculateDestinationPosition(controller_object.transform.position, controller_object.transform.eulerAngles, controller_distance);

            transform.position = destinationPosition;
        }
    }
    public void RayOver(){
        GetComponent<MeshRenderer>().material.color = Color.red;
    }
    public void RayOut(){
        //Debug.Log("out");
        GetComponent<MeshRenderer>().material.color = Color.white;
    }
    public void RayPress(GameObject root_object){
        //Debug.Log("press");
        GetComponent<MeshRenderer>().material.color = Color.blue;
        controller_distance = Vector3.Distance(root_object.transform.position, transform.position);
        controller_object = root_object;
        isDragging = true;
        pressEvents.Invoke();
    }
    public void RayRelease(){
        //Debug.Log("release");
        GetComponent<MeshRenderer>().material.color = Color.red;
        controller_object = null;
        isDragging = false;
        releaseEvents.Invoke();
    }
    Vector3 CalculateDestinationPosition(Vector3 startPosition, Vector3 rotationEulerAngles, float distance)
    {
        Quaternion rotation = Quaternion.Euler(rotationEulerAngles);
        Vector3 direction = rotation * Vector3.forward;
        Vector3 destinationPosition = startPosition + direction * distance;
        return destinationPosition;
    }
}

```