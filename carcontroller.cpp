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
    setGPIO(11,1);
}

void CarController::turn(CarController::TURN_DIRECTION direction, double power)
{
    qDebug() << "Turning";
}

void CarController::stop()
{
    qDebug() << "Stop";
}

void CarController::setGPIO(int no, int value)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QUrl url("http://192.168.1.6:8000/GPIO/" + QString::number(no) + "/value/"+QString::number(value));
    url.setUserName("webiopi");
    url.setPassword("raspberry");
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->post(request,"");
    qDebug() << reply->readAll();
}
