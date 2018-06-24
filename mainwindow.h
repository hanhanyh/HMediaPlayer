#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private :
    QMediaPlayer * mplayer;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnOpen_clicked();
    //当载入音乐后会触发这个信号 获取音乐的长度
    void durationChanged(qint64 dur);
    //播放进度改变
    void posChanged(qint64 pos);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
