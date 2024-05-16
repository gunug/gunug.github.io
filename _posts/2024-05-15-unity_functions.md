---
layout: post
title: unity 여러가지 기능들
category: unity3d
tags:
---

# unity 여러가지 기능들

---

# 스카이박스 교체하기
```c#
 using System.Collections;
 using System.Collections.Generic;
 using UnityEngine;
 
 public class SkyButton : MonoBehaviour
 {
     public Material sky1;
     private void OnMouseDown()
     {
         Debug.Log("sky change");
         RenderSettings.skybox = sky1;
     }
 }
```

---

# 키입력 파악하기
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KeyInput : MonoBehaviour
{
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Debug.Log("Space key was pressed.");
        }

        if (Input.GetKeyUp(KeyCode.Space))
        {
            Debug.Log("Space key was released.");
        }
        Input.GetAxis("Horizontal"); //수평축 입력
        Input.GetAxis("Vertical"); //수직축 입력
    }
}
```

---

# 주위를 회전하는 물체
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AroundingObject : MonoBehaviour
{
	public GameObject target;
    void Update()
    {
        transform.RotateAround(target.transform.position,Vector3.up,360f/10*Time.deltaTime);
        //public void RotateAround(Vector3 point, Vector3 axis, float angle);
        //axis : back, down, forward, left, one, right, up, zero
        transform.LookAt(target.transform.position);
    }
}
```

---

# 깜빡이는 빛
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlickLight : MonoBehaviour
{
    private Light target_light;
    private float strong = 0; //빛 세기
    [Range(0, 0.3f)]
    public float blink_speed = 0; //깜박이는 속도
    [Range(1, 10)]
    public float light_strong = 1; //빛의 세기
    void Start() //게임이 시작될때 1번
    {
        target_light = GetComponent<Light>();
        //컴퍼넌트가져오기<Light>();
    }
    void Update()
    {
        target_light.intensity = (Mathf.Sin(strong)+1)* light_strong;
        // strong 0~
        // Mathf.Sin(strong) 0~1~0~-1~0~1~0~-1, -1~1
        // Mathf.Sin(strong)+1 0~2
        strong += blink_speed; //0.2씩 증가 (깜박이는 속도)
        //strong = strong + 0.2f;
    }
}
```

---

# 빛 제어하기
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class LightControl : MonoBehaviour
{
    private Light my_light;
    void Start()
    {
        my_light = gameObject.GetComponent<Light>();
        lightOn();
    }
    public void lightOn(){
    	iTween.ValueTo(gameObject, iTween.Hash("from", 0, "to", 100, "onUpdate", "Counter", "delay", 0, "time", 2));       
    }
    public void lightOff(){
    	iTween.ValueTo(gameObject, iTween.Hash("from", 100, "to", 0, "onUpdate", "Counter", "delay", 0, "time", 2));       	
    }
    private void Counter(int get_number)
	{
		my_light.intensity = (float)get_number/100*2;
	}
}
```

---

# 빛 각도 조절하기
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public void makeAngle(Vector3 target_angle){
		//this.gameObject.transform.eulerAngles = target_angle;
		iTween.RotateTo(this.gameObject, iTween.Hash("rotation", 
        target_angle, "easetype", iTween.EaseType.easeOutCubic, "time", 1.0f));
}
```

---

# 충돌체 충돌여부 파악하기
```c#
void OnCollisionEnter (Collision collision){
    Debug.Log("Enter called");
}
void OnCollisionStay (Collision collision){
    Debug.Log("Stay occurring..");
}
void OnCollisionExit (Collision collision){
    Debug.Log("Exit called.");
}
```

---

# 충돌여부 파악하여 색 바꾸기
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CollisionObject : MonoBehaviour
{
    void OnCollisionEnter(Collision col){
        //col 부딧힌 대상
        Debug.Log("충돌시작");
        Renderer self = GetComponent<Renderer>();
        self.material.color = Color.red;
    }
    void OnCollisionStay(Collision col){
        Debug.Log("충돌중");
    }
    void OnCollisionExit(Collision col){
        Debug.Log("충돌끝");
        Renderer self = GetComponent<Renderer>();
        self.material.color = Color.white;
    }
}
```

---

# 트리거를 이용하여 물체의 위치 파악하기
```c#
void OnTriggerEnter(Collider other) {
    //Destroy(other.gameObject);
    Debug.Log("trigger enter");
}
void OnTriggerStay(Collider other) {
    Debug.Log("trigger stay");
}
void OnTriggerExit(Collider other) {
    Debug.Log("trigger out");
}
```

---

# Material을 이용하여 이미지 교체하기
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MaterialChange : MonoBehaviour
{
    public Material[] materials;
    public int index = 0;
    private Renderer myRenderer;
    private void Start()
    {
        myRenderer = GetComponent<Renderer>();
    }
    private void OnMouseDown()
    {
        index++;
        myRenderer.material = materials[index%2];
        //index%2  = index를 2로 나눈뒤 남는 나머지값
    }
}
```

---

# 물리적인 힘 추가하기
```c#
Rigidbody rb = GetComponent<Rigidbody>();
rb.AddForce(transform.up * 200);
rb.AddForce(transform.up * 200, ForceMode.Acceleration);
//질량을 무시하고, 리지드바디에(rigidbody)에 연속적인 가속력(Acceleration)을 가합니다.
//질량이 다른 두개 이상의 물체에 동일한 가속력을 가하고 싶다면 유용합니다.
//기본값은 ForceMode.Force 입니다.
```
---

- ForceMode : 힘을 가하는 방식
- - Force : 질량을 포함한 가속
- - Acceleration : 질량을 무시한 가속
- - Impulse : 질량을 포함한 속도적용 (순간적 속도변화)
- - VelocityChange : 질량을 무시한 속도적용 (순간적 속도변화)
- https://docs.unity3d.com/kr/530/ScriptReference/Transform.html
- forward : 월드 공간에서 트랜스폼의 파랑색 축(Z)을 나타냅니다.
- right : 월드 공간에서 트랜스폼의 빨간색 축을 나타냅니다.
- up : 월드 공간에서 트랜스폼의 초록색 축을 나타냅니다.

---

# 회전힘 추가하기
```c#
public float amount = 50f;
void FixedUpdate(){
    Rigidbody rb = GetComponent<Rigidbody>();
    float h = Input.GetAxis("Horizontal") * amount * Time.deltaTime;
    float v = Input.GetAxis("Vertical") * amount * Time.deltaTime;
    rb.AddTorque(transform.up * h);
    rb.AddTorque(transform.right *v);
}
```

---

# 주사위 굴리기
```c#
void OnMouseDown()
    {
        Debug.Log("마우스 눌림");
        myBody.AddForce(Vector3.up * 500); //위치 힘 추가하기
        myBody.AddTorque(transform.right * 15);
        myBody.AddTorque(transform.up * 20); //회전 힘 추가하기
        //내 기준 윗쪽 transform.up
        //월드 기준 윗쪽 Vector3.up
    }
```