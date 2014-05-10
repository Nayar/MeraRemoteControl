#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <QObject>

class CarController : public QObject
{
    Q_OBJECT
    Q_ENUMS(TURN_DIRECTION)
    Q_ENUMS(ACCELERATE_DIRECTION)
    Q_PROPERTY(QString ipAddress READ ipAddress WRITE setIpAddress NOTIFY ipAddressChanged)
    Q_PROPERTY(int forward_GPIO READ forward_GPIO WRITE setForward_GPIO NOTIFY forward_GPIOChanged)
    Q_PROPERTY(int backward_GPIO READ backward_GPIO WRITE setBackward_GPIO NOTIFY backward_GPIOChanged)
    Q_PROPERTY(int right_GPIO READ right_GPIO WRITE setRight_GPIO NOTIFY right_GPIOChanged)
    Q_PROPERTY(int left_GPIO READ left_GPIO WRITE setLeft_GPIO NOTIFY left_GPIOChanged)

    QString m_ipAddress;

    int m_forward_GPIO;

    int m_backward_GPIO;

    int m_right_GPIO;

    int m_left_GPIO;

public:
    enum TURN_DIRECTION {
        FRONT,
        LEFT,
        RIGHT
    };

    enum ACCELERATE_DIRECTION {
        FORWARD,
        BACKWARD,
        STOP
    };

    explicit CarController(QObject *parent = 0);
    Q_INVOKABLE void accelerate(ACCELERATE_DIRECTION direction, double power = 1);
    Q_INVOKABLE void turn(TURN_DIRECTION direction, double power = 1);
    Q_INVOKABLE void stop();

    void setGPIO(int no, int value);

    QString ipAddress() const
    {
        return m_ipAddress;
    }

    int forward_GPIO() const
    {
        return m_forward_GPIO;
    }

    int backward_GPIO() const
    {
        return m_backward_GPIO;
    }

    int right_GPIO() const
    {
        return m_right_GPIO;
    }

    int left_GPIO() const
    {
        return m_left_GPIO;
    }

signals:

    void ipAddressChanged(QString arg);

    void forward_GPIOChanged(int arg);

    void backward_GPIOChanged(int arg);

    void right_GPIOChanged(int arg);

    void left_GPIOChanged(int arg);

public slots:

void setIpAddress(QString arg)
{
    if (m_ipAddress != arg) {
        m_ipAddress = arg;
        emit ipAddressChanged(arg);
    }
}
void setForward_GPIO(int arg)
{
    if (m_forward_GPIO != arg) {
        m_forward_GPIO = arg;
        emit forward_GPIOChanged(arg);
    }
}
void setBackward_GPIO(int arg)
{
    if (m_backward_GPIO != arg) {
        m_backward_GPIO = arg;
        emit backward_GPIOChanged(arg);
    }
}
void setRight_GPIO(int arg)
{
    if (m_right_GPIO != arg) {
        m_right_GPIO = arg;
        emit right_GPIOChanged(arg);
    }
}
void setLeft_GPIO(int arg)
{
    if (m_left_GPIO != arg) {
        m_left_GPIO = arg;
        emit left_GPIOChanged(arg);
    }
}
};

#endif // CARCONTROLLER_H
