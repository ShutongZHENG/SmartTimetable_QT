#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "adddialog.h"

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

    ui->stackedWidget->setCurrentIndex(6);



}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::addCourse(Course course)
{
    this->courses.emplace_back(course);
}



void MainWindow::on_btnGenerate_clicked()
{
    qDebug() << "Clicked button Generate";
}


void MainWindow::on_btnAdd_clicked()
{
    qDebug() << "Clicked button Add";
    if(ui->listWidgetBasic->currentItem() == NULL){
        qDebug() << "no selected";
        return ;
    }
    if (ui->listWidgetBasic->currentItem()->text() == "Courses"){
        ui->stackedWidget->setCurrentIndex(0);
    }else if (ui->listWidgetBasic->currentItem()->text() == "Rooms"){
        ui->stackedWidget->setCurrentIndex(1);
    }else if (ui->listWidgetBasic->currentItem()->text() == "Labs"){
        ui->stackedWidget->setCurrentIndex(2);
    }else if (ui->listWidgetBasic->currentItem()->text() == "Lecturers"){
        ui->stackedWidget->setCurrentIndex(3);
    }else if (ui->listWidgetBasic->currentItem()->text() == "Slots"){
        ui->stackedWidget->setCurrentIndex(4);
    }else if (ui->listWidgetBasic->currentItem()->text() == "Sujects"){
        ui->stackedWidget->setCurrentIndex(5);
    }
    else{
        ui->stackedWidget->setCurrentIndex(6);
    }

    AddDialog *dialog = new AddDialog(this,this);
    dialog->setAttribute(Qt::WA_DeleteOnClose); // 确保对话框关闭时删除
    dialog->show();


}


void MainWindow::on_btnDelete_clicked()
{
    qDebug() << "Clicked button Delete";
}


void MainWindow::on_listWidgetBasic_itemClicked(QListWidgetItem *item)
{
    qDebug() << item->text();

    ui->listWidgetIntermediate->clear();
    ui->stackedWidget->setCurrentIndex(6);
    if(item->text() == "Courses"){
        if(!this->courses.empty()){
            for(auto element: courses){
                ui->listWidgetIntermediate->addItem( QString::fromStdString(element.name));
            }
            ui->listWidgetIntermediate->setCurrentRow(0);
        }
    }else if(item->text() == "Rooms"){
        if(!this->classrooms.empty()){
            for(auto element: classrooms){
                ui->listWidgetIntermediate->addItem("Room "+  QString::number(element.roomID));
            }
            ui->listWidgetIntermediate->setCurrentRow(0);
        }

    }else if(item->text() == "Labs"){
        if(!this->laboratories.empty()){
            for(auto element: laboratories){
               ui->listWidgetIntermediate->addItem("Lab "+  QString::number(element.labID));
            }
            ui->listWidgetIntermediate->setCurrentRow(0);
        }

    }else if(item->text() == "Lecturers"){
        if(!this->lecturers.empty()){
            for(auto element: lecturers){
                ui->listWidgetIntermediate->addItem(QString::fromStdString(element.name));
            }
            ui->listWidgetIntermediate->setCurrentRow(0);
        }


    }else if(item->text() == "Subjects"){
        if(!this->subjects.empty()){
            for(auto element: subjects){
                ui->listWidgetIntermediate->addItem(QString::fromStdString(element.name));
            }
            ui->listWidgetIntermediate->setCurrentRow(0);
        }
    }
    else{
        if(!this->timeSlots.empty()){
            for(auto element: timeSlots){
                ui->listWidgetIntermediate->addItem(QString::fromStdString(element.time));
            }
            ui->listWidgetIntermediate->setCurrentRow(0);
        }

    }



}



void MainWindow::on_listWidgetIntermediate_currentRowChanged(int currentRow)
{
    if(currentRow == -1)
        return;
    qDebug()<< "Basic: " <<ui->listWidgetBasic->currentItem()->text();
    QString basicList  = ui->listWidgetBasic->currentItem()->text();
    qDebug()<< "current row: " << currentRow;

    if(basicList == "Courses"){
        ui->stackedWidget->setCurrentIndex(0);
    }else if(basicList == "Rooms"){
        ui->stackedWidget->setCurrentIndex(1);
    }else if(basicList == "Labs"){
        ui->stackedWidget->setCurrentIndex(2);
    }else if(basicList == "Lecturers"){
        ui->stackedWidget->setCurrentIndex(3);
    }else if(basicList == "Slots"){
        ui->stackedWidget->setCurrentIndex(4);
    }else{
        ui->stackedWidget->setCurrentIndex(5);
    }



}



