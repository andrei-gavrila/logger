#include "logger_console.h"

#include <stdio.h>

void LoggerConsole::logString(char *string)
{
	printf(string);
}

ILogger* LoggerConsoleFactory::buildLogger()
{
	return new LoggerConsole();
}

