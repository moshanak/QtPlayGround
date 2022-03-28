#include "Logger.h"

Logger& Logger::getInstance() {
    static Logger instance_;
    return instance_;
}

void Logger::setLogs(QString logs)
{
    if (logs_ != logs) {
        logs_ = logs;
        emit logsChanged();
    }
}

Logger::Logger()
    :QObject(nullptr)
{
}
