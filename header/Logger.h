#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>

class Logger : public QObject
{
    Q_OBJECT
        Q_PROPERTY(int someProperty READ someProperty WRITE setSomeProperty NOTIFY somePropertyChanged)

public:
    explicit Logger(QObject* parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE int doSomething();

    int someProperty() const { return m_someProperty; }
    void setSomeProperty(int val);

signals:
    void somePropertyChanged(int newValue);

private:
    int m_someProperty = 0;
};


#endif //LOGGER_H