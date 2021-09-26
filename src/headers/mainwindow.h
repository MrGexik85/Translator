#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../headers/codeenvwgt.h"
#include "../headers/startconfwgt.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    StartConfWgt *startCongWgt = nullptr;
    CodeEnvWgt *codeEnvWgt = nullptr;

    QString translatorFile = "";

bool runProcess(QString command);
bool compileFlexAndBison(const QString &flexSrc, const QString &bisonSrc);
void startCompilerErrorMsg();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    friend class CodeEnvWgt;
private slots:
    void startCodeEnv(const QString& flexPath, const QString& bisonPath);
};
#endif // MAINWINDOW_H
