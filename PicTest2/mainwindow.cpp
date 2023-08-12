#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <opencv2/imgproc.hpp>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cap.open(0);
    if(!cap.isOpened()){
        qDebug() << "Error opening video stream or file" << "\n";
    }
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start(25);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update()
{
    if (filename.isEmpty() == 0 or camera_flag == 1)
    {
        if(camera_flag == 1)
            {
            cap.read(img);
            if (draw_flag == 1)
                Draw();
            }
        switch (state)
        {
            case 0:
            {
            image = QImage(img.data, img.cols, img.rows, QImage::Format_RGB888).rgbSwapped();
            pixel = QPixmap::fromImage(image);
            ui->label_image->setPixmap(pixel);
            break;
            }
            case 1:
            {
            cv::Mat gray_mat;
            cv::cvtColor(img, gray_mat, cv::COLOR_BGR2GRAY, 0);
            image = QImage(gray_mat.data, gray_mat.cols, gray_mat.rows, QImage::Format_Grayscale8).rgbSwapped();
            pixel = QPixmap::fromImage(image);
            ui->label_image->setPixmap(pixel);
            break;
            }
            case 2:
            {
            cv::Mat gray_mat;
            cv::Mat treshold_mat;
            cv::cvtColor(img, gray_mat, cv::COLOR_BGR2GRAY, 0);
            cv::threshold(gray_mat, treshold_mat, 125, 255, cv::THRESH_BINARY);
            image = QImage(treshold_mat.data, treshold_mat.cols, treshold_mat.rows, QImage::Format_Grayscale8).rgbSwapped();
            pixel = QPixmap::fromImage(image);
            ui->label_image->setPixmap(pixel);
            break;
            }
            case 3:
            {
            cv::Mat blur_mat;
            cv::blur(img, blur_mat, cv::Size(3, 3), cv::Point(-1,-1));
            image = QImage(blur_mat.data, blur_mat.cols, blur_mat.rows, QImage::Format_RGB888).rgbSwapped();
            pixel = QPixmap::fromImage(image);
            ui->label_image->setPixmap(pixel);
            break;
            }
            case 4:
            {
            cv::Mat gaussian_mat;
            cv::GaussianBlur(img, gaussian_mat, cv::Size(5, 5), 0, 0);
            image = QImage(gaussian_mat.data, gaussian_mat.cols, gaussian_mat.rows, QImage::Format_RGB888).rgbSwapped();
            pixel = QPixmap::fromImage(image);
            ui->label_image->setPixmap(pixel);
            break;
            }
            case 5:
            {
            cv::Mat gray_mat;
            cv::Mat canny_mat;
            cv::cvtColor(img, gray_mat, cv::COLOR_BGR2GRAY, 0);
            cv::Canny(gray_mat, canny_mat, 100, 255);
            image = QImage(canny_mat.data, canny_mat.cols, canny_mat.rows, QImage::Format_Grayscale8).rgbSwapped();
            pixel = QPixmap::fromImage(image);
            ui->label_image->setPixmap(pixel);
            break;
            }
            case 6:
            {
            cv::Mat hsv_mat;
            cv::cvtColor(img, hsv_mat, cv::COLOR_BGR2HSV, 0);
            image = QImage(hsv_mat.data, hsv_mat.cols, hsv_mat.rows, QImage::Format_RGB888).rgbSwapped();
            pixel = QPixmap::fromImage(image);
            ui->label_image->setPixmap(pixel);
            break;
            }
        }
    }

}

void MainWindow::Draw()
{
    cv::line(img, cv::Point(20, 20), cv::Point(40, 40), cv::Scalar(255, 0, 0), 3);
    cv::ellipse(img, cv::Point(75, 30), cv::Size(20, 30), 30, 0, 360, cv::Scalar(0, 255, 0), 2);
    cv::rectangle(img, cv::Point(120, 20), cv::Point(160, 40), cv::Scalar(0, 0, 255), 2);
    cv::circle(img, cv::Point(200, 30), 25, cv::Scalar(0, 0, 0), cv::FILLED);
    std::vector<cv::Point> pts = {{240,20}, {240,60}, {280,60}, {300,40}};
    cv::fillPoly(img, pts, cv::Scalar( 255, 255, 255 ));
    cv::putText(img, "Объекты нарисованы", cv::Point(20, 120), cv::FONT_HERSHEY_COMPLEX, 1.0, CV_RGB(120, 120, 0), 2);

}
void MainWindow::on_Normal_clicked()
{
    state = 0;
}
void MainWindow::on_Open_Image_clicked()
{
    camera_flag = 0;
    filename = QFileDialog::getOpenFileName(this, "Open Image", "/Users", "Image Files (*.png *.jpg *.bmp *.jpeg)");
    img = cv::imread(filename.toStdString());
    cv::resize(img, img, cv::Size(700, 500));
    image = QImage(img.data, img.cols, img.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
    state = 0;
}
void MainWindow::on_Grayscale_clicked()
{
    state = 1;
}
void MainWindow::on_Binary_clicked()
{
    state = 2;
}
void MainWindow::on_Blur_clicked()
{
    state = 3;
}
void MainWindow::on_GaussianBlur_clicked()
{
    state = 4;
}
void MainWindow::on_Canny_clicked()
{
    state = 5;
}
void MainWindow::on_HSV_clicked()
{
    state = 6;
}
void MainWindow::on_Draw_stateChanged(int arg1)
{
    if (camera_flag == 1)
    {
        if (arg1 == 0)
            draw_flag = 0;
        if (arg1 != 0)
            draw_flag = 1;
    }
    if (filename.isEmpty() == 0)
    {
        if (arg1 == 0)
            {
            img = img2.clone();
            //qDebug() << arg1;
            if (state==0)
                on_Normal_clicked();
            if (state==1)
                on_Grayscale_clicked();
            if (state==2)
                on_Binary_clicked();
            if (state==3)
                on_Blur_clicked();
            if (state==4)
                on_GaussianBlur_clicked();
            if (state==5)
                on_Canny_clicked();
            if (state==6)
                on_HSV_clicked();
            }
        if (arg1 != 0)
           {
            img2 = img.clone();
            Draw();
            if (state==0)
                on_Normal_clicked();
            if (state==1)
                on_Grayscale_clicked();
            if (state==2)
                on_Binary_clicked();
            if (state==3)
                on_Blur_clicked();
            if (state==4)
                on_GaussianBlur_clicked();
            if (state==5)
                on_Canny_clicked();
            if (state==6)
                on_HSV_clicked();
            }
    }
}

void MainWindow::on_Open_Camera_clicked()
{
    camera_flag = 1;
    state = 0;
}

