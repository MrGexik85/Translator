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
    FileInputWgt *bisonPath;

public:
    explicit StartConfWgt(QWidget *parent = nullptr);
    ~StartConfWgt();

signals:
    void startBtnClicked(const QString& flexPath, const QString& bisonPath);

private slots:
    void sendFilesSrc();
};

#endif // STARTCONFWGT_H
