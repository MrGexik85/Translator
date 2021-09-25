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
                       "Убедитесь в правильности выбранных файлов flex и bison",
                       QFlag(0), this);
    msgBox.addButton("&Выбрать снова",
                     QMessageBox::AcceptRole);
    msgBox.exec();
}

bool MainWindow::compileFlexAndBison() {
    /*
    *   Compile flex and byzon source files to tmp/translator.exe
    *
    *   return: bool (success)
    */

    //mkdir tmp
    //flex -o./tmp/flexout.yy.c *flexpath*

    return false;
}


/* SLOTS */

void MainWindow::startCodeEnv(const QString& flexSrc, const QString& bisonSrc) {
    /*
    *   Slot for change files choose widget to text enviroment
    *
    *   flexSrc and bisonSrc compile to ./tmp/translator.exe
    */

    this->flexSrcFile = flexSrc;
    this->bisonSrcFile = bisonSrc;
    qDebug() << "mainwindow:: get flex,bison files path: flex file:" << flexSrc << " bison file: " << bisonSrc;

    /* Compile flex and bison source files */
    if(compileFlexAndBison() == false){
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
