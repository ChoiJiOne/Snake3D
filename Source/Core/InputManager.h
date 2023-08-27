#pragma once

#include <vector>
#include <functional>
#include <unordered_map>

#include"Core/IManager.h"

#include "Utils/Macro.h"

#include "Vector/Vector.h"

class GameTimer;


/**
 * @brief �Է� ���¸� ��Ÿ���ϴ�.
 *
 * --------------------------------------
 * | ���� ������ | ���� ������ | �Է� ���� |
 * --------------------------------------
 * |     0      |     0      | NONE     |
 * |     0      |     1      | PRESSED  |
 * |     1      |     0      | RELEASED |
 * |     1      |     1      | HELD     |
 * --------------------------------------
 */
enum class EPressState : int32_t
{
	NONE = 0,
	PRESSED = 1,
	RELEASED = 2,
	HELD = 3
};


/**
 * @brief ���� Ű �ڵ� ���Դϴ�.
 *
 * @see https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
 */
enum class EVirtualKey : int32_t
{
	CODE_NONE = 0x00,
	CODE_LBUTTON = 0x01,
	CODE_RBUTTON = 0x02,
	CODE_CANCEL = 0x03,
	CODE_MBUTTON = 0x04,
	CODE_XBUTTON1 = 0x05,
	CODE_XBUTTON2 = 0x06,
	CODE_BACK = 0x08,
	CODE_TAB = 0x09,
	CODE_CLEAR = 0x0C,
	CODE_RETURN = 0x0D,
	CODE_SHIFT = 0x10,
	CODE_CONTROL = 0x11,
	CODE_MENU = 0x12,
	CODE_PAUSE = 0x13,
	CODE_CAPITAL = 0x14,
	CODE_KANA = 0x15,
	CODE_HANGUEL = 0x15,
	CODE_HANGUL = 0x15,
	CODE_IME_ON = 0x16,
	CODE_JUNJA = 0x17,
	CODE_FINAL = 0x18,
	CODE_HANJA = 0x19,
	CODE_KANJI = 0x19,
	CODE_IME_OFF = 0x1A,
	CODE_ESCAPE = 0x1B,
	CODE_CONVERT = 0x1C,
	CODE_NONCONVERT = 0x1D,
	CODE_ACCEPT = 0x1E,
	CODE_MODECHANGE = 0x1F,
	CODE_SPACE = 0x20,
	CODE_PRIOR = 0x21,
	CODE_NEXT = 0x22,
	CODE_END = 0x23,
	CODE_HOME = 0x24,
	CODE_LEFT = 0x25,
	CODE_UP = 0x26,
	CODE_RIGHT = 0x27,
	CODE_DOWN = 0x28,
	CODE_SELECT = 0x29,
	CODE_PRINT = 0x2A,
	CODE_EXECUTE = 0x2B,
	CODE_SNAPSHOT = 0x2C,
	CODE_INSERT = 0x2D,
	CODE_DELETE = 0x2E,
	CODE_HELP = 0x2F,
	CODE_0 = 0x30,
	CODE_1 = 0x31,
	CODE_2 = 0x32,
	CODE_3 = 0x33,
	CODE_4 = 0x34,
	CODE_5 = 0x35,
	CODE_6 = 0x36,
	CODE_7 = 0x37,
	CODE_8 = 0x38,
	CODE_9 = 0x39,
	CODE_A = 0x41,
	CODE_B = 0x42,
	CODE_C = 0x43,
	CODE_D = 0x44,
	CODE_E = 0x45,
	CODE_F = 0x46,
	CODE_G = 0x47,
	CODE_H = 0x48,
	CODE_I = 0x49,
	CODE_J = 0x4A,
	CODE_K = 0x4B,
	CODE_L = 0x4C,
	CODE_M = 0x4D,
	CODE_N = 0x4E,
	CODE_O = 0x4F,
	CODE_P = 0x50,
	CODE_Q = 0x51,
	CODE_R = 0x52,
	CODE_S = 0x53,
	CODE_T = 0x54,
	CODE_U = 0x55,
	CODE_V = 0x56,
	CODE_W = 0x57,
	CODE_X = 0x58,
	CODE_Y = 0x59,
	CODE_Z = 0x5A,
	CODE_LWIN = 0x5B,
	CODE_RWIN = 0x5C,
	CODE_APPS = 0x5D,
	CODE_SLEEP = 0x5F,
	CODE_NUMPAD0 = 0x60,
	CODE_NUMPAD1 = 0x61,
	CODE_NUMPAD2 = 0x62,
	CODE_NUMPAD3 = 0x63,
	CODE_NUMPAD4 = 0x64,
	CODE_NUMPAD5 = 0x65,
	CODE_NUMPAD6 = 0x66,
	CODE_NUMPAD7 = 0x67,
	CODE_NUMPAD8 = 0x68,
	CODE_NUMPAD9 = 0x69,
	CODE_MULTIPLY = 0x6A,
	CODE_ADD = 0x6B,
	CODE_SEPARATOR = 0x6C,
	CODE_SUBTRACT = 0x6D,
	CODE_DECIMAL = 0x6E,
	CODE_DIVIDE = 0x6F,
	CODE_F1 = 0x70,
	CODE_F2 = 0x71,
	CODE_F3 = 0x72,
	CODE_F4 = 0x73,
	CODE_F5 = 0x74,
	CODE_F6 = 0x75,
	CODE_F7 = 0x76,
	CODE_F8 = 0x77,
	CODE_F9 = 0x78,
	CODE_F10 = 0x79,
	CODE_F11 = 0x7A,
	CODE_F12 = 0x7B,
	CODE_F13 = 0x7C,
	CODE_F14 = 0x7D,
	CODE_F15 = 0x7E,
	CODE_F16 = 0x7F,
	CODE_F17 = 0x80,
	CODE_F18 = 0x81,
	CODE_F19 = 0x82,
	CODE_F20 = 0x83,
	CODE_F21 = 0x84,
	CODE_F22 = 0x85,
	CODE_F23 = 0x86,
	CODE_F24 = 0x87,
	CODE_NUMLOCK = 0x90,
	CODE_SCROLL = 0x91,
	CODE_LSHIFT = 0xA0,
	CODE_RSHIFT = 0xA1,
	CODE_LCONTROL = 0xA2,
	CODE_RCONTROL = 0xA3,
	CODE_LMENU = 0xA4,
	CODE_RMENU = 0xA5,
	CODE_BROWSER_BACK = 0xA6,
	CODE_BROWSER_FORWARD = 0xA7,
	CODE_BROWSER_REFRESH = 0xA8,
	CODE_BROWSER_STOP = 0xA9,
	CODE_BROWSER_SEARCH = 0xAA,
	CODE_BROWSER_FAVORITES = 0xAB,
	CODE_BROWSER_HOME = 0xAC,
	CODE_VOLUME_MUTE = 0xAD,
	CODE_VOLUME_DOWN = 0xAE,
	CODE_VOLUME_UP = 0xAF,
	CODE_MEDIA_NEXT_TRACK = 0xB0,
	CODE_MEDIA_PREV_TRACK = 0xB1,
	CODE_MEDIA_STOP = 0xB2,
	CODE_MEDIA_PLAY_PAUSE = 0xB3,
	CODE_LAUNCH_MAIL = 0xB4,
	CODE_LAUNCH_MEDIA_SELECT = 0xB5,
	CODE_LAUNCH_APP1 = 0xB6,
	CODE_LAUNCH_APP2 = 0xB7,
	CODE_OEM_1 = 0xBA,
	CODE_OEM_PLUS = 0xBB,
	CODE_OEM_COMMA = 0xBC,
	CODE_OEM_MINUS = 0xBD,
	CODE_OEM_PERIOD = 0xBE,
	CODE_OEM_2 = 0xBF,
	CODE_OEM_3 = 0xC0,
	CODE_OEM_4 = 0xDB,
	CODE_OEM_5 = 0xDC,
	CODE_OEM_6 = 0xDD,
	CODE_OEM_7 = 0xDE,
	CODE_OEM_8 = 0xDF,
	CODE_OEM_102 = 0xE2,
	CODE_PACKET = 0xE7,
	CODE_ATTN = 0xF6,
	CODE_CRSEL = 0xF7,
	CODE_EXSEL = 0xF8,
	CODE_EREOF = 0xF9,
	CODE_PLAY = 0xFA,
	CODE_ZOOM = 0xFB,
	CODE_NONAME = 0xFC,
	CODE_PA1 = 0xFD,
	CODE_OEM_CLEAR = 0xFE,
};


/**
 * @brief ������ �̺�Ʈ�Դϴ�.
 */
enum class EWindowEvent : int32_t
{
	NONE = 0x00,
	ACTIVE = 0x01,
	INACTIVE = 0x02,
	MOVE = 0x03,
	CLOSE = 0x04,
};


/**
 * @brief �Է� ó���� �����ϴ� �Ŵ����Դϴ�.
 */
class InputManager : public IManager
{
public:
	/**
	 * @brief �Է� ó���� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(InputManager);


	/**
	 * @brief �Է� ó���� �����ϴ� �޴����� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief �Է� ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief �Է� ���¸� ������Ʈ�մϴ�.
	 * 
	 * @note �� �޼���� �� ������ ȣ��Ǿ�� �մϴ�.
	 */
	void Tick();


	/**
	 * @brief ������ â�� �ݾƾ� �ϴ��� Ȯ���մϴ�.
	 * 
	 * @return ������ â�� �ݾƾ� �Ѵٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool ShouldCloseWindow() { return bShouldCloswWindow_; }


	/**
	 * @brief Ű�� �Է� ���¸� ��ȯ�մϴ�.
	 *
	 * @param virtualKey �˻縦 ������ ���� Ű�Դϴ�.
	 *
	 * @return Ű�� ��ư ���¸� ��ȯ�մϴ�.
	 */
	EPressState GetKeyPressState(const EVirtualKey& virtualKey) const;


	/**
	 * @brief Ű�� �Է� ���� �ð����� ����ϴ�.
	 * 
	 * @note �ð����� ������ �ʴ����Դϴ�.
	 * 
	 * @param virtualKey �ð����� ���� ���� Ű���Դϴ�.
	 * 
	 * @return Ű�� �Է� ���� �ð����� ��ȯ�մϴ�.
	 */
	float GetKeyPressTime(const EVirtualKey& virtualKey) const;


	/**
	 * @brief ���� ��ũ�� ���� ���콺 ��ġ�� ����ϴ�.
	 * 
	 * @return ���� ��ũ�� ���� ���콺 ��ġ�� ��ȯ�մϴ�.
	 */
	Vector2i GetScreenMousePosition() { return currScreenMousePosition_; }


	/**
	 * @brief ���� ������ ���� ���콺 ��ġ�� ����ϴ�.
	 * 
	 * @return ���� ������ ���� ���콺 ��ġ�� ��ȯ�մϴ�.
	 */
	Vector2i GetWindowMousePosition() { return currWindowMousePosition_; }


	/**
	 * @brief ���� ������ ��ũ�� ���� ���콺 ��ġ�� ���� ������ ���콺 ��ġ�� ���� ���� ����ϴ�.
	 * 
	 * @return ���� ������ ��ũ�� ���� ���콺 ��ġ�� ���� ������ ���콺 ��ġ�� ���� ���� ��ȯ�մϴ�.
	 */
	Vector2i GetDiffScreenMousePosition() { return currScreenMousePosition_ - prevScreenMousePosition_; }
	
	 
	/**
	 * @brief ���� ������ ������ ���� ���콺 ��ġ�� ���� ������ ���콺 ��ġ�� ���� ���� ����ϴ�.
	 * 
	 * @return ���� ������ ������ ���� ���콺 ��ġ�� ���� ������ ���콺 ��ġ�� ���� ���� ��ȯ�մϴ�.
	 */
	Vector2i GetDiffWindowMousePosition() { return currWindowMousePosition_ - prevWindowMousePosition_; }


	/**
	 * @brief ������ �̺�Ʈ�� ������ �׼��� ���ε��մϴ�.
	 *
	 * @param windowEvent ������ �׼ǿ� �����ϴ� ������ �̺�Ʈ�Դϴ�.
	 * @param eventAction ������ �̺�Ʈ ������ ��� ������ �׼��Դϴ�.
	 */
	void BindWindowEventAction(const EWindowEvent& windowEvent, const std::function<void()>& eventAction);


	/**
	 * @brief ������ �̺�Ʈ�� ������ �׼��� ���ε��� �����մϴ�.
	 *
	 * @param windowEvent ���ε� ������ ������ �̺�Ʈ�� �����ϴ� �׼��Դϴ�.
	 */
	void UnbindWindowEventAction(const EWindowEvent& windowEvent);
	

	/**
	 * @brief ������ �޽����� ó���մϴ�.
	 * 
	 * @note �� �Լ��� ������ â ���� �� ������ ���� �뵵�Դϴ�.
	 *
	 * @param windowHandle �����쿡 ���� �ڵ��Դϴ�.
	 * @param messageCode ������ �޽��� �ڵ��Դϴ�.
	 * @param wParam �޽����� ���õ� �߰� �������Դϴ�.
	 * @param lParam �޽����� ���õ� �߰� �������Դϴ�.
	 *
	 * @return ���α׷��� Windows�� ��ȯ�ϴ� �������Դϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/writing-the-window-procedure
	 */
	static LRESULT CALLBACK WindowMessageHandler(HWND windowHandle, uint32_t messageCode, WPARAM wParam, LPARAM lParam);


private:
	/**
	 * @brief �Է� ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(InputManager);


	/**
	 * @brief ������ �޽����� ó���մϴ�.
	 * 
	 * @note
	 * - wParam �� lParam ���� ��� ������ �ʺ��� ũ��(32��Ʈ �Ǵ� 64��Ʈ)�� ��Ÿ���� ���� ���Դϴ�.
	 * - â ���ν������� Ư�� �޽����� ó������ �ʴ� ��� �޽��� �Ű� ������ DefWindowProcW �Լ��� ���� �����մϴ�.
	 * 
	 * @param windowHandle �����쿡 ���� �ڵ��Դϴ�.
	 * @param messageCode ������ �޽��� �ڵ��Դϴ�.
	 * @param wParam �޽����� ���õ� �߰� �������Դϴ�.
	 * @param lParam �޽����� ���õ� �߰� �������Դϴ�.
	 *
	 * @return ���α׷��� Windows�� ��ȯ�ϴ� �������Դϴ�.
	 */
	LRESULT ProcessWindowMessage(HWND windowHandle, uint32_t messageCode, WPARAM wParam, LPARAM lParam);


	/**
	 * @brief Ư�� Ű�� ���ȴ��� �˻��մϴ�.
	 *
	 * @param keyboardState �˻縦 ������ Ű���� �����Դϴ�.
	 * @param virtualKey �˻縦 ������ ���� Ű ���Դϴ�.
	 *
	 * @return Ű�� ���ȴٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsPressKey(const std::vector<uint8_t>& keyboardState, const EVirtualKey& virtualKey) const;


	/**
	 * @brief ��ü ȭ���� �������� ���� ���콺�� ��ġ�� ����ϴ�.
	 *
	 * @return ����͸� �������� ���� ���콺�� (x, y) ��ġ�� ��ȯ�մϴ�.
	 * 
	 * @note ȭ�� ��ǥ��� ������ �����ϴ�.
	 * ��������������������������������������������������������
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 */
	Vector2i GetCurrentScreenMousePosition();


	/**
	 * @brief �����츦 �������� ���� ���콺�� ��ġ�� ����ϴ�.
	 *
	 * @see https://stackoverflow.com/questions/6423729/get-current-cursor-position
	 *
	 * @return �����츦 �������� ���� ���콺�� (x, y) ��ġ�� ��ȯ�մϴ�.
	 * 
	 * @note ȭ�� ��ǥ��� ������ �����ϴ�.
	 * ��������������������������������������������������������
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 * ��
	 */
	Vector2i GetCurrentWindowMousePosition();


private:
	/**
	 * @brief ������ â�� �ݾƾ� �ϴ��� Ȯ���մϴ�.
	 */
	bool bShouldCloswWindow_ = false;


	/**
	 * @brief �Է� ó�� ����� �Ǵ� �������� �ڵ��Դϴ�.
	 */
	HWND WindowHandle_ = nullptr;


	/**
	 * @brief �Է� ���� ���� �ð��� Ȯ���� �� ����� Ÿ�̸��Դϴ�.
	 */
	std::unique_ptr<GameTimer> pressCheckTimer_ = nullptr;


	/**
	 * @brief �Է� ó�� ���� ������Ʈ ����(Tick ȣ�� ����)�� Ű���� �����Դϴ�.
	 */
	std::vector<uint8_t> prevKeyboardState_;


	/**
	 * @brief �Է� ó�� ���� ������Ʈ ����(Tick ȣ�� ����)�� Ű���� �����Դϴ�.
	 */
	std::vector<uint8_t> currKeyboardState_;


	/**
	 * @brief Ű������ �Է� ������ ���� �ð� �Դϴ�.
	 */
	std::vector<float> keyPressElapsedTimes_;


	/**
	 * @brief ������Ʈ ����(Tick ȣ�� ����)�� ��ü ȭ�� ���� ���콺 ��ġ�Դϴ�.
	 */
	Vector2i prevScreenMousePosition_;


	/**
	 * @brief ������Ʈ ��(Tick ȣ�� ��)�� ��ü ȭ�� ���� ���콺 ��ġ�Դϴ�.
	 */
	Vector2i currScreenMousePosition_;


	/**
	 * @brief ������Ʈ ����(Tick ȣ�� ����)�� ������ ���� ���콺 ��ġ�Դϴ�.
	 */
	Vector2i prevWindowMousePosition_;


	/**
	 * @brief ������Ʈ ����(Tick ȣ�� ��)�� ������ ���� ���콺 ��ġ�Դϴ�.
	 */
	Vector2i currWindowMousePosition_;


	/**
	 * @brief ������ �̺�Ʈ�� �����ϴ� �׼��Դϴ�.
	 */
	std::unordered_map<EWindowEvent, std::function<void()>> windowEventActions_;


	/**
	 * @brief Ű���� ���� ������ ũ���Դϴ�.
	 */
	static const int32_t KEYBOARD_BUFFER_SIZE = 256;
};