#include "../headers/startconfwgt.h"

StartConfWgt::StartConfWgt(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    flexPath = new FileInputWgt("Flex файл (*.l)", "Flex files (*.l)", this);
    byzonPath = new FileInputWgt("Byzon файл (*.y)", "Byzon files (*.y)", this);

    QPushButton *sendBtn = new QPushButton("Начать", this);
    connect(sendBtn, SIGNAL(clicked()), this, SLOT(sendFilesSrc()));

    layout->addWidget(flexPath);
    layout->addWidget(byzonPath);
    layout->addWidget(sendBtn);
    this->setLayout(layout);

    qDebug("startConfWgt: success constructor");
}

StartConfWgt::~StartConfWgt() {

    qDebug("startConfWgt: success destructor");
}


/* SLOTS */

void StartConfWgt::sendFilesSrc() {
    /*
    *   Slot for change files choose widget to text enviroment
    */
    qDebug("startCongWgt: files was been sended");
    emit startBtnClicked(this->flexPath->getCurrentPath(), this->byzonPath->getCurrentPath());
}
