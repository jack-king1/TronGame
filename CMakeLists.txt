cmake_minimum_required(VERSION 3.12)
project(TronGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(Libs)
include_directories(Libs/ASGE)
include_directories(Libs/ASGE/Include)
include_directories(Libs/ASGE/Include/Engine)
include_directories(Source)

add_executable(TronGame
        Libs/ASGE/Include/Engine/Colours.h
        Libs/ASGE/Include/Engine/Font.h
        Libs/ASGE/Include/Engine/Game.h
        Libs/ASGE/Include/Engine/Gamepad.h
        Libs/ASGE/Include/Engine/GameTime.h
        Libs/ASGE/Include/Engine/Input.h
        Libs/ASGE/Include/Engine/InputEvents.h
        Libs/ASGE/Include/Engine/KeyIndex.h
        Libs/ASGE/Include/Engine/Keys.h
        Libs/ASGE/Include/Engine/Mouse.h
        Libs/ASGE/Include/Engine/NonCopyable.h
        Libs/ASGE/Include/Engine/OGLGame.h
        Libs/ASGE/Include/Engine/Platform.h
        Libs/ASGE/Include/Engine/Renderer.h
        Libs/ASGE/Include/Engine/Sprite.h
        Libs/ASGE/Include/Engine/Texture.h
        Libs/ASGE/Include/Engine/Value.h
        Source/Actions.cpp
        Source/Actions.h
        Source/Game.cpp
        Source/Game.h
        Source/GameObject.cpp
        Source/GameObject.h
        Source/GameScene.cpp
        Source/GameScene.h
        Source/Line.cpp
        Source/Line.h
        Source/main.cpp
        Source/MenuScene.cpp
        Source/MenuScene.h
        Source/Rect.cpp
        Source/Rect.h
        Source/Scene.h
        Source/SpriteComponent.cpp
        Source/SpriteComponent.h
        Source/Vector2.cpp
        Source/Vector2.h)
