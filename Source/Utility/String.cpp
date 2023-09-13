#include "Utility/String.h"

char String::mbcsBuffer_[String::MAX_BUFFER_SIZE];
wchar_t String::wcsBuffer_[String::MAX_BUFFER_SIZE];

std::vector<std::string> String::Split(const std::string& text, const std::string& delimiter)
{
	std::vector<std::string> tokens;
	std::size_t position = 0ULL;
	std::string remain = text;

	while ((position = remain.find(delimiter)) != std::string::npos)
	{
		tokens.push_back(remain.substr(0, position));
		remain.erase(0, position + delimiter.length());
	}

	tokens.push_back(remain);
	return tokens;
}

std::vector<std::wstring> String::Split(const std::wstring& text, const std::wstring& delimiter)
{
	std::vector<std::wstring> tokens;
	std::size_t position = 0ULL;
	std::wstring remain = text;

	while ((position = remain.find(delimiter)) != std::string::npos)
	{
		tokens.push_back(remain.substr(0, position));
		remain.erase(0, position + delimiter.length());
	}

	tokens.push_back(remain);
	return tokens;
}

std::string String::Format(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	int32_t size = vsnprintf(mbcsBuffer_, MAX_BUFFER_SIZE, format, args);
	va_end(args);

	return std::string(mbcsBuffer_, size);
}

std::wstring String::Format(const wchar_t* format, ...)
{
	va_list args;
	va_start(args, format);
	int32_t size = _vsnwprintf_s(wcsBuffer_, MAX_BUFFER_SIZE, format, args);
	va_end(args);

	return std::wstring(wcsBuffer_, size);
}

std::wstring String::Convert(const std::string& text)
{
	std::size_t size = std::mbstowcs(wcsBuffer_, text.c_str(), MAX_BUFFER_SIZE);
	return std::wstring(wcsBuffer_, size);
}

std::string String::Convert(const std::wstring& text)
{
	std::size_t size = std::wcstombs(mbcsBuffer_, text.c_str(), MAX_BUFFER_SIZE);
	return std::string(mbcsBuffer_, size);
}