#pragma once

#include "Manager/IManager.h"


/**
 * @brief ����� ó���� �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱��� Ŭ�����Դϴ�.
 */
class AudioManager : public IManager
{
public:
	/**
	 * @brief ����� ó���� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(AudioManager);


	/**
	 * @brief ����� ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�մϴ�.
	 */
	void Initialize();


	/**
	 * @brief ����� ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ���� ���ҽ��� �����մϴ�.
	 *
	 * @param path ���� ���ҽ��� ����Դϴ�.
	 *
	 * @return ������ ���� ���ҽ��� ���̵� ��ȯ�մϴ�. ������ �����ϸ� -1�� ��ȯ�մϴ�.
	 */
	int32_t CreateSound(const std::string& path);


	/**
	 * @brief ���� ���ҽ��� �ı��մϴ�.
	 *
	 * @param soundID �ı��� ������ ���̵��Դϴ�.
	 */
	void DestroySound(int32_t soundID);


	/**
	 * @brief ������ ũ�⸦ �����մϴ�.
	 *
	 * @param soundID ũ�⸦ ������ ������ ���̵��Դϴ�.
	 * @param volume ������ ũ���Դϴ�. ������ 0.0 ~ 1.0 �Դϴ�.
	 */
	void SetVolume(int32_t soundID, float volume);


	/**
	 * @brief ���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @param soundID �Ҹ� ũ�⸦ ���� ������ ���̵��Դϴ�.
	 *
	 * @return ���� ������ ũ�⸦ ����ϴ�.
	 */
	float GetVolume(int32_t soundID);


	/**
	 * @brief ������ �ݺ� ���θ� �����մϴ�.
	 *
	 * @param soundID �ݺ� ���θ� ������ ������ ���̵��Դϴ�.
	 * @param bIsLoop ���� �ݺ� �����Դϴ�.
	 */
	void SetLooping(int32_t soundID, bool bIsLoop);


	/**
	 * @brief ������ �ݺ� ���θ� ����ϴ�.
	 *
	 * @param soundID �ݺ� ���θ� Ȯ���� ������ ���̵��Դϴ�.
	 *
	 * @return ���尡 �ݺ��Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsLooping(int32_t soundID);


	/**
	 * @brief ���带 �÷����մϴ�.
	 *
	 * @note ������ ������ ���� �ִٸ� ������ �������� �÷��̵˴ϴ�.
	 *
	 * @param soundID �÷����� ������ ���̵��Դϴ�.
	 */
	void Play(int32_t soundID);


	/**
	 * @brief ���尡 �÷��������� Ȯ���մϴ�.
	 *
	 * @param soundID �÷��� ������ Ȯ���� ���� ���̵��Դϴ�.
	 *
	 * @return ���尡 �÷��� ���̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsPlaying(int32_t soundID);


	/**
	 * @brief ���� �÷��̰� �������� Ȯ���մϴ�.
	 *
	 * @param soundID �÷��̰� �������� Ȯ���� ���� ���̵��Դϴ�.
	 *
	 * @return ���� �÷��̰� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsDone(int32_t soundID);


	/**
	 * @brief ���� �÷��̸� �����մϴ�.
	 *
	 * @param soundID �÷��̸� ������ ���� ���̵��Դϴ�.
	 */
	void Stop(int32_t soundID);


	/**
	 * @brief ���� �÷��̰� ���� �Ǿ����� Ȯ���մϴ�.
	 *
	 * @param soundID �÷��̰� ���� �Ǿ����� Ȯ���� ���� ���̵��Դϴ�.
	 *
	 * @return ���� �÷��̰� ���� �Ǿ��ٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsStopping(int32_t soundID);


	/**
	 * @brief ���带 �ʱ�ȭ�մϴ�.
	 *
	 * @param soundID �ʱ�ȭ�� ������ ���̵��Դϴ�.
	 */
	void Reset(int32_t soundID);


private:
	/**
	 * @brief ����� ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(AudioManager);


private:
	/**
	 * @brief ������� ������ ���� ���ҽ��� ���Դϴ�.
	 */
	int32_t countSoundResource_ = 0;
};