#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawPoint(ChainList<Point>& ptList)
{
    QPainter painter(this);

    painter.setBrush(Qt::SolidPattern);
    int number = ptList->size();
    for(int i=0;i<number;i++)
    {
        QPoint pt(ptList->get(i)._x,ptList->get(i)._y);
        painter.drawEllipse(pt,2,2);
      //  painter.drawPoint(pt);
  //      qDebug()<<i<<" : "<<pt<<endl;
    }
}

ChainList<Point> *MainWindow::createPoints(int number)
{
    ChainList<Point> *ptList = new ChainList<Point>;
    srand((unsigned)time(0));
    srand(rand());
    srand(rand());
    for(int i=0;i<number;i++)
    {
        int x = rand()%400+50;
        int y = rand()%400+50;
        Point *pt = new Point(x,y);
        ptList->insert(0,*pt);
    }
    return ptList;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    update();
}

void MainWindow::drawConvexPolygon(ChainList<Point> &ptList)
{
     int size = ptList.size();
    if(size<3)
        return;
    if(checkOneLine(ptList))
        return;
    int xIndex = bottomPoint(ptList);
    qDebug()<<"Draw COnverx Polygon 1"<<endl;
    DLinkList<Point> *dblList = new DLinkList<Point>;
    ChainList<Point> *sigList = new ChainList<Point>(ptList);
    sortPoints(*sigList,*dblList);
    qDebug()<<"Draw COnverx Polygon 2 "<<xIndex<<endl;
//    sortPoints(ptList,*dblList);
    xIndex = dblList->indexOf(ptList.get(xIndex));
    qDebug()<<"Draw COnverx Polygon 2 "<<xIndex<<endl;
    Point p,x,rx,rrx;
    p = dblList->get(xIndex);
    qDebug()<<"Draw COnverx Polygon 2"<<endl;
    for(x=p,rx=dblList->get(xIndex+1);p!=rx;)
    {
        rrx = dblList->get(dblList->indexOf(rx)+1);
        if(pointCompare(x,rx,rrx))
        {
            dblList->erase(dblList->indexOf(rx));
            rx = x;
            x = dblList->get(dblList->indexOf(rx)-1);
        }
        else
        {
            x = rx;
            rx = rrx;
        }
    }
    drawLine(*dblList);
}

bool MainWindow::checkOneLine(ChainList<Point> &ptList)
{
    int size = ptList.size();
    int x1 = ptList.get(0)._x;
    int y1 = ptList.get(0)._y;
    int x2 = ptList.get(1)._x;
    int y2 = ptList.get(1)._y;
    int dx = x2-x1;
    int dy = y2-y1;
    for(int i=2;i<size;i++)
    {
        int x3 = ptList.get(i)._x;
        int y3 = ptList.get(i)._y;
        int dx2 = x3-x1;
        int dy2 = y3-y1;
        if(dx*dy2 != dy*dx2)
            return false;
    }
    return true;
}

int MainWindow::bottomPoint(ChainList<Point> &ptList)
{
    int size = ptList.size();
    int numth = 0;
    for(int i=1;i<size;i++)
    {
        if(ptList.get(numth)._y<ptList.get(i)._y)
            numth = i;
    }
    return numth;
}

Point &MainWindow::findXPoint(ChainList<Point> &ptList)
{
    int x=0, y=0, size=ptList.size();
    for(int i=0;i<size;i++)
    {
        x+=ptList.get(i)._x;
        y+=ptList.get(i)._y;
    }
    x = x/size;
    y = y/size;
    return *(new Point(x,y));
}

bool MainWindow::pointCompare(Point &x, Point &rx, Point &rrx)
{
    int x1 = x._x;
    int y1 = x._y;
    int x2 = rx._x;
    int y2 = rx._y;
    int x3 = rrx._x;
    int y3 = rrx._y;
    int dy =  (x3-x1)*(x2-x1)-(y2-y1)*(y3-y1);
    if(dy<0)
        return true;
    else
        return false;
}

void MainWindow::drawLine(DLinkList<Point> &dblList)
{
    QPainter painter(this);
    int size = dblList.size();
    for(int i=0;i<size;i++)
    {
        int x1 = dblList.get(i)._x;
        int y1 = dblList.get(i)._y;
        int x2 = dblList.get(i+1)._x;
        int y2 = dblList.get(i+1)._y;
        painter.drawLine(x1,y1,x2,y2);
    }
}

void MainWindow::sortPoints(ChainList<Point> &ptList, DLinkList<Point> &poles)
{

    int size = ptList.size();

    for(int i=0;i<size;i++)
    {
        int index = 0;
        for(int j=1;j<ptList.size();j++)
        {
            qDebug()<<"Sort 1 "<<j << " " <<index<<" "<<endl;
            if(ptList.get(index)>ptList.get(j))
            {
                index = j;
                qDebug()<<"Sort 2 "<<j << " " <<index<<endl;
            }

        }

        poles.insert(i,ptList.get(index));
        ptList.erase(index);

    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    int number = 100;
    ChainList<Point>* ptList = createPoints(number);
    drawPoint(*ptList);
    drawConvexPolygon(*ptList);
}


