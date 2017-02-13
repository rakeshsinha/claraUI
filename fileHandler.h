#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QFile>
#include <QMap>

#include "globalVariables.h"

class FileHandler : public QFile
{
    static FileHandler *fileHandler;
    FileHandler(QString str);
public:
    static void initialize(QString fileName);
    static FileHandler *instance();
    static const QMap<QString, QString> proStringMap;
    static bool openFile();
};

#endif // FILEHANDLER_H
