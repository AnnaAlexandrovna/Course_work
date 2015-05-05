#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Списочная структура");

    ui->Secondary->hide();
    ui->pushButton_2->setDisabled(true);
    this->setFixedSize(415,130);

    QPixmap right("right1.png");

    ui->next->setIcon(right);
    ui->next->setIconSize(right.size());

    QPixmap down("down1.png");

    ui->down->setIcon(down);
    ui->down->setIconSize(down.size());

    QPixmap first("start1.png");

    ui->first->setIcon(first);
    ui->first->setIconSize(first.size());


}

/*
void MainWindow::aboutDev()
{
QMessageBox::about(this, tr("О разработчике"),
tr("<h2>Разработчик</h2>"
    "<p>Разработала Сорокина Анна Александровна, "
    "<p>студентка группы А-45 "
    "факультета Автоматической Электросвязи СибГУТИ."
    "<p>Новосибирск <p> 2015г."));
}

void MainWindow::about()
{
QMessageBox::about(this, tr("О программе"),
tr("<p><h2>Вариант № 17</h2>"
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
    "<img src='scheme.jpg'> </img>"));
}
*/

void MainWindow::insertEven(List1 **s, int x)
{
    List1 *list = *s;
    List1 *previous = 0;

    while (list!=0)
    {
        previous = list;
        list=list->next;
    }

    previous->info=x;

    List1 *cur = new List1;
    cur->down=0;
    cur->info=0;
    cur->next=0;
    previous->next=cur;
}


void MainWindow::insertUneven(List1 **s, int x)
{
    List1 *list=*s;
    List2 *listDown;

    while ((list->down)!=0)
    {
        listDown=list->down;
        list=list->next;
    }

    List2 *c = new List2;
    c->back=NULL;
    c->next=0;
    c->info=x;
    listDown->next=c;
    list->down=listDown->next;
}
/*
void MainWindow::on_pushButton_clicked()
{
        {
             insertUneven(&Head,a);
        }
    }
     current=Head;state=1;
}  QString sequence = ui->createEdit->text();
   int a=0;
   if (!sequence.isEmpty())
   {
       ui->pushButton_2->show();
   }
   for (int i=0;  i <sequence.count(); i++ )
    {
        a = sequence[i].digitValue();
        if  (i == 0)
        {
            Head = new List1;
            Head->next=NULL;
            Head->down=NULL;
            Head->info=0;

            List2 *l = new List2;
            l->info=a;
            l->back=NULL;
            l->next=NULL;
            Head->down=l;
        }
        else if ( (i % 2) != 0)
        {
             insertEven(&Head,a);
        }
        else
        {
             insertUneven(&Head,a);
        }
    }
     current=Head;state=1;
}*/


void MainWindow::on_pushButton_clicked()
{
    QString sequence = ui->createEdit->text() + " ";
     QString s;
   int a=0; int count = 1;
   if (!sequence.isEmpty())
   {
       ui->pushButton_2->setDisabled(false);
   }
   for (int i=0;  i <sequence.count(); i++ )
    {
       while (sequence[i] != ' ')
       {
           s = s + sequence[i];
           a = s.toInt();
           i++;
       }
        if  (count == 1)
        {
            Head = new List1;
            Head->next=NULL;
            Head->down=NULL;
            Head->info=0;

            List2 *l = new List2;
            l->info=a;
            l->back=NULL;
            l->next=NULL;
            Head->down=l;
        }
        else if ( (count % 2) == 0)
        {
             insertEven(&Head,a);
        }
        else
        {
             insertUneven(&Head,a);
        }
    count++;
    s = "\0";
   }
     current=Head;state=1;
}

void MainWindow::on_first_clicked()
{
    ui->value->setText(QString::number(Head->info));
    current=Head;
    state = 1;
   on_pushButton_2_clicked();
}

void MainWindow::on_down_clicked()
{
    state = 0;
    if (current->down)
    ui->value->setText(QString::number(current->down->info));
   on_pushButton_2_clicked();
}

void MainWindow::on_next_clicked()
{
    if (state == 1)
    {
        if (current->next)
        {
            current=current->next;
            ui->value->setText( QString::number(current->info));
        }
   }
   else if (state == 0)
    {
        if (current->next && current->down)
        {
            current=current->next;
            ui->value->setText( QString::number(current->down->info));
            state =0;
        }
    }
   on_pushButton_2_clicked();
}

void MainWindow::on_pushButton_2_clicked()
{
         this->setFixedSize(415,255);
    List1 *s = Head;
       QString s1 = ""; QString s2 = "";
       if (s->down)
           if (s==current &&  state ==0)
               s2=  s2 + "< font color='lightskyblue'>" + QString::number(s->down->info) + "</font>" ;
           else
               s2=  s2 + QString::number(s->down->info);
       if (s)
           if ( s == current &&  state == 1)
                 s1=  s1 + "< font color='lightskyblue'>" + QString::number(s->info) + "</font>"  ;
              else
                 s1=  s1 + QString::number(s->info);
      if (s->next)
      {
           s=s->next;
           while (s->next)
           {
               if (s==current && state == 1)
                   s1= s1+ "->" + "< font color='lightskyblue'>" + QString::number(s->info) + "</font>" ;
               else
               s1=  s1 + "->" + QString::number(s->info) ;
               if (s==current &&  state ==0)
                   s2=  s2 +"->" + "< font color='lightskyblue'>" + QString::number(s->down->info) + "</font>" ;
               else
                   s2=  s2 + "->" +QString::number(s->down->info);
               s=s->next;
           }
           if (s->down)
           {
               if (s==current &&  state ==0)
                   s2=  s2 +"->" + "< font color='lightskyblue'>" + QString::number(s->down->info) + "</font>" ;
               else
                   s2=  s2 + "->" +QString::number(s->down->info);
           }
      }
       ui->textBrowser->setText(s1 + "<br>" + s2);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionHelp_triggered()
{
    Dialog dialog;
    dialog.setWindowFlags(Qt::WindowFullscreenButtonHint);
    dialog.exec();
}
