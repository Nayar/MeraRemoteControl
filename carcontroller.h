#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <QObject>

class CarController : public QObject
{
    Q_OBJECT
    Q_ENUMS(TURN_DIRECTION)
    Q_ENUMS(ACCELERATE_DIRECTION)
    Q_PROPERTY(QString ipAddress READ ipAddress WRITE setIpAddress NOTIFY ipAddressChanged)
    Q_PROPERTY(int portNo READ portNo WRITE setPortNo NOTIFY portNoChanged)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)

    Q_PROPERTY(int forward_GPIO READ forward_GPIO WRITE setForward_GPIO NOTIFY forward_GPIOChanged)
    Q_PROPERTY(int backward_GPIO READ backward_GPIO WRITE setBackward_GPIO NOTIFY backward_GPIOChanged)
    Q_PROPERTY(int right_GPIO READ right_GPIO WRITE setRight_GPIO NOTIFY right_GPIOChanged)
    Q_PROPERTY(int left_GPIO READ left_GPIO WRITE setLeft_GPIO NOTIFY left_GPIOChanged)

    QString m_ipAddress;

    int m_forward_GPIO;

    int m_backward_GPIO;

    int m_right_GPIO;

    int m_left_GPIO;

    int m_portNo;

    QString m_username;

QString m_password;

public:
    enum TURN_DIRECTION {
        FRONT,
        RIGHT,
        LEFT
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

signals:

    void ipAddressChanged(QString arg);

    void forward_GPIOChanged(int arg);

    void backward_GPIOChanged(int arg);

    void right_GPIOChanged(int arg);

    void left_GPIOChanged(int arg);

    void portNoChanged(int arg);

    void usernameChanged(QString arg);

    void passwordChanged(QString arg);

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
    void setPortNo(int arg)
    {
        if (m_portNo != arg) {
            m_portNo = arg;
            emit portNoChanged(arg);
        }
    }
    void setUsername(QString arg)
    {
        if (m_username != arg) {
            m_username = arg;
            emit usernameChanged(arg);
        }
    }
    void setPassword(QString arg)
    {
        if (m_password != arg) {
            m_password = arg;
            emit passwordChanged(arg);
        }
    }
};

#endif // CARCONTROLLER_H
