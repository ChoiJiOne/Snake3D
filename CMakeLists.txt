# Snake3D의 CMake 최소 버전입니다.
cmake_minimum_required(VERSION 3.27)

# Snake3D 프로젝트 정보입니다.
project(Snake3D LANGUAGES CXX)

# Snake3D 프로젝트의 C++ 표준을 설정합니다.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source 폴더 경로의 소스 코드입니다.
set(SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Source")
set(GAME_SOURCE_PATH "${SOURCE_PATH}/Game")
set(MANAGER_SOURCE_PATH "${SOURCE_PATH}/Manager")
set(RESOURCE_SOURCE_PATH "${SOURCE_PATH}/Resource")
set(UTILITY_SOURCE_PATH "${SOURCE_PATH}/Utility")
set(WINDOWS_SOURCE_PATH "${SOURCE_PATH}/Windows")
file(GLOB_RECURSE GAME_SOURCE "${GAME_SOURCE_PATH}/*")
file(GLOB_RECURSE MANAGER_SOURCE "${MANAGER_SOURCE_PATH}/*")
file(GLOB_RECURSE RESOURCE_SOURCE "${RESOURCE_SOURCE_PATH}/*")
file(GLOB_RECURSE UTILITY_SOURCE "${UTILITY_SOURCE_PATH}/*")
file(GLOB_RECURSE WINDOWS_SOURCE "${WINDOWS_SOURCE_PATH}/*")

# Snake3D 프로젝트의 클라이언트입니다.
add_executable(
    Client
    ${GAME_SOURCE}
    ${MANAGER_SOURCE}
    ${RESOURCE_SOURCE}
    ${UTILITY_SOURCE}
    ${WINDOWS_SOURCE}
)

# 클라이언의 헤더 경로를 설정합니다.
target_include_directories(Client PUBLIC ${SOURCE_PATH})

# 클라이언트의 소스 그룹을 설정합니다.
source_group(Source\\Game FILES ${GAME_SOURCE})
source_group(Source\\Manager FILES ${MANAGER_SOURCE})
source_group(Source\\Resource FILES ${RESOURCE_SOURCE})
source_group(Source\\Utility FILES ${UTILITY_SOURCE})
source_group(Source\\Windows FILES ${WINDOWS_SOURCE})

# Snake3D 프로젝트의 시작 프로젝트를 클라이언트로 설정합니다.
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Client)