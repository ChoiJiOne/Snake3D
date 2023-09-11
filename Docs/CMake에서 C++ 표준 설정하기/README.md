# CMake에서 C++ 표준 설정하기

이 문서는 CMake에서 C++ 표준을 설정하는 방법에 대한 문서입니다.
<br><br>


## CMake에서 C++ 표준 설정하기

CMake에서 C++ 표준을 설정하기 위해서는 다음과 같이 입력하면 됩니다.

```
set (CMAKE_CXX_STANDARD <STANDARD>)
```

만약, 프로젝트의 C++ 표준을 C++14로 설정하고 싶다면 다음과 같이 입력하면 됩니다.

```
set (CMAKE_CXX_STANDARD 14)
```

C++ 표준 사용을 명시하기 위해서는 다음 키워드를 추가합니다.

```
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```
<br><br>


## CMake에서 지원하는 C++ 표준

CMake에서 지원하는 C++ 표준 목록은 다음과 같습니다. 일부 표준은 CMake 버전에 따라 다릅니다.

| C++ 표준 | 지원 여부 |
|:---:|:---|
| C++98 | O |
| C++11 | O |
| C++14 | O |
| C++17 | O (New in version 3.8.) |
| C++20 | O (New in version 3.12.) |
| C++23 | O (New in version 3.20.) |

<br><br>


## 참조
- [How do I activate C++ 11 in CMake?](https://stackoverflow.com/questions/10851247/how-do-i-activate-c-11-in-cmake)
- [CMake Document : CXX_STANDARD](https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html)