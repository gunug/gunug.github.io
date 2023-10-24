---
layout: post
title: unity HumanPoseHandler 휴먼 포즈 핸들러
category: unity3d
tags: c# simple-code 
---

```c#
using UnityEngine;
using UnityEditor;

public class MecanimScript : MonoBehaviour
{
    public HumanPoseHandler humanPoseHandler;
   public MecanimScript VFXHuman;
    private HumanPose humanPose;

    private void Update()
    {
         humanPoseHandler.GetHumanPose(ref humanPose);
         if(VFXHuman != null){
            VFXHuman.humanPoseHandler.SetHumanPose(ref humanPose);
         }
    }
    void Start()
    {
        Animator anim = this.gameObject.GetComponent<Animator>();
        humanPoseHandler = new HumanPoseHandler(anim.avatar, this.transform);
        humanPose = new HumanPose();
        humanPoseHandler.GetHumanPose(ref humanPose);
         humanPoseHandler.SetHumanPose(ref humanPose);
   }
}
```

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class MecanimScript : MonoBehaviour
{
    private HumanPoseHandler humanPoseHandler;
    private HumanPose humanPose;
    [Range(-3,3)]public float[] muscles_;

    private void Update()
    {
        for(int i=0; i<muscles_.Length; i++)
        {
            humanPose.muscles[i] = muscles_[i];
        }
        humanPoseHandler.SetHumanPose(ref humanPose);
    }
    void Start()
    {
        Animator anim = this.gameObject.GetComponent<Animator>();
        humanPoseHandler = new HumanPoseHandler(anim.avatar, this.transform);
        humanPose = new HumanPose();
        humanPoseHandler.GetHumanPose(ref humanPose);
        humanPose.muscles[0] = 0f;
        humanPose.muscles[1] = 0f;
        humanPose.muscles[2] = 0f;
        humanPose.muscles[3] = 0f;
        humanPose.muscles[4] = 0f;
        humanPose.muscles[5] = 0f;
        humanPose.muscles[6] = 0f;
        humanPose.muscles[7] = 0f;
        humanPose.muscles[8] = 0f;
        humanPose.muscles[9] = 0f;
        humanPose.muscles[10] = 0f;
        humanPose.muscles[11] = 0f;
        humanPose.muscles[12] = 0f;
        humanPose.muscles[13] = 0f;
        humanPose.muscles[14] = 0f;
        humanPose.muscles[16] = 0f;
        humanPose.muscles[18] = 0f;
        humanPose.muscles[19] = 1.028553f;
        humanPose.muscles[21] = 0.5912678f;
        humanPose.muscles[22] = 0.02391984f;
        humanPose.muscles[23] = -0.3350839f;
        humanPose.muscles[24] = 1.001714f;
        humanPose.muscles[25] = 0.2296576f;
        humanPose.muscles[26] = -0.007519196f;
        humanPose.muscles[27] = 0.03165575f;
        humanPose.muscles[28] = 0f;
        humanPose.muscles[29] = 0.5912538f;
        humanPose.muscles[30] = 0.02393157f;
        humanPose.muscles[31] = -0.3353789f;
        humanPose.muscles[32] = 1.0017f;
        humanPose.muscles[33] = 0.2298868f;
        humanPose.muscles[34] = -0.007534596f;
        humanPose.muscles[35] = 0.03168624f;
        humanPose.muscles[36] = 0f;
        humanPose.muscles[39] = 0.3875203f;
        humanPose.muscles[40] = 0.3130022f;
        humanPose.muscles[41] = 0.004141518f;
        humanPose.muscles[42] = 1.005535f;
        humanPose.muscles[43] = 0.0606268f;
        humanPose.muscles[44] = -0.0003488492f;
        humanPose.muscles[48] = 0.3875171f;
        humanPose.muscles[49] = 0.3130058f;
        humanPose.muscles[50] = 0.004390163f;
        humanPose.muscles[51] = 1.005516f;
        humanPose.muscles[52] = 0.06033607f;
        humanPose.muscles[53] = -0.0003474732f;
        humanPose.muscles[55] = -0.7710331f;
        humanPose.muscles[56] = 0.3264397f;
        humanPose.muscles[57] = 0.6025394f;
        humanPose.muscles[58] = 0.6025394f;
        humanPose.muscles[59] = 0.6651618f;
        humanPose.muscles[60] = -0.3629383f;
        humanPose.muscles[61] = 0.8053817f;
        humanPose.muscles[62] = 0.8053818f;
        humanPose.muscles[63] = 0.6668495f;
        humanPose.muscles[64] = -0.4736939f;
        humanPose.muscles[65] = 0.8019281f;
        humanPose.muscles[66] = 0.8019281f;
        humanPose.muscles[67] = 0.6668813f;
        humanPose.muscles[68] = -0.650219f;
        humanPose.muscles[69] = 0.8097187f;
        humanPose.muscles[70] = 0.8097187f;
        humanPose.muscles[71] = 0.6675717f;
        humanPose.muscles[72] = -0.4611372f;
        humanPose.muscles[73] = 0.811213f;
        humanPose.muscles[74] = 0.8112127f;
        humanPose.muscles[75] = -0.7712734f;
        humanPose.muscles[76] = 0.3237967f;
        humanPose.muscles[77] = 0.603806f;
        humanPose.muscles[78] = 0.6038052f;
        humanPose.muscles[79] = 0.665509f;
        humanPose.muscles[80] = -0.3649435f;
        humanPose.muscles[81] = 0.8050572f;
        humanPose.muscles[82] = 0.8050573f;
        humanPose.muscles[83] = 0.6668472f;
        humanPose.muscles[84] = -0.4735937f;
        humanPose.muscles[85] = 0.8022231f;
        humanPose.muscles[86] = 0.8022232f;
        humanPose.muscles[87] = 0.6668215f;
        humanPose.muscles[88] = -0.6518124f;
        humanPose.muscles[89] = 0.8098171f;
        humanPose.muscles[90] = 0.8098171f;
        humanPose.muscles[91] = 0.6676161f;
        humanPose.muscles[92] = -0.4607274f;
        humanPose.muscles[93] = 0.811323f;
        humanPose.muscles[94] = 0.811323f;
        humanPoseHandler.SetHumanPose(ref humanPose);
    }
}
```