#include "poligon.h"

poligon::poligon()
{
    x1=0;
    x2=0;
    x3=0;
    y1=0;
    y2=0;
    y3=0;
    red=0;
    green=0;
    blue=0;
    alpha=255;
}

void poligon::SetTri(int new_x1, int new_y1, int new_x2, int new_y2, int new_x3, int new_y3)
{
    x1=new_x1;
    x2=new_x2;
    x3=new_x3;
    y1=new_y1;
    y2=new_y2;
    y3=new_y3;
}

void poligon::GetTri(int &cur_x1, int &cur_y1, int &cur_x2, int &cur_y2, int &cur_x3, int &cur_y3)
{
    cur_x1=x1;
    cur_x2=x2;
    cur_x3=x3;
    cur_y1=y1;
    cur_y2=y2;
    cur_y3=y3;
}
void poligon::SetRGBA(int r, int g, int b, int a)
{
    red=r;
    green=g;
    blue=b;
    alpha=a;
}

void poligon::GetRGBA(int &r, int &g, int &b, int &a)
{
    r=red;
    g=green;
    b=blue;
    a=alpha;
}

void poligon::draw(QImage &pol)
{
    QPainter painter(&pol);
    QPen pen;
    QColor color;
    color.setRgb(red,green,blue,alpha);
    pen.setWidth(1);
    pen.setColor(color);
    painter.setPen(pen);

    painter.drawLine(x1,y1,x2,y2);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(x3,y3,x1,y1);
}
