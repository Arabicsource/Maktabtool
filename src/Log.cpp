#include<sstream>
#include<iostream>
#include<string>
#include "Log.h"



// Log constructor
Log::Log()
    : m_filename(""), m_entry({0, LOG_LEVEL::INFO, ""}) 

{}; 


// format returns a string formatted log entry
std::string Log::format()
{
    std::string log_str;
    return log_str;
};

// info sets log message with log level info
void Log::info(std::string msg)
{

    this->m_entry = {std::time(nullptr), LOG_LEVEL::INFO, msg};
};

// warning sets log message with log level warning
void Log::warning(std::string msg)
{

    this->m_entry = {std::time(nullptr), LOG_LEVEL::WARNING, msg};
};

// critical sets log message with log level critical
void Log::critical(std::string msg)
{

    this->m_entry = {std::time(nullptr), LOG_LEVEL::CRITICAL, msg};
};

// fatal sets log message with log level fatal
void Log::fatal(std::string msg)
{

    this->m_entry = {std::time(nullptr), LOG_LEVEL::FATAL, msg};
};

