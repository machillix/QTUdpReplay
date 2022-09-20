#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Worker* worker = new Worker();
    QThread* thread = new QThread();
    worker->moveToThread(thread);
    thread->start();

    connect(this, SIGNAL(startWork()),worker,SLOT(doWork()));

    // Start Button Signal
    connect(ui->startButton, SIGNAL(pressed()),this,SLOT(onStartButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartButtonPressed()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap = pcap_open_offline(ui->pcapFilePath->text().toLocal8Bit(),errbuf);

    if(NULL == pcap)
    {
        ui->errorText->setText(QString(errbuf));
    }
    emit startWork();
}

Worker::Worker()
{
}

Worker::~Worker()
{
}
void Worker::doWork()
{
    while(true){
        QThread::usleep(1);
    }
}
