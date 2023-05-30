#ifndef POLIGON_H
#define POLIGON_H

#include <QImage>
#include <QPainter>
#include <QPen>
#include<QColor>
#include <QImage>

class poligon
{
public:
    poligon();
    void draw(QImage &pol);
    void SetTri(int new_x1,int new_y1,int new_x2,int new_y2,int new_x3,int new_y3);
    void GetTri(int &cur_x1,int &cur_y1,int &cur_x2,int &cur_y2,int &cur_x3,int &cur_y3);
    void SetRGBA(int r, int g, int b, int a);
    void GetRGBA(int &r, int &g, int &b, int &a);
protected:
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int red;
    int green;
    int blue;
    int alpha;
};

#endif // POLIGON_H
