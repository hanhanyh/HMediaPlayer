#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QFileDialog>
#include<QUrl>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mplayer=new QMediaPlayer();
    this->mplayer->setMedia(QUrl::fromLocalFile("D://CloudMusic/薛之谦 - 肆无忌惮.mp3"));
    this->mplayer->play();
    this->ui->btnstart->setText("停止");
    connect(this->mplayer,SIGNAL(durationChanged(qint64)),this,SLOT(durationChanged(qint64)));
    connect(this->mplayer,SIGNAL(positionChanged(qint64)),this,SLOT(posChanged(qint64)));
}

MainWindow::~MainWindow()
{
    delete ui;
    this->mplayer->deleteLater();
}
//打开音乐文件
void MainWindow::on_btnOpen_clicked()
{
  QMessageBox::about(this,"提示","提示");

}
void MainWindow::durationChanged(qint64 dur)
{
    qDebug()<<"载入成功获取长度"<<dur;
    this->ui->progressBar->setMaximum(dur);
    this->ui->progressBar->setMinimum(0);
    this->ui->progressBar->setValue(0);
}
void MainWindow::posChanged(qint64 pos)
{
   this->ui->progressBar->setValue(pos);
}

void MainWindow::on_btnstart_clicked()
{
    if(this->ui->btnstart->text()=="停止")
    {    this->mplayer->stop();
      this->ui->btnstart->setText("播放");
    }else{
        this->mplayer->play();
              this->ui->btnstart->setText("停止");

    }

}
