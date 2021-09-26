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
     *  Init and return layout with TextEdit field and 2 buttons (Save and Open)
     *
     *  return: QLayout*
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

    qDebug() << "CodeEnvWgt(getSrcTextLayout): success create layout for source code";
    return layout;
}

QLayout* CodeEnvWgt::getResTextLayout() {
    /*
     *  Init and return layout with TextEdit field and button (Save)
     *
     *  return: QLayout*
    */

    pSaveResultBtn = new QPushButton("Сохранить", this);
    pTxtEditResult = new QTextEdit("Результат трансляции", this);
    pTxtEditResult->setFont(QFont("Lucida Console", 12));
    pTxtEditResult->setTabStopDistance(QFontMetricsF(pTxtEditSource->font()).horizontalAdvance(' ') * 4);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(pTxtEditResult);
    layout->addWidget(pSaveResultBtn);

    qDebug() << "CodeEnvWgt(getSrcTextLayout): success create layout for result code";
    return layout;

}


/* SLOTS */
void CodeEnvWgt::translate() {
    /*
     * Get text from textEditSource -> make QProcess "translator.exe" with gotten text as argument
     *   -> set stdout from QProcess to textEditResult
     *
     *   return: void
    */
    pTranslateBtn->setEnabled(false);
    QApplication::setOverrideCursor(Qt::WaitCursor);

    QProcess translatorProc;
    translatorProc.start("./tmp/translator.exe", QStringList());
    translatorProc.write(pTxtEditSource->toPlainText().toStdString().c_str());
    translatorProc.closeWriteChannel();
    translatorProc.waitForReadyRead();
    QString res = translatorProc.readAllStandardOutput();
    qDebug() << translatorProc.readAllStandardError();
    qDebug() << translatorProc.exitCode();
    pTxtEditResult->setText(res);

    QApplication::restoreOverrideCursor();
    pTranslateBtn->setEnabled(true);

    qDebug() << "codeEnvWgt(translate): success translate";
}
