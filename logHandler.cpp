#include "logHandler.h"

LogHandler::LogHandler()
{}

const QMap<globalVar::logType, LogHandler::callBack> LogHandler::funcMap{
    {globalVar::MSG, &LogHandler::displayMsg},
    {globalVar::IN_LOG_FILE, &LogHandler::writeInLog}
};

void LogHandler::printMessage(globalVar::logType temp, QString str)
{
    callBack c = funcMap.value(temp);
    (this->*c)(str);
}

void LogHandler::displayMsg(QString str){ str = ""; }

void LogHandler::writeInLog(QString str){ str = ""; }
