#include "save.h"
#include "ui_save.h"
#include <QDir>
#include <QFileSystemModel>
#include <QFileInfo>
#include <iostream>
#include <mainwindow.h>

using namespace std;

Save::Save(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save)
{
    ui->setupUi(this);
    this->setWindowTitle("Сохранить");
    //connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));

    mdlDir = new QFileSystemModel(this);
    mdlDir->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    mdlDir->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    mdlDir->setRootPath("/");

    ui->listView->setModel(mdlDir);
    QModelIndex idx = mdlDir->index("/home/anna");
    ui->listView->setRootIndex(idx);
    pathf = mdlDir->filePath(idx);
}


void Save::on_listView_clicked(const QModelIndex &index)
{
    ui->treeView->setModel(mdlDir);
   ui->treeView->setRootIndex(index);
   ui->label_3->setText( mdlDir->filePath(index));
    pathf = mdlDir->filePath(index);
}

Save::~Save()
{
    delete ui;
}

void Save::on_treeView_clicked(const QModelIndex &index)
{
    ui->treeView->setModel(mdlDir);
    ui->treeView->setRootIndex(index);
    ui->label_3->setText( mdlDir->filePath(index));
    pathf = mdlDir->filePath(index);
}

void Save::on_pushButton_clicked()
{

    pathf = pathf + "/" + ui->lineEdit->text() + ".txt";
    close();
}

void Save::on_pushButton_2_clicked()
{
    close();
}
