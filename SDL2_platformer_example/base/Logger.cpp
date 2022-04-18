
#include "Logger.hpp"

#include <iostream>

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

std::ostream& operator<< (std::ostream& out, signed char const& c)
{
	out << "#(" << (int)c << ")";
	return out;
}

std::ostream& operator<< (std::ostream& out, unsigned char const& c)
{
	out << "#(" << (int)c << ")";
	return out;
}

std::map<Logger::Level, std::string> Logger::_levelMap({
	{Level::Error,		BOLD(FRED("Error ----> "))},
	{Level::Info,		BOLD(FCYN("Info -----> "))},
	{Level::Warning,	BOLD(FYEL("Warning --> "))}
	});

void Logger::logIt(Logger::Level type, std::string const& message)
{
	std::cout << _levelMap[type] << message << std::endl;
}
