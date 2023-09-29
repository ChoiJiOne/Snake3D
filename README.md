# Snake3D *v0.0*
- 3D 뱀 게임 개발 프로젝트의 *v0.0*입니다.
<br><br>


## Platform

`Snake3D` *v0.0*는 `Windows Platform`만 지원합니다.
<br><br>


## Requirements

`Snake3D` *v0.0*를 유지보수 하기 위한 요구 사항은 다음과 같습니다.

- [git](https://git-scm.com/)
- [Visual Studio 2019 이상](https://visualstudio.microsoft.com/)
<br><br>


## Language

`Snake3D` *v0.0*은 `C++17` 으로 구현되었습니다.  
> `Windows`에 특화된 코드도 존재하므로, `Linux`나 `MacOSX`에서는 빌드되지 않습니다.

<br><br>


## Clone

`CMD` 에서 다음과 같이 수행하시면 *v0.0*의 저장소 복제본을 얻을 수 있습니다.

```
git clone https://github.com/ChoiJiOne/Snake3D --single-branch -b v0.0
```
<br><br>


## Download & Play

실행 가능한 게임 실행 파일을 얻기 위해서는 [v0.0](https://github.com/ChoiJiOne/Snake3D/releases/tag/v0.0)으로 이동한 뒤 `Snake3D.zip`을 클릭합니다.

![](./Docs/게임%20다운로드%20및%20플레이%20방법/image/image00.png)
<br><br>


### 게임 실행

다운로드가 완료 되었으면 `Snake3D.zip`의 압축을 해제합니다. 압축을 해제하면 다음과 같은 구조를 볼 수 있는데, `RunGame.bat`를 실행하면 게임을 실행할 수 있습니다.

![](./Docs/게임%20다운로드%20및%20플레이%20방법/image/image01.png)
<br><br>


### 게임 실행 화면

게임 실행 화면은 총 3개로, 아래와 같습니다.


#### 시작 화면

게임을 실행하면 아래와 같은 화면을 볼 수 있습니다.

![](./Docs/게임%20다운로드%20및%20플레이%20방법/image/image02.png)

시작 화면 내에는 버튼만 있고, 이 버튼들은 좌측 마우스 버튼으로 클릭 가능합니다. 게임의 `Start` 버튼을 클릭하면 게임을 플레이할 수 있고, `Quit` 버튼을 클릭하면 게임이 종료됩니다.


#### 플레이 화면

시작 화면에서 `START` 버튼을 클릭하면 아래와 같은 화면을 볼 수 있습니다.

![](./Docs/게임%20다운로드%20및%20플레이%20방법/image/image03.png)

시작하자 마자 몸통의 크기가 4인 뱀이 있는데, 이 뱀은 키보드의 상, 하, 좌, 우 키로 조종할 수 있습니다. 그리드 상에 존재하는 먹이를 먹으면 크기가 1씩 증가하고, 먹이를 7개 먹을 때마다 뱀의 이동 속도가 빨라집니다. 


#### 종료 화면 

더 이상 플레이 할 수 없으면 아래의 화면으로 전환됩니다.

![](./Docs/게임%20다운로드%20및%20플레이%20방법/image/image04.png)

플레이가 종료되면 화면은 회색 화면으로 전환되고, 종료 화면의 버튼 또한 좌측 마우스 버튼으로 클릭 가능합니다. 아래의 버튼 중 `Continue` 버튼을 클릭하면 시작 화면으로 돌아가고, `Quit` 버튼을 클릭하게 되면 게임을 종료하게 됩니다.
<br><br>


## Misc

그 외의 배치 스크립트 사용법은 [여기](./Docs/README.md)의 문서 목록을 확인하시면 됩니다.