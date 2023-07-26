#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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
    void on_Button_minus_clicked();

    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();

    void on_Button_0_clicked();

    void on_Button_plus_clicked();

    void on_Button_plus_minus_clicked();

    void on_Button_digit_clicked();

    void on_Button_comp_clicked();

    void on_Button_x_clicked();

    void on_Button_delenie_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_32_clicked();

    void on_Button_pi_clicked();

    void on_Button_e_clicked();

    void on_Button_delet_all_clicked();

    void on_Button_delet_clicked();

    void on_Button_exit_clicked();

private:
    Ui::MainWindow *ui;
public:
    QString str;
//public:

};
#endif // MAINWINDOW_H
