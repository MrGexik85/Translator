#include "../headers/startconfwgt.h"

StartConfWgt::StartConfWgt(QWidget *parent) : QWidget(parent)
{
    QPushButton *btn = new QPushButton("Start text", this);
    flexChoose = "privet";
    byzonChoose = "poka";
    connect(btn, SIGNAL(clicked()), this, SLOT(sendFilesSrc()));

    qDebug("startConfWgt: success constructor");
}

StartConfWgt::~StartConfWgt() {

    qDebug("startConfWgt: success destructor");
}

void StartConfWgt::sendFilesSrc() {
    /*
    *   Slot for change files choose widget to text enviroment
    */
    qDebug("startCongWgt: files was been sended");
    emit startBtnClicked(flexChoose, byzonChoose);
}
