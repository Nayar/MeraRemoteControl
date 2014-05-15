#include "gpio.h"
#include "carcontroller.h"
#include <QUrl>

GPIO::GPIO(QObject *parent) :
    QObject(parent)
{
    this->parent = (CarController *) parent;
}

bool GPIO::operator !=(GPIO *other)
{
    return (this->number() != other->number());
}

void GPIO::setGPIO(int no, int value)
{
    QUrl url("http://" + parent->ipAddress() + ":" + QString::number(parent->portNo()) + "/GPIO/" + QString::number(no) + "/value/"+ QString::number(value));
    parent->sendPOST(url);
}

void GPIO::setGPIO_PWM(int no, double value)
{
    QUrl url("http://"+parent->ipAddress()+":" + QString::number(parent->portNo()) + "/GPIO/" + QString::number(no) + "/pulseRatio/"+QString::number(value));
    parent->sendPOST(url);
}

void GPIO::configGPIO(int no, Function function)
{
    QString function_string;
    if(function == in){
        function_string = "in";
    }
    else if(function == out){
        function_string = "out";
    }

    QUrl url("http://"+parent->ipAddress()+":" + QString::number(parent->portNo()) + "/GPIO/" + QString::number(no) + "/function/"+function_string);

    parent->sendPOST(url);
}

void GPIO::setNumber(int arg)
{
    if (m_no != arg) {
        configGPIO(m_no,in);
        m_no = arg;
        configGPIO(m_no,out);
        emit numberChanged(arg);
    }
}
