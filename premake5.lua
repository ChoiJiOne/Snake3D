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

    -- 엔진 경로입니다.
    engine="%{wks.location}/../Engine"

    -- 엔진의 소스 코드 경로입니다.
    engineSource="%{engine}/Source"

    -- 엔진의 설정 파일 경로입니다.
    engineConfig="%{engine}/Config"

    -- 엔진의 셰이더 파일 경로입니다.
    engineShader="%{engine}/HLSL"

    -- 엔진의 스크립트 경로입니다.
    engineScript="%{engine}/Script"

    -- 엔진의 서드 파티 라이브러리 경로입니다.
    engineThirdparty="%{engine}/ThirdParty"

    -- 클라이언트 경로입니다.
    client="%{wks.location}/../Client"

    -- 클라이언트의 소스 코드 경로입니다.
    clientSource="%{client}/Source"

    -- 클라이언트의 설정 파일 경로입니다.
    clientConfig="%{client}/Config"

    -- 클라이언트의 리소스 파일 경로입니다.
    clientResource="%{client}/Resource"

    -- 시작 프로젝트를 설정합니다.
    startproject "Client"

    -- 엔진 프로젝트입니다.
    project "Engine"
        -- 엔진 프로젝트의 종류를 설정합니다.
        kind "StaticLib"

        -- 프로그래밍 언어를 설정합니다.
        language "C++"

        -- C++의 표준을 설정합니다.
        cppdialect "C++17"

        -- 엔진의 include 경로를 추가합니다.
        includedirs {
            "%{engineSource}",
            "%{engineConfig}",
            "%{engineShader}",
            "%{engineScript}",
            "%{engineThirdparty}",
        }

        -- 엔진의 file 경로를 추가합니다.
        files {
            "%{engineSource}/*",
            "%{engineSource}/Game/*",
            "%{engineSource}/Manager/*",
            "%{engineSource}/Matrix/*",
            "%{engineSource}/Resource/*",
            "%{engineSource}/Shader/*",
            "%{engineSource}/Utils/*",
            "%{engineSource}/Vector/*",

            "%{engineConfig}/*",
            
            "%{engineShader}/*",

            "%{engineScript}/*",
            
            "%{engineThirdparty}/json/*",
            "%{engineThirdparty}/miniaudio/*",
            "%{engineThirdparty}/sqlite3/*",
            "%{engineThirdparty}/stb/*",
        }

        -- 빌드 시 셰이더 컴파일은 비활성화합니다.
        filter { "files:**.hlsl" }
            flags { "ExcludeFromBuild" }
        filter { }


        -- 라이브러리를 연결합니다.
        links {
            "Dbghelp.lib",
            "d3d11.lib",
            "dxgi.lib",
            "dxguid.lib",
            "d3dcompiler.lib",
            "winmm.lib",
            "pdh.lib",
            "shlwapi.lib",
        }

        -- 특정 라이브러리에서 발생하는 경고를 무시합니다.
        disablewarnings { 
            "4996", 
            "4006",
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

    
    -- 클라이언트 프로젝트
    project "Client"
        -- 클라이언트 프로젝트의 종류를 설정합니다.
        kind "WindowedApp"

        -- 프로그래밍 언어를 설정합니다.
        language "C++"

        -- C++의 표준을 설정합니다.
        cppdialect "C++17"

        -- 엔진을 연결합니다.
        links {"Engine"}
        
        -- 클라이언트의 include 경로를 추가합니다.
        includedirs {
            "%{engineSource}", -- 엔진 소스 경로 추가 필요!
            "%{engineThirdparty}", -- 엔진 서드 파티 라이브러리 추가 필요!
            "%{clientSource}",
            "%{clientConfig}",
            "%{clientResource}",
        }

        -- 클라이언트의 file 경로를 추가합니다.
        files {
            "%{clientSource}/*",

            "%{clientConfig}/*",
        }

        -- 명령행 인수를 설정합니다.
        debugargs {
            "Crash=%{wks.location}..\\Crash\\",
            "Shader=%{wks.location}..\\Engine\\HLSL\\",
            "Resource=%{wks.location}..\\Client\\Resource\\",
            "EngineConfig=%{wks.location}..\\Engine\\Config\\Config.json",
            "ClientConfig=%{wks.location}..\\Client\\Config\\Config.json",
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

