#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "mainwindow.h"

class AddDialog : public QDialog
{
    Q_OBJECT
private:
    QDialogButtonBox *buttonBox;
    QVBoxLayout *VLay;
    QLabel *label1;
    QLabel *label2;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    MainWindow *mainWindowPtr;

public:
    explicit AddDialog(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~AddDialog();
};

#endif // ADDDIALOG_H
