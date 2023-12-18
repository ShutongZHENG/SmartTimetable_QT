#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //init the font of listview
    QFont font;
    font.setFamily("Arial");  // 设置字体名称
    font.setPointSize(16);    // 设置字体大小
    ui->listWidgetBasic->setFont(font);

    ui->stackedWidget->setCurrentIndex(5);



}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_btnGenerate_clicked()
{
    qDebug() << "Clicked button Generate";
}


void MainWindow::on_btnAdd_clicked()
{
    qDebug() << "Clicked button Add";
    //qDebug() << ui->listWidgetBasic->currentItem()->text();
    if (ui->listWidgetBasic->currentItem()->text() == "Courses"){
        ui->stackedWidget->setCurrentIndex(0);
    }else if (ui->listWidgetBasic->currentItem()->text() == "Rooms"){
        ui->stackedWidget->setCurrentIndex(1);
    }else if (ui->listWidgetBasic->currentItem()->text() == "Labs"){
        ui->stackedWidget->setCurrentIndex(2);
    }else if (ui->listWidgetBasic->currentItem()->text() == "Lecturers"){
        ui->stackedWidget->setCurrentIndex(3);
    }else{
        ui->stackedWidget->setCurrentIndex(4);
    }




}


void MainWindow::on_btnDelete_clicked()
{
    qDebug() << "Clicked button Delete";
}


void MainWindow::on_listWidgetBasic_itemClicked(QListWidgetItem *item)
{
    qDebug() << item->text();

    ui->listWidgetIntermediate->clear();
    if(item->text() == "Courses"){
        for(auto element: subjects){
            ui->listWidgetIntermediate->addItem( QString::fromStdString(element.name));
        }
    }else if(item->text() == "Rooms"){
        for(auto element: classrooms){
            ui->listWidgetIntermediate->addItem("Room "+  QString::number(element.roomID));
        }
    }else if(item->text() == "Labs"){
        for(auto element: laboratories){
           ui->listWidgetIntermediate->addItem("Lab "+  QString::number(element.labID));
        }
    }else if(item->text() == "Lecturers"){
        for(auto element: lecturers){
            ui->listWidgetIntermediate->addItem(QString::fromStdString(element.name));
        }
    }else{
        for(auto element: timeSlots){
            ui->listWidgetIntermediate->addItem(QString::fromStdString(element.time));
        }
    }



}

