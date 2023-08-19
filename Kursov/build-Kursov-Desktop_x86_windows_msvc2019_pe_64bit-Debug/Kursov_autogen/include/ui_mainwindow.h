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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSplitter *splitter;
    QLabel *origin_label;
    QLabel *Thresh_label;
    QSplitter *splitter_2;
    QLabel *origin_label_part;
    QLabel *Thresh_label_part;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1500, 750);
        MainWindow->setMinimumSize(QSize(1500, 750));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(1250, 0, 3, 750));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(1330, 50, 88, 24));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(1330, 90, 88, 24));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(1290, 270, 160, 18));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(1290, 350, 160, 18));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(centralwidget);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setGeometry(QRect(1290, 430, 160, 18));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(40, 20, 1161, 400));
        splitter->setOrientation(Qt::Horizontal);
        origin_label = new QLabel(splitter);
        origin_label->setObjectName("origin_label");
        origin_label->setMinimumSize(QSize(550, 400));
        splitter->addWidget(origin_label);
        Thresh_label = new QLabel(splitter);
        Thresh_label->setObjectName("Thresh_label");
        Thresh_label->setMinimumSize(QSize(550, 400));
        splitter->addWidget(Thresh_label);
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setGeometry(QRect(290, 460, 681, 240));
        splitter_2->setOrientation(Qt::Horizontal);
        origin_label_part = new QLabel(splitter_2);
        origin_label_part->setObjectName("origin_label_part");
        splitter_2->addWidget(origin_label_part);
        Thresh_label_part = new QLabel(splitter_2);
        Thresh_label_part->setObjectName("Thresh_label_part");
        splitter_2->addWidget(Thresh_label_part);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1500, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        origin_label->setText(QCoreApplication::translate("MainWindow", "Origin", nullptr));
        Thresh_label->setText(QCoreApplication::translate("MainWindow", "Thresh", nullptr));
        origin_label_part->setText(QCoreApplication::translate("MainWindow", "Origin_part", nullptr));
        Thresh_label_part->setText(QCoreApplication::translate("MainWindow", "Thresh_part", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
