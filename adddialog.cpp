#include "adddialog.h"


AddDialog::AddDialog(MainWindow *mainWindow, QWidget *parent) : QDialog(parent), mainWindowPtr(mainWindow) {
    // 设置窗口属性或添加控件
     //   this->setMinimumSize(450,600);
        this->setMaximumSize(450,600);
        //this->
        buttonBox = new QDialogButtonBox();
        buttonBox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        this->label1 = new QLabel("℘ Course");
        this->label2 = new QLabel("Course name");
        this->lineEdit1 = new QLineEdit();
        this->lineEdit2 = new QLineEdit();
        this->VLay = new QVBoxLayout();
        this->VLay->addWidget(label1);
        this->VLay->addWidget(lineEdit1);
        this->VLay->addWidget(label2);
        this->VLay->addWidget(lineEdit2);
        this->VLay->addWidget(buttonBox);
        setLayout(VLay);


}

AddDialog::~AddDialog(){

}
