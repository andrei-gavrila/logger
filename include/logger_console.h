#ifndef LOGGER_CONSOLE_H
#define LOGGER_CONSOLE_H

#include "logger.h"

class LoggerConsole: public ILogger
{
public:
	void logString(char *string);
};

class LoggerConsoleFactory: public ILoggerFactory
{
public:
	static void registerFactory()
	{
		Logger::registerLoggerFactory(std::string("console"), new LoggerConsoleFactory());
	}

	ILogger* buildLogger();
};

#endif // LOGGER_CONSOLE_H

