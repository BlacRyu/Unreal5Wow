set "UE5_PATH=E:/Unreal Engine 5"
set "PROJECT_NAME=Unreal5Wow"

"%UE5_PATH%/Engine/Build/Batchfiles/RunUAT.bat" BuildEditor "-project=%~dp0%PROJECT_NAME%.uproject" -notools -platform=Win64 -clientconfig=Development
