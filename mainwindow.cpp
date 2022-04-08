#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <opencv2\core\core.hpp>
//#include <opencv2\highgui\highgui.hpp>


//int camera = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),cap(0)  // 멤버 변수 초기화
{
    ui->setupUi(this); //셋업
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeloop()));
//타이머라는 객체에서 타임아웃이라는 시그널이 날아오면 타임루프라는 함수가 세팅되도록 한다.
// 타이머에 대한 객체 생성후 connection을 통해 원하는 콜백 펑션과 연결해준다.

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_input_clicked()
{
    ui -> Dialog -> setPlainText("Hello");

    timer.setInterval(33);//몇 미리세컨드마다 쓸것인가???, 타이머의 멤버 함수
    timer.start();// 타이머 켜는 함수, 타이머의 멤버 함수


}


void MainWindow::on_erase_clicked()
{
    ui -> Dialog -> setPlainText("");
}



void MainWindow::on_end_clicked()
{
    this ->close();
//    camera = 0;
}

void MainWindow::timeloop()
{
    if (cap.isOpened())
    {
        Mat img;
        cap.read(img);
        imshow("test", img);
    }
}


