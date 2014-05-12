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

void CarController::accelerate(ACCELERATE_DIRECTION direction, double power)
{
    qDebug() << "direction" << direction;
    if((direction == FORWARD) && (power > 0)){
        qDebug() << "Forward";
        setGPIO(forward_GPIO(),1);
        setGPIO(backward_GPIO(),0);
    }
    else if ((direction == BACKWARD) && (power > 0)){
        qDebug() << "Backward";
        setGPIO(forward_GPIO(),0);
        setGPIO(backward_GPIO(),1);
    }
    else{
        setGPIO(forward_GPIO(),0);
        setGPIO(backward_GPIO(),0);
    }
}

void CarController::turn(TURN_DIRECTION direction, double power)
{
    qDebug() << "direction" << direction;
    if(direction == RIGHT && power > 0){
        qDebug() << "Right";
        setGPIO(right_GPIO(),1);
        setGPIO(left_GPIO(),0);
    }
    else if (direction == LEFT && power > 0){
        qDebug() << "Left";
        setGPIO(right_GPIO(),0);
        setGPIO(left_GPIO(),1);
    }
    else {
        qDebug() << "Front";
        setGPIO(right_GPIO(),0);
        setGPIO(left_GPIO(),0);
    }
}

void CarController::stop()
{
    qDebug() << "Stop";
    setGPIO(forward_GPIO(),0);
    setGPIO(backward_GPIO(),0);
}

void CarController::setGPIO(int no, int value)
{
    QUrl url("http://"+ipAddress()+":" + QString::number(portNo()) + "/GPIO/" + QString::number(no) + "/value/"+QString::number(value));
    sendPOST(url);
}

void CarController::configGPIO(int no, gpio_function function)
{
    QString function_string;
    if(function == in){
        function_string = "in";
    }
    else if(function == out){
        function_string = "out";
    }

    QUrl url("http://"+ipAddress()+":" + QString::number(portNo()) + "/GPIO/" + QString::number(no) + "/function/"+function_string);

    sendPOST(url);
}

void CarController::sendPOST(QUrl url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl params;
    url.setUserName(username());
    url.setPassword(password());
    qDebug() << "POSTING" << url.toString();
    QNetworkReply *reply = manager->post(QNetworkRequest(url),"");
    //qDebug() << reply->readAll();
}
