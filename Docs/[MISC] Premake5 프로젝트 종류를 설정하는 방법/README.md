# [MISC] Premake5 프로젝트 종류를 설정하는 방법

이 문서는 Premake5에서 프로젝트 종류를 설정하는 방법에 대한 문서입니다.
<br><br>


## Premake5 프로젝트 종류 설정 

Premake5는 프로젝트에서 생성되는 바이너리 객체의 종류를 설정할 수 있는 기능을 제공합니다. 이는 콘솔 또는 창 애플리케이션, 공유 또는 정적 라이브러리와 같은 것일 수 있습니다. 사용 방법은 다음과 같습니다.

```
kind ("kind")
```

<br><br>


## Parameters

"kind"는 다음과 같은 문자열 식별자 중 하나입니다.

| Value | Description |
|:---:|:---|
| ConsoleApp | 콘솔 또는 명령줄 응용 프로그램 |
| WindowedApp | 데스크톱 창에서 실행되는 응용 프로그램 |
| SharedLib | 공유 라이브러리 또는 DLL |
| StaticLib | 정적 라이브러리 |

<br><br>


## Example

사용 예시는 다음과 같습니다.

1. 콘솔 애플리케이션으로 프로젝트 종류 설정
   ```
   kind "ConsoleApp"
   ```
2. DLL로 프로젝트 종류 설정
   ```
   kind "SharedLib"
   ```
3. `premake5.lua` 스크립트 내 사용 예시
   ```
   workspace "MyWorkspace"
      configurations { "DebugLib", "DebugDLL", "ReleaseLib", "ReleaseDLL" }

      project "MyProject"

         filter "*Lib"
            kind "StaticLib"

         filter "*DLL"
            kind "SharedLib"
   ```
<br><br>


## Reference
- [Premake5 document reference : kind](https://premake.github.io/docs/kind/)