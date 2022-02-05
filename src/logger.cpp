#include "logger.h"

#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdexcept>

void ILogger::log(const char *function, const char *file, const int line, const char *format, ...)
{
	static char string[1024];

	va_list args;

	va_start(args, format);
	logToString(string, function, file, line, format, args);
	va_end(args);

	logString(string);
}

void ILogger::logToString(char *string, const char *function, const char *file, const int line, const char *format, va_list args)
{
	static char timestr[20];
	static time_t rawtime;
	static struct tm* timeinfo;
	static char message[1024];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", timeinfo);

	vsnprintf(message, 1024, format, args);

	snprintf(string, 1024, "%s [%s] [%s:%d] %s\n", timestr, function, file, line, message);
}

std::map<std::string, Logger::loggerEntry_t *> Logger::entries = std::map<std::string, Logger::loggerEntry_t *>();

void Logger::registerLoggerFactory(std::string name, ILoggerFactory *loggerFactory)
{
	if (entries.find(name) == entries.end())
	{
		entries[name] = new loggerEntry_t{loggerFactory, nullptr};
	}
	else
	{
		throw std::logic_error("logger factory already registered");
	}
}

ILogger* Logger::getLogger(std::string name)
{
	for (auto e: entries)
	{
		if (name == "" || name == std::get<0>(e))
		{
			if (!std::get<1>(e)->logger)
			{
				std::get<1>(e)->logger = std::get<1>(e)->factory->buildLogger();
			}

			return std::get<1>(e)->logger;
		}
	}

	throw std::logic_error("invalid logger requested (no factory registered for this name)");
}

