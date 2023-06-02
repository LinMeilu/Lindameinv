#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPoint>
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QPen>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QPoint> GetConvexHullByGrahamScan(QList<QPoint> listPoint);
    double Get2DistancePP(QPoint p1,QPoint p2);

public:
    //void paintEvent(QPaintEvent *);
private:
    Ui::MainWindow *ui;



};
// extern QList<QPoint> ListResult;

//QPoint(int x, int y);

#endif // MAINWINDOW_H
