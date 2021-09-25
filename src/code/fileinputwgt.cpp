#include "../headers/fileinputwgt.h"

FileInputWgt::FileInputWgt(QString lineTitle, QString filesFilter, QWidget *parent) :
    QWidget(parent), filesFilter(filesFilter)
{
    layout = new QHBoxLayout();

    pathToFile = new QLineEdit(lineTitle, this);
    pathToFile->setEnabled(false);

    chooseFileBtn = new QPushButton("Выбрать файл...", this);
    connect(chooseFileBtn, SIGNAL(clicked()), this, SLOT(onChooseFileBtnClicked()));

    layout->addWidget(pathToFile);
    layout->addWidget(chooseFileBtn);

    this->setLayout(layout);
    qDebug("fileInputWgt: Success constructor");
}

FileInputWgt::~FileInputWgt() {

    qDebug("fileInputWgt: Success destructor");
}

QString FileInputWgt::getCurrentPath() {
    /*
    *   Get current path from QLineEdit widget
    *
    *   return: QString
    */
    if(pathToFile != nullptr) {
        qDebug("fileInputWgt: Success getCurrentPath()");
        return pathToFile->text();
    } else {
        qDebug("fileInputWgt: Fail getCurrentPath()");
        return QString("");
    }
}


/* SLOTS */
void FileInputWgt::onChooseFileBtnClicked(){
    /*
    *
    */
    qDebug("fileInputWgt: Choose file btn clicked");
    QString file = QFileDialog::getOpenFileName(this, "Choose file", "./", filesFilter);
    this->pathToFile->setText(file);
}
