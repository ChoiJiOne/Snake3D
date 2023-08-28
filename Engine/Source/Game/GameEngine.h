#pragma once

#include <windows.h>

#include "Manager/AudioManager.h"
#include "Manager/InputManager.h"
#include "Manager/ObjectManager.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "Resource/ColorMaterial.h"
#include "Resource/Mesh.h"
#include "Resource/Model.h"
#include "Resource/Sound.h"
#include "Resource/TTFont.h"

#include "Utils/Camera3D.h"
#include "Utils/CommandLine.h"
#include "Utils/FileHelper.h"
#include "Utils/GameTimer.h"
#include "Utils/GeometryGenerator.h"
#include "Utils/JsonHelper.h"
#include "Utils/MathHelper.h"
#include "Utils/MinidumpWriter.h"
#include "Utils/Vertex.h"
#include "Utils/Window.h"


/**
 * @brief 게임 엔진입니다.
 * 
 * @note 게임 엔진 클래스의 모든 메서드 및 멤버 변수는 정적(static)입니다.
 */
class GameEngine
{
public:
	/**
	 * @brief 게임 엔진을 사용하기 위한 초기화를 수행합니다.
	 */
	static void LaunchStartup();


	/**
	 * @brief 게임 엔진 사용을 종료합니다.
	 */
	static void LaunchShutdown();


private:
	/**
	 * @brief 게임 엔진을 초기화했는지 확인합니다.
	 */
	static bool bIsInitialized_;
};