#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_minus_clicked()
{
    if ((str.isEmpty() == 0) and (str.right(1) != "-") and (str.right(1) != "+") and (str.right(1) != "x") and (str.right(1) != "/"))
        str.append("-");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_1_clicked()
{
    str.append("1");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_2_clicked()
{
    str.append("2");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_3_clicked()
{
    str.append("3");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_plus_minus_clicked()
{
    if (str.isEmpty() == 0){
        if (str[0] != "-"){
            str.prepend("-");
            ui->lineEdit->setText(str);
            return;}
        if (str[0] == "-"){
            str.remove(0, 1);}}
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_0_clicked()
{
    if (str.isEmpty() == 0)
        str.append("0");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_digit_clicked()
{
    if (str.isEmpty() == 0)
        str.append(".");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_plus_clicked()
{
    if ((str.isEmpty() == 0) and (str.right(1) != "-") and (str.right(1) != "+") and (str.right(1) != "x") and (str.right(1) != "/"))
        str.append("+");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_4_clicked()
{
    str.append("4");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_5_clicked()
{
    str.append("5");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_6_clicked()
{
    str.append("6");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_7_clicked()
{
    str.append("7");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_8_clicked()
{
    str.append("8");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_9_clicked()
{
    str.append("9");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_x_clicked()
{
    if ((str.isEmpty() == 0) and (str.right(1) != "-") and (str.right(1) != "+") and (str.right(1) != "x") and (str.right(1) != "/"))
        str.append("x");
    ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_29_clicked()
{
    str.append("(");
    ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_28_clicked()
{
    if (str.isEmpty() == 0)
        str.append(")");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_delenie_clicked()
{
    if ((str.isEmpty() == 0) and (str.right(1) != "-") and (str.right(1) != "+") and (str.right(1) != "x") and (str.right(1) != "/"))
        str.append("/");
    ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_27_clicked()
{
    if (str.isEmpty() == 0){
        str.append(")");
        str.prepend("exp(");}
    ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_26_clicked()
{
    if (str.isEmpty() == 0){
        str.append("|");
        str.prepend("|");}
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_pi_clicked()
{
    str = "3.14";
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_e_clicked()
{
    str = "2.718";
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_delet_all_clicked()
{
    str = "";
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_delet_clicked()
{
    str.chop(1);
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_exit_clicked()
{
    return;
}

void MainWindow::on_Button_comp_clicked()
{
    QString num1Text = "";
    QString num2Text = "";
    QString last = str.at(str.size() - 1);
    float rezult = 0;
    float num1 = 0;
    float num2 = 0;
    if ((str.contains("-") or str.contains("+") or str.contains("x") or str.contains("/")) and ((last == "1") or (last == "2") or (last == "3") or (last == "4") or (last == "5") or (last == "6") or (last == "7") or (last == "8") or (last == "9") or (last == "0")))
    {
        QStringList alldata = str.split(QRegExp("[-+/x]"));
        if (str.contains("-"))
        {
            num1Text = str.left(str.indexOf("-"));
            num2Text = str.right(str.size() - str.indexOf("-") - 1);
            num1 = num1Text.toFloat();
            num2 = num2Text.toFloat();
            rezult = num1-num2;
        };

        if (str.contains("+"))
        {
            num1Text = str.left(str.indexOf("+"));
            num2Text = str.right(str.size() - str.indexOf("+") - 1);
            num1 = num1Text.toFloat();
            num2 = num2Text.toFloat();
            rezult = num1+num2;
        };

        if (str.contains("x"))
        {
            num1Text = str.left(str.indexOf("x"));
            num2Text = str.right(str.size() - str.indexOf("x") - 1);
            num1 = num1Text.toFloat();
            num2 = num2Text.toFloat();
            rezult = num1*num2;
        };

        if (str.contains("/"))
        {
            num1Text = str.left(str.indexOf("/"));
            num2Text = str.right(str.size() - str.indexOf("/") - 1);
            num1 = num1Text.toFloat();
            num2 = num2Text.toFloat();
            rezult = num1/num2;
        };

        str = QString::number(rezult);
    };

    ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_9_clicked()
{
    str = "";
    ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_32_clicked()
{
    str = "";
    ui->lineEdit->setText(str);
}
