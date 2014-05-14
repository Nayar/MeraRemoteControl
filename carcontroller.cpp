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

void CarController::accelerate(double power)
{
    if(power > 0.2){
        if(accelerateDirection() != FORWARD){
            qDebug() << "Forward";
            setGPIO(forward_GPIO(),1);
            setGPIO(backward_GPIO(),0);
            setAccelerateDirection(FORWARD);
        }
        setForward_GPIOPWM(power);
    }
    else if (power < -0.2){
        if(accelerateDirection() != BACKWARD){
            qDebug() << "Backward";
            setGPIO(forward_GPIO(),0);
            setGPIO(backward_GPIO(),1);
            setAccelerateDirection(BACKWARD);
        }
        setGPIO_PWM(backward_GPIO(),-power);
    }
    else{
        setGPIO(forward_GPIO(),0);
        setForward_GPIOPWM(0);
        setGPIO(backward_GPIO(),0);
    }
}

void CarController::turn(double power)
{
    int pinToBeActivated;
    int pinToBeActivatedComplement;
    bool setupRequired = false;

    if(power > 0.2){
        pinToBeActivated = right_GPIO();
        pinToBeActivatedComplement = left_GPIO();
        if(turnDirection() != RIGHT){
            setTurnDirection(RIGHT);
            setupRequired = true;
        }
    }
    else if (power < -0.2){
        pinToBeActivated = left_GPIO();
        pinToBeActivatedComplement = right_GPIO();
        if(turnDirection() != LEFT){
            setupRequired = true;
            setTurnDirection(LEFT);
        }
    }
    else {
        qDebug() << "Front";
        setGPIO(right_GPIO(),0);
        setGPIO(left_GPIO(),0);
        return;
    }
    if(setupRequired){
        setGPIO(pinToBeActivatedComplement,0);
        setGPIO(pinToBeActivated,1);
    }
    setGPIO_PWM(pinToBeActivated,power);
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

void CarController::setGPIO_PWM(int no, double value)
{
    QUrl url("http://"+ipAddress()+":" + QString::number(portNo()) + "/GPIO/" + QString::number(no) + "/pulseRatio/"+QString::number(value));
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
