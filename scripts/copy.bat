
set dirToCopy=%~1
set targetDir=%~2

echo Copying

echo %dirToCopy%
echo %targetDir%

cd "%targetDir%"
mkdir "assets"
xcopy /y /s /e "%dirToCopy%" "%targetDir%/assets"

pause
REM cd "$(OutDir)"
REM mkdir "assets"
REM xcopy /s /e /y "$(SolutionDir)assets" "$(OutDir)assets"