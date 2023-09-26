@echo off

SET project=%1
SET visualstudio=%2
SET premake5=Bin\\premake5.exe

if "%project%" == "" (
    echo project name is empty...
    GOTO:EOF
)

if "%visualstudio%" == "" (
    echo make a choice visual studio version vs2019 or vs2022...
    GOTO:EOF
)

echo Start HotReload.bat script...
echo Project name is %project%...

@REM premake5 실행
if "%visualstudio%" == "vs2019" (
    echo Your Visual Studio version is %visualstudio%...
) else if "%visualstudio%" == "vs2022" (
    echo Your Visual Studio version is %visualstudio%...
) else (
    echo Your Visual Studio version %visualstudio% is illegal...
    GOTO:EOF
)

echo Start premake5.exe...
%premake5% %visualstudio% %project%