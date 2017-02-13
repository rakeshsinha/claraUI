#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QTextEdit>
#include <QProcess>
#include <QTcpSocket>
#include <QThread>

#include "claraKeyMap.h"
#include "globalVariables.h"
#include "fileHandler.h"
#include "logHandler.h"


class ClaraTerminal : public QTextEdit
{
    //whenever declaring own signals or slots you must have this macro must appear
    Q_OBJECT
public:
    ClaraTerminal();
    enum class CurrMode{
        FILE_CREATE,
        WRITING,
        EXECUTE
    };
    ~ClaraTerminal();

    CurrMode currMode;
    void keyPressEvent(QKeyEvent *keyEvent);
    void handleCodeFile();
    void writeIntoCodeFile();
    void displayMessage(QString str);
    void displayClaraOutput(QByteArray);
    //void doNothing();
    //void connectClient();

public slots:
    void runCommand();
    void displayStdOutput();
    void displayStdErr();

private:
    QString cmdStr;
    QProcess *claraProcess;
    QString processName;
    quint16 lastCursorPosition;
    QTextCursor docTextCursor;
    QList<QString> historyList;
    QString fileName;
    QTcpSocket *clientSocket;
};

#endif // TEXTEDITOR_H
