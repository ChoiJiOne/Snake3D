# Snake3D의 CMake 최소 버전입니다.
cmake_minimum_required(VERSION 3.27)

# Snake3D 프로젝트 정보입니다.
project(Snake3D LANGUAGES CXX)

# Snake3D 프로젝트의 C++ 표준을 설정합니다.
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# Source 폴더 경로의 소스 코드입니다.
set(SOURCE_PATH             "${CMAKE_CURRENT_SOURCE_DIR}/Source")
set(GAME_SOURCE_PATH        "${SOURCE_PATH}/Game")
set(MANAGER_SOURCE_PATH     "${SOURCE_PATH}/Manager")
set(RESOURCE_SOURCE_PATH    "${SOURCE_PATH}/Resource")
set(UTILITY_SOURCE_PATH     "${SOURCE_PATH}/Utility")
set(WINDOWS_SOURCE_PATH     "${SOURCE_PATH}/Windows")
file(GLOB_RECURSE GAME_SOURCE       "${GAME_SOURCE_PATH}/*")
file(GLOB_RECURSE MANAGER_SOURCE    "${MANAGER_SOURCE_PATH}/*")
file(GLOB_RECURSE RESOURCE_SOURCE   "${RESOURCE_SOURCE_PATH}/*")
file(GLOB_RECURSE UTILITY_SOURCE    "${UTILITY_SOURCE_PATH}/*")
file(GLOB_RECURSE WINDOWS_SOURCE    "${WINDOWS_SOURCE_PATH}/*")

# GLSL 폴더 경로의 GLSL 셰이더 파일입니다.
set(GLSL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/GLSL")
file(GLOB_RECURSE GLSL_SOURCE "${GLSL_PATH}/*")

# 서드 파티 경로입니다.
set(THIRD_PARTY_PATH    "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty")
set(THIRD_PARTY_BIN     "${THIRD_PARTY_PATH}/Bin")
set(THIRD_PARTY_INCLUDE "${THIRD_PARTY_PATH}/Include")
set(GLAD_PATH           "${THIRD_PARTY_INCLUDE}/glad")
set(GLFW_PATH           "${THIRD_PARTY_INCLUDE}/glfw")
set(GLM_PATH            "${THIRD_PARTY_INCLUDE}/glm")
set(MINIAUDIO_PATH      "${THIRD_PARTY_INCLUDE}/miniaudio")
set(STB_PATH            "${THIRD_PARTY_INCLUDE}/stb")
file(GLOB_RECURSE THIRD_PARTY_SOURCE "${THIRD_PARTY_INCLUDE}/**")
file(GLOB_RECURSE GLAD_SOURCE        "${GLAD_PATH}/*")
file(GLOB_RECURSE GLFW_SOURCE        "${GLFW_PATH}/*")
file(GLOB_RECURSE GLM_SOURCE         "${GLM_PATH}/**")
file(GLOB_RECURSE MINIAUDIO_SOURCE   "${MINIAUDIO_PATH}/*")
file(GLOB_RECURSE STB_SOURCE         "${STB_PATH}/*")

# Snake3D 프로젝트의 클라이언트입니다.
add_executable(
    Client
    ${GAME_SOURCE}
    ${MANAGER_SOURCE}
    ${RESOURCE_SOURCE}
    ${UTILITY_SOURCE}
    ${WINDOWS_SOURCE}
    ${GLSL_SOURCE}
    ${THIRD_PARTY_SOURCE}
)

# 클라이언트의 헤더 경로를 설정합니다.
target_include_directories(Client PUBLIC ${SOURCE_PATH} ${THIRD_PARTY_INCLUDE})

# 클라이언트에서 사용할 라이브러리를 추가합니다.
target_link_libraries(Client PUBLIC Dbghelp.lib ${THIRD_PARTY_BIN}/glfw3.lib)

# 클라이언트의 소스 그룹을 설정합니다.
source_group(GLSL                   FILES ${GLSL_SOURCE})
source_group(Source\\Game           FILES ${GAME_SOURCE})
source_group(Source\\Manager        FILES ${MANAGER_SOURCE})
source_group(Source\\Resource       FILES ${RESOURCE_SOURCE})
source_group(Source\\Utility        FILES ${UTILITY_SOURCE})
source_group(Source\\Windows        FILES ${WINDOWS_SOURCE})
source_group(ThirdParty\\glad       FILES ${GLAD_SOURCE})
source_group(ThirdParty\\glfw       FILES ${GLFW_SOURCE})
source_group(ThirdParty\\glm        FILES ${GLM_SOURCE})
source_group(ThirdParty\\miniaudio  FILES ${MINIAUDIO_SOURCE})
source_group(ThirdParty\\stb        FILES ${STB_SOURCE})

# Snake3D 프로젝트의 시작 프로젝트를 클라이언트로 설정합니다.
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Client)