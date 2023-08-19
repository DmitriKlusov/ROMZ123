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
    cap.open("D:/Qt/project_video.mp4");
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
    cap.read(img);
    cv::resize(img, img, cv::Size(540, 390));
    cv::Mat image_origin = img.clone();
    cv::Mat gray_mat;
    cv::Mat treshold_mat;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    //int fps = cap.get(cv::CAP_PROP_FPS);
    //int frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);
    double current_frame = cap.get(cv::CAP_PROP_POS_FRAMES);
    QString str_current_frame = QString::number(current_frame);
    cv::putText(image_origin, str_current_frame.toStdString(), cv::Point(50, 50), cv::FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(0, 255, 0), 2);

    image = QImage(image_origin.data, image_origin.cols, image_origin.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->origin_label->setPixmap(pixel);

    cv::cvtColor(img, gray_mat, cv::COLOR_BGR2HSV, 0);
    cv::inRange(gray_mat, cv::Scalar(0, 0, 200), cv::Scalar(255, 255, 255), treshold_mat);
    image = QImage(treshold_mat.data, treshold_mat.cols, treshold_mat.rows, QImage::Format_Grayscale8).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->Thresh_label->setPixmap(pixel);

    cv::findContours(treshold_mat, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE );
    for(size_t i = 0; i< contours.size(); i++ )
        {
        cv::drawContours(image_origin, contours, (int)i, cv::Scalar(0, 0, 255), 2, cv::LINE_8, hierarchy, 0);
        image = QImage(image_origin.data, image_origin.cols, image_origin.rows, QImage::Format_RGB888).rgbSwapped();
        pixel = QPixmap::fromImage(image);
        ui->origin_label->setPixmap(pixel);
        }
}
