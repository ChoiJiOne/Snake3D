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
 * @brief ���� �����Դϴ�.
 * 
 * @note ���� ���� Ŭ������ ��� �޼��� �� ��� ������ ����(static)�Դϴ�.
 */
class GameEngine
{
public:
	/**
	 * @brief ���� ������ ����ϱ� ���� �ʱ�ȭ�� �����մϴ�.
	 */
	static void LaunchStartup();


	/**
	 * @brief ���� ���� ����� �����մϴ�.
	 */
	static void LaunchShutdown();


private:
	/**
	 * @brief ���� ������ �ʱ�ȭ�ߴ��� Ȯ���մϴ�.
	 */
	static bool bIsInitialized_;
};