#ifndef LOGGER_CONSOLE_AND_FILE_H
#define LOGGER_CONSOLE_AND_FILE_H

#include "logger.h"

#include "logger_console.h"
#include "logger_file.h"

class LoggerConsoleAndFile: public ILogger
{
private:
	ILogger *lc = new LoggerConsole();
	ILogger *lf = new LoggerFile();

public:
	void logString(char *string);
};

class LoggerConsoleAndFileFactory: public ILoggerFactory
{
public:
	static void registerFactory()
	{
		Logger::registerLoggerFactory(std::string("console-and-file"), new LoggerConsoleAndFileFactory());
	}

	ILogger* buildLogger();
};

#endif // LOGGER_CONSOLE_AND_FILE_H

