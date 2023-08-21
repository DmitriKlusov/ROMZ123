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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QSplitter *splitter;
    QLabel *origin_label;
    QLabel *Thresh_label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_5;
    QSlider *Gmin_Slider;
    QSlider *Rmax_Slider;
    QTextBrowser *textBrowser_6;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_3;
    QSlider *Gmax_Slider;
    QSlider *Rmin_Slider;
    QSlider *Bmax_Slider;
    QTextBrowser *textBrowser_2;
    QSlider *Bmin_Slider;
    QTextBrowser *textBrowser;
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
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(1270, 160, 221, 501));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_5 = new QTextBrowser(widget);
        textBrowser_5->setObjectName("textBrowser_5");

        gridLayout->addWidget(textBrowser_5, 10, 0, 1, 1);

        Gmin_Slider = new QSlider(widget);
        Gmin_Slider->setObjectName("Gmin_Slider");
        Gmin_Slider->setMaximum(500);
        Gmin_Slider->setSliderPosition(420);
        Gmin_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Gmin_Slider, 3, 0, 1, 1);

        Rmax_Slider = new QSlider(widget);
        Rmax_Slider->setObjectName("Rmax_Slider");
        Rmax_Slider->setMaximum(255);
        Rmax_Slider->setSliderPosition(255);
        Rmax_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Rmax_Slider, 7, 0, 1, 1);

        textBrowser_6 = new QTextBrowser(widget);
        textBrowser_6->setObjectName("textBrowser_6");

        gridLayout->addWidget(textBrowser_6, 8, 0, 1, 1);

        textBrowser_4 = new QTextBrowser(widget);
        textBrowser_4->setObjectName("textBrowser_4");

        gridLayout->addWidget(textBrowser_4, 6, 0, 1, 1);

        textBrowser_3 = new QTextBrowser(widget);
        textBrowser_3->setObjectName("textBrowser_3");

        gridLayout->addWidget(textBrowser_3, 4, 0, 1, 1);

        Gmax_Slider = new QSlider(widget);
        Gmax_Slider->setObjectName("Gmax_Slider");
        Gmax_Slider->setMaximum(255);
        Gmax_Slider->setSliderPosition(255);
        Gmax_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Gmax_Slider, 9, 0, 1, 1);

        Rmin_Slider = new QSlider(widget);
        Rmin_Slider->setObjectName("Rmin_Slider");
        Rmin_Slider->setMaximum(150);
        Rmin_Slider->setSliderPosition(120);
        Rmin_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Rmin_Slider, 1, 0, 1, 1);

        Bmax_Slider = new QSlider(widget);
        Bmax_Slider->setObjectName("Bmax_Slider");
        Bmax_Slider->setMaximum(255);
        Bmax_Slider->setSliderPosition(255);
        Bmax_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Bmax_Slider, 11, 0, 1, 1);

        textBrowser_2 = new QTextBrowser(widget);
        textBrowser_2->setObjectName("textBrowser_2");

        gridLayout->addWidget(textBrowser_2, 2, 0, 1, 1);

        Bmin_Slider = new QSlider(widget);
        Bmin_Slider->setObjectName("Bmin_Slider");
        Bmin_Slider->setMaximum(160);
        Bmin_Slider->setSliderPosition(150);
        Bmin_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Bmin_Slider, 5, 0, 1, 1);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName("textBrowser");

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        origin_label_part = new QLabel(centralwidget);
        origin_label_part->setObjectName("origin_label_part");
        origin_label_part->setGeometry(QRect(180, 430, 270, 270));
        Thresh_label_part = new QLabel(centralwidget);
        Thresh_label_part->setObjectName("Thresh_label_part");
        Thresh_label_part->setGeometry(QRect(800, 420, 270, 270));
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
        textBrowser_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Bmax</p></body></html>", nullptr));
        textBrowser_6->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Gmax</p></body></html>", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Rmax</p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\321\213\321\201\320\276\321\202\320\260 \320\277\320\270\321\200\320\260\320\274\320\270\320\264\321\213</p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\250\320\270\321\200\320\270\320\275\320\260 \320\275\320\270\320\267\320\260 \320\277\320\270\321\200\320\260\320\274\320\270\320\264\321\213</p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\250\320\270\321\200\320\270\320\275\320\260 \320\262\320\265\321\200\321\205\320\260 \320\277\320\270\321\200\320\260\320\274\320\270\320\264\321\213</p></body></html>", nullptr));
        origin_label_part->setText(QCoreApplication::translate("MainWindow", "Origin_part", nullptr));
        Thresh_label_part->setText(QCoreApplication::translate("MainWindow", "Thresh_part", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
