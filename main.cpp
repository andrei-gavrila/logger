#include <iostream>

//#include "logger.h"
#include "logger_console.h"
#include "logger_file.h"
#include "logger_console_and_file.h"

/*
 * Used design patters:
 *  - Multiton (Singleton with map)
 *  - Factory
 *  - Template method
 *  - Wrapper
 */

int main(int argc, char **argv)
{
	LoggerConsoleFactory::registerFactory();
	LoggerFileFactory::registerFactory();
	LoggerConsoleAndFileFactory::registerFactory();

	Logger::getLogger()->log(__FUNCTION__, __FILE__, __LINE__, "Log test in a logger produced by the first registered logger factory");
	Logger::getLogger("console")->log(__FUNCTION__, __FILE__, __LINE__, "Log test in a logger produced by the console logger factory");
	Logger::getLogger("file")->log(__FUNCTION__, __FILE__, __LINE__, "Log test in a logger produced by the file logger factory");
//	Logger::getLogger("not-defined")->log(__FUNCTION__, __FILE__, __LINE__, "Will generate an exception");

	LOG("Test %s: %d", "message", 42);

	return 0;
}

