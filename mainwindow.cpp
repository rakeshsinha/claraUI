#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uiHandler = new UIHandler();
    //uiHandler->setStyleSheet(
    //    "QWidget { background: lightgray; }"
    //            );
    uiHandler->setupAllTheComponents();
    uiHandler->registerSignalsAndSlots();
    ui->statusBar->showMessage("Clara Programming by Dr. Todd Ebert");
    setCentralWidget(uiHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}
