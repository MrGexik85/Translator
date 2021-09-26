#include "../headers/codeenvwgt.h"

CodeEnvWgt::CodeEnvWgt(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout();

    pTranslateBtn = new QPushButton("-->", this);
    connect(pTranslateBtn, SIGNAL(clicked()), this, SLOT(translate()));

    layout->addLayout(getSrcTextLayout());
    layout->addWidget(pTranslateBtn);
    layout->addLayout(getResTextLayout());

    this->setLayout(layout);

    qDebug("CodeEnvWgt(constructor): Success");
}

CodeEnvWgt::~CodeEnvWgt() {


    qDebug("CodeEnvWgt(destructor): Success");
}

QLayout* CodeEnvWgt::getSrcTextLayout() {
    /*
     *
     *
    */

    pOpenSourceBtn = new QPushButton("Открыть", this);
    pSaveSourceBtn = new QPushButton("Сохранить", this);
    pTxtEditSource = new QTextEdit("Исходный текст", this);
    pTxtEditSource->setFont(QFont("Lucida Console", 12));
    pTxtEditSource->setTabStopDistance(
        QFontMetricsF(pTxtEditSource->font()).horizontalAdvance(' ') * 4);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(pOpenSourceBtn);
    btnLayout->addWidget(pSaveSourceBtn);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(pTxtEditSource);
    layout->addLayout(btnLayout);

    return layout;
}

QLayout* CodeEnvWgt::getResTextLayout() {
    /*
     *
    */

    pSaveResultBtn = new QPushButton("Сохранить", this);
    pTxtEditResult = new QTextEdit("Результат трансляции", this);
    pTxtEditResult->setFont(QFont("Lucida Console", 12));
    pTxtEditResult->setTabStopDistance(
        QFontMetricsF(pTxtEditSource->font()).horizontalAdvance(' ') * 4);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(pTxtEditResult);
    layout->addWidget(pSaveResultBtn);

    return layout;

}


/* SLOTS */
void CodeEnvWgt::translate() {
    /* Взять текст из source - прогнать через процесс translator.exe
    *   -> Вставить результать стандартонго вывода процесса в Result
    */

    qDebug() << "codeEnvWgt(translate): success translate";
}
