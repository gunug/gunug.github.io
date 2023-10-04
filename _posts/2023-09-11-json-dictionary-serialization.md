---
layout: post
title: json dictionary serialization 제이슨 딕셔너리 직렬화
category: unity3d
tags: simple-code
---

* [출처](https://drehzr.tistory.com/931)

```c#
public class SerializableDictionary<TKey,TValue> : Dictionary<TKey,TValue>, ISerializationCallbackReceiver
{
   [SerializeField]
   private List<TKey> keys = new List<TKey>();
   [SerializeField]
   private List<TValue> values = new List<TValue>();

   //save the dictionary to lists
   public void OnBeforeSerialize()
   {
       keys.Clear();
       values.Clear();
       foreach (KeyValuePair<TKey, TValue> pair in this)
       {
           keys.Add(pair.Key); values.Add(pair.Value);
       }
   }
   //load dictionary from lists
   public void OnAfterDeserialize()
   {
       this.Clear();
       if (keys.Count != values.Count)
           throw new System.Exception(string.Format("there are {0} keys and {1} values after deserialization. Make sure that both key and value types are serializable."));
       for(int i=0; i<keys.Count; i++)
       {
           this.Add(keys[i], values[i]);
       }
   }
}

[System.Serializable]
public class SerialDicString : SerializableDictionary<string, string>{

}
public SerialDicString item = new SerialDicString();
```

* 만약 json data를 직렬화 할일이 있으면 string으로 변조 하였다가 다시 복조하는 방법이 쉬울듯함
* 위 방법을 사용하면 inspector에서 표시할수 있는 직렬화 데이터를 만들 수 있음