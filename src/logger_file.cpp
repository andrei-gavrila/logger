#include "logger_file.h"

#include <stdio.h>

void LoggerFile::logString(char *string)
{
	FILE *f = fopen("messages.log", "a");

	fprintf(f, string);

	fclose(f);
}

ILogger* LoggerFileFactory::buildLogger()
{
	return new LoggerFile();
}

