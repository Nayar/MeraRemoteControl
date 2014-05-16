#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <QObject>
#include "gpio.h"

class GPIO;

class CarController : public QObject
{

public:
    enum ACCELERATE_DIRECTION {
        FORWARD,
        BACKWARD
    };

    enum TURN_DIRECTION {
        FRONT,
        RIGHT,
        LEFT
    };

    Q_OBJECT
    Q_ENUMS(TURN_DIRECTION)
    Q_ENUMS(ACCELERATE_DIRECTION)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString ipAddress READ ipAddress WRITE setIpAddress NOTIFY ipAddressChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(int portNo READ portNo WRITE setPortNo NOTIFY portNoChanged)
    Q_PROPERTY(GPIO *gpio_forward READ gpio_forward WRITE setGpio_forward NOTIFY gpio_forwardChanged)
    Q_PROPERTY(GPIO *gpio_backward READ gpio_backward WRITE setGpio_backward NOTIFY gpio_backwardChanged)
    Q_PROPERTY(GPIO *gpio_right READ gpio_right WRITE setGpio_right NOTIFY gpio_rightChanged)
    Q_PROPERTY(GPIO *gpio_left READ gpio_left WRITE setGpio_left NOTIFY gpio_leftChanged)
    Q_PROPERTY(ACCELERATE_DIRECTION accelerateDirection READ accelerateDirection WRITE setAccelerateDirection NOTIFY accelerateDirectionChanged)
    Q_PROPERTY(TURN_DIRECTION turnDirection READ turnDirection WRITE setTurnDirection NOTIFY turnDirectionChanged)

private:
    QString m_ipAddress;

    int m_portNo;

    QString m_username;

    QString m_password;

    bool m_carConnected;

    ACCELERATE_DIRECTION m_accelerateDirection;

    TURN_DIRECTION m_turnDirection;

    GPIO *m_gpio_forward;

    GPIO *m_gpio_backward;

    GPIO *m_gpio_right;

    GPIO *m_gpio_left;

public:

    explicit CarController(QObject *parent = 0);
    Q_INVOKABLE void accelerate(double power = 0);
    Q_INVOKABLE void turn(double power);
    Q_INVOKABLE void stop();
    Q_INVOKABLE bool connect();

    void init();
    void sendPOST(QUrl url);

    Q_INVOKABLE void reset()
    {
//        configGPIO(forward_GPIO(),out);
//        configGPIO(backward_GPIO(),out);
//        configGPIO(right_GPIO(),out);
//        configGPIO(left_GPIO(),out);
    }

    QString ipAddress() const
    {
        return m_ipAddress;
    }

    int portNo() const
    {
        return m_portNo;
    }

    QString username() const
    {
        return m_username;
    }

    QString password() const
    {
        return m_password;
    }

    bool carConnected() const
    {
        return m_carConnected;
    }

    ACCELERATE_DIRECTION accelerateDirection() const
    {
        return m_accelerateDirection;
    }

    TURN_DIRECTION turnDirection() const
    {
        return m_turnDirection;
    }

    GPIO * gpio_forward() const
    {
        return m_gpio_forward;
    }

    GPIO * gpio_backward() const
    {
        return m_gpio_backward;
    }

    GPIO * gpio_right() const
    {
        return m_gpio_right;
    }

    GPIO * gpio_left() const
    {
        return m_gpio_left;
    }

signals:

    void ipAddressChanged(QString arg);

    void forward_GPIOChanged(int arg);

    void backward_GPIOChanged(int arg);

    void right_GPIOChanged(int arg);

    void left_GPIOChanged(int arg);

    void portNoChanged(int arg);

    void usernameChanged(QString arg);

    void passwordChanged(QString arg);



    void carConnectedChanged(bool arg);

    void accelerateDirectionChanged(ACCELERATE_DIRECTION arg);

    void forward_GPIOPWMChanged(double arg);

    void turnDirectionChanged(TURN_DIRECTION arg);

    void backward_GPIOPWMChanged(double arg);

    void gpio_forwardChanged(GPIO * arg);

    void gpio_backwardChanged(GPIO * arg);

    void gpio_rightChanged(GPIO * arg);

    void gpio_leftChanged(GPIO * arg);

public slots:

    void setIpAddress(QString arg)
    {
        if (m_ipAddress != arg) {
            m_ipAddress = arg;
            reset();
            emit ipAddressChanged(arg);
        }
    }
    void setPortNo(int arg)
    {
        if (m_portNo != arg) {
            m_portNo = arg;
            reset();
            emit portNoChanged(arg);
        }
    }
    void setUsername(QString arg)
    {
        if (m_username != arg) {
            m_username = arg;
            reset();
            emit usernameChanged(arg);
        }
    }
    void setPassword(QString arg)
    {
        if (m_password != arg) {
            m_password = arg;
            reset();
            emit passwordChanged(arg);
        }
    }
    void setAccelerateDirection(ACCELERATE_DIRECTION arg)
    {
        if (m_accelerateDirection != arg) {
            m_accelerateDirection = arg;
            emit accelerateDirectionChanged(arg);
        }
    }
    void setTurnDirection(TURN_DIRECTION arg)
    {
        if (m_turnDirection != arg) {
            m_turnDirection = arg;
            emit turnDirectionChanged(arg);
        }
    }
    void setGpio_forward(GPIO * arg)
    {
        if (m_gpio_forward != arg) {
            m_gpio_forward = arg;
            emit gpio_forwardChanged(arg);
        }
    }
    void setGpio_backward(GPIO * arg)
    {
        if (m_gpio_backward != arg) {
            m_gpio_backward = arg;
            emit gpio_backwardChanged(arg);
        }
    }
    void setGpio_right(GPIO * arg)
    {
        if (m_gpio_right != arg) {
            m_gpio_right = arg;
            emit gpio_rightChanged(arg);
        }
    }
    void setGpio_left(GPIO * arg)
    {
        if (m_gpio_left != arg) {
            m_gpio_left = arg;
            emit gpio_leftChanged(arg);
        }
    }
};

#endif // CARCONTROLLER_H
