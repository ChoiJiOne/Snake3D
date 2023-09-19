#pragma once

#include <array>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <windows.h>
#include <vector>

#include "GameObject/Camera3D.h"
#include "GameObject/DirectionalLight.h"
#include "GameObject/Light.h"
#include "GameObject/PointLight.h"
#include "GameObject/SpotLight.h"

#include "Manager/AudioManager.h"
#include "Manager/LogManager.h"
#include "Manager/ObjectManager.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "Resource/CubeMap.h"
#include "Resource/Material.h"
#include "Resource/Mesh.h"
#include "Resource/Model.h"
#include "Resource/Shader.h"

#include "Utility/Assertion.h"
#include "Utility/CommandLine.h"
#include "Utility/FileSystem.h"
#include "Utility/GameTimer.h"
#include "Utility/GeometryGenerator.h"
#include "Utility/Logging.h"
#include "Utility/Macro.h"
#include "Utility/MinidumpWriter.h"
#include "Utility/String.h"
#include "Utility/Vertex.h"
#include "Utility/Window.h"


/**
 * @brief 전체적인 게임을 초기화/해제하는 엔진입니다.
 * 
 * @note 이 클래스의 모든 멤버 변수와 메서드는 정적(static)입니다.
 */
class GameEngine
{
public:
	/**
	 * @brief 게임 엔진의 본격적인 초기화 전에 호출합니다.
	 * 
	 * @param argc 명령행 인자의 수입니다.
	 * @param argv 명령행 인자입니다.
	 */
	static void PreInitialize(int32_t argc, char* argv[]);


	/**
	 * @brief 게임 엔진의 초기화를 수행합니다.
	 * 
	 * @param mainWindow 게임의 메인 윈도우입니다.
	 */
	static void PostInitialize(Window* mainWindow);


	/**
	 * @brief 게임 엔진의 초기화를 해제합니다.
	 */
	static void Release();

	
	/**
	 * @brief 메인 윈도우의 포인터를 얻습니다.
	 * 
	 * @return 메인 윈도우의 포인터를 반환합니다.
	 */
	static Window* GetMainWindowPtr() { return mainWindow_; }


private:
	/**
	 * @brief 사전 초기화가 수행되었는지 확인합니다.
	 */
	static bool bIsPreInitialized_;


	/**
	 * @brief 사전 초기화 이후의 초기화가 진행되었는지 확인합니다.
	 */
	static bool bIsPostInitialized_;


	/**
	 * @brief 게임의 메인 윈도우입니다.
	 */
	static Window* mainWindow_;
};