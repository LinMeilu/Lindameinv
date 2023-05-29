#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPoint>
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
// extern QList<QPoint> ListResult;

//QPoint(int x, int y);
/*方式一、返回 凸包点集，通过 Graham Scan 方法*/
QList<QPoint> MainWindow::GetConvexHullByGrahamScan(QList<QPoint> listPoint)
{
    QList<QPoint> ListResult;
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
    QList<QPoint>::iterator iter;
    for(iter=ListResult.begin();iter!=ListResult.end();iter++)
        qDebug() << *iter << " ";

    /*QListIterator<QPoint> ListResult; // 创建列表的只读迭代器，将list作为参数


        qDebug()<< "the forward is :";
        while (ListResult.hasNext())             // 正向遍历列表，结果为A，B，C，D
        qDebug()<< ListResult.next();*/
    return ListResult;
}

#endif // MAINWINDOW_H
