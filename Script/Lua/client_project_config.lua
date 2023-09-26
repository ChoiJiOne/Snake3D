-- Client 프로젝트입니다.
project "Client"
    -- Client 프로젝트의 종류를 설정합니다.
    kind "ConsoleApp"

    -- 프로그래밍 언어를 설정합니다.
    language "C++"

    -- C++의 표준을 설정합니다.
    cppdialect "C++17"

    -- 멀티 스레드 빌드를 활성화합니다.
    flags { "MultiProcessorCompile" }

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