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

if not exist Crash (
    echo make Crash directory...
    mkdir Crash
)

if not exist Log (
    echo make Log directory...
    mkdir Log
)

echo Start GenerateProjectFiles.bat script...
echo Project name is %project%...

if "%visualstudio%" == "vs2019" (
    echo Your Visual Studio version is %visualstudio%...
) else if "%visualstudio%" == "vs2022" (
    echo Your Visual Studio version is %visualstudio%...
) else (
    echo Your Visual Studio version %visualstudio% is illegal...
    GOTO:EOF
)

@REM premake5 실행
echo Start premake5.exe...
%premake5% %visualstudio% %project%

echo start visual studio solution...
start %project%\\%project%.sln