#ifndef STARTCONFWGT_H
#define STARTCONFWGT_H

#include <QWidget>
#include <QtWidgets>

class StartConfWgt : public QWidget
{
    Q_OBJECT
private:
    QString flexChoose;
    QString byzonChoose;
public:
    explicit StartConfWgt(QWidget *parent = nullptr);
    ~StartConfWgt();

signals:
    void startBtnClicked(const QString&, const QString&);

private slots:
    void sendFilesSrc();
};

#endif // STARTCONFWGT_H
