#include "../headers/startconfwgt.h"

StartConfWgt::StartConfWgt(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    QHBoxLayout *inputLayout_1 = new QHBoxLayout();
    QHBoxLayout *inputLayout_2 = new QHBoxLayout();

    flexPath = new QLineEdit("Flex файл (*.l)", this);
    byzonPath = new QLineEdit("Byzon файл (*.y)", this);

    QPushButton *inBtn_1 = new QPushButton("Выбрать файл...", this);
    QPushButton *inBtn_2 = new QPushButton("Выбрать файл...", this);
    QPushButton *sendBtn = new QPushButton("Начать", this);
    connect(sendBtn, SIGNAL(clicked()), this, SLOT(sendFilesSrc()));

    inputLayout_1->addWidget(flexPath);
    inputLayout_1->addWidget(inBtn_1);

    inputLayout_2->addWidget(byzonPath);
    inputLayout_2->addWidget(inBtn_2);

    layout->addLayout(inputLayout_1);
    layout->addLayout(inputLayout_2);
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
    emit startBtnClicked(this->flexPath->text(), this->byzonPath->text());
}
