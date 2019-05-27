#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listAlgorithm.h"
#include <QtCore/qmath.h>

struct Point
{
    int _x;
    int _y;
    Point(int x,int y):_x(x),_y(y){}
    Point():_x(0),_y(0){}
    bool operator!=(Point pt)
    {
        return (_x!=pt._x) || (_y!=pt._y);
    }
    bool operator==(Point pt)
    {
        return (_x==pt._x) && (_y==pt._y);
    }


    bool operator>(Point &pt)
    {
        qDebug()<<"Operator > 0: "<<endl;
        int x1 = _x - 250;
        int y1 = _y - 250;
        qDebug()<<this<<" "<<&pt<<endl;
        int x2 = pt._x - 250;
        int y2 = pt._y - 250;
        qDebug()<<"Operator > 1: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<endl;
        if((x1*x1+y1*y1)==0)
            return false;
        if((x2*x2+y2*y2)==0)
            return true;
        qreal r1 = qSqrt(x1*x1+y1*y1);
        qreal r2 = qSqrt(x2*x2+y2*y2);
        qDebug()<<"Operator > 1: "<<r1<<" "<<r2<<endl;
        qreal cosP1 = x1/r1;
        qreal cosP2 = x1/r2;
        qreal acosP1 = qAcos(cosP1);
        qreal acosP2 = qAcos(cosP2);
        qreal alfa1 , alfa2;

        if(y1>0)
            alfa1 = acosP1;
        else
            alfa1 = 360 - acosP1;
        if(y2>0)
            alfa2 = acosP2;
        else
            alfa2 = 360 - acosP2;
        if(alfa1 > alfa2)
            return true;
        qDebug()<<"Operator > 2 "<<alfa1<<" "<<alfa2<<endl;
        return false;
    }
    friend ostream& operator<<(ostream &out,Point &p)
    {
        out<<p._x<<" "<<p._y;
        return out;
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); 
    void paintEvent(QPaintEvent *);

    void drawPoint(ChainList<Point>& ptList);
    ChainList<Point>* createPoints(int number);
    void mousePressEvent(QMouseEvent *e);
    void drawConvexPolygon(ChainList<Point>& ptList);
    bool checkOneLine(ChainList<Point>& ptList);
    int bottomPoint(ChainList<Point>& ptList);
    Point& findXPoint(ChainList<Point>& ptList);
    bool pointCompare(Point &x,Point &rx,Point &rrx);
    void drawLine(DLinkList<Point> &dblList);
    void sortPoints(ChainList<Point> &ptList,DLinkList<Point> &poles);
private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
