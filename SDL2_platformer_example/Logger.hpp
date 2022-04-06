
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <map>
#include <sstream>

class Logger
{
public:
	enum class Level
	{
		Error,
		Info,
		Warning
	};

	static void logIt(Logger::Level type, std::string const& message);

private:
	static std::map<Logger::Level, std::string> _levelMap;
};

std::ostream& operator<< (std::ostream& out, signed char const& c);
std::ostream& operator<< (std::ostream& out, unsigned char const& c);

#define EZ_LOG(level, ...) \
{ \
    std::stringstream ss; \
    ss << __VA_ARGS__; \
    ::Logger::logIt(level, ss.str()); \
}

#endif
