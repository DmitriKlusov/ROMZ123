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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Open_Image;
    QLabel *label_image;
    QPushButton *Contur;
    QCheckBox *Color;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Open_Image = new QPushButton(centralwidget);
        Open_Image->setObjectName("Open_Image");
        Open_Image->setGeometry(QRect(240, 510, 93, 29));
        label_image = new QLabel(centralwidget);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(50, 40, 700, 451));
        Contur = new QPushButton(centralwidget);
        Contur->setObjectName("Contur");
        Contur->setGeometry(QRect(370, 510, 93, 29));
        Color = new QCheckBox(centralwidget);
        Color->setObjectName("Color");
        Color->setGeometry(QRect(490, 513, 100, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\272\320\276\320\275\321\202\321\203\321\200\320\276\320\262", nullptr));
        Open_Image->setText(QCoreApplication::translate("MainWindow", "Open_Image", nullptr));
        label_image->setText(QString());
        Contur->setText(QCoreApplication::translate("MainWindow", "Contur", nullptr));
        Color->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273. \321\206\320\262\320\265\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
