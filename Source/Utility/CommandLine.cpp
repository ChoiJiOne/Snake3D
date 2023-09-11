#include "Utility/CommandLine.h"
#include "Utility/String.h"

#include <array>
#include <algorithm>
#include <regex>

std::string CommandLine::executePath_;
std::vector<std::string> CommandLine::options_;
std::unordered_map<std::string, std::string> CommandLine::keyValues_;
std::unordered_map<CommandLine::EArgumentType, std::string> CommandLine::argPatterns_ =
{
	{ CommandLine::EArgumentType::OPTION,   "^-[a-zA-Z]+$"  },
	{ CommandLine::EArgumentType::KEYVALUE, "^[^=]+=[^=]+$" },
};

void CommandLine::Parse(int32_t argc, char* argv[])
{
	executePath_ = argv[0];

	for (std::size_t index = 1; index < argc; ++index)
	{
		ParseArg(argv[index]);
	}
}

bool CommandLine::IsValidOption(const std::string& option)
{
	return std::find(options_.begin(), options_.end(), option) != options_.end();
}

bool CommandLine::IsValidKey(const std::string& key)
{
	return keyValues_.find(key) != keyValues_.end();
}

std::string CommandLine::GetValue(const std::string& key)
{
	return (IsValidKey(key) ? keyValues_.at(key) : "");
}

bool CommandLine::CheckArgPatternMatch(const std::string& arg, const std::string& pattern)
{
	return std::regex_match(arg, std::regex(pattern));
}

CommandLine::EArgumentType CommandLine::GetArgType(const std::string& arg)
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

void CommandLine::ParseArg(const std::string& arg)
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
		std::vector<std::string> keyValue = String::Split(arg, "=");
		keyValues_.insert({ keyValue.front(), keyValue.back() });
		break;
	}
}