#include "dialog.h"
#include "ui_dialog.h"

#include <QColor>
#include <QPalette>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Справка");
    QPalette p = ui->textBrowser->palette();

    p.setColor(QPalette::Base, QColor("#ECECEC"));
    ui->textBrowser->setPalette(p);

    on_AboutDev_clicked();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Help_clicked()
{
    ui->textBrowser->setText("<h3><p align='center'>Создание списочной структуры</p></h3>"
                       "<p>Для создания списочной структуры следует ввести последовательность"
                       " чисел в поле ввода, и щелкнуть по кнопке 'Добавить'. После этого "
                       "списочную структуру можно вывести, щелкнув по кнопке 'Показать'"
                       "<p>Так же можно использовать клавиши быстрого доступа.");
}

void Dialog::on_AboutDev_clicked()
{
    ui->textBrowser->setText("<h3><p align='center'>Разработчик</p></h3>"
        "<p align='center'>Разработала Сорокина Анна Александровна, "
        "<p align='center'>студентка группы А-45 "
        "<p align='center'>факультета Автоматической Электросвязи СибГУТИ.</p>"
       "<p align='center'>Новосибирск</p> <p align='center'> 2015г.</p>");
}

void Dialog::on_About_clicked()
{
    ui->textBrowser->setText("<h3><p align='center'>О программе</p></h3>"
                             "<h4><p align='center'>Вариант № 17</p></h4>"
        "<p> Программа строит списочную структуру, каждый  элемент "
                             "которой состоит из 3 полей: первое поле - для связи двух "
                             "линейных списков, второе - информационное (заполняется вводимой "
                             "последовательностью целых чисел "
                             "<p>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, 0</sub>, "
                             "<p>в которой 0 отмечает конец ввода. Число N не вводится, а подсчитывается"
                             "при вводе последовательности), третье - для связи элементов в одном "
                             "списке. Если N нечетно, то один из списков должен оказаться короче "
                             "другого. Ссылочным полням, которые никуда не ведут, должно быть "
                             "присвоено значение NIL. Ссылочная переменная S используется для "
                             "доступа к списочной структуре"
                             "<img src='scheme.jpg'> </img>");
}
