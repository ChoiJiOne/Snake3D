#pragma once

#include <cstdint>

#include "Manager/IManager.h"

class Window;


/**
 * @brief ������ ó���� �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱��� Ŭ�����Դϴ�.
 */
class RenderManager : public IManager
{
public:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(RenderManager);


	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�մϴ�.
	 * 
	 * @param renderTargetWindow ������ ����� �Ǵ� �������Դϴ�.
	 * @param bEnableVsync ���� ����ȭ Ȱ��ȭ �����Դϴ�.
	 */
	void Initialize(Window* renderTargetWindow, bool bEnableVsync = false);


	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


private:
	/**
	 * @brief ������ ����� �Ǵ� �������Դϴ�.
	 */
	Window* renderTargetWindow_ = nullptr;


	/**
	 * @brief ���� ����ȭ Ȱ��ȭ �����Դϴ�.
	 */
	bool bEnableVsync_ = true;


	/**
	 * @brief OpenGL�� �� �����Դϴ�.
	 */
	const int32_t majorVersion_ = 4;


	/**
	 * @brief OpenGL�� �� �����Դϴ�.
	 */
	const int32_t minorVersion_ = 5;
};