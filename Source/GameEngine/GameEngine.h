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
 * @brief ��ü���� ������ �ʱ�ȭ/�����ϴ� �����Դϴ�.
 * 
 * @note �� Ŭ������ ��� ��� ������ �޼���� ����(static)�Դϴ�.
 */
class GameEngine
{
public:
	/**
	 * @brief ���� ������ �������� �ʱ�ȭ ���� ȣ���մϴ�.
	 * 
	 * @param argc ����� ������ ���Դϴ�.
	 * @param argv ����� �����Դϴ�.
	 */
	static void PreInitialize(int32_t argc, char* argv[]);


	/**
	 * @brief ���� ������ �ʱ�ȭ�� �����մϴ�.
	 * 
	 * @param mainWindow ������ ���� �������Դϴ�.
	 */
	static void PostInitialize(Window* mainWindow);


	/**
	 * @brief ���� ������ �ʱ�ȭ�� �����մϴ�.
	 */
	static void Release();

	
	/**
	 * @brief ���� �������� �����͸� ����ϴ�.
	 * 
	 * @return ���� �������� �����͸� ��ȯ�մϴ�.
	 */
	static Window* GetMainWindowPtr() { return mainWindow_; }


private:
	/**
	 * @brief ���� �ʱ�ȭ�� ����Ǿ����� Ȯ���մϴ�.
	 */
	static bool bIsPreInitialized_;


	/**
	 * @brief ���� �ʱ�ȭ ������ �ʱ�ȭ�� ����Ǿ����� Ȯ���մϴ�.
	 */
	static bool bIsPostInitialized_;


	/**
	 * @brief ������ ���� �������Դϴ�.
	 */
	static Window* mainWindow_;
};