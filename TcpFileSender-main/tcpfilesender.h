#ifndef TCPFILESENDER_H
#define TCPFILESENDER_H

#include <QDialog>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>
#include <QProgressBar>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>
#include <QIntValidator> // Add this line

class TcpFileSender : public QDialog
{
    Q_OBJECT

public:
    TcpFileSender(QWidget *parent = nullptr);
    ~TcpFileSender();

private slots:
    void openFile();
    void start();
    void startTransfer();
    void updateClientProgress(qint64 numBytes);
    void startServer();
    void acceptConnection();
    void receiveFile();

private:
    QTcpSocket tcpClient;
    QTcpServer *tcpServer;
    QTcpSocket *tcpServerSocket;
    QFile *localFile;
    QFile *receivedFile;

    qint64 loadSize;
    qint64 totalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 bytesReceived;
    qint64 totalReceivedBytes;
    QString fileName;

    QProgressBar *clientProgressBar;
    QLabel *clientStatusLabel;
    QLabel *ipLabel;
    QLabel *portLabel;
    QLineEdit *ipLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *openButton;

    QProgressBar *serverProgressBar;
    QLabel *serverStatusLabel;
    QPushButton *startServerButton;
    QPushButton *quitServerButton;

    QTabWidget *tabWidget;
    QByteArray outBlock;
};

#endif // TCPFILESENDER_H
