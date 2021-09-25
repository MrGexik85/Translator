#ifndef FILEINPUTWGT_H
#define FILEINPUTWGT_H

#include <QWidget>
#include <QtWidgets>

class FileInputWgt : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *layout = nullptr;
    QLineEdit *pathToFile = nullptr;
    QPushButton *chooseFileBtn = nullptr;
    QString filesFilter;
public:
    explicit FileInputWgt(QString lineTitle, QString filesFilters, QWidget *parent = nullptr);
    ~FileInputWgt();
    QString getCurrentPath();
private slots:
    void onChooseFileBtnClicked();
signals:

};

#endif // FILEINPUTWGT_H
