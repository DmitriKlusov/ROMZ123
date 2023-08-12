/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QPushButton *Open_Image;
    QLabel *label_image;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *Normal;
    QSpacerItem *verticalSpacer;
    QRadioButton *Grayscale;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *Binary;
    QSpacerItem *verticalSpacer_3;
    QRadioButton *Blur;
    QSpacerItem *verticalSpacer_5;
    QRadioButton *GaussianBlur;
    QSpacerItem *verticalSpacer_6;
    QRadioButton *Canny;
    QSpacerItem *verticalSpacer_4;
    QRadioButton *HSV;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *Open_Camera;
    QSpacerItem *horizontalSpacer;
    QCheckBox *Draw;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(950, 600);
        MainWindow->setMinimumSize(QSize(950, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(790, 10, 20, 501));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(920, 10, 20, 501));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(800, 10, 130, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(800, 510, 130, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        Open_Image = new QPushButton(centralwidget);
        Open_Image->setObjectName("Open_Image");
        Open_Image->setGeometry(QRect(820, 520, 93, 29));
        label_image = new QLabel(centralwidget);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(50, 10, 700, 500));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(810, 31, 110, 461));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Normal = new QRadioButton(layoutWidget);
        Normal->setObjectName("Normal");

        gridLayout->addWidget(Normal, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(58, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        Grayscale = new QRadioButton(layoutWidget);
        Grayscale->setObjectName("Grayscale");

        gridLayout->addWidget(Grayscale, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(58, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);

        Binary = new QRadioButton(layoutWidget);
        Binary->setObjectName("Binary");

        gridLayout->addWidget(Binary, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(58, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 5, 0, 1, 1);

        Blur = new QRadioButton(layoutWidget);
        Blur->setObjectName("Blur");

        gridLayout->addWidget(Blur, 6, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(58, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 7, 0, 1, 1);

        GaussianBlur = new QRadioButton(layoutWidget);
        GaussianBlur->setObjectName("GaussianBlur");

        gridLayout->addWidget(GaussianBlur, 8, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(58, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 9, 0, 1, 1);

        Canny = new QRadioButton(layoutWidget);
        Canny->setObjectName("Canny");

        gridLayout->addWidget(Canny, 10, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(58, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 11, 0, 1, 1);

        HSV = new QRadioButton(layoutWidget);
        HSV->setObjectName("HSV");

        gridLayout->addWidget(HSV, 12, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(560, 520, 208, 31));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Open_Camera = new QPushButton(widget);
        Open_Camera->setObjectName("Open_Camera");

        gridLayout_2->addWidget(Open_Camera, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        Draw = new QCheckBox(widget);
        Draw->setObjectName("Draw");

        gridLayout_2->addWidget(Draw, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 950, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\264\320\273\321\217 \321\202\320\265\321\201\321\202\320\260 OpenCv", nullptr));
        Open_Image->setText(QCoreApplication::translate("MainWindow", "Open_Image", nullptr));
        label_image->setText(QString());
        Normal->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        Grayscale->setText(QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        Binary->setText(QCoreApplication::translate("MainWindow", "Treshold", nullptr));
        Blur->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        GaussianBlur->setText(QCoreApplication::translate("MainWindow", "GaussianBlur", nullptr));
        Canny->setText(QCoreApplication::translate("MainWindow", "Canny", nullptr));
        HSV->setText(QCoreApplication::translate("MainWindow", "HSV", nullptr));
        Open_Camera->setText(QCoreApplication::translate("MainWindow", "Open_Camera", nullptr));
        Draw->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
