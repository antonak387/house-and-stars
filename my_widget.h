#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QPainter>


class my_widget : public QWidget
{
    Q_OBJECT
public:
    explicit my_widget(QWidget *parent = nullptr);
    QImage im;


signals:
public slots:


protected:
    void paintEvent(QPaintEvent *);


};

#endif // MY_WIDGET_H
