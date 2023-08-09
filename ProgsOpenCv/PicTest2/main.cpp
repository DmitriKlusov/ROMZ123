#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <QString>
#include <QFileDialog>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //fileName = QFileDialog::getOpenFileName(MainWindow::MainWindow, "Open Image", "C:/Users", "Image Files (*.png *.jpg *.bmp)");
    w.show();
    /*cv::Mat blur_mat, gaussian_mat, treshold_mat, gray_mat, hsv_mat, canny_mat;
    cv::Mat img = cv::imread("C:/Users/foto3.jpeg");

    if (img.empty())
        return -1;
    cv::namedWindow("Example_1", cv::WINDOW_AUTOSIZE);
    cv::pyrDown(img, img, cv::Size(img.cols/2, img.rows/2));
    cv::imshow("Example_1", img);
    cv::blur(img, blur_mat, cv::Size(3, 3), cv::Point(-1,-1));
    cv::imshow("Blur", blur_mat);
    cv::GaussianBlur(img, gaussian_mat, cv::Size(5, 5), 0, 0);
    cv::imshow("GaussianBlur", gaussian_mat);
    cv::cvtColor(img, gray_mat, cv::COLOR_BGR2GRAY, 0);
    cv::imshow("GRAY", gray_mat);
    cv::threshold(gray_mat, treshold_mat, 125, 255, cv::THRESH_BINARY);
    cv::imshow("Threshold", treshold_mat);
    cv::cvtColor(img, hsv_mat, cv::COLOR_BGR2HSV, 0);
    cv::imshow("HSV", hsv_mat);
    cv::Canny(gray_mat, canny_mat, 100, 255);
    cv::imshow("Canny", canny_mat);
    cv::waitKey(0);
    cv::destroyWindow("Example_1");*/

    return a.exec();
}
