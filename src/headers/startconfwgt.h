#ifndef STARTCONFWGT_H
#define STARTCONFWGT_H

#include <QWidget>
#include <QtWidgets>
#include "fileinputwgt.h"

class StartConfWgt : public QWidget
{
    Q_OBJECT
private:
    FileInputWgt *flexPath;
    FileInputWgt *byzonPath;

public:
    explicit StartConfWgt(QWidget *parent = nullptr);
    ~StartConfWgt();

signals:
    void startBtnClicked(const QString&, const QString&);

private slots:
    void sendFilesSrc();
};

#endif // STARTCONFWGT_H
