#include "fileHandler.h"


const QMap<QString, QString> FileHandler::proStringMap{
    {"bash", "#!/bin/bash\n"},
    {"clara", ""}
};


FileHandler::FileHandler(QString str)
    :QFile(str)
{}

FileHandler *FileHandler::fileHandler = 0;


void FileHandler::initialize(QString fileName)
{
    if(!fileHandler)
        fileHandler = new FileHandler(fileName);
}


FileHandler* FileHandler::instance()
{
    return fileHandler;
}


bool FileHandler::openFile()
{
    if(!fileHandler->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        globalVar::errorMessage = fileHandler->errorString();
        return false;
    }

    return true;
}
