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
    /*
    *   Show message with compile error information
    *
    *   return: void
    */
    QMessageBox msgBox(QMessageBox::Warning,
                       "Ошибка компиляции",
                       "Убедитесь в правильности выбранных файлов flex и bison",
                       QFlag(0), this);
    msgBox.addButton("&Выбрать снова",
                     QMessageBox::AcceptRole);
    msgBox.exec();
}

bool MainWindow::compileFlexAndBison(const QString &flexSrc, const QString &bisonSrc) {
    /*
    *   Compile flex and byzon source files to tmp/translator.exe
    *
    *
    *   return: bool (success)
    */
    this->setEnabled(false);
    QApplication::setOverrideCursor(Qt::WaitCursor);

    QDir dir;
    dir.mkdir("tmp");
    dir.cd("tmp");

    bool bOk = runProcess("flex -o./tmp/lex.yy.c " + flexSrc);
    if(bOk == false) {
        this->setEnabled(true);
        QApplication::restoreOverrideCursor();
        qDebug() << "mainWindow(compileFlexAndBison): fail compile flex";
        return false;
    }

    bOk &= runProcess("bison -d --defines=./tmp/parser.tab.h --output=./tmp/parser.tab.c " + bisonSrc);
    if(bOk == false) {
        this->setEnabled(true);
        QApplication::restoreOverrideCursor();
        qDebug() << "mainWindow(compileFlexAndBison): fail compile bison";
        return false;
    }

    bOk &= runProcess("gcc -o ./tmp/translator.exe ./tmp/lex.yy.c ./tmp/parser.tab.c");
    if(bOk == false) {
        this->setEnabled(true);
        QApplication::restoreOverrideCursor();
        qDebug() << "mainWindow(compileFlexAndBison): fail compile translator.exe";
        return false;
    }

    translatorFile = "./tmp/translator.exe";

    dir.setNameFilters(QStringList() << "*.c" << "*.h");
    dir.setFilter(QDir::Files);
    foreach(QString dirFile, dir.entryList())
    {
        dir.remove(dirFile);
    }

    this->setEnabled(true);
    QApplication::restoreOverrideCursor();
    return bOk;
}

bool MainWindow::runProcess(QString command){
    /*
    *   Make process instance, run it and check success
    *
    *   return: bool (success)
    */

    QStringList args = command.split(" ");
    if(args.isEmpty()) {
       qDebug() << "mainWindow(runProcess): empty process string";
       return false;
    }

    QString processName = args.takeFirst();

    QProcess process;
    process.start(processName, args);
    bool bOk = process.waitForFinished();
    int exitCode = process.exitCode();

    qDebug() << "mainWindow(runProcess): errout for" << processName << "process:" << process.readAllStandardError();
    qDebug() << "mainWindow(runProcess): stdout for" << processName << "process:" << process.readAllStandardOutput();
    qDebug() << "mainWindow(runProcess): stdout for" << processName << "process:" << exitCode;

    bOk &= (exitCode == 0);
    return bOk;
}


/* SLOTS */

void MainWindow::startCodeEnv(const QString& flexSrc, const QString& bisonSrc) {
    /*
    *   Slot for change files choose widget to text enviroment
    *
    *   flexSrc and bisonSrc compile to ./tmp/translator.exe
    */

    //this->flexSrcFile = flexSrc;
    //this->bisonSrcFile = bisonSrc;
    qDebug() << "mainwindow:: get flex,bison files path: flex file:" << flexSrc << " bison file: " << bisonSrc;

    /* Compile flex and bison source files */
    if(compileFlexAndBison(flexSrc, bisonSrc) == false){
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
