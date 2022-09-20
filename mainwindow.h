#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pcap.h>
#include <QThread>


class Worker : public QObject
{
    Q_OBJECT
public:
    Worker();
    ~Worker();
private:

public slots:
    void doWork();
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void onStartButtonPressed();

signals:
    void startWork();

private:
    Ui::MainWindow *ui;
    pcap_t *pcap;
    Worker *worker;
};


#endif // MAINWINDOW_H
