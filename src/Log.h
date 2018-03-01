#ifndef _LOG_H
#define _LOG_H
#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<string>
#include<ctime>

enum LOG_LEVEL {
    INFO,
    WARNING,
    CRITICAL, 
    FATAL
};

struct LOG_ENTRY_LINE 
{
    std::time_t	timestamp;
    LOG_LEVEL	level;
    std::string	msg;
};

class Log 
{
    public:
    private:
	std::string			m_filename;
	LOG_ENTRY_LINE			m_entry;

    public:
	Log();
	std::string format();
	void info(std::string msg);
	void warning(std::string msg);
	void critical(std::string msg);
	void fatal(std::string msg);

};

#endif
