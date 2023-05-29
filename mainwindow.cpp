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

