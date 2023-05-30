#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColor>
#include<QPainter>
#include <QPainterPath>
#include "my_widget.h"




MainWindow::MainWindow(QWidget *parent) :  //конструктор
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    QPolygon my_polygon;
    QPainter painter(&ui->widget->im);
    painter.drawLine(700,600,1200,600);
    QColor color;
    QBrush brush;
    QPen pen;
    brush.setStyle(Qt::SolidPattern);



    color.setRgb(40,40,60,255);      //земля
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    painter.drawRect(0,400,1200,400);




    color.setRgb(20,20,25,255);      //небо
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    painter.drawRect(0,0,1200,400);

    //    color.setRgb(61*0.5,43*0.5,31*0.5,255);//стена зад
    //    pen.setColor(color);
    //    painter.setPen(pen);
    //    brush.setColor(color);
    //    painter.setBrush(brush);
    //    painter.drawRect(100,430,300,125);
    //    repaint();


    color.setRgb(51,43,31,255);// стена перед
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    painter.drawRect(200,450,400,200);








    color.setRgb(51,43,31,255);//крыша
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    my_polygon.putPoints(0,3,200,450,400,300,600,450);
    painter.drawPolygon(my_polygon);



    color.setRgb(51*1.25,43*1.25,31*1.25,255);//боковая крыша
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    my_polygon.putPoints(0,4,200,350,100,430,200,450,400,300);
    painter.drawPolygon(my_polygon);



    color.setRgb(51*1.1,43*1.1,31*1.1,255);// боковая стена
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    my_polygon.putPoints(0,4,200,450,100,430,100,575,200,650);
    painter.drawPolygon(my_polygon);



    QLinearGradient linearGrad(QPointF(200,650), QPointF(200,800));
        linearGrad.setColorAt(0, Qt::black);
        color.setRgb(40,40,60,255);
        linearGrad.setColorAt(1, color);

        pen.setColor(color);
        painter.setPen(pen);
        brush.setColor(color);
        painter.setBrush(linearGrad);

        my_polygon.putPoints(0,4,448,650,525,650,875,800,750,800);
        painter.drawPolygon(my_polygon);



    color.setRgb(Qt::black);//дверь
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    my_polygon.putPoints(0,4,450,650,450,500,525,500,525,650);
    painter.drawPolygon(my_polygon);









    color.setRgb(255*0.75,250*0.75,205*0.75,255);       //окно
    pen.setColor(color);
    pen.setWidth(5);
    painter.setPen(pen);
    color.setRgb(171*0.75,205*0.75,239*0.75,255);
    brush.setColor(color);
    painter.setBrush(brush);
    my_polygon.putPoints(0,4,275,600,275,500,375,500,375,600);
    painter.drawPolygon(my_polygon);






    color.setRgb(20,20,25,255);             //море
    pen.setColor(color);
    pen.setWidth(-1);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    QPainterPath path;
    path.moveTo(700, 400);
    path.cubicTo(800, 600,  900, 700,  1000, 800);
    my_polygon.putPoints(0,4,700,400,1000,800,1200,800,1200,400);
    painter.drawPolygon(my_polygon);
    painter.drawPath(path);

    color.setRgb(Qt::black);     //линия отделяющая море от неба
    pen.setColor(color);
    pen.setWidth(1);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    painter.drawLine(700,401,1200,401);
    repaint();



}

MainWindow::~MainWindow() //дестурктор
{
    delete ui;
}

void MainWindow::on_pushButton_draw_clicked()
{
    on_pushButton_clear_clicked();      //удаляем все что было на небе до этого
    QPolygon my_polygon;
    QPainter painter(&ui->widget_2->im);
    QColor color;
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    QPen pen;
    color.setRgb(255, 243, 181, 255);
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);

    int num_stars=ui->spinBox_num->value();
    int rand_x=0,rand_y=0,rand_l_x,rand_l_y;
    int mirror_rand_y;
//    rand_x=rand() %1100;
//    rand_y=rand() %300;
 //   painter.drawEllipse(rand_x,rand_y, 100,100);


    bool fl=true;
    while(fl)
    {
        rand_x=rand() %1100;
        rand_y=rand() %300;
            if(rand_x<-4*(rand_y)+1100||4*(rand_x)<-5*(rand_y)+1800||3*(rand_x)>4*(rand_y)+300)
        {
            painter.drawEllipse(rand_x,rand_y, 100,100);

            /////
            if(rand_x>600)
            {
                mirror_rand_y=700-rand_y;
                painter.drawEllipse(rand_x,mirror_rand_y, 100,100);
            }
            /////

            fl=false;



        }
    }

        rand_l_x=rand_x;
        rand_l_y=rand_y;



        color.setRgb(225, 220, 151,255);
        pen.setColor(color);
        painter.setPen(pen);
        brush.setColor(color);
        painter.setBrush(brush);

        fl=true;
        while(fl)
        {
            rand_x=rand() %75-37.5;
            rand_y=rand() %75-37.5;
            if(((rand_x)*(rand_x)+(rand_y)*(rand_y)<1400)){
               painter.drawEllipse(rand_x+rand_l_x+37.5,rand_y+rand_l_y+37.5, 25,25);
               fl=false;

               ////
                if(rand_l_x>600)
               painter.drawEllipse(rand_x+rand_l_x+37.5,mirror_rand_y-rand_y+37.5, 25,25);
               ///

            }
        }

        color.setRgb(255,255,255,255);
        pen.setColor(color);
        painter.setPen(pen);
        brush.setColor(color);
        painter.setBrush(brush);

    for(int i = 0;i<num_stars;i++)
    {
        rand_x=rand() %1200;
        rand_y=rand() %376;
        if((rand_x<-4*(rand_y+25)+1600||4*(rand_x)<-5*(rand_y+25)+2550||3*(rand_x)>4*(rand_y+25))&&((rand_l_x-rand_x+50)*(rand_l_x-rand_x+50)+(rand_l_y-rand_y+50)*(rand_l_y-rand_y+50)  >=5625))
        {
            my_polygon.putPoints(0,8,5+rand_x,-5+rand_y,0+rand_x,-25+rand_y,-5+rand_x,-5+rand_y,-25+rand_x,0+rand_y,-5+rand_x,5+rand_y,0+rand_x,25+rand_y,5+rand_x,5+rand_y,25+rand_x,0+rand_y) ;
            painter.drawPolygon(my_polygon);

            /////
            if(rand_x>700){
                rand_y=800-rand_y;
                my_polygon.putPoints(0,8,5+rand_x,-5+rand_y,0+rand_x,-25+rand_y,-5+rand_x,-5+rand_y,-25+rand_x,0+rand_y,-5+rand_x,5+rand_y,0+rand_x,25+rand_y,5+rand_x,5+rand_y,25+rand_x,0+rand_y) ;
                painter.drawPolygon(my_polygon);
            }
            /////


        }
        else {
            i=i-1;
        }
    }

    color.setRgb(40,40,60,255);
    pen.setColor(color);
    pen.setWidth(-1);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    QPainterPath path;
    path.moveTo(700, 401);
    path.cubicTo(800, 600, 900, 700, 1000, 800);
    path.lineTo(601, 800);
    path.lineTo(601, 401);

   // my_polygon.putPoints(0,4,700,400,1000,800,1200,800,1200,400);
    //painter.drawPolygon(my_polygon);
    painter.drawPath(path);

    color.setRgb(Qt::black);
    pen.setColor(color);
    painter.setPen(pen);
    brush.setColor(color);
    painter.setBrush(brush);
    painter.drawLine(700,401,1200,401);



    QPolygon new_polygon;
    QLinearGradient linearGrad(QPointF(200,650), QPointF(200,800));
        linearGrad.setColorAt(0, Qt::black);
        color.setRgb(40,40,60,255);
        linearGrad.setColorAt(1, color);

        pen.setColor(color);
        painter.setPen(pen);
        brush.setColor(color);
        painter.setBrush(linearGrad);

        new_polygon.putPoints(0,4,448,650,525,650,875,800,750,800);
        painter.drawPolygon(new_polygon);


repaint();

}

void MainWindow::on_pushButton_clear_clicked()
{

    ui->widget_2->im.fill(0);
    repaint();

}
