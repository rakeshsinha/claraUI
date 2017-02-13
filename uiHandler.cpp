#include "uiHandler.h"

#define PROJECT_EXPLORER "Project Explorer"
#define TERMINAL "Terminal"

UIHandler::UIHandler()
{
    claraTerminal = new ClaraTerminal();
    projectExplorer = new ProjectExplorer();
    qTextEditHighlighter = new QTextEditHighlighter();
    claraHelp = new ClaraHelp();
    dockExplorer = new QDockWidget(tr("Explorer"), this);
    dockHelp = new QDockWidget(tr("Clara Help"), this);
    mainVBoxLayout = new QVBoxLayout();
    centralWidget = new QWidget();
    codeEditorTabWidget = new QTabWidget();
    extraEditorTabWidget = new QWidget();
    terminalTabWidget = new QTabWidget();
}

void UIHandler::setupAllTheComponents()
{
    //codeEditorTabWidget->setTabPosition(QTabWidget::West);
    codeEditorTabWidget->setWindowTitle("Editor");
    codeEditorTabWidget->addTab(qTextEditHighlighter, "Untitled");
    codeEditorTabWidget->addTab(extraEditorTabWidget, "+");
    codeEditorTabWidget->setTabsClosable(true);
    terminalTabWidget->setTabPosition(QTabWidget::West);
    terminalTabWidget->addTab(claraTerminal, "                    Clara Terminal                    ");
    terminalTabWidget->setTabsClosable(true);

    mainVBoxLayout->addWidget(codeEditorTabWidget);
    mainVBoxLayout->addWidget(terminalTabWidget);

    centralWidget->setLayout(mainVBoxLayout);
    this->setCentralWidget(centralWidget);
    dockExplorer->setAllowedAreas(Qt::RightDockWidgetArea);
    dockExplorer->setWidget(projectExplorer);
    addDockWidget(Qt::RightDockWidgetArea, dockExplorer);
    dockHelp->setAllowedAreas(Qt::RightDockWidgetArea);
    dockHelp->setWidget(claraHelp);
    addDockWidget(Qt::RightDockWidgetArea, dockHelp);
}

void UIHandler::closeTab(int index)
{

}

void UIHandler::registerSignalsAndSlots()
{
    //connect(expTabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
}
