#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QString>

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


void MainWindow::on_Normal_clicked()
{
    image = QImage(img.data, img.cols, img.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}


void MainWindow::on_Open_Image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Image", "/Users", "Image Files (*.png *.jpg *.bmp *.jpeg)");

    img = cv::imread(filename.toStdString());
    cv::resize(img, img, cv::Size(700, 500));
    image = QImage(img.data, img.cols, img.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}


void MainWindow::on_Grayscale_clicked()
{
    cv::Mat gray_mat;
    cv::cvtColor(img, gray_mat, cv::COLOR_BGR2GRAY, 0);
    image = QImage(gray_mat.data, gray_mat.cols, gray_mat.rows, QImage::Format_Grayscale8).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}


void MainWindow::on_Binary_clicked()
{
    cv::Mat gray_mat;
    cv::Mat treshold_mat;
    cv::cvtColor(img, gray_mat, cv::COLOR_BGR2GRAY, 0);
    cv::threshold(gray_mat, treshold_mat, 125, 255, cv::THRESH_BINARY);
    image = QImage(treshold_mat.data, treshold_mat.cols, treshold_mat.rows, QImage::Format_Grayscale8).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}


void MainWindow::on_Blur_clicked()
{
    cv::Mat blur_mat;
    cv::blur(img, blur_mat, cv::Size(3, 3), cv::Point(-1,-1));
    image = QImage(blur_mat.data, blur_mat.cols, blur_mat.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}


void MainWindow::on_GaussianBlur_clicked()
{
    cv::Mat gaussian_mat;
    cv::GaussianBlur(img, gaussian_mat, cv::Size(5, 5), 0, 0);
    image = QImage(gaussian_mat.data, gaussian_mat.cols, gaussian_mat.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}


void MainWindow::on_Canny_clicked()
{
    cv::Mat gray_mat;
    cv::Mat canny_mat;
    cv::cvtColor(img, gray_mat, cv::COLOR_BGR2GRAY, 0);
    cv::Canny(gray_mat, canny_mat, 100, 255);
    image = QImage(canny_mat.data, canny_mat.cols, canny_mat.rows, QImage::Format_Grayscale8).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}


void MainWindow::on_HSV_clicked()
{
    cv::Mat hsv_mat;
    cv::cvtColor(img, hsv_mat, cv::COLOR_BGR2HSV, 0);
    image = QImage(hsv_mat.data, hsv_mat.cols, hsv_mat.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->label_image->setPixmap(pixel);
}

