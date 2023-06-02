#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QListIterator>
#include <QMutableListIterator>
#include <QDebug>
#include <QPoint>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::Get2DistancePP(QPoint p1,QPoint p2)
{
    return(sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+(p1.y()-p2.y())*(p1.y()-p2.y())));
}

QList<QPoint> MainWindow::GetConvexHullByGrahamScan(QList<QPoint> listPoint)
{ QList<QPoint> ListResult;
    //QList<QPoint> ListResult;
    int i = 0, j = 0,k=0;
    QPoint tmP = listPoint[0];

    //排序 找到最下且偏左的点
    for (i = 1; i < listPoint.size(); i++)
    {
        if ((listPoint[i].y() < tmP.y()) || ((listPoint[i].y() == tmP.y()) && (listPoint[i].x() < tmP.x())))
        {
            tmP = listPoint[i];
            k = i;
        }
    }
    listPoint[k] = listPoint[0];
    listPoint[0] = tmP;

    //排序 按极角从小到大，距离从近到远
    for (i = 1; i < listPoint.size(); i++)
    {
        k = i;
        for (j = i + 1; j < listPoint.size(); j++)
        {

            double disance_j = Get2DistancePP(listPoint[0], listPoint[j]);
            double disance_k = Get2DistancePP(listPoint[0], listPoint[k]);

        }
        tmP = listPoint[i];
        listPoint[i] = listPoint[k];
        listPoint[k] = tmP;
    }

    //添加第一、二个凸包点
    ListResult.append(listPoint[0]);
    ListResult.append(listPoint[1]);


    for (i = 2; i < listPoint.size(); ++i)
    {

        ListResult.append(listPoint[i]);
    }
    qDebug()<<"hhh";
    QList<QPoint>::iterator iter;
    for(iter=ListResult.begin();iter!=ListResult.end();iter++)
        qDebug() << *iter << " ";

    // 创建列表的只读迭代器，将list作为参数



}
/*void MainWindow::paintEvent(QPaintEvent *)
{
    /*QPen pen;

    QRectF rectangle1(10.0, 100.0, 80.0, 80.0);
    QPainter painter(this);
    painter.drawEllipse();
    QPainter painter(this);
    painter.setPen(QPen(Qt::blue,4));//设置画笔形式
    painter.setBrush(QColor(255,0,0));//设置画刷，如果不画实现的直接把Brush设置为setBrush(Qt::NoBrush);
    painter.drawEllipse(20,20,200,200);//画圆
    painter.drawPoint(120,120);
}*/
