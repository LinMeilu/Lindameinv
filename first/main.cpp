#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<iostream>
#include <QList>
#include <QListIterator>
#include <QMutableListIterator>
#include <QDebug>
#include <QPoint>
#include <QApplication>
#include <QPixmap>
#include <QPainter>

#include <QPen>
#include <QBrush>


   int main(int argc, char *argv[])
{
       qDebug()<<"aaaaa";
    QApplication a(argc, argv);
qDebug()<<"bbbbb";
    QPoint p1(0,0);
    QPoint p2(10,10);
    QPoint p3(5,5);
    QPoint p4(10,0);
    QPoint p5(0,10);
    /*p1(0,0);
    p2(10,10);
    p3(5,5);
    p4(10,0);
    p5(0,10);
    p1.x=0;
    p1.y=0;
    p2.x=10;
    p2.y=10;
    p3.x=5;
    p3.y=5;
    p4.x=10;
    p4.y=0;
    p5.x=0;
    p5.y=10;*/

    //static QList<QPoint> ListResult;
qDebug()<<"ccccc";
    QList<QPoint> listPoint={p1,p2,p3,p4,p5};
qDebug()<<"dddd";
    listPoint[0]=p1;
    listPoint[1]=p2;
    listPoint[2]=p3;
    listPoint[3]=p4;
    listPoint[4]=p5;
    qDebug()<<"eeeee";
    MainWindow w;
qDebug()<<"ffff";
    w.GetConvexHullByGrahamScan(listPoint);
qDebug()<<"gggg";
     /*QListIterator<QPoint> i(ListResult); // 创建列表的只读迭代器，将list作为参数

    qDebug()<< "the forward is :";
    while (i.hasNext())             // 正向遍历列表，结果为A，B，C，D
        qDebug()<< i.next();*/

    w.show();
    return a.exec();


}
