#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addCourse(Course course);

private slots:

    void on_btnGenerate_clicked();

    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void on_listWidgetBasic_itemClicked(QListWidgetItem *item);

    void on_listWidgetIntermediate_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
    std::vector<TimeSlot> timeSlots =  {TimeSlot{"T1"}, TimeSlot{"T2"}, TimeSlot{"T3"}, TimeSlot{"T4"}, TimeSlot{"T5"}, TimeSlot{"T6"} };
    std::vector<Subject> subjects;
    std::vector<Lecturer> lecturers;
    std::vector<Classroom> classrooms;
    std::vector<Laboratory> laboratories;
    std::vector<Course> courses;
    std::vector<sameLecturer> sameLecturers;
    std::vector<classPerWeekOfsubject> classPerWeekOfsubjects;
};
#endif // MAINWINDOW_H
