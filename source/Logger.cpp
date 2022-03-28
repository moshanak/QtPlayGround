#include "Logger.h"

int Logger::doSomething()
{
    setSomeProperty(5);
    return m_someProperty;
}

void Logger::setSomeProperty(int val) {
    if (m_someProperty != val) {
        m_someProperty = val;
        emit somePropertyChanged(val);
    }
}
