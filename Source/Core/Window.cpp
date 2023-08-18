#include "Window.h"

HINSTANCE Window::hMainInstance_ = nullptr;
bool Window::bIsRegisterWindowClass_ = false;
std::wstring Window::windowClassName_;
ATOM Window::windowClassAtom_ = 0;

Window::~Window()
{
}

void Window::Create(const std::wstring& title, const int32_t& screenX, const int32_t& screenY, const int32_t& clientWidth, const int32_t& clientHeight)
{
	ASSERT(bIsRegisterWindowClass_, "window class has not been registered...");

	int32_t windowWidth;
	int32_t windowHeight;
	DWORD windowStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE;

	GetWindowSizeFromClient(clientWidth, clientHeight, windowStyle, windowWidth, windowHeight);

	windowHandle_ = CreateWindowExW(
		WS_EX_OVERLAPPEDWINDOW,
		windowClassName_.c_str(),
		title.c_str(),
		windowStyle,
		screenX, screenY,
		windowWidth, windowHeight,
		nullptr,
		nullptr,
		hMainInstance_,
		nullptr
	);

	ASSERT(windowHandle_ != nullptr, "failed to create window...");

	ASSERT(SetForegroundWindow(windowHandle_), "failed to set forground window...");
}

void Window::GetClientSize(uint32_t& outClientWidth, uint32_t& outClientHeight)
{
	RECT clientRect = {};
	ASSERT(GetClientRect(windowHandle_, &clientRect), "failed to get client rect...");

	outClientWidth = clientRect.right - clientRect.left;
	outClientHeight = clientRect.bottom - clientRect.top;
}

void Window::RegisterWindowClass(WNDPROC wndProc, const std::wstring& windowClassName)
{
	if (bIsRegisterWindowClass_)
	{
		return;
	}

	hMainInstance_ = GetModuleHandle(nullptr);

	WNDCLASSEXW wcex = {};
	wcex.cbSize = sizeof(WNDCLASSEXW);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = wndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hMainInstance_;
	wcex.hIcon = LoadIcon(hMainInstance_, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(hMainInstance_, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(hMainInstance_, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = windowClassName.c_str();

	windowClassAtom_ = ::RegisterClassExW(&wcex);
	windowClassName_ = windowClassName;

	ASSERT(windowClassAtom_ != 0, "failed to register window class...");
	bIsRegisterWindowClass_ = true;
}

void Window::UnregisterWindowClass()
{
	if (bIsRegisterWindowClass_)
	{
		ASSERT(UnregisterClassW(windowClassName_.c_str(), hMainInstance_), "failed to unregister window class...");
		bIsRegisterWindowClass_ = false;
	}
}

void Window::GetWindowSizeFromClient(const int32_t& clientWidth, const int32_t& clientHeight, const DWORD& windowStyle, int32_t& outWindowWidth, int32_t& outWindowHeight)
{
	RECT windowRect = { 0, 0, static_cast<LONG>(clientWidth), static_cast<LONG>(clientHeight) };
	ASSERT(AdjustWindowRectEx(&windowRect, windowStyle, FALSE, WS_EX_OVERLAPPEDWINDOW), "failed to get window size...");

	outWindowWidth = static_cast<int32_t>(windowRect.right - windowRect.left);
	outWindowHeight = static_cast<int32_t>(windowRect.bottom - windowRect.top);
}