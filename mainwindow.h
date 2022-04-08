#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    멤버 선언
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer timer; //타이머 클래스의 객체 생성
    VideoCapture cap; //비디오 캡쳐 클래스의 객체 생성

private slots:
    //버튼이 눌리면 실행되는 기능

    void timeloop();

    void on_input_clicked();

    void on_erase_clicked();

    void on_end_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
