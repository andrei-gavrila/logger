#ifndef LOGGER_H
#define LOGGER_H

#include <map>

#define LOG(format, ...) Logger::getLogger()->log(__FUNCTION__, __FILE__, __LINE__, format, ## __VA_ARGS__);

class ILogger
{
public:
	virtual void logString(char *string) = 0;

	void log(const char *function, const char *file, const int line, const char *format, ...);

	void logToString(char *string, const char *function, const char *file, const int line, const char *format, va_list args);
};

class ILoggerFactory
{
public:
	virtual ILogger* buildLogger() = 0;
};

class Logger
{
private:
	typedef struct _loggerEntry_t
	{
		ILoggerFactory *factory;
		ILogger *logger;
	} loggerEntry_t;

	static std::map<std::string, loggerEntry_t *> entries;

	Logger() = delete;
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;	

public:
	static void registerLoggerFactory(std::string name, ILoggerFactory *loggerFactory);

	static ILogger* getLogger(std::string name = "");
};

#endif // LOGGER_H

