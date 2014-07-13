#include "carcontroller.h"
#include <QDebug>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>

CarController::CarController(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Constructor starting";
    qDebug() << m_ipAddress;
    m_gpio_forward = new GPIO(this);
    m_gpio_backward = new GPIO(this);
    m_gpio_right = new GPIO(this);
    m_gpio_left = new GPIO(this);
}

bool CarController::connect()
{
    m_gpio_forward->setFunction(GPIO::out);
    m_gpio_backward->setFunction(GPIO::out);
    m_gpio_right->setFunction(GPIO::out);
    m_gpio_left->setFunction(GPIO::out);
    return true;
}

void CarController::accelerate(double power)
{
    if(power > 0.2){
        if(accelerateDirection() != FORWARD){
            qDebug() << "Forward";
            gpio_forward()->setValue(1);
            gpio_backward()->setValue(0);
            setAccelerateDirection(FORWARD);
        }
        gpio_forward()->setPWM(power);
        gpio_forward()->setValue(1);
    }
    else if (power < -0.2){
        if(accelerateDirection() != BACKWARD){
            qDebug() << "Backward";
            gpio_forward()->setValue(0);
            gpio_backward()->setValue(1);
            setAccelerateDirection(BACKWARD);
        }
        gpio_backward()->setPWM(-power);
        gpio_backward()->setValue(1);
    }
    else{
        gpio_forward()->setValue(0);
        gpio_forward()->setPWM(0);
        gpio_backward()->setValue(0);
        gpio_backward()->setPWM(0);
    }
}

void CarController::turn(double power)
{
    GPIO *pinToBeActivated;
    GPIO *pinToBeActivatedComplement;
    bool setupRequired = false;

    if(power > 0.2){
        pinToBeActivated = gpio_right();
        pinToBeActivatedComplement = gpio_left();
        if(turnDirection() != RIGHT){
            setTurnDirection(RIGHT);
            setupRequired = true;
        }
    }
    else if (power < -0.2){
        pinToBeActivated = gpio_left();
        pinToBeActivatedComplement = gpio_right();
        if(turnDirection() != LEFT){
            setupRequired = true;
            setTurnDirection(LEFT);
        }
        power = -power;
    }
    else {
        //qDebug() << "Front";
        gpio_right()->setValue(0);
        gpio_right()->setPWM(0);
        gpio_left()->setValue(0);
        gpio_left()->setPWM(0);
        return;
    }
    if(setupRequired){
        pinToBeActivatedComplement->setValue(0);
        pinToBeActivated->setValue(1);
    }
    pinToBeActivated->setPWM(power);
}

void CarController::stop()
{
    qDebug() << "Stop";
    this->accelerate(0);
    this->turn(0);
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
