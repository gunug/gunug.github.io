---
layout: post
title: Unity path 유니티 경로
category: unity3d
tags: c#
---

# 유니티 경로
* [Application.dataPath](https://docs.unity3d.com/ScriptReference/Application-dataPath.html)
* Unity Editor: <path to project folder>/Assets
* Mac player: <path to player app bundle>/Contents
* iOS player: <path to player app bundle>/<AppName.app>/Data (this folder is read only, use Application.persistentDataPath to save data).
Win/Linux player: <path to executablename_Data folder> (note that most Linux installations will be case-sensitive!)
* WebGL: The absolute url to the player data file folder (without the actual data file name)
* Android: Normally it points directly to the APK. If you are running a split binary build, it points to the OBB instead.
* Windows Store Apps: The absolute path to the player data folder (this folder is read only, use Application.persistentDataPath to save data)