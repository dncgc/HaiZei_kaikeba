/*************************************************************************
	> File Name: 38.loger.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 21 Mar 2021 08:27:14 PM CST
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <map>
#include "thread_pool.h"
using std::endl;
using std::cout;
using std::string;

#define LOG(level) haizei::Logger::LoggerStream(level, __FILE__, __LINE__, haizei::haizei_log)
#define LOG_INFO    LOG(haizei::LogLevel::INFO)
#define LOG_WARNING LOG(haizei::LogLevel::WARNING)
#define LOG_DEBUG   LOG(haizei::LogLevel::DEBUG)
#define LOG_ERROR   LOG(haizei::LogLevel::ERROR)
#define LOG_FATAL   LOG(haizei::LogLevel::FATAL)
#define SET_LEVEL(level) haizei::haizei_log.set_level(level)

namespace haizei {

class LogLevel {
public:
    static const int INFO;
    static const int WARNING;
    static const int DEBUG;
    static const int ERROR;
    static const int FATAL;
};
const int LogLevel::INFO = 1;
const int LogLevel::WARNING = 2;
const int LogLevel::DEBUG = 3;
const int LogLevel::ERROR = 4;
const int LogLevel::FATAL = 5;
static std::map<int, string> LevelString = {
    {LogLevel::INFO, "INFO"},
    {LogLevel::WARNING, "WARNING"},
    {LogLevel::DEBUG, "DEBUG"},
    {LogLevel::ERROR, "ERROR"},
    {LogLevel::FATAL, "FATAL"},
};
class Logger {
public:
    Logger() : LOG_LEVEL(LogLevel::INFO) {}
    class LoggerStream : public std::ostringstream {
    public:
        LoggerStream(int level, const char *file_name, int line_no, Logger &raw_log) : line_no(line_no), level(level), raw_log(raw_log) {
            std::ostringstream &now = *this;
            now << "[" << file_name << " : " << LevelString[level] << "] ";
        }
        ~LoggerStream() {
            if (level < raw_log.LOG_LEVEL) return ;
            std::unique_lock<std::mutex> lock(raw_log.m_mutex);
            cout << this->str() << " (" << line_no << ")" << endl;;
        }
    private:
        int line_no, level;
        Logger &raw_log;
    };
    void set_level(int level) { this->LOG_LEVEL = level; }
    int LOG_LEVEL;
    std::mutex m_mutex;
};
Logger haizei_log;
Logger haizei_log1;

} // end of haizei

void func(int a, int b, int c) {
    LOG_INFO << a << " " << b << " " << c;
    return ;
}

int main() {
    // SET_LEVEL(haizei::LogLevel::DEBUG);
    LOG_INFO << "hello world " << 123 << " " << 12.45;
    LOG_WARNING << "hello world " << 123 << " " << 12.45;
    LOG_DEBUG << "hello world " << 123 << " " << 12.45;
    LOG_ERROR << "hello world " << 123 << " " << 12.45;
    LOG_FATAL << "hello world " << 123 << " " << 12.45;
    haizei::ThreadPool tp;
    for (int i = 0; i < 100; i++) {
        tp.addOneTask(func, i, 2 * i, 3 * i);
    }
    tp.stop();
    return 0;
}
