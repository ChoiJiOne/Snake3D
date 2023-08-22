# Build.bat 사용법

이 문서는 `Build.bat` 사용법에 대한 문서입니다.
<br><br>


## 개요

이전 프로젝트들에서 제공하는 빌드 스크립트는 `MSBuild.exe`의 경로를 환경 변수에 등록해야 사용할 수 있었습니다. 이는 매우 번거로운 작업입니다. 이러한 번거로움을 없애기 위해 `MSBuild.exe` 경로를 찾고, 그 경로를 기반으로 솔루션을 빌드하는 `Build.bat` 스크립트를 구현하게 되었습니다.
<br><br>



## 준비

`Build.bat`를 사용하기 위해서는 다음이 필요합니다.

- Visual Studio 2019 or 2022

> MSBuild.exe 경로를 찾는 기능을 이용하기 위해서는 vswhere.exe 가 필요한데, 이 실행 파일은 프로젝트의 Bin폴더에 있습니다.

<br><br>



## 사용법

`Build.bat`를 사용하기 위해서는 `Snake3D` 폴더에서 CMD 혹은 터미널을 실행하고 다음 명령어를 입력합니다.

```
> Build.bat <mode>
```

이 스크립트가 지원하는 `mode`는 Debug, Release, Shipping입니다. 각 모드 별 특징은 다음과 같습니다.

| mode | description |
|:---|:---|
| Debug | 	빌드 과정에서 최적화를 하지 않고, 디버그 정보 파일(.pdb)을 생성합니다. |
| Release | 빌드 과정에서 최적화는 하지만 디버그 정보 파일(.pdb)을 생성합니다. |
| Shipping | 빌드 과정에서 컴파일러가 할 수 있는 모든 최적화를 수행합니다. |

따라서, `Build.bat` 사용 예시는 다음과 같습니다.

```
Debug 모드로 빌드할 경우...
> Build.bat Debug

Release 모드로 빌드할 경우...
> Build.bat Release

Shipping 모드로 빌드할 경우...
> Build.bat Shipping
```
<br><br>


## Reference
- [vswhere wiki : Find MSBuild](https://github.com/microsoft/vswhere/wiki/Find-MSBuild)