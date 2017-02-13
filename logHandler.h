#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <QMap>

#include "globalVariables.h"

class LogHandler : public QWidget
{
private:

public:
    LogHandler();

    typedef void (LogHandler::*callBack)(QString);
    static const QMap<globalVar::logType, callBack> funcMap;
    void printMessage(globalVar::logType temp, QString str);
    void displayMsg(QString str);
    void writeInLog(QString str);
};

#endif // ERRORHANDLER_H
