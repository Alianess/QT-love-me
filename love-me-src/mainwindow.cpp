#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = 0, y = 0;
    qDebug() << event->x() << " " << event->y() << " " << flag;
    x = event->x();
    y = event->y();
    if(x > 100 && x < 200 && y > 200 && y < 250 && flag >= 0 && flag <= 4)
    {
        on_pushButton_2_clicked();
    }
    if(x > 330 && x < 430 && y > 200 && y < 250 && flag == 0)
    {
        ui->label_3->setGeometry(40,80,100,50);
        ui->label->setText("不行，不可以点这个！！");
        ui->label_5->setText(" ");
        flag += 1;
    }
    if(x > 40 && x < 140 && y > 80 && y < 130 && flag == 1)
    {
        ui->label_3->setGeometry(170,280,100,50);
        ui->label->setText("你还点这个！");
        ui->label_5->setText("要不开心了 呜呜呜");
        flag += 1;
    }
    if(x > 170 && x < 270 && y > 280 && y < 330 && flag == 2)
    {
        ui->label_3->setGeometry(240,130,100,50);
        ui->label->setText("喜欢我嘛~~点那个好不好嘛~");
        ui->label_5->setText(" ");
        flag += 1;
    }
    if(x > 240 && x < 340 && y > 130 && y < 180 && flag == 3)
    {
        ui->label_3->setGeometry(350,300,100,50);
        ui->label->setText("再给最后一次机会！！哼");
        ui->label_5->setText("要生气了哦 后果很严重的！！");
        flag += 1;
    }
    if(x > 350 && x < 450 && y > 300 && y < 350 && flag == 4)
    {
        ui->label_2->setGeometry(130,150,250,150);
        ui->label_3->setGeometry(430,310,50,25);
        ui->label->setText("哼唧 就不让你选");
        ui->label_5->setText("气鼓鼓  ٩(๑`^´๑)۶");
        flag += 1;
    }
    if(x > 430 && x < 480 && y > 325 && y < 350 && flag == 5)
    {
        ui->label_2->setGeometry(600,150,1,1);
        ui->label_3->setGeometry(600,310,1,1);
        ui->label->setText("生气了 哄不好的那种");
        ui->label_5->setText("关你电脑 哼！");
        on_pushButton_clicked();

    }
    if(x > 130 && x < 380 && y > 150 && y < 300 && flag == 5)
    {
        on_pushButton_2_clicked();
    }

}

//延时函数
void MainWindow::sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);

    while(QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_pushButton_clicked()
{
    QString program = "C:/WINDOWS/system32/shutdown.exe";
    QStringList arguments;
    arguments << "-s";
    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
}

void MainWindow::on_pushButton_2_clicked()
{
    love = new Form;
    love->show();
    sleep(3000);
    love->close();
    QApplication::closeAllWindows();
}
