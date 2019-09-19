#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    QTcpSocket* tcpSocket;
    QTcpSocket* tcpSocket1;
    char buf[1024];
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
    //发送指令
    void send_cmd(char* msg);
    //验证服务短发过来的状态码
    void varify_states(int states);


private slots:
    void on_download_clicked();

    void on_upload_clicked();

    void on_connect_clicked();

    void connect_success();

    void recv();

    void list();
    void on_client_edit_returnPressed();

    void on_server_edit_returnPressed();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
