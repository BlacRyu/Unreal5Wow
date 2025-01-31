set "UE5_PATH=E:/Unreal Engine 5"
set "PROJECT_NAME=Unreal5Wow"

"%UE5_PATH%/Engine/Build/Batchfiles/Build.bat" -projectfiles "-project=%~dp0%PROJECT_NAME%.uproject"
