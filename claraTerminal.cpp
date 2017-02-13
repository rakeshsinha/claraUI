#include "claraTerminal.h"

#define MESSAGE(tempLogType, tempStr)((new LogHandler)->printMessage(tempLogType, tempStr))
#define MESSAGE_SELF(tempStr)(displayMessage(tempStr))
#define ERROR_PARAMETER_LENGTH "Before pressing Ctrl+Return, you need to provide "\
                               "two parameters separated by colon as <processname>:<filename> \n"\
                               "\te.g. clara:claraFile1.txt"

ClaraTerminal::ClaraTerminal()
{
    docTextCursor = this->textCursor();
    this->setTextCursor(docTextCursor);

    claraProcess = new QProcess(this);
    claraProcess->start("/home/rakesh/Spring_17/clara/clara_code/source/clara", QStringList("-g"), QIODevice::OpenModeFlag::ReadWrite);
    //claraProcess->start("bash", QStringList("-i"), QIODevice::OpenModeFlag::ReadWrite);
    //connect (claraProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(displayStdOutput()));
    //connect (claraProcess, SIGNAL(readyReadStandardError()), this, SLOT(displayStdErr()));

    this->insertPlainText("Clara Process Id - " + QString::number(claraProcess->processId()) + "\n");
    this->insertPlainText(globalVar::clara_home + ">");

    //Connecting Client to Clara
    QThread::sleep(5);
    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost("127.0.0.1", 8888);

    if(clientSocket->waitForConnected(3000))
    {
        qDebug() << "Connected!";
    }
    else
    {
        qDebug() << "Not connected!";
    }

    lastCursorPosition=this->textCursor().position();
}


void ClaraTerminal::keyPressEvent(QKeyEvent *keyEvent)
{
    if(this->textCursor().position() < lastCursorPosition)
    {
        this->setReadOnly(true);
        this->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
        if (Qt::Key_Return == keyEvent->key())
        {
            cmdStr = "\n";
            runCommand();
        }
        else
            QTextEdit::keyPressEvent(keyEvent);

        this->setReadOnly(false);
    }
    else if(this->textCursor().position() == lastCursorPosition &&
            (Qt::Key_Backspace == keyEvent->key() || Qt::Key_Left == keyEvent->key()
             || Qt::Key_Up == keyEvent->key()))
    {}
    else
    {
        switch (keyEvent->key())
        {
            case Qt::Key_Tab:
            {
                docTextCursor.movePosition( QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor,
                                            this->textCursor().position() - lastCursorPosition );
                cmdStr = docTextCursor.selectedText() + "\t";
                claraProcess->write(cmdStr.toUtf8());
                cmdStr = "";
                this->moveCursor(QTextCursor::End);
                break;
            }
            case Qt::Key_Return:
            {
                if(Qt::Key_Return == keyEvent->key() && keyEvent->modifiers() & Qt::ControlModifier)
                {
                    handleCodeFile();
                }
                else if(Qt::Key_Return == keyEvent->key() && CurrMode::WRITING == currMode)
                {
                    currMode = CurrMode::EXECUTE;
                    handleCodeFile();
                }
                else
                {
                    docTextCursor.movePosition( QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor,
                                                this->textCursor().position() - lastCursorPosition);
                    cmdStr = docTextCursor.selectedText() + "\n";
                    runCommand();
                }
                break;
            }
            default:
            {
                QTextEdit::keyPressEvent(keyEvent);
                break;
            }
        }
    }
}


/*void ClaraTerminal::runCommand()
{
    claraProcess->write(cmdStr.toUtf8());
    cmdStr = "";
    this->moveCursor(QTextCursor::End);
}*/

void ClaraTerminal::runCommand()
{
    // send to the server
    clientSocket->write(cmdStr.toUtf8());
    clientSocket->waitForBytesWritten(1000);
    clientSocket->waitForReadyRead(3000);
    qDebug() << "Reading: " << clientSocket->bytesAvailable();
    QByteArray claraOutput = clientSocket->readAll();
    displayClaraOutput(claraOutput);
}


void ClaraTerminal::handleCodeFile()
{
    switch (currMode)
    {
        case CurrMode::FILE_CREATE:
        {       //explicitly putting bracket to safegaurd the scope of stringList
            currMode = CurrMode::WRITING;
            docTextCursor.movePosition( QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor,
                                        this->textCursor().position() - lastCursorPosition );
            cmdStr = docTextCursor.selectedText();

            QStringList stringList = cmdStr.split(globalVar::rx);
            if (2 != stringList.length())
                MESSAGE_SELF(ERROR_PARAMETER_LENGTH);
            else
            {
                processName = QString(stringList.at(0)).trimmed();
                fileName = globalVar::clara_home + "/" + QString(stringList.at(1)).trimmed();
                FileHandler::initialize(fileName);

                if (FileHandler::openFile())
                {
                    this->moveCursor(QTextCursor::EndOfLine);
                    docTextCursor.insertText(QString("Writing in the file %1 for the %2 process\n").arg(fileName).arg(processName));
                    lastCursorPosition=this->textCursor().position();
                    docTextCursor.setPosition(lastCursorPosition);
                    docTextCursor.insertText(FileHandler::proStringMap.value(processName));
                    this->moveCursor(QTextCursor::EndOfLine);   //to move the verticle bar
                    writeIntoCodeFile();
                }
                else
                {
                    MESSAGE_SELF(globalVar::errorMessage);
                    globalVar::errorMessage = "";
                }
            }
            break;
        }

        case CurrMode::WRITING:
        {
            writeIntoCodeFile();
            break;
        }
        case CurrMode::EXECUTE:
        {
            //We need to write the last line too after the enter is pressed
            writeIntoCodeFile();
            FileHandler::instance()->close();
            if(processName == "bash")
            {
                cmdStr = "sh " + fileName + "\n";
                runCommand();
            }
            else if (processName == "clara")
            {
             cmdStr = "./" + fileName + "\n";
            }
            else
                MESSAGE_SELF("Are you kidding me, we only support clara and bash");
            currMode = CurrMode::FILE_CREATE;
            break;
        }
        default:
        {
            break;
        }
    }
}


void ClaraTerminal::writeIntoCodeFile()
{
    docTextCursor.movePosition( QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor,
                                this->textCursor().position() - lastCursorPosition );
    cmdStr = docTextCursor.selectedText();
    FileHandler::instance()->write(cmdStr.toUtf8() + "\n");
    FileHandler::instance()->flush();
    docTextCursor.clearSelection();
    this->moveCursor(QTextCursor::EndOfLine);
    docTextCursor.setPosition(this->textCursor().position());
    docTextCursor.insertText("\n");
    lastCursorPosition = this->textCursor().position();
}


void ClaraTerminal::displayStdOutput()
{
    qDebug() << "Standard Output";
    QByteArray strdata = claraProcess->readAllStandardOutput();
    //QMessageBox::information(this, "Output", strdata);
    docTextCursor.insertText(strdata);
    lastCursorPosition = this->textCursor().position();
    docTextCursor.setPosition(lastCursorPosition);
    //currMode = CurrMode::FILE_CREATE;
}


void ClaraTerminal::displayMessage(QString str)
{
    this->append("\n"+str);
    cmdStr = "\n";
    runCommand();
}


void ClaraTerminal::displayStdErr()
{
    qDebug() << "Error Output";
    QStringList lines = QString(claraProcess->readAllStandardError()).split("\n");
    foreach (QString line, lines)
        this->append(line);
    this->moveCursor(QTextCursor::End);
    lastCursorPosition = this->textCursor().position();
    docTextCursor.setPosition(lastCursorPosition);
    currMode = CurrMode::FILE_CREATE;
}


//void ClaraTerminal::doNothing(){}


void ClaraTerminal::displayClaraOutput(QByteArray claraOutput)
{
    qDebug() << "Clara Output";
    this->moveCursor(QTextCursor::End);
    lastCursorPosition = this->textCursor().position();
    docTextCursor.setPosition(lastCursorPosition);
    docTextCursor.insertText("\n");
    //QMessageBox::information(this, "Output", strdata);
    docTextCursor.insertText(claraOutput);
    docTextCursor.insertText("\n");
    this->insertPlainText(globalVar::clara_home + ">");
    this->moveCursor(QTextCursor::End);
    lastCursorPosition = this->textCursor().position();
    docTextCursor.setPosition(lastCursorPosition);
}


ClaraTerminal::~ClaraTerminal()
{
    qDebug() << "\n";
    clientSocket->close();
    qDebug() << "Connection closed with the Server";
}
