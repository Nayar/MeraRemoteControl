#include "carcontroller.h"
#include <QDebug>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>

CarController::CarController(QObject *parent) :
    QObject(parent)
{
}

void CarController::accelerate(CarController::ACCELERATE_DIRECTION direction, double power)
{
    qDebug() << "Accelerating";

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QUrl url("http://192.168.1.6:8000/GPIO/11/value/1");
    url.setUserName("webiopi");
    url.setPassword("raspberry");
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->post(request,"");
    qDebug() << reply->readAll();
}

void CarController::turn(CarController::TURN_DIRECTION direction, double power)
{
    qDebug() << "Turning";
}

void CarController::stop()
{
    qDebug() << "Stop";
}
