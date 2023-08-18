#include <array>
#include <algorithm>
#include <regex>

#include "Core/CommandLine.h"
#include "Core/StringHelper.h"

std::wstring CommandLine::executePath_;
std::vector<std::wstring> CommandLine::options_;
std::unordered_map<std::wstring, std::wstring> CommandLine::keyValues_;
std::unordered_map<CommandLine::EArgumentType, std::wstring> CommandLine::argPatterns_ = {
	{ CommandLine::EArgumentType::OPTION,   L"^-[a-zA-Z]+$"  },
	{ CommandLine::EArgumentType::KEYVALUE, L"^[^=]+=[^=]+$" },
};

void CommandLine::Parse(const std::wstring& cmdLine)
{
	std::vector<std::wstring> args = StringHelper::Split(cmdLine, L" ");
	executePath_ = args[0];

	for (std::size_t index = 1; index < args.size(); ++index)
	{
		ParseArg(args[index]);
	}
}

bool CommandLine::IsValidOption(const std::wstring& option)
{
	return std::find(options_.begin(), options_.end(), option) != options_.end();
}

bool CommandLine::IsValidKey(const std::wstring& key)
{
	return keyValues_.find(key) != keyValues_.end();
}

std::wstring CommandLine::GetValue(const std::wstring& key)
{
	return (IsValidKey(key) ? keyValues_.at(key) : L"");
}

bool CommandLine::CheckArgPatternMatch(const std::wstring& arg, const std::wstring& pattern)
{
	return std::regex_match(arg, std::wregex(pattern));
}

CommandLine::EArgumentType CommandLine::GetArgType(const std::wstring& arg)
{
	EArgumentType argType = EArgumentType::NONE;

	for (const auto& argPattern : argPatterns_)
	{
		if (CheckArgPatternMatch(arg, argPattern.second))
		{
			argType = argPattern.first;
			break;
		}
	}

	return argType;
}

void CommandLine::ParseArg(const std::wstring& arg)
{
	EArgumentType argType = GetArgType(arg);

	switch (argType)
	{
	case EArgumentType::NONE:
		break;

	case EArgumentType::OPTION:
		options_.push_back(arg);
		break;

	case EArgumentType::KEYVALUE:
		std::vector<std::wstring> keyValue = StringHelper::Split(arg, L"=");
		keyValues_.insert({ keyValue.front(), keyValue.back() });
		break;
	}
}