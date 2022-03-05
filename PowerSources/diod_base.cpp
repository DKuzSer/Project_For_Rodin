#include "diod_base.h"
#include "ui_diod_base.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

diod_base::diod_base(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diod_base)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);

    ID = new QTableWidgetItem(QString::fromUtf8("Марка диода"));
    ui->tableWidget->setHorizontalHeaderItem(0, ID);
    ID = new QTableWidgetItem(QString::fromUtf8("Uобр_max"));
    ui->tableWidget->setHorizontalHeaderItem(1, ID);
    ID = new QTableWidgetItem(QString::fromUtf8("Iпр"));
    ui->tableWidget->setHorizontalHeaderItem(2,ID);

//    for (int r = 0;r<ui->tableWidget->rowCount() ; r++)
//    {
//        for(int c = 0; c<ui->tableWidget->columnCount();c++)
//        {
//            QString s = QString("(%1:%2)").arg(r).arg(c);
//            ID = new QTableWidgetItem();
//            ID->setText(s);
//            ui->tableWidget->setItem(r,c,ID);
//        }
//    }

}

diod_base::~diod_base()
{
    delete ui;
}


void diod_base::on_pushButton_2_clicked()
{

    if(names_of_diods.size() != 0)
    {
        names_of_diods.clear();
        Uobr_max.clear();
        Ipr.clear();
    }

    QFile OutFile_am("Diode_brands");
    OutFile_am.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out_am(&OutFile_am);

    for(int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        out_am << ui->tableWidget->item(row,0)->text() << "\t" <<
                  ui->tableWidget->item(row,1)->text() << "\t" <<
                  ui->tableWidget->item(row,2)->text() << "\n";

        names_of_diods.push_back(ui->tableWidget->item(row,0)->text());
        Uobr_max.push_back(ui->tableWidget->item(row,1)->text().toDouble());
        Ipr.push_back(ui->tableWidget->item(row,2)->text().toDouble());
    }

    emit signal_data_update(names_of_diods,Uobr_max,Ipr);

    OutFile_am.close();

}


void diod_base::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    double Uobr = ui->doubleSpinBox_2->value();
    double Ipr = ui->doubleSpinBox_3->value();

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);

    QString s2 = QString("%1").arg(Uobr);
    QString s3 = QString("%1").arg(Ipr);

    ID = new QTableWidgetItem();
    ID->setText(name);
    ui->tableWidget->setItem(row,0,ID);

    ID = new QTableWidgetItem();
    ID->setText(s2);
    ui->tableWidget->setItem(row,1,ID);

    ID = new QTableWidgetItem();
    ID->setText(s3);
    ui->tableWidget->setItem(row,2,ID);
}


void diod_base::on_pushButton_3_clicked()
{
    int i = ui->spinBox->value();
    ui->tableWidget->removeRow(i-1);
}


void diod_base::slot_diod_base()
{
    QStringList list;
    if(names_of_diods.size() != 0)
    {
        //QMessageBox::information(this,"Error","Files uploaded");
        names_of_diods.clear();
        Uobr_max.clear();
        Ipr.clear();
    }
    QFile mFile("Diode_brands");
    if (!mFile.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::information(this,"Error","Could not open file for Reading");
        return;
    }

    QTextStream in(&mFile);
    int line_counter = 0;
    while(!in.atEnd())
        {
            QString sz = in.readLine();
            list = sz.split("\t");
            names_of_diods.push_back(list.at(0));
            Uobr_max.push_back(list.at(1).toDouble());
            Ipr.push_back(list.at(2).toDouble());
            line_counter = line_counter + 1;
        }

    ui->tableWidget->setRowCount(line_counter);

    for (int row = 0; row < line_counter ; row++)
        {
            QString s1 = QString("%1").arg(names_of_diods[row]);
            ID = new QTableWidgetItem();
            ID->setText(s1);
            ui->tableWidget->setItem(row,0,ID);

            QString s2 = QString("%1").arg(Uobr_max[row]);
            ID = new QTableWidgetItem();
            ID->setText(s2);
            ui->tableWidget->setItem(row,1,ID);

            QString s3 = QString("%1").arg(Ipr[row]);
            ID = new QTableWidgetItem();
            ID->setText(s3);
            ui->tableWidget->setItem(row,2,ID);
        }

    mFile.close();
}
