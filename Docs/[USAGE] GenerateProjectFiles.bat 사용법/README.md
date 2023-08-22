# GenerateProjectFiles.bat 사용법

이 문서는 `GenerateProjectFiles.bat` 사용법에 대한 문서입니다.
<br><br>


## 개요

이전에 다운로드 받은 오픈 소스에 Visual Studio 솔루션과 하위 프로젝트가 있었는데 세팅이 미묘하게 달라 빌드되지 않은 상황이 있었습니다. 그런데, 이러한 경우가 이 이외에도 의외로 빈번했습니다. 따라서, 이 프로젝트를 배포할 때 Visual Studio 솔루션과 하위 프로젝트를 배포하는 대신, 사용자의 Visual Studio에 맞게 프로젝트를 세팅하는 스크립트를 구현하였습니다.
<br><br>


## 준비

`GenerateProjectFiles.bat`를 사용하기 위해서는 다음이 필요합니다.

- Visual Studio 2019 or 2022
<br><br>


## 사용법

`GenerateProjectFiles.bat`를 사용하기 위해서는 `Snake3D` 폴더에서 CMD 혹은 터미널을 실행하고 다음 명령어를 입력합니다.

```
> GenerateProjectFiles.bat <visual-studio-version>
```
- Visual Studio 2019를 사용하고 있는 경우
    ```
    > GenerateProjectFiles.bat vs2019
    ```
- Visual Studio 2022를 사용하고 있는 경우
    ```
    > GenerateProjectFiles.bat vs2022
    ```