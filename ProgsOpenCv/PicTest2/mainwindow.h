#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Normal_clicked();

    void on_Open_Image_clicked();

    void on_Grayscale_clicked();

    void on_Binary_clicked();

    void on_Blur_clicked();

    void on_GaussianBlur_clicked();

    void on_Canny_clicked();

    void on_HSV_clicked();

private:
    Ui::MainWindow *ui;
public:
    cv::Mat img;
    QImage image;
    QPixmap pixel;
};
#endif // MAINWINDOW_H
