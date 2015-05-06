#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QPixmap>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Списочная структура");

    ui->Secondary->hide();
    ui->display->setDisabled(true);
    this->setFixedSize(415,120);

}

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
/* //добаввление числовой последовательности и распределение по спискам по одной цифре
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
       ui->display->show();
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


void MainWindow::on_addElements_clicked()
{

   QString sequence = ui->createEdit->text() + " ";
   QString s;
   int a=0; int count = 1;
   if (!sequence.isEmpty())
   {
       ui->display->setDisabled(false);
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
   on_display_clicked();
}

void MainWindow::on_down_clicked()
{
    state = 0;
    if (current->down)
    ui->value->setText(QString::number(current->down->info));
   on_display_clicked();
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
   on_display_clicked();
}

void MainWindow::on_display_clicked()
{
     this->setFixedSize(415,248);
     List1 *s = Head;

       QString s1 = ""; QString s2 = "";
       if (s->down)
           if (s==current &&  state ==0)
               s2=  s2 + "<code> <strong>" + QString::number(s->down->info) + "</strong></code>" ;
           else
               s2=  s2 + QString::number(s->down->info);
       if (s)
           if ( s == current &&  state == 1)
                 s1=  s1 + "<code><strong>" + QString::number(s->info) + "</strong></code>"  ;
              else
                 s1=  s1 + QString::number(s->info);
      if (s->next)
      {
           s=s->next;
           while (s->next)
           {
               if (s==current && state == 1)
                   s1= s1+ "->" + "< code><strong>" + QString::number(s->info) + "</strong></code>" ;
               else
               s1=  s1 + "->" + QString::number(s->info) ;
               if (s==current &&  state ==0)
                   s2=  s2 +"->" + "< code><strong>" + QString::number(s->down->info) + "</strong></code>" ;
               else
                   s2=  s2 + "->" +QString::number(s->down->info);
               s=s->next;
           }
           if (s->down)
           {
               if (s==current &&  state ==0)
                   s2=  s2 +"->" + "< code><strong>" + QString::number(s->down->info) + "</strong></code>" ;
               else
                   s2=  s2 + "->" +QString::number(s->down->info);
           }
      }
       ui->textBrowser->setText("<br>" + s1 + "<br>" + s2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Help_triggered()
{
    Dialog dialog;
    dialog.setWindowFlags(Qt::WindowFullscreenButtonHint);
    dialog.exec();
}

void MainWindow::on_refresh_clicked()
{
    on_display_clicked();
}

void MainWindow::on_record_triggered()
{
    QFile *file = new QFile("struct.txt");
    file->open(QIODevice::WriteOnly);

    this->setFixedSize(415,248);
    List1 *s = Head;

      QString s1 = ""; QString s2 = "";
      if (s->down)
          s2=  s2 + QString::number(s->down->info);
      if (s)
       s1=  s1 + QString::number(s->info);
     if (s->next)
     {
          s=s->next;
          while (s->next)
          {
              s1=  s1 + "->" + QString::number(s->info) ;
              s2=  s2 + "->" +QString::number(s->down->info);
              s=s->next;
          }
          if (s->down)
          {

                  s2=  s2 + "->" +QString::number(s->down->info);
          }
     }
     file->write(s1.toUtf8() + "\n" + s2.toUtf8());
    file->close();
}
