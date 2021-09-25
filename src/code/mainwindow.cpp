#include "../headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    startCongWgt = new StartConfWgt(this);
    this->setCentralWidget(startCongWgt);
    connect(startCongWgt, SIGNAL(startBtnClicked(const QString&, const QString&)), this, SLOT(startCodeEnv(const QString&, const QString&)));

    qDebug("mainwindow: Start app");
}

MainWindow::~MainWindow()
{

    qDebug("mainwindow: success destructor");
}


/* SLOTS */

void MainWindow::startCodeEnv(const QString& flexSrc, const QString& bznSrc) {
    /*
    *   Slot for change files choose widget to text enviroment
    */
    this->flexSrcFile = flexSrc;
    this->byzonSrcFile = bznSrc;
    qDebug() << "mainwindow:: get flex,byzon files path: flex file:" << flexSrc << " byzon file: " << bznSrc;

    codeEnvWgt = new CodeEnvWgt(this);
    this->resize(1280, 720);
    this->move(200, 150);
    this->setCentralWidget(codeEnvWgt);
    delete startCongWgt;

    qDebug("mainwindow: change widget from files choose to text env");
}
