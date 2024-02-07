---
layout: post
title: unity image changer 이미지 교체
category: unity3d
tags: simple-code
---

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class image_changer : MonoBehaviour {

    public Material[] mats;
    private int mater_counter = 0;
	// Use this for initialization
	void Start () {
        /*
        moveTo(0, 9, 0f);
        moveTo(9, 0, 5.0f);
        */
    }
    public void pushUp()
    {
        moveTo(0, 9, 0f);
        moveTo(9, 0, 5.0f);
    }
    public void moveTo(float start, float end, float delay)
    {
        iTween.ValueTo(gameObject, iTween.Hash("delay", delay, "from", start, "to", end, "onupdatetarget", gameObject,"onupdate", "tweenOnUpdateCallBack", "time", 1.0f, "easetype", iTween.EaseType.linear));
    }
    private void tweenOnUpdateCallBack(float p)
    {
        mater_counter = Mathf.RoundToInt(p);
        this.gameObject.GetComponent<Renderer>().material = mats[mater_counter];
    }

    // Update is called once per frame
    void Update () {
        /*
        this.gameObject.GetComponent<Renderer>().material = mats[mater_counter];
        mater_counter++;
        if (mater_counter >= mats.Length) mater_counter = 0;
        */
    }
}
```
