#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger
{
public:
	static void logError(std::string const& text);
	static void logError(std::string const& text, std::string const& error);
	static void logInfo(std::string const& text);
	static void logWarning(std::string const& error);
};

#endif
