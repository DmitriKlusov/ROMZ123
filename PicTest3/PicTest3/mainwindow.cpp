#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <opencv2/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Open_Image_clicked()
{
    filename = QFileDialog::getOpenFileName(this, "Open Image", "/Users", "Image Files (*.png *.jpg *.bmp *.jpeg)");
    img = cv::imread(filename.toStdString());
    cv::resize(img, img, cv::Size(700, 451));
    image = QImage(img.data, img.cols, img.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}

void MainWindow::on_Contur_clicked()
{
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat image_gray;
    cv::blur(img, image_gray, cv::Size(3, 3), cv::Point(-1,-1));
    cv::Mat image_origin = img.clone();
    cv::cvtColor(image_gray, image_gray, cv::COLOR_BGR2GRAY, 0);
    cv::threshold(image_gray, image_gray, 40, 255, cv::THRESH_BINARY);
    cv::findContours(image_gray, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE );
    cv::Mat image_copy = img.clone();
    std::vector<std::vector<cv::Point>> contours0;
    contours0.resize(contours.size());
    if (flag == 0)
        image_copy = image_origin.clone();
    if (flag == 1)
        image_copy = image_gray.clone();
    for(size_t i = 0; i< contours.size(); i++ )
        {
        std::vector cnt = contours[i];
        double epsilon = 0.01*cv::arcLength(cnt, 1);
        cv::Scalar color = cv::Scalar(100+i*50, 100, 0+i*70);
        cv::Scalar color2 = CV_RGB(255, 255, 255);
        cv::approxPolyDP(cv::Mat(contours[i]), contours0[i], epsilon, 1);
        std::vector cnt0 = contours0[i];
        /*
        cv::Point sum_coord;
        cv::Point2f mean_coord;
        int s = cnt0.size();
        for(size_t i2 = 0; i2< cnt0.size(); i2++ )
            {
            sum_coord = sum_coord + cnt0[i2];
            }
        mean_coord = sum_coord/s;
        */
        cv::Rect Rectan;
        Rectan = cv::boundingRect(cnt0);
        cv::drawContours(image_copy, contours, (int)i, color, 2, cv::LINE_8, hierarchy, 0);

        if (cnt0.size() == 3)
            cv::putText(image_copy, "треугольник", cv::Point(Rectan.x, Rectan.y-15), cv::FONT_HERSHEY_COMPLEX, 1.0, color2, 2);
        if (cnt0.size() == 4)
            {
            if ((Rectan.width > Rectan.height-16) and (Rectan.width < Rectan.height+16))
                cv::putText(image_copy, "квадрат", cv::Point(Rectan.x, Rectan.y-15), cv::FONT_HERSHEY_COMPLEX, 1.0, color2, 2);
            else
                cv::putText(image_copy, "прямоугольник", cv::Point(Rectan.x, Rectan.y-15), cv::FONT_HERSHEY_COMPLEX, 1.0, color2, 2);
            }
        if (cnt0.size() > 5)
            cv::putText(image_copy, "круг", cv::Point(Rectan.x, Rectan.y-15), cv::FONT_HERSHEY_COMPLEX, 1.0, color2, 2);
        if (flag == 0)
            image = QImage(image_copy.data, image_copy.cols, image_copy.rows, QImage::Format_RGB888).rgbSwapped();
        if (flag == 1)
            image = QImage(image_copy.data, image_copy.cols, image_copy.rows, QImage::Format_Grayscale8).rgbSwapped();
        pixel = QPixmap::fromImage(image);
        ui->label_image->setPixmap(pixel);
        }
}

void MainWindow::on_Color_stateChanged(int arg1)
{
    if (arg1 == 0)
        flag = 1;
    if (arg1 != 0)
        flag = 0;
}

