-- Snake3D 게임 개발 작업 영역입니다.
workspace "Snake3D"
    -- 빌드 구성 요소입니다.
    configurations { 
        "Debug", 
        "Release", 
        "Shipping" 
    }

    -- 플랫폼을 설정합니다.
    platforms { "Win64" }

    -- 솔루션 경로를 설정합니다.
    location "%{wks.name}"

    -- 소스 코드 경로입니다.
    source="%{wks.location}/../Source"

    -- 셰이더 파일 경로입니다.
    shader="%{wks.location}/../GLSL"

    -- 스크립트 파일 경로입니다.
    script="%{wks.location}/../Script"

    -- 서드 파티 라이브러리 경로입니다.
    thirdparty="%{wks.location}/../ThirdParty"

    -- 시작 프로젝트를 설정합니다.
    startproject "Client"

    -- 서드 파티 라이브러리 설정 스크립트를 추가합니다.
    include "Script/ThirdParty.lua"

    -- Client 프로젝트입니다.
    project "Client"
        -- Client 프로젝트의 종류를 설정합니다.
        kind "ConsoleApp"

        -- 프로그래밍 언어를 설정합니다.
        language "C++"

        -- C++의 표준을 설정합니다.
        cppdialect "C++17"

        -- 외부 라이브러리를 연결합니다.
        links { 
            "glfw", 
            "glad", 
            "stb", 
            "miniaudio", 
            "glm",
            "Dbghelp.lib",
        }

        -- 클라이언트의 include 경로를 추가합니다.
        includedirs {
            "%{source}",

            "%{thirdparty}",
            
            "%{thirdparty}/glfw/Include",
            "%{thirdparty}/glad/Include",
            "%{thirdparty}/stb/Include",
            "%{thirdparty}/miniaudio/Include",
        }

        -- 클라이언트의 file 경로를 추가합니다.
        files {
            "%{source}/**",
            "%{shader}/**",
            "%{script}/**",
        }

        -- 특정 라이브러리에서 발생하는 경고를 무시합니다.
        disablewarnings { 
            "4996", 
            "4006",
            "26812", 
            "6385", 
        }

        -- 명령행 인수를 설정합니다.
        debugargs {
            "Crash=%{wks.location}..\\Crash\\",
            "Shader=%{wks.location}..\\GLSL\\",
            "Resource=%{wks.location}..\\Resource\\",
            "Log=%{wks.location}..\\Log\\",
            "Vsync=off",
            "-SaveLogFile",
        }

        -- 구성 요소별 설정을 수행합니다.
        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG", "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"

        filter "configurations:Shipping"
            defines { "NDEBUG", "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"