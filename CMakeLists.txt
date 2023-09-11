# Snake3D의 CMake 최소 버전입니다.
cmake_minimum_required(VERSION 3.27)

# Snake3D 프로젝트 정보입니다.
project(Snake3D LANGUAGES CXX)

# Snake3D 프로젝트의 C++ 표준을 설정합니다.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Snake3D 프로젝트의 클라이언트입니다.
add_executable(
    Client
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Application.cpp
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Client)