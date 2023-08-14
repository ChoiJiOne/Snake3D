#include "Window.h"

HINSTANCE Window::hMainInstance_ = nullptr;
bool Window::bIsRegisterWindowClass_ = false;
std::wstring Window::windowClassName_;
ATOM Window::windowClassAtom_ = 0;

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