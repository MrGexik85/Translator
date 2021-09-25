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

void MainWindow::startCompilerErrorMsg() {
    QMessageBox msgBox(QMessageBox::Warning,
                       "Ошибка компиляции",
                       "Убедитесь в правильности выбранных файлов flex и byzon",
                       QFlag(0), this);
    msgBox.addButton("&Выбрать снова",
                     QMessageBox::AcceptRole);
    msgBox.exec();
}

bool MainWindow::compileFlexAndByzon() {
    /*
    *   Compile flex and byzon source files to tmp/translator.exe
    *
    *   return: bool (success)
    */

    return false;
}


/* SLOTS */

void MainWindow::startCodeEnv(const QString& flexSrc, const QString& bznSrc) {
    /*
    *   Slot for change files choose widget to text enviroment
    *
    *   flexSrc and bznSrc compile to tmp/translator.exe
    */

    this->flexSrcFile = flexSrc;
    this->byzonSrcFile = bznSrc;
    qDebug() << "mainwindow:: get flex,byzon files path: flex file:" << flexSrc << " byzon file: " << bznSrc;

    /* Compile flex and byzon source files */
    if(compileFlexAndByzon() == false){
        qDebug("mainWindow: Cannot compile source files");
        startCompilerErrorMsg();
        return;
    }

    codeEnvWgt = new CodeEnvWgt(this);
    this->resize(1280, 720);
    this->move(200, 150);
    this->setCentralWidget(codeEnvWgt);
    delete startCongWgt;

    qDebug("mainwindow: change widget from files choose to text env");
}
