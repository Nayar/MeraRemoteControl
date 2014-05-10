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

void CarController::accelerate(CarController::ACCELERATE_DIRECTION direction, int power)
{
    if(direction == CarController::FORWARD && power == 1){
        setGPIO(backward_GPIO(),0);
        setGPIO(forward_GPIO(),1);
    }
    else if (direction == CarController::BACKWARD && power == 0){
        setGPIO(forward_GPIO(),0);
        setGPIO(backward_GPIO(),1);
    }
}

void CarController::turn(CarController::TURN_DIRECTION direction, int power)
{
    if(direction == CarController::RIGHT && power > 0){
        setGPIO(left_GPIO(),1-power);
        setGPIO(right_GPIO(),power);
    }
    else if (direction == CarController::LEFT && power > 0){
        setGPIO(right_GPIO(),1-power);
        setGPIO(left_GPIO(),power);
    }
}

void CarController::stop()
{
    qDebug() << "Stop";
    setGPIO(forward_GPIO(),0);
    //setGPIO(backward_GPIO(),0);
}

void CarController::setGPIO(int no, int value)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("http://"+ipAddress()+":8000/GPIO/" + QString::number(no) + "/value/"+QString::number(value));
    url.setUserName("webiopi");
    url.setPassword("raspberry");
    QNetworkReply *reply = manager->post(QNetworkRequest(url),"");
    qDebug() << reply->readAll();
}
