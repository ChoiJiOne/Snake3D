-- Visual Studio 솔루션 이름을 인자로 전달했는지 확인합니다.
if _ARGS[1] then
    solution = _ARGS[1]
    print(string.format("Setting '%s' visual studio solution name...", solution))
else
    print("Missing visual studio solution name...")
    os.exit()
end

-- 프로젝트 루트 디렉토리입니다.
rootdirectory=_MAIN_SCRIPT_DIR

-- 소스 파일 경로입니다.
source="%{rootdirectory}/Source"

-- 셰이더 파일 경로입니다.
shader="%{rootdirectory}/GLSL"

-- 스크립트 파일 경로입니다.
script="%{rootdirectory}/Script"

-- 서드 파티 라이브러리 경로입니다.
thirdparty="%{rootdirectory}/ThirdParty"

include "Script/vs_solution_config.lua"
include "Script/thirdparty_project_config.lua"
include "Script/client_project_config.lua"