#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include <QString>
#include <QRegularExpression>
#include <QtGlobal>
#include <QMessageBox>
#include <QtDebug>

namespace globalVar
{
    extern QString clara_home;
    extern QRegularExpression rx;
    extern QString errorMessage;
    enum logType{
        MSG,
        IN_LOG_FILE
    };
}



#endif // GLOBALVARIABLES_H
