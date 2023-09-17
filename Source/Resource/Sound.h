#pragma once

#include <string>

#include "Resource/IResource.h"


/**
 * @brief ���� ������ ��µ� �����Դϴ�.
 */
class Sound : public IResource
{
public:
	/**
	 * @brief ���� ������ ��µ� ������ �⺻ �������Դϴ�.
	 *
	 * @note �ʱ�ȭ�� �����ϱ� ���ؼ��� �ݵ�� Initialzie �޼��带 ȣ���ؾ� �մϴ�.
	 */
	Sound() = default;


	/**
	 * @brief ���� ������ ��µ� ������ ���� �Ҹ����Դϴ�.
	 *
	 * @note ������ �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Sound();


	/**
	 * @brief ���� ������ ��µ� ���� Ŭ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Sound);


	/**
	 * @brief ���� ������ ��µ� ���带 �ʱ�ȭ�մϴ�.
	 */
	void Initialize(const std::string& path);


	/**
	 * @brief ���� ������ ��µ� ���� ���ҽ��� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ������ ũ�⸦ �����մϴ�.
	 *
	 * @param volume ������ ũ���Դϴ�. ������ 0.0 ~ 1.0 �Դϴ�.
	 */
	void SetVolume(float volume);


	/**
	 * @brief ���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @note ���� ũ���� ������ 0.0 ~ 1.0 �Դϴ�.
	 *
	 * @return ���� ������ ũ�⸦ ����ϴ�.
	 */
	float GetVolume();


	/**
	 * @brief ������ �ݺ� ���θ� �����մϴ�.
	 *
	 * @param bIsLoop ���� �ݺ� �����Դϴ�.
	 */
	void SetLooping(bool bIsLoop);


	/**
	 * @brief ������ �ݺ� ���θ� ����ϴ�.
	 *
	 * @return ���尡 �ݺ��Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsLooping();


	/**
	 * @brief ���带 �÷����մϴ�.
	 *
	 * @note ������ ������ ���� �ִٸ� ������ �������� �÷��̵˴ϴ�.
	 */
	void Play();


	/**
	 * @brief ���尡 �÷��������� Ȯ���մϴ�.
	 *
	 * @return ���尡 �÷��� ���̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsPlaying();


	/**
	 * @brief ���� �÷��̰� �������� Ȯ���մϴ�.
	 *
	 * @return ���� �÷��̰� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsDone();


	/**
	 * @brief ���� �÷��̸� �����մϴ�.
	 */
	void Stop();


	/**
	 * @brief ���� �÷��̰� ���� �Ǿ����� Ȯ���մϴ�.
	 *
	 * @return ���� �÷��̰� ���� �Ǿ��ٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsStopping();


	/**
	 * @brief ���带 �ʱ�ȭ�մϴ�.
	 */
	void Reset();


private:
	/**
	 * @brief ���� ���ҽ��� ���̵��Դϴ�.
	 *
	 * @note -1 ���� ��ȿ���� �ʴ� ������ �̴� ���� ���ҽ� ������ ������ ���Դϴ�.
	 */
	int32_t soundID_ = -1;
};