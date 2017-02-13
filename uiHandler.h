#ifndef UIREGISTRY_H
#define UIREGISTRY_H

#include <QVBoxLayout>
#include <QMainWindow>
#include <QDockWidget>
#include <QGroupBox>

#include "projectExplorer.h"
#include "claraHelp.h"
#include "qtextedithighlighter.h"

//class UIHandler : public QWidget
class UIHandler : public QMainWindow
{
    Q_OBJECT
public:
    UIHandler();
    void setupAllTheComponents();
    void registerSignalsAndSlots();
public slots:
    void closeTab(int);
private:
    ClaraTerminal *claraTerminal;
    ProjectExplorer *projectExplorer;
    QTextEditHighlighter *qTextEditHighlighter;
    ClaraHelp *claraHelp;
    QDockWidget *dockExplorer;
    QDockWidget *dockHelp;
    QWidget *centralWidget;
    QVBoxLayout *mainVBoxLayout;
    QTabWidget *codeEditorTabWidget;
    QTabWidget *terminalTabWidget;
    QWidget *extraEditorTabWidget;
};

#endif // UIREGISTERY_H
