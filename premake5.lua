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

    -- 소스 파일 경로를 설정합니다.
    source="%{wks.location}/../Source"

    -- 셰이더 파일 경로를 설정합니다.
    shader="%{wks.location}/../HLSL"

    -- 스크립트 경로를 설정합니다.
    script="%{wks.location}/../Script"

    -- 컨텐츠 경로를 설정합니다.
    content="%{wks.location}/../Content"

    -- 서드 파티 라이브러리 경로를 설정합니다.
    thirdparty="%{wks.location}/../ThirdParty"

    -- 시작 프로젝트를 설정합니다.
    startproject "Snake3D"

    -- Snake3D 게임 프로젝트입니다.
    project "Snake3D"
        -- 프로젝트의 종류를 설정합니다.
        kind "WindowedApp"

        -- 프로그래밍 언어를 설정합니다.
        language "C++"

        -- C++의 표준을 설정합니다.
        cppdialect "C++17"

        -- include 경로를 추가합니다.
        includedirs {
            "%{source}",
            "%{shader}",
            "%{script}",
            "%{thirdparty}",
        }

        -- file 경로를 추가합니다.
        files {
            "%{source}/*",
            "%{source}/Core/*",
            "%{source}/Matrix/*",
            "%{source}/Vector/*",
            
            "%{shader}/*",

            "%{script}/*",
            
            "%{thirdparty}/json/*",
            "%{thirdparty}/sqlite3/*",
            "%{thirdparty}/stb/*",
        }

        -- 빌드 시 셰이더 컴파일은 비활성화합니다.
        filter { "files:**.hlsl" }
            flags { "ExcludeFromBuild" }
        filter { }

        -- 명령행 인수를 설정합니다.
        debugargs {
            "Crash=%{wks.location}..\\Crash\\",
            "Shader=%{wks.location}..\\HLSL\\",
            "Content=%{wks.location}..\\Content\\",
        }

        -- 라이브러리를 연결합니다.
        links {
            "Dbghelp.lib",
            "Xaudio2.lib",
            "Xinput.lib",
            "d3d11.lib",
            "dxgi.lib",
            "dxguid.lib",
            "d3dcompiler.lib",
            "winmm.lib",
            "pdh.lib",
        }

        -- 특정 라이브러리에서 발생하는 경고를 무시합니다.
        disablewarnings { 
            "4996", 
            "26812", 
            "6385", 
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