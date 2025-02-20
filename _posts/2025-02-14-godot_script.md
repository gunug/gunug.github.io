---
layout: post
title: godot script 고도 소스코드
category: game
tags: 
---

# godot script 고도 소스코드

## ray_cast_3d.gd
```python
@tool
extends RayCast3D

# 변수 선언
@export var quad: Node3D

func _ready():
	enabled = true

func _process(delta):
	var direction = Vector3.FORWARD
	var length = 10.0
	target_position = direction * length
	look_at(quad.global_transform.origin, Vector3.UP)
```

## set_child.gd
```python
@tool
extends Node3D
var initial_local_transform: Transform3D = Transform3D.IDENTITY

@export var camera: Camera3D  # 이 변수를 에디터에서 Camera3D 노드로 설정해야 합니다.

func _process(delta):
	# 노드가 존재하는지 확인합니다.
	var target = $SubViewport/Camera3D if has_node("SubViewport/Camera3D") else null
	if target:
		var parent_global_transform = camera.global_transform
		target.global_transform = parent_global_transform
	else:
		print("Target node not found!")
```