# SuperSideScroller
- 클래스 구조를 표와 텍스트로 표현해놓았습니다.
- 편하신 방법으로 보시면 됩니다.

## 클래스 구조 - 표
![SuperSideScroller 클래스 사진](https://github.com/ernati/SuperSideScroller/assets/31719912/6eb5def7-fded-4e86-a963-b418c7a11041)



## 클래스 구조 - 텍스트
- 각 클래스 별로, 범주 구분을 위해 "==="를 사용합니다.
  
## SuperSideScrollerGameMode 클래스

- GameMode 블루프린트의 부모 클래스

==================================================

## Start_PlayerController 클래스

- 시작 레벨을 담당하는 클래스
- 게임이 시작되면, 플레이어의 키보드 입력을 제한하고, 메인 메뉴를 띄워준다.

## SuperSideScroller_Controller 클래스

- 인게임 레벨을 담당하는 클래스
- 인게임 레벨로 진입하면, 유저에게 현재까지 획득한 코인의 수를 알려주는 UI를 띄운다.
- 유저가 코인을 모두 모으면, 재시작 UI를 띄운다.

==================================================

## SuperSideScroller_Player 클래스

- 플레이어 클래스
- 플레이어의 행동 함수들이 구현되어있다.
    - 공 발사
    - 코인이나 물약을 주웠을 때의 호출될 함수

## EnemyBase 클래스

- 적들이 상속받을 부모 클래스
- 액터를 삭제하는 Destory() 함수만 가지고 있다.

=======================================

## BagComponent 클래스

- 플레이어가 가지고 다닐 물건들을 담는 가방 컴포넌트
- 플레이어가 얻을 코인에 대한 함수들을 담고 있다.

========================================

## PickableActor_Base 클래스

- 플레이어가 줍는 액터들이 상속받을 부모 클래스다.
- 주웠을 때, 자식 클래스들이 어떤 행동을 할지 결정할 
오버라이딩 함수인 PlayerPickedUp을 보유 중이다.

## PickableActor_Collectable 클래스

- 플레이어가 줍는 액터 중 플레이어가 가지고 다닐 액터의 클래스다.
    - 코인

## PickableActor_Powerup 클래스

- 플레이어가 줍는 액터 중 플레이어를 일정시간 강화시켜주는 클래스

====================================================

## SuperSideScroller_Brick 클래스

- 플레이어가 액터에 밑부분에 닿으면 파괴되며, 플레이어에게 코인을 부여하는 클래스
- 마치 마리오가 부수는 박스와 같다.

==============================================

## PlayerProjectile 클래스

- 플레이어가 던지는 공을 담당하는 클래스\
- 적이 맞으면 적 액터가 사라진다.

===============================================

## Anim_ProjectileNotify 클래스

- 애니메이션 재생시, 애님 노티파이를 통해 호출될 함수를 구현
- 이 기능을 통해, 던지기 애니메이션이 재생될 때, 원하는 타이밍에 공을 스폰시킴.

===============================================

## MainMenuWidget 클래스
## SideScroller_IngameWIdget클래스
