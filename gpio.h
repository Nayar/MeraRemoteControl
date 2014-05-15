#ifndef GPIO_H
#define GPIO_H

#include <QObject>
#include "carcontroller.h"

class CarController;

class GPIO : public QObject
{
public:
    enum Function{
        in,
        out
    };

private:

    Q_OBJECT
    Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(double PWM READ PWM WRITE setPWM NOTIFY PWMChanged)
    Q_PROPERTY(Function function READ function WRITE setFunction NOTIFY functionChanged)

    CarController *parent;

    int m_no;

    double m_PWM;

    int m_value;

    Function m_function;

    int m_number;

public:
    explicit GPIO(QObject *parent = 0);
    bool operator !=(GPIO * other);
    void setGPIO(int no, int value);
    void setGPIO_PWM(int no, double value);
    void configGPIO(int no, Function function);

int number() const
{
    return m_no;
}

double PWM() const
{
    return m_PWM;
}

int value() const
{
    return m_value;
}

Function function() const
{
    return m_function;
}

signals:

void numberChanged(int arg);

void PWMChanged(double arg);

void valueChanged(int arg);

void functionChanged(Function arg);

public slots:

void setNumber(int arg);
void setPWM(double arg)
{
    if (m_PWM != arg) {
        m_PWM = arg;
        setGPIO_PWM(number(),arg);
        emit PWMChanged(arg);
    }
}
void setValue(int arg)
{
    if (m_value != arg) {
        m_value = arg;
        setGPIO(number(),arg);
        emit valueChanged(arg);
    }
}
void setFunction(Function arg)
{
    if (m_function != arg) {
        m_function = arg;
        configGPIO(number(),arg);
        emit functionChanged(arg);
    }
}
};

#endif // GPIO_H
