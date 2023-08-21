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
    cv::Mat gray_mat, gray_mat_part;
    cv::Mat treshold_mat, treshold_mat_part;
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

    double a, b, c, d, e;
    cv::Mat ipm_mat;

    // Узловые точки лэйбла на котором будет отображаться вырезанная и афинно преобразованная часть изображения
    cv::Point2f ipn_points[4];
    ipn_points[0] = cv::Point2f(0, 0);
    ipn_points[1] = cv::Point2f(270, 0);
    ipn_points[2] = cv::Point2f(270, 270);
    ipn_points[3] = cv::Point2f(0, 270);

    cv::Point2f traprezoid[4];
    a = (540 - Verh)/2;
    b = (540 + Verh)/2;
    c = (540 - Niz)/2;
    d = (540 + Niz)/2;
    e = 390 - Hight;
    // Узловые точки пирамиды
    traprezoid[0] = cv::Point2f(qRound(a), qRound(e));
    traprezoid[1] = cv::Point2f(qRound(b), qRound(e));
    traprezoid[2] = cv::Point2f(qRound(d), 360);
    traprezoid[3] = cv::Point2f(qRound(c), 360);

    cv::Mat transform_mat = cv::getPerspectiveTransform(traprezoid, ipn_points);
    //Размер 260, 260 - это размер итогового изображения на малом лэйбле снизу, сам лэйбл 270 на 270, взял меньше, чтобы изображение не рушилось
    cv::warpPerspective(img, ipm_mat, transform_mat, cv::Size(260, 260));

    cv::circle(image_origin, traprezoid[0], 2, cv::Scalar(0, 255, 0), 2, cv::LINE_8, 0);
    cv::circle(image_origin, traprezoid[1], 2, cv::Scalar(0, 255, 0), 2, cv::LINE_8, 0);
    cv::circle(image_origin, traprezoid[2], 2, cv::Scalar(0, 255, 0), 2, cv::LINE_8, 0);
    cv::circle(image_origin, traprezoid[3], 2, cv::Scalar(0, 255, 0), 2, cv::LINE_8, 0);
    cv::line(image_origin, traprezoid[0], traprezoid[1], cv::Scalar(0, 255, 0), 2, 8);
    cv::line(image_origin, traprezoid[1], traprezoid[2], cv::Scalar(0, 255, 0), 2, 8);
    cv::line(image_origin, traprezoid[2], traprezoid[3], cv::Scalar(0, 255, 0), 2, 8);
    cv::line(image_origin, traprezoid[3], traprezoid[0], cv::Scalar(0, 255, 0), 2, 8);

    image = QImage(image_origin.data, image_origin.cols, image_origin.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->origin_label->setPixmap(pixel);

    cv::Mat part_origin = ipm_mat.clone();
    image = QImage(part_origin.data, part_origin.cols, part_origin.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->origin_label_part->setPixmap(pixel);

    cv::cvtColor(part_origin, gray_mat_part, cv::COLOR_BGR2HSV, 0);
    cv::inRange(gray_mat_part, cv::Scalar(0, 0, 200), cv::Scalar(255, 255, 255), treshold_mat_part);
    image = QImage(treshold_mat_part.data, treshold_mat_part.cols, treshold_mat_part.rows, QImage::Format_Grayscale8).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->Thresh_label_part->setPixmap(pixel);
    /*
    for(size_t i = 0; i< contours.size(); i++ )
        {
        cv::drawContours(image_origin, contours, (int)i, cv::Scalar(0, 0, 255), 2, cv::LINE_8, hierarchy, 0);
        image = QImage(image_origin.data, image_origin.cols, image_origin.rows, QImage::Format_RGB888).rgbSwapped();
        pixel = QPixmap::fromImage(image);
        ui->origin_label->setPixmap(pixel);
        }*/
}

void MainWindow::on_Rmin_Slider_valueChanged(int value)
{
    Verh = value; //Ширина верха пирамиды
}

void MainWindow::on_Gmin_Slider_valueChanged(int value)
{
    Niz = value; //Ширина низа пирамиды
}

void MainWindow::on_Bmin_Slider_valueChanged(int value)
{
    Hight = value; //Высота пирамиды
}

void MainWindow::on_Rmax_Slider_valueChanged(int value)
{
    Rmax = value;
}

void MainWindow::on_Gmax_Slider_valueChanged(int value)
{
    Gmax = value;
}

void MainWindow::on_Bmax_Slider_valueChanged(int value)
{
    Bmax = value;
}
