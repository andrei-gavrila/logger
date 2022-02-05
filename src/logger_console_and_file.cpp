#include "logger_console_and_file.h"

void LoggerConsoleAndFile::logString(char *string)
{
	lc->logString(string);
	lf->logString(string);
}

ILogger* LoggerConsoleAndFileFactory::buildLogger()
{
	return new LoggerConsoleAndFile();
}

