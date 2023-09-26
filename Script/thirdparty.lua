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

-- miniaudio 프로젝트입니다.
project "miniaudio"
  -- miniaudio 프로젝트의 종류를 설정합니다.
  kind "StaticLib"

  -- 프로그래밍 언어를 설정합니다.
  language "C"

  -- miniaudio의 include 경로를 추가합니다.
  includedirs {
      "%{thirdparty}/miniaudio/Include",
  }

  -- miniaudio의 file 경로를 추가합니다.
  files {
      "%{thirdparty}/miniaudio/Include/*",
      "%{thirdparty}/miniaudio/Source/*",
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

-- glm 프로젝트입니다.
project "glm"
  -- glm 프로젝트의 종류를 설정합니다.
  kind "StaticLib"

  -- 프로그래밍 언어를 설정합니다.
  language "C"

  -- glm의 include 경로를 추가합니다.
  includedirs {
      "%{thirdparty}",
  }

  -- glm의 file 경로를 추가합니다.
  files {
      "%{thirdparty}/glm/**",
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