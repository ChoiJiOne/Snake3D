# [USAGE] HotReload.bat 사용법

이 문서는 `HotReload.bat` 사용법에 대한 문서입니다.
<br><br>


## 개요

만약 Premake5 스크립트를 이용해서 Visual Studio 솔루션 및 하위 프로젝트 설정을 변경하여 그 변경 사항을 업데이트하기 위해서는 `CMD`에서 `Bin\\premake5.exe <your-visual-studio>`를 입력하거나 `GenerateProjectFiles.bat`를 실행해야 합니다. 첫 번째의 경우는 매번 입력하기 귀찮고, 두번째의 경우 실행할 때마다 Visual Studio가 새롭게 열여 번거롭습니다. 따라서, 위 두 가지 이유로 Visual Studio 솔루션 및 하위 프로젝트의 업데이트만 수행하는 `HotReload.bat` 스크립트를 구현하게 되었습니다.
<br><br>


## 준비

`HotReload.bat`를 사용하기 위해서는 다음이 필요합니다.

- Visual Studio 2019 or 2022
<br><br>


## 사용법

`HotReload.bat`를 사용하기 위해서는 `Snake3D` 폴더에서 CMD 혹은 터미널을 실행하고 다음 명령어를 입력합니다.

```
> HotReload.bat <visual-studio-version>
```
- Visual Studio 2019를 사용하고 있는 경우
    ```
    > HotReload.bat vs2019
    ```
- Visual Studio 2022를 사용하고 있는 경우
    ```
    > HotReload.bat vs2022
    ```