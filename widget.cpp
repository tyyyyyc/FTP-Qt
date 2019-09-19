#include <string.h>
#include "widget.h"
#include "ui_widget.h"
#include <dirent.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket;
    tcpSocket1 = new QTcpSocket;
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connect_success()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv()));
    connect(tcpSocket1,SIGNAL(readyRead()),this,SLOT(list()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connect_success()
{
    ui->download->setEnabled(true);
    ui->upload->setEnabled(true);
    ui->connect->setEnabled(true);

    QIcon icon_dir("./image/dir.png");
    QIcon icon_text("./image/text.png");
    //显示客户端初始目录
    DIR* dp = opendir("./");
    for(struct dirent* de = readdir(dp) ; NULL != de ; de = readdir(dp))
    {
        if(strcmp(".",de->d_name))
        {
            if(DT_DIR == de->d_type)
            {
                QListWidgetItem* item = new QListWidgetItem(icon_dir,de->d_name);
                ui->client->addItem(item);
            }
            else
            {
                QListWidgetItem* item = new QListWidgetItem(icon_text,de->d_name);
                ui->client->addItem(item);
            }
        }
    }

    char buf[256] = {};
    sprintf(buf,"PASV\n");
    tcpSocket->write(buf,strlen(buf));
    bzero(buf,sizeof(buf));

    //发送list
    sprintf(buf,"LIST -al\n");
    tcpSocket->write(buf,strlen(buf));
}

void Widget::list()
{
    //显示服务端初始目录
    qDebug("****recv***");
    bzero(buf,sizeof(buf));
    int ret = 0;
    char* temp = buf;
    while(ret = tcpSocket1->read(temp,sizeof(buf)))
    {
        while(true)
        {
            char filename[256] = {};
            sscanf(temp,"%*s %*d %*d %*d %*d %*s %*d %*s %s",filename);
            char* p = strchr(temp,'\n');
            //if()
            temp++;
            qDebug("filename:%s",filename);
        }
    }

}

void Widget::recv()
{
    qDebug("-----recv-----");
    char buf[256] = {};
    tcpSocket->read(buf,sizeof(buf));
    qDebug("%s",buf);
    if(strstr(buf,"("))
    {
        qDebug("-------------tyc--------");
        unsigned char ip1,ip2,ip3,ip4,port1,port2;
        sscanf(strchr(buf,'(')+1,"%hhu,%hhu,%hhu,%hhu,%hhu,%hhu",&ip1,&ip2,&ip3,&ip4,&port1,&port2);
        sprintf(buf,"%hhu.%hhu.%hhu.%hhu",ip1,ip2,ip3,ip4);
        qDebug("%s",buf);
        tcpSocket1->abort();//取消已有连接，重置套接字
        tcpSocket1->connectToHost(buf,port1*256+port2);
    }
}

void Widget::on_download_clicked()
{
    QIcon icon("./image/dir.png");
    QListWidgetItem* item = new QListWidgetItem(icon,"FileName");
    ui->client->addItem(item);
}

void Widget::on_upload_clicked()
{
    QIcon icon("./image/dir.png");
    QListWidgetItem* item = new QListWidgetItem(icon,"tyc");
    ui->server->addItem(item);
}

void Widget::on_connect_clicked()
{
    char buf[256] = {};
    tcpSocket->connectToHost(ui->ip_edit->text().toStdString().c_str(),ui->port_edit->text().toInt());
    sprintf(buf,"USER %s\n",ui->name_edit->text().toStdString().c_str());
    //发送用户名
    int ret = tcpSocket->write(buf,strlen(buf));
    qDebug("--ret:%d--",ret);
    bzero(buf,sizeof(buf));
    sprintf(buf,"PASS %s\n",ui->pass_edit->text().toStdString().c_str());
    //发送密码
    int ret1 = tcpSocket->write(buf,strlen(buf));
    qDebug("----ret1:%d----",ret1);
    bzero(buf,sizeof(buf));
    sprintf(buf,"SYST\n");
    tcpSocket->write(buf,strlen(buf));
    bzero(buf,sizeof(buf));

    sprintf(buf,"FEAT\n");
    tcpSocket->write(buf,strlen(buf));
    bzero(buf,sizeof(buf));

    sprintf(buf,"OPTS UTF8 ON\n");
    tcpSocket->write(buf,strlen(buf));
    bzero(buf,sizeof(buf));

    sprintf(buf,"PWD\n");
    tcpSocket->write(buf,strlen(buf));
 //   tcpSocket->waitForBytesWritten();
    bzero(buf,sizeof(buf));
/*    char* path_start = strstr(buf,"\"")+1;
    char* path_end = strstr(path_start,"\"");
    *path_end = '\0';
    ui->server_edit->setText(path_start);
    */
}

void Widget::on_client_edit_returnPressed()
{

}

void Widget::on_server_edit_returnPressed()
{

}
