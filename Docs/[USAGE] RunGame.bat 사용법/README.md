# RunGame.bat 사용법

이 문서는 `RunGame.bat` 사용법에 대한 문서입니다.
<br><br>


## 개요

`Snake3D` 프로젝트를 실행할 때는 다양한 명령행 인자를 설정해주어야 합니다. 하지만 다양한 명령행 인자를 실행할 때마다 일일이 전달하기는 매우 귀찮기 때문에, `RunGame.bat` 스크립트를 구현하게 되었습니다.
<br><br>


## 준비

`RunGame.bat`는 사전에 빌드된 바이너리 파일을 실행하는 것이므로, `Snake3D` 프로젝트가 빌드되어 있어야 합니다.
<br><br>


## 사용법

`RunGame.bat`를 사용하기 위해서는 `Snake3D` 폴더에서 CMD 혹은 터미널을 실행하고 다음 명령어를 입력합니다.

```
> RunGame.bat <mode>
```

이 스크립트가 지원하는 `mode`는 Debug, Release, Shipping입니다. 각 모드 별 특징은 다음과 같습니다.

| mode | description |
|:---|:---|
| Debug | 	빌드 과정에서 최적화를 하지 않고, 디버그 정보 파일(.pdb)을 생성합니다. |
| Release | 빌드 과정에서 최적화는 하지만 디버그 정보 파일(.pdb)을 생성합니다. |
| Shipping | 빌드 과정에서 컴파일러가 할 수 있는 모든 최적화를 수행합니다. |

따라서, `RunGame.bat` 사용 예시는 다음과 같습니다.

```
Debug 모드로 실행할 경우...
> RunGame.bat Debug

Release 모드로 실행할 경우...
> RunGame.bat Release

Shipping 모드로 실행할 경우...
> RunGame.bat Shipping
```