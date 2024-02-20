---
layout: post
title: unity shader chroma key 크로마키 쉐이더
category: arduino
tags: unity3d shader
---

# unity shader chroma key 크로마키 쉐이더
* 출처 : https://seokiki0413.tistory.com/1
  
```c++
Shader "Transparent/Cutout/ChromakeyShader" {
    Properties {
         _MainTex ("Base (RGB)", 2D) = "white" {}
         _Sens ("Sensibilidad", Range (0,0.1)) = 0.3
         _Cutoff("Cutoff", Range(0, 0.05)) = 0.1
         _Color ("Chroma", Color) = (0, 0, 0)
    }
    
    SubShader {
        Tags { "Queue"="Transparent" "RenderType"="Transparent" }
        LOD 200
        
        CGPROGRAM
        #pragma surface surf Lambert alpha

        sampler2D _MainTex;
        float _Cutoff;
        float _Sens;
        half3 _Color;


        struct Input {
            float2 uv_MainTex;
        };

        void surf (Input IN, inout SurfaceOutput o) {
            half4 c = tex2D (_MainTex, IN.uv_MainTex);
            o.Albedo = c.rgb;
            
            float aR = abs(c.r - _Color.r) < _Sens ? abs(c.r - _Color.r) : 1;
            float aG = abs(c.g - _Color.g) < _Sens ? abs(c.g - _Color.g) : 1;
            float aB = abs(c.b - _Color.b) < _Sens ? abs(c.b - _Color.b) : 1; 

            float a = (aR + aG + aB) / 3; 

            if (a < _Cutoff) {
                o.Alpha = 0;
            } else {
                o.Alpha = 1;
            }
        }
        ENDCG
    }
    FallBack "Diffuse"
}
```
