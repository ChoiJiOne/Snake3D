@echo off
setlocal enabledelayedexpansion

SET project=%1
SET mode=%2
SET vswherepath=Engine\\Bin\\vswhere.exe
SET solutionpath=%project%\\%project%.sln

if "%project%" == "" (
    echo project name is empty...
    GOTO:EOF
)

if "%mode%" == "Debug" (
    echo Build %mode% mode game...
) else if "%mode%" == "Release" (
    echo Build %mode% mode game...
) else if "%mode%" == "Shipping" (
    echo Build %mode% mode game...
) else (
    echo %mode% is illegal mode...
    GOTO:EOF
)

for /f "usebackq tokens=*" %%i in (`%vswherepath% -latest -requires Microsoft.Component.MSBuild -find MSBuild\**\Bin\MSBuild.exe`) do (
    set path="%%i"
)

%path% %solutionpath% -property:Configuration=%mode% -target:Rebuild