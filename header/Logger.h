#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>
#include <QString>
#include <mutex>

class Logger : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString logs READ getLogs WRITE setLogs NOTIFY logsChanged)

public:
	static Logger& getInstance();
	static void info(const QString& log);
	static void error(const QString& log);

	QString getLogs() const { return logs_; }
	void setLogs(QString logs);

signals:
	void logsChanged();

private:
	Logger();

	QString logs_;
	std::mutex mtx_;
};

#endif // LOGGER_H