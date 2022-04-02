#include "Logger.h"

Logger& Logger::getInstance() {
    static Logger instance_;
    return instance_;
}

void Logger::info(const QString& log)
{
    Logger& logger = getInstance();
    const QString addLog = logger.logs_ + "[INFO] " + log + "\n";
    logger.setLogs(addLog);
}

void Logger::error(const QString& log)
{
    Logger& logger = getInstance();
    const QString addLog = logger.logs_ + "[ERROR] " + log + "\n";
    logger.setLogs(addLog);
}

void Logger::setLogs(QString logs)
{
    std::lock_guard<std::mutex> lock(mtx_);
    if (logs_ != logs) {
        logs_ = logs;
        emit logsChanged();
    }
}

Logger::Logger()
    :QObject(nullptr)
{
}
