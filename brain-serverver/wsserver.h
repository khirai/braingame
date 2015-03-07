#ifndef WSSERVER_H
#define WSSERVER_H

#include <QObject>
#include <QList>
#include <QByteArray>
#include <QStringList>
#include "csengine.h"

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)


class WsServer : public QObject
{
    Q_OBJECT
public:
    explicit WsServer(quint16 port, QObject *parent = NULL);
    ~WsServer();

    void sendMessage(QWebSocket *socket, QString message);
	//void sendFirstMessage(int voice); // sends signals and necessary info about first message in the que to UI and Csound


public Q_SLOTS:


Q_SIGNALS:
    void closed();
    void newConnection(int connectionsCount);
	void newMessage(QString name, QString messageString);



private Q_SLOTS:
    void onNewConnection();
    void processTextMessage(QString message);
    //void processBinaryMessage(QByteArray message);
    void socketDisconnected();


private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
	void sendToAll(QString message, QWebSocket *sender = NULL );
	CsEngine *cs;

};



#endif // WSSERVER_H
