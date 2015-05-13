#ifndef SAVE_H
#define SAVE_H

#include <QDialog>
#include <QDirModel>
#include <QTreeWidget>
#include <QFileSystemModel>


namespace Ui {
class Save;
}

class Save : public QDialog
{
    Q_OBJECT

public:
    explicit Save(QWidget *parent = 0);
    ~Save();

    QString  pathf;

private slots:

    void on_listView_clicked(const QModelIndex &index);
    void on_treeView_clicked(const QModelIndex &index);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_createDir_clicked();

private:

    QFileSystemModel *mdlDir;

    Ui::Save *ui;
};

#endif // SAVE_H
