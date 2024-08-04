---
layout: post
title: network game 네트워크 게임
category: coding
tags: 
---

# Network game

---
호스트(Host): 게임 세션을 생성하고 제어하는 플레이어 또는 컴퓨터입니다. 호스트는 게임 매개변수 설정, 플레이어 연결 관리 및 게임 상태 유지를 담당합니다.

게스트(Guest): 호스트가 생성한 게임 세션에 참가하는 플레이어입니다. 게스트는 게임의 매개변수나 상태를 제어할 수 없지만 호스트가 정의한 대로 게임 세계와 상호 작용할 수 있습니다.

서버(Server): 멀티플레이어 게임을 위한 중앙 집중식 플랫폼을 제공하는 컴퓨터 또는 프로그램입니다. 서버는 게임 세계 관리, 플레이어 입력 처리, 연결된 모든 클라이언트에 게임 데이터 배포를 담당합니다.

클라이언트(Client): 멀티플레이어 게임에 참여하기 위해 서버에 연결하는 플레이어의 컴퓨터 또는 장치입니다. 클라이언트는 서버에 입력을 보내고 그 대가로 게임 상태에 대한 업데이트를 받습니다.

마스터(Master): 일부 게임에서는 게임의 세계나 메커니즘에 대해 가장 큰 권위나 힘을 가진 플레이어를 마스터라고 부를 수 있습니다. 이 용어는 탁상용 또는 롤플레잉 게임에서 더 일반적으로 사용됩니다.

노예(Slave): 이 계층 구조를 사용하는 게임에서 마스터 플레이어에게 복종하는 플레이어입니다. 이 용어는 탁상용 또는 롤플레잉 게임에서 더 일반적으로 사용됩니다.

피어 투 피어(Peer-to-peer): 게임 세션의 모든 플레이어가 중앙 서버를 통하지 않고 서로 직접 연결되는 네트워킹 아키텍처입니다. P2P 네트워크에서 각 플레이어의 장치는 클라이언트 및 서버 역할을 모두 수행하여 다른 플레이어의 장치와 직접 통신합니다.

대기 시간(Latency): 플레이어의 입력이 서버에 등록되고 서버의 응답이 플레이어의 장치에 수신되는 데 걸리는 시간입니다. 대기 시간은 게임의 응답성에 영향을 미치고 게임 플레이의 지연 또는 지연으로 이어질 수 있으므로 멀티플레이어 게임에서 중요한 요소입니다.

---


클라이언트-서버(Client-server): 게임 세션의 모든 플레이어가 중앙 서버에 연결되는 네트워킹 아키텍처입니다. 서버는 게임 세계를 관리하고 플레이어 입력을 처리하며 클라이언트는 서버에서 게임 상태에 대한 업데이트를 받습니다.

하이브리드(Hybrid): P2P 및 클라이언트-서버 모델의 요소를 결합한 네트워킹 아키텍처입니다. 하이브리드 네트워크에서 일부 플레이어는 서버에 연결하고 다른 플레이어는 서로 직접 연결할 수 있습니다.

클라우드 기반(Cloud-based): 클라우드 서버를 사용하여 게임 세션을 관리하는 네트워킹 아키텍처입니다. 클라우드 기반 네트워크는 클라우드 서버가 워크로드를 분산하고 플레이어 연결을 처리할 수 있으므로 플레이어 수가 많은 게임에 확장성과 안정성을 제공할 수 있습니다.

메시(Mesh): 네트워크의 각 장치가 여러 다른 장치에 직접 연결되는 네트워킹 아키텍처입니다. 메시 네트워크는 소규모 멀티플레이어 게임에서 사용할 수 있지만 일반적으로 대규모 게임의 경우 클라이언트-서버 또는 클라우드 기반 아키텍처보다 효율성이 떨어집니다.

릴레이(Relay): 플레이어의 장치가 하나 이상의 릴레이 서버를 통해 간접적으로 통신하는 네트워킹 아키텍처입니다. 릴레이 네트워크는 지리적으로 서로 떨어져 있는 플레이어의 대기 시간과 연결성을 개선하는 데 사용할 수 있지만 네트워크에 대기 시간과 복잡성을 추가할 수 있습니다.

---

네트워크 게임에서 "원격(remote)"은 일반적으로 플레이어가 사용하는 것과 다른 컴퓨터나 장치에 있는 개체나 플레이어를 나타냅니다. 여기에는 원격 서버, 원격 클라이언트 또는 원격 게임 개체가 포함될 수 있습니다.

---

로컬(Local): 플레이어와 동일한 컴퓨터 또는 장치에 있는 개체 또는 플레이어입니다. 예를 들어 분할 화면 멀티플레이어 게임에서 각 플레이어의 캐릭터는 각자의 화면에 로컬로 간주됩니다.

동기화(Sync): "동기화"의 줄임말로, 네트워크 게임의 모든 플레이어가 동일한 게임 상태를 갖도록 하는 프로세스를 나타냅니다. 게임이 모든 플레이어에게 일관되게 표시되려면 게임 개체, 플레이어 위치 및 기타 게임 데이터가 모든 장치에서 동기화되어야 합니다.

지연(Lag): 플레이어가 명령을 입력하는 시점과 게임에서 명령이 실행되는 시점 사이에 지연을 일으킬 수 있는 네트워크의 지연 또는 대기 시간입니다. 지연은 느린 네트워크 연결, 높은 네트워크 트래픽, 네트워크 거리 등 다양한 요인으로 인해 발생할 수 있습니다.

Ping(Ping): 플레이어의 장치와 원격 서버 또는 플레이어 간의 대기 시간 측정입니다. 낮은 핑은 일반적으로 더 빠르고 반응이 빠른 연결을 나타냅니다.

패킷(Packet): 네트워크를 통해 전송되는 데이터 단위. 네트워크 게임에서는 플레이어 위치, 입력 명령, 게임 상태 업데이트와 같은 게임 데이터가 패킷으로 전송됩니다.

대역폭(Bandwidth): 주어진 시간 동안 네트워크를 통해 전송할 수 있는 데이터의 양. 네트워크 게임에서 대역폭이 높을수록 게임 데이터를 더 빠르고 안정적으로 전송할 수 있습니다.

NAT(NAT): 네트워크 주소 변환, 인터넷을 통한 통신을 위해 사설 IP 주소를 공용 IP 주소로 매핑하는 데 사용되는 프로세스입니다. NAT는 특히 P2P 네트워크의 경우 네트워크 게임의 연결 및 성능에 영향을 줄 수 있습니다.

---

# Photon

---

Photon은 멀티플레이어 게임 개발에 널리 사용되는 미들웨어 플랫폼입니다. Photon에서 일반적으로 사용되는 일부 용어는 다음과 같습니다.

Photon Server: 게임 세션, 게임 개체 및 플레이어 연결을 관리하는 백엔드 인프라입니다.

방: 플레이어가 게임에서 서로 상호 작용할 수 있는 가상 공간입니다. 룸을 사용하여 플레이어를 다른 게임 세션 또는 매치 유형으로 구분할 수 있습니다.

피어: 네트워크에 연결되어 있고 게임에서 다른 피어와 통신할 수 있는 플레이어 또는 장치입니다. Photon에서 각 플레이어는 피어로 간주됩니다.

마스터 클라이언트: Photon 룸에서 한 피어가 "마스터 클라이언트"로 지정됩니다. 마스터 클라이언트는 게임 개체를 만들고 파괴하는 기능과 같은 특별한 권한이 있으며 룸에 있는 다른 플레이어에게 게임 상태 업데이트를 보내는 일을 담당합니다.

액터: 플레이어가 제어하거나 상호 작용할 수 있는 게임 세계의 개체 또는 개체입니다. 액터에는 플레이어 캐릭터, 비플레이어 캐릭터 및 기타 게임 개체가 포함될 수 있습니다.

RPC: "Remote Procedure Call"의 줄임말인 RPC는 네트워크의 원격 피어에서 함수를 호출하는 방법입니다. RPC는 피어 간에 게임 상태 업데이트, 플레이어 입력 명령 및 기타 데이터를 보내는 데 사용할 수 있습니다.

이벤트: Photon에서 이벤트는 네트워크의 피어 간에 전송되는 메시지입니다. 이벤트는 다른 플레이어에게 플레이어 사망 또는 업적과 같은 게임 이벤트를 알리는 데 사용할 수 있습니다.

방 속성: 방 이름, 플레이어 수 및 사용자 지정 게임 매개 변수와 같은 Photon 방과 관련된 데이터입니다.

로비: 플레이어가 사용 가능한 방을 탐색하고 게임 세션에 참여할 수 있는 가상 대기실입니다. 로비는 매치 유형 또는 기타 기준에 따라 게임을 구성하는 데 사용할 수 있습니다.

Photon Cloud: 멀티플레이어 게임을 위한 호스팅 및 매치메이킹 서비스를 제공하는 Photon의 클라우드 기반 버전입니다. Photon 클라우드는 특히 소규모 개발 팀을 위해 멀티플레이어 게임의 설정 및 관리를 단순화하는 데 사용할 수 있습니다.

---

# master client 판단
```c#
using Photon.Pun;
using Photon.Realtime;
using System.Collections.Generic;

public class MyGameRoomManager : MonoBehaviourPunCallbacks
{
    private Player masterClient;

    // This method is called by Photon whenever a new player joins the room
    public override void OnPlayerEnteredRoom(Player newPlayer)
    {
        base.OnPlayerEnteredRoom(newPlayer);

        // Check if the new player should be assigned as the master client
        if (ShouldAssignMasterClient(newPlayer))
        {
            // Update the master client variable
            masterClient = newPlayer;

            // Notify other players that the master client has changed
            Hashtable properties = new Hashtable();
            properties["MasterClient"] = masterClient.ActorNumber;
            PhotonNetwork.CurrentRoom.SetCustomProperties(properties);
        }
    }

    // This method is called by Photon whenever a player leaves the room
    public override void OnPlayerLeftRoom(Player otherPlayer)
    {
        base.OnPlayerLeftRoom(otherPlayer);

        // Check if the leaving player was the master client
        if (otherPlayer.Equals(masterClient))
        {
            // Reassign the master client role to another player
            List<Player> otherPlayers = new List<Player>(PhotonNetwork.PlayerListOthers);
            masterClient = otherPlayers[Random.Range(0, otherPlayers.Count)];

            // Notify other players that the master client has changed
            Hashtable properties = new Hashtable();
            properties["MasterClient"] = masterClient.ActorNumber;
            PhotonNetwork.CurrentRoom.SetCustomProperties(properties);
        }
    }

    // This method determines whether a new player should be assigned as the master client
    private bool ShouldAssignMasterClient(Player newPlayer)
    {
        // Check if the new player has a lower actor number than the current master client
        return masterClient == null || newPlayer.ActorNumber < masterClient.ActorNumber;
    }
}

```

# isMine

Photon에서 isMine 속성은 특정 게임 개체 또는 구성 요소가 로컬 클라이언트에 속하는지 아니면 같은 방에 있는 다른 클라이언트에 속하는지를 나타내는 부울 값입니다.

새 게임 개체가 인스턴스화되거나 새 구성 요소가 기존 개체에 추가되면 Photon은 게임의 소유권 규칙에 따라 해당 개체의 소유권을 특정 클라이언트에 자동으로 할당합니다. 개체를 소유한 클라이언트는 개체의 상태를 업데이트하고 해당 상태를 같은 방에 있는 다른 클라이언트에게 보내는 일을 담당합니다.

isMine 속성은 게임 개체 또는 구성 요소가 로컬 클라이언트에 속하는지 여부를 결정하는 데 사용할 수 있습니다. isMine이 참이면 객체가 로컬 클라이언트에 속하고 클라이언트가 해당 객체의 상태를 업데이트하고 관리할 책임이 있음을 의미합니다. isMine이 거짓이면 객체가 같은 방에 있는 다른 클라이언트에 속하고 로컬 클라이언트가 객체의 상태를 직접 수정하거나 업데이트하려고 시도해서는 안 된다는 의미입니다.

다음은 Photon 스크립트에서 isMine을 사용하는 방법의 예입니다.

---

```c#
using UnityEngine;
using Photon.Pun;

public class MyScript : MonoBehaviourPun
{
    // Update is called once per frame
    void Update()
    {
        if (photonView.IsMine)
        {
            // Only update the position if this object belongs to the local client
            transform.position += new Vector3(1f, 0f, 0f) * Time.deltaTime;
        }
    }
}
```
이 예에서는 시간이 지남에 따라 객체를 오른쪽으로 이동시키는 간단한 스크립트를 게임 객체에 첨부했습니다. 그러나 개체가 로컬 클라이언트에 속하는 경우에만 위치를 업데이트하려고 합니다. 개체에 연결된 PhotonView 구성 요소의 isMine 속성을 확인하여 이를 수행할 수 있습니다. isMine이 참이면 transform.position을 사용하여 객체의 위치를 업데이트합니다. isMine이 false이면 아무것도 하지 않고 대신 소유 클라이언트가 개체의 위치를 업데이트하도록 합니다.

---

Photon에서 "로컬 클라이언트"와 "클라이언트"라는 용어는 종종 같은 의미로 사용되지만 문맥에 따라 약간 다른 의미를 가질 수 있습니다.

일반적으로 "클라이언트"는 Photon 서버에 연결되어 실시간 멀티플레이어 게임에 참여하는 모든 장치 또는 애플리케이션을 의미합니다. 여기에는 데스크톱 컴퓨터, 모바일 장치, 게임 콘솔 또는 Photon 클라이언트 애플리케이션을 실행할 수 있는 기타 장치가 포함될 수 있습니다.

반면에 "로컬 클라이언트"는 일반적으로 사용자의 로컬 장치에서 현재 실행 중인 클라이언트를 나타냅니다. 이것은 종종 사용자가 상호 작용하는 게임이나 시뮬레이션을 실행하는 클라이언트입니다.

대부분의 경우 동일한 Photon 룸에 있는 로컬 클라이언트와 다른 클라이언트는 게임 논리 및 동작 측면에서 동일합니다. 그러나 로컬 클라이언트가 다른 방식으로 처리해야 하거나 다른 클라이언트가 액세스할 수 없는 추가 정보나 리소스에 액세스해야 하는 특정 경우가 있을 수 있습니다.

예를 들어 1인칭 슈팅 게임에서 로컬 클라이언트는 플레이어의 입력과 이동을 직접 처리해야 하는 반면 다른 클라이언트는 플레이어의 위치와 방향에 대한 업데이트를 받기만 하면 됩니다. 마찬가지로 실시간 전략 게임에서 로컬 클라이언트는 게임 세계와 모든 유닛 및 리소스에 대한 자세한 보기에 액세스할 수 있는 반면 다른 클라이언트는 게임 세계에 대한 제한된 보기에만 액세스할 수 있습니다.

전반적으로 Photon에서 "로컬 클라이언트"와 "클라이언트"의 차이점은 대부분 관점과 컨텍스트의 문제입니다. 두 유형의 클라이언트 모두 매력적이고 반응이 빠른 실시간 멀티플레이어 게임을 만드는 데 중요합니다.

---

# 소유권 변경

예, Photon에서는 객체 소유권을 한 클라이언트에서 다른 클라이언트로 변경할 수 있습니다. 이는 플레이어 간에 게임 개체를 전송해야 하는 상황이나 플레이어가 게임을 떠나고 다른 플레이어가 개체를 제어해야 하는 경우에 유용할 수 있습니다.

Photon에서 객체의 소유권을 변경하려면 PhotonView.TransferOwnership() 메소드를 사용할 수 있습니다. 이 메소드는 소유권을 이전하려는 게임 오브젝트에 연결된 PhotonView 컴포넌트에서 호출할 수 있습니다.

다음은 현재 소유자(마스터 클라이언트를 포함한 모든 클라이언트일 수 있음)에서 특정 플레이어로 개체 소유권을 이전하는 방법을 보여주는 예제 코드 스니펫입니다.

---

```c#
using Photon.Pun;
using Photon.Realtime;
using UnityEngine;

public class ExampleScript : MonoBehaviourPunCallbacks
{
    [SerializeField] private GameObject objectToTransfer;
    [SerializeField] private Player newOwner;

    private void TransferObjectOwnership()
    {
        // Get the PhotonView component attached to the object
        PhotonView photonView = objectToTransfer.GetComponent<PhotonView>();
        
        // Transfer ownership to the specified player
        photonView.TransferOwnership(newOwner);
    }
}
```

---

이 예제에서는 먼저 objectToTransfer에 첨부된 PhotonView 컴포넌트에 대한 참조를 얻습니다. 그런 다음 PhotonView에서 TransferOwnership() 메서드를 호출하여 객체의 새로운 소유자를 나타내는 Player 객체를 전달합니다.

TransferOwnership() 메서드는 객체의 현재 소유자만 호출할 수 있으므로 마스터 클라이언트에서 다른 플레이어로 소유권을 이전하려면 마스터 클라이언트의 PhotonView 인스턴스에서 메서드를 호출해야 합니다. 요소. 마스터가 아닌 클라이언트에서 다른 클라이언트로 소유권을 이전하려면 사용자 지정 RPC 또는 다른 메커니즘을 사용하여 클라이언트 간의 이전을 조정해야 합니다.

---