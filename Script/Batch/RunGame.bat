@echo off

SET project=%1
SET mode=%2
SET exepath=%project%\\bin\\Win64\\%mode%\\Client.exe
SET crash=Crash\\
SET shader=GLSL\\
SET resource=Resource\\
SET log=Log\\

if "%project%" == "" (
    echo project name is empty...
    GOTO:EOF
)

if "%mode%" == "Debug" (
    echo run %mode% mode game...
) else if "%mode%" == "Release" (
    echo run %mode% mode game...
) else if "%mode%" == "Shipping" (
    echo run %mode% mode game...
) else (
    echo %mode% is illegal mode...
    GOTO:EOF
)

start %exepath% Crash=%crash% Shader=%shader% Resource=%resource% Log=%log% Vsync=off -SaveLogFile