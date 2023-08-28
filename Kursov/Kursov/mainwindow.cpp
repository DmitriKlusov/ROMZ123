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
    std::vector<cv::Point> poly;

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
    int wight_hight = 260;
    // Узловые точки лэйбла на котором будет отображаться вырезанная и афинно преобразованная часть изображения
    cv::Point2f ipn_points[4];
    ipn_points[0] = cv::Point2f(0, 0);
    ipn_points[1] = cv::Point2f(wight_hight + 10, 0);
    ipn_points[2] = cv::Point2f(wight_hight + 10, wight_hight + 10);
    ipn_points[3] = cv::Point2f(0, wight_hight + 10);

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
    cv::warpPerspective(img, ipm_mat, transform_mat, cv::Size(wight_hight, wight_hight));

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

    cv::cvtColor(part_origin, gray_mat_part, cv::COLOR_BGR2HSV, 0);
    cv::inRange(gray_mat_part, cv::Scalar(0, 0, 200), cv::Scalar(255, 255, 255), treshold_mat_part);
    image = QImage(treshold_mat_part.data, treshold_mat_part.cols, treshold_mat_part.rows, QImage::Format_Grayscale8).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->Thresh_label_part->setPixmap(pixel);

    std::vector<cv::Point> points_x_l, points_x_r;
    std::vector<int> y_l, y_r;
    std::vector<cv::Point2i> locations;
    int i, j;
    int k = 20;
    int l1 = 0, l2 = 0;
    int o1 = 0, o2 = 0;
    int x = 0, y = 0;
    frames.push_back(treshold_mat_part);
    for (int u = 0; u < frames.size(); u++)
        {
        for (y = 0; y < wight_hight-25; y += k)
            {
            l2 = 0;
            o2 = 0;
            int my_x = 0;
            // Первый вариант
            /*
            for (x = 0; x < wight_hight-25; x += k)
                {
                cv::Mat out = frames[u](cv::Rect(x,y,k,k));
                cv::findNonZero(out, locations);
                if (locations.size() >= 70)
                    {
                    //cv::rectangle(part_origin, cv::Rect(x,y,k,k), cv::Scalar(0, 255, 0));
                    //cv::line(frames[u], cv::Point(x+k/2, y+k/2), cv::Point(x+k/2, y+k/2), cv::Scalar(0, 255, 0), 2, cv::LINE_AA);
                    if (x < wight_hight/2)
                        {
                        points_x_l.push_back(cv::Point(x+k/2, y+k/2));
                        l1+=1;
                        l2+=1;
                        }
                    if (x >= wight_hight/2)
                        {
                        points_x_r.push_back(cv::Point(x+k/2, y+k/2));
                        o1+=1;
                        o2+=1;
                        }
                    }
                }
            if (l2 > 0)
                {
                if (l2 >= 2)
                    {
                    for (int u2 = 0; u2 < l2; u2++)
                        {
                        my_x = my_x + points_x_l[l1-1].x;
                        points_x_l.erase(points_x_l.end());
                        l1-=1;
                        }
                    my_x = my_x/l2;
                    points_x_l.push_back(cv::Point(my_x, y+k/2));
                    l1+=1;
                    }
                cv::rectangle(part_origin, cv::Rect(points_x_l[l1-1].x-k/2,points_x_l[l1-1].y-k/2,k,k), cv::Scalar(0, 255, 0));
                }
            if (o2 > 0)
                cv::rectangle(part_origin, cv::Rect(points_x_r[o1-1].x-k/2,points_x_r[o1-1].y-k/2,k,k), cv::Scalar(0, 255, 0));
            //
            */
            // Второй вариант
            for (x = 0; x < wight_hight-25; x += k)
                {
                cv::Mat out = frames[u](cv::Rect(x,y,k,k));
                cv::findNonZero(out, locations);
                if (locations.size() >= 50) //было 70
                    {
                    if (x < wight_hight/2)
                        {
                        points_x_l.push_back(cv::Point(x+k/2, y+k/2));
                        l1+=1;
                        l2+=1;
                        }
                    if (x >= wight_hight/2)
                        {
                        points_x_r.push_back(cv::Point(x+k/2, y+k/2));
                        o1+=1;
                        o2+=1;
                        }
                    }
                }
            if (l2 > 0)
                {
                y_l.push_back(y+k/2);
                if (y_l.size() >=2)
                    {
                    if (std::find(y_l.begin(), y_l.end()-1, y+k/2) != y_l.end()-1)
                        {
                        y_l.erase(y_l.end());
                        }
                    }
                if (l2 >= 2)
                    {
                    for (int u2 = 0; u2 < l2; u2++)
                        {
                        my_x = my_x + points_x_l[l1-1].x;
                        points_x_l.erase(points_x_l.end());
                        l1-=1;
                        }
                    my_x = my_x/l2;
                    points_x_l.push_back(cv::Point(my_x, y+k/2));
                    l1+=1;
                    }
                if (l1 >= 2)
                    {
                    for (int u3 = 0; u3 < l1-1; u3++)
                        {
                        if (points_x_l[u3].y == y+k/2)
                            {
                            points_x_l.erase(points_x_l.begin()+u3);
                            l1-=1;
                            }
                        }
                    }
                //cv::rectangle(part_origin, cv::Rect(points_x_l[l1-1].x-k/2,points_x_l[l1-1].y-k/2,k,k), cv::Scalar(0, 255, 0));
                }
            my_x = 0;
            if (o2 > 0)
                {
                y_r.push_back(y+k/2);
                if (y_r.size() >=2)
                    {
                    if (std::find(y_r.begin(), y_r.end()-1, y+k/2) != y_r.end()-1)
                        {
                        y_r.erase(y_r.end());
                        }
                    }
                if (o2 >= 2)
                    {
                    for (int u2 = 0; u2 < o2; u2++)
                        {
                        my_x = my_x + points_x_r[o1-1].x;
                        points_x_r.erase(points_x_r.end());
                        o1-=1;
                        }
                    my_x = my_x/o2;
                    points_x_r.push_back(cv::Point(my_x, y+k/2));
                    o1+=1;
                    }
                if (o1 >= 2)
                    {
                    for (int u3 = 0; u3 < o1-1; u3++)
                        {
                        if (points_x_r[u3].y == y+k/2)
                            {
                            points_x_r.erase(points_x_r.begin()+u3);
                            o1-=1;
                            }
                        }
                    }
                //cv::rectangle(part_origin, cv::Rect(points_x_r[o1-1].x-k/2,points_x_r[o1-1].y-k/2,k,k), cv::Scalar(0, 255, 0));
                }
            //
            }
        }
    std::sort(y_l.begin(), y_l.end());
    std::sort(y_r.begin(), y_r.end(), std::greater<int>());
    poly.resize(y_l.size()+y_r.size());
    for (int u4 = 0; u4 < l1; u4++)
        {
        if (std::find(y_l.begin(), y_l.end(), points_x_l[u4].y) != y_l.end())
            {
            std::vector<int>::iterator it = std::find(y_l.begin(), y_l.end(), points_x_l[u4].y);
            int my_i = std::distance(y_l.begin(), it);
            poly.erase(poly.begin()+my_i);
            poly.insert(poly.begin()+my_i, points_x_l[u4]);
            }
        cv::rectangle(part_origin, cv::Rect(points_x_l[u4].x-k/2,points_x_l[u4].y-k/2,k,k), cv::Scalar(0, 255, 0));
        }
    for (int u4 = 0; u4 < o1; u4++)
        {
        if (std::find(y_r.begin(), y_r.end(), points_x_r[u4].y) != y_r.end())
            {
            std::vector<int>::iterator it = std::find(y_r.begin(), y_r.end(), points_x_r[u4].y);
            int my_i = std::distance(y_r.begin(), it);
            poly.erase(poly.begin()+y_l.size()+my_i);
            poly.insert(poly.begin()+y_l.size()+my_i, points_x_r[u4]);
            }
        cv::rectangle(part_origin, cv::Rect(points_x_r[u4].x-k/2,points_x_r[u4].y-k/2,k,k), cv::Scalar(0, 255, 0));
        }
    if (frames.size() >= 30)
        frames.erase(frames.begin());

    /*
    double a1 = 0;
    double b1 = 0;
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
    int len = points_x_l.size();
    for (i = 1; i < len; i++)
        {
        sumx = sumx + points_x_l[i].x;
        sumxy = sumxy + points_x_l[i].x*points_x_l[i].y;
        sumy = sumy + points_x_l[i].y;
        sumx2 = sumx2 + points_x_l[i].x*points_x_l[i].x;
        }
    a1 = (len*sumxy - sumx*sumy)/(len*sumx2 - sumx*sumx);
    b1 = (sumy-a1*sumx)/len;
    cv::Point point1, point2;
    point1.y = 1;
    point1.x = int((1-b1)/a1);
    point2.y = wight_hight;
    point2.x = int((wight_hight-b1)/a1);*/
    //cv::line(part_origin, point1, point2, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);
    std::vector<cv::Point> contours_new;
    double epsilon = 0.07*cv::arcLength(poly, 1);
    cv::approxPolyDP(cv::Mat(poly), contours_new, epsilon, 1);
    cv::fillPoly(part_origin, contours_new, cv::Scalar( 150, 150, 150 ));

    image = QImage(part_origin.data, part_origin.cols, part_origin.rows, QImage::Format_RGB888).rgbSwapped();
    pixel = QPixmap::fromImage(image);
    ui->origin_label_part->setPixmap(pixel);
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
