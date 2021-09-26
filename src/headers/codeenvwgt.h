#ifndef CODEENVWGT_H
#define CODEENVWGT_H

#include <QWidget>
#include <QtWidgets>

class CodeEnvWgt : public QWidget
{
    Q_OBJECT

private:
    QTextEdit *pTxtEditSource = nullptr;
    QTextEdit *pTxtEditResult = nullptr;
    QPushButton *pTranslateBtn = nullptr;
    QPushButton *pOpenSourceBtn = nullptr;
    QPushButton *pSaveSourceBtn = nullptr;
    QPushButton *pSaveResultBtn = nullptr;

    QLayout* getSrcTextLayout();
    QLayout* getResTextLayout();
public:
    explicit CodeEnvWgt(QWidget *parent = nullptr);
    ~CodeEnvWgt();

private slots:
    void translate();

signals:

};

#endif // CODEENVWGT_H
