#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QInputDialog>
class Myclass{
public:
    QList<QString> list;
    QString filepath;
    QStringList elems;
public: void write()
{
    QFile file(filepath);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Не могу открыть файл";
        return;
    }

    QTextStream out(&file);
    out.setLocale(QLocale::Russian);
    out.setCodec("UTF-8");
    int i;
    for(i=0;i<list.count(); i++)
    {
        if (i%2 ==0)
        {
            out << "Name:" << list[i] << "\n";
        }
        if (i%2 !=0)
        {
            out << "Age:" << list[i] << "\n";
        }
    }
    file.flush();
    file.close();
}

public: void read()
{
    QFile file(filepath);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Не могу открыть файл";
        return;
    }
    QTextStream in(&file);
    QTextStream out(stdout);
    QString myText = in.readAll();
    elems = myText.split("\n");
    QStringListIterator it(elems);
    while (it.hasNext()){
        out << it.next().trimmed() << "\n";
    }
    //qDebug() << myText;

    file.close();
}
public: void firstread()
{
    QFile file(filepath);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Файл ещё не создан";
        return;
    }
    QTextStream in(&file);
    QTextStream out(stdout);
    QString myText = in.readAll();
    QStringList elems2;
    elems2 = myText.split("\n");
    int i;
    for(i=0;i<elems2.count(); i++)
    {
        if (i%2 ==0)
        {
            elems2[i].remove(0, 5);
            list << elems2[i];
        }
        if (i%2 !=0)
        {
            elems2[i].remove(0, 4);
            list << elems2[i];
        }
    }
    list.removeLast();
    file.close();
}
};

int main()
{
    Myclass Test;

    Test.filepath = "D:/Qt/MyFile.txt";
    Test.firstread();
    Test.list << "Dmitri" << "30";
    Test.write();
    Test.list << "Vlad" << "20";
    Test.write();
    Test.list << "Igor" << "40";
    Test.write();
    Test.read();
    return 0;
}
