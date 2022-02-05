#ifndef LOGGER_FILE_H
#define LOGGER_FILE_H

#include "logger.h"

class LoggerFile: public ILogger
{
public:
	void logString(char *string);
};

class LoggerFileFactory: public ILoggerFactory
{
public:
	static void registerFactory()
	{
		Logger::registerLoggerFactory(std::string("file"), new LoggerFileFactory());
	}

	ILogger* buildLogger();
};

#endif // LOGGER_FILE_H

