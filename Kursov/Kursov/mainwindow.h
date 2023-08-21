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

public slots:
    void Update();

private:
    Ui::MainWindow *ui;
public:
    cv::VideoCapture cap;
    cv::Mat img;
    QImage image;
    QPixmap pixel;
    int Verh = 120, Niz = 420, Hight = 150, Rmax = 255, Gmax = 255, Bmax = 255;
private slots:
    void on_Rmin_Slider_valueChanged(int value);
    void on_Gmin_Slider_valueChanged(int value);
    void on_Bmin_Slider_valueChanged(int value);
    void on_Rmax_Slider_valueChanged(int value);
    void on_Gmax_Slider_valueChanged(int value);
    void on_Bmax_Slider_valueChanged(int value);
};
#endif // MAINWINDOW_H
