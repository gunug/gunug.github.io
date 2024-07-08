---
layout: post
title: electronic 전기 기초
category: arduino
tags: 
---

# electronic 전기 기초
## Live(Hot) 와 Neutural(Cold)

1. 전류는 전압이 높은쪽에서 낮은 쪽으로 이동합니다. 전자제품 코드선을 꽂을때 전류가 전자제품 내부로 흐르게 됩니다.
2. 교류의 Live(hot)라인은 +220, -220을 60hz(1초에 60번 변함) 로 반복합니다. Neutural(Cold)은 0으로 유지됩니다.
3. Live가 +220일때는 Live에서 Neutural(중성선)로, -220일때는 Neutural에서 Live로 전류가 흐르게 됩니다.
4. 전류와는 별개로 (-)전자라고 하는것이 도선을 따라 전자부품들을 지날 때 전자부품들을 동작하게 합니다.
5. (-)전자가 전자부품을 스치면 작동하는것 이라고 보는것이 맞지만 스치기 위해서는 전위차가 있는 두 도선이 연결 되어야 하기 때문에 (전압이 높은 곳에서 낮은 곳으로 끌려가듯 이동) 코드가 연결되지 않은 상태에서 전자가 이동할리 없고, 따라서 전자가 부품에 스치는 순간과 코드가 연결되는 순간을 따로 분리하여 생각하지는 않는것 같습니다.

* -전압일때 중성선에서 활선으로 전류가 흐르는지에 대한 확신이 없다.

---

교류 전원은 +,-가 지속적으로 변경됩니다. 트랜지스터는 베이스(base)에 전기를 흘리면 컬렉터(collectoer)에서 이미터(emitter) 방향으로 전기가 흐르게 해주는 장치 입니다. 제가 교류전기에 대해서는 확실히 알지 못하여 컬렉터가 -가 되고 이미터가 +가 되었을 때 전기를 어떻게 흘리는지에 대한 정보가 없습니다. 추측 상으로는 역방향으로는 전기가 흐르지 않아 전기가 제대로 공급되지 않을 수도 있겠다는 생각이 들어 릴레이(극성이 관계없이 전기를 흐를 수 있게하는 부품)을 추천드렸습니다.

* NPN: 베이스(base)에서 이미터(emitter)방향으로 전기가 흐를때 컬렉터(collector)에서 이미터(emitter) 방향으로 전기가 흐름. 컬렉터+, 이미터-, 베이스+
* PNP: 이미터(emitter)에서 베이스(base)방향으로 전기가 흐를때
이미터(emitter)에서 컬렉터(collector)로 전기가 흐름. 이미터+, 컬렉터-, 베이스-

---

DC 모터는 무부하, 적정부하, 최대부하(정지)시 필요한 전류량이 각각 달라집니다. 이 기준에서 데이터 시트를 보면
No load(무부하), At Maximum Efficiency(최대효율, 적정부하), Stall(정지) 상태 각각의 전류(A)값을 볼 수 있습니다. 2.9A, 12.2A, 51A 같이 나오네요. 같은 스펙의 모터라면 비슷하게 나올 수 있지만 그래도 데이터 시트를 보아야 해당 제품의 정확한 전류량을 알 수가 있습니다. (540모터중 하나의 데이터 시트 링크 드립니다)

---

* LED 저항계산기: https://whoisit.tistory.com/414
* 저항 컬러코드 환산기 : http://kor.pe.kr/util/4/r_calc/

---

* HVT (High Voltage Threshold) : Threshold Voltage는 높아 leakage Power를 많이 줄일 수 있으나 Speed가 느리고 미세공정에서는 지원하지 않을 수도 있다.
* RVT(Regular Voltage Threshold) : 표준적인 leakage Power와 Threshold Voltage를 가지고 있어 가장 많이 사용되는 Cell이다.
* LVT(Low Voltage Threshold) : RVT 비해 Leakage Power크고 Threshold Voltage 낮아서 Speed를 빠른 Block에서 사용되고 있다.
* SLVT (Super Low Voltage Threshold) : Leakage Power가 매우 크지만 Threshold Voltage 매우 낮아 High Speed를 구현 해야만 하는 block에서 사용되고 있다.

VT는 브랜드가 없는 (중국어) 커패시터 와 브랜드가 있는( Multicomp Pro ) 커패시터 의 시리즈 이름으로 사용됩니다 .
RVT는 Elna 에서 만든 일련의 커패시터 이지만 Xuanx 및 아마도 다른 일련의 넓은 온도 커패시터의 표시이기도 합니다 .
VT와 RVT는 모두 일련 의 커패시터(값은 다르지만 사양이 유사한 커패시터, 일반적으로 단일 제조업체에서 제조)의 이름이지만 이름과 표시(및 커패시터 사양)의 실제 의미는 제조업체마다 다릅니다. .
표시 자체는 거의 또는 전혀 알려주지 않습니다. 제조업체를 알고 있을 때만 의미가 있으므로 적절한 데이터시트를 찾아볼 수 있습니다.