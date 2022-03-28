#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>
#include <QString>

class Logger : public QObject
{
    Q_OBJECT
        
    Q_PROPERTY(QString logs READ getLogs WRITE setLogs NOTIFY logsChanged)

public:
    static Logger& getInstance();

    QString getLogs() const { return logs_; }
    void setLogs(QString logs);

signals:
    void logsChanged();

private:
    Logger();

    QString logs_;
};


#endif //LOGGER_H