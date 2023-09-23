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

    -- glfw 프로젝트입니다.
    project "glfw"
        -- glfw 프로젝트의 종류를 설정합니다.
        kind "StaticLib"

        -- 프로그래밍 언어를 설정합니다.
        language "C"

        -- glfw의 include 경로를 추가합니다.
        includedirs {
            "%{thirdparty}/glfw/Include",
        }

        -- glfw의 file 경로를 추가합니다.
        files {
            "%{thirdparty}/glfw/Include/*",
            "%{thirdparty}/glfw/Source/*",
        }

        disablewarnings { 
            "4996", 
        }

        -- 구성 요소별 설정을 수행합니다.
        filter "configurations:Debug"
            defines { "DEBUG", "_GLFW_WIN32" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG", "RELEASE", "_GLFW_WIN32"  }
            runtime "Release"
            optimize "On"
            symbols "On"

        filter "configurations:Shipping"
            defines { "NDEBUG", "SHIPPING", "_GLFW_WIN32"  }
            runtime "Release"
            optimize "Full"
            symbols "Off"

    -- glad 프로젝트입니다.
    project "glad"
        -- glad 프로젝트의 종류를 설정합니다.
        kind "StaticLib"

        -- 프로그래밍 언어를 설정합니다.
        language "C"

        -- glad의 include 경로를 추가합니다.
        includedirs {
            "%{thirdparty}/glad/Include",
        }

        -- glad의 file 경로를 추가합니다.
        files {
            "%{thirdparty}/glad/Include/*",
            "%{thirdparty}/glad/Source/*",
        }

        disablewarnings { 
            "4996", 
        }

        -- 구성 요소별 설정을 수행합니다.
        filter "configurations:Debug"
            defines { "DEBUG", }
            runtime  "Debug"
            optimize "Off"
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG", "RELEASE", }
            runtime "Release"
            optimize "On"
            symbols "On"

        filter "configurations:Shipping"
            defines { "NDEBUG", "SHIPPING", }
            runtime "Release"
            optimize "Full"
            symbols "Off"

    -- stb 프로젝트입니다.
    project "stb"
        -- stb 프로젝트의 종류를 설정합니다.
        kind "StaticLib"

        -- 프로그래밍 언어를 설정합니다.
        language "C"

        -- stb의 include 경로를 추가합니다.
        includedirs {
            "%{thirdparty}/stb/Include",
        }

        -- stb의 file 경로를 추가합니다.
        files {
            "%{thirdparty}/stb/Include/*",
            "%{thirdparty}/stb/Source/*",
        }

        disablewarnings { 
            "4996", 
        }

        -- 구성 요소별 설정을 수행합니다.
        filter "configurations:Debug"
            defines { "DEBUG", }
            runtime  "Debug"
            optimize "Off"
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG", "RELEASE", }
            runtime "Release"
            optimize "On"
            symbols "On"

        filter "configurations:Shipping"
            defines { "NDEBUG", "SHIPPING", }
            runtime "Release"
            optimize "Full"
            symbols "Off"

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
            "Dbghelp.lib",
        }

        -- 클라이언트의 include 경로를 추가합니다.
        includedirs {
            "%{source}",

            "%{thirdparty}/Include",

            "%{thirdparty}/glfw/Include",
            "%{thirdparty}/glad/Include",
            "%{thirdparty}/stb/Include",
        }

        -- 클라이언트의 file 경로를 추가합니다.
        files {
            "%{source}/*",
            "%{source}/Game/*",
            "%{source}/GameEngine/*",
            "%{source}/GameObject/*",
            "%{source}/Manager/*",
            "%{source}/Resource/*",
            "%{source}/Utility/*",

            "%{shader}/*",

            "%{script}/*",

            "%{thirdparty}/Include/glad/*",
            "%{thirdparty}/Include/glm/*",
            "%{thirdparty}/Include/glm/detail/*",
            "%{thirdparty}/Include/glm/ext/*",
            "%{thirdparty}/Include/glm/gtc/*",
            "%{thirdparty}/Include/glm/gtx/*",
            "%{thirdparty}/Include/glm/simd/*",
            "%{thirdparty}/Include/miniaudio/*",
            "%{thirdparty}/Include/stb/*",
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