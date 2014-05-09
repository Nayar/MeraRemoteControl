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

    QNetworkAccessManager manager;
    QUrl url("http://192.192.168.6/GPIO/11/function/oeut");
    QUrl params;
    QNetworkRequest request(url);
    qDebug()<< manager.post(request,"")->;
}

void CarController::turn(CarController::TURN_DIRECTION direction, double power)
{
    qDebug() << "Turning";
}

void CarController::stop()
{
    qDebug() << "Stop";
}
