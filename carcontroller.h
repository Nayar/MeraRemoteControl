#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <QObject>

class CarController : public QObject
{
    Q_OBJECT
    Q_ENUMS(TURN_DIRECTION)
    Q_ENUMS(ACCELERATE_DIRECTION)
    Q_PROPERTY(bool carConnected READ carConnected WRITE setCarConnected NOTIFY carConnectedChanged)
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

bool m_carConnected;

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

    enum gpio_function {
        in,
        out
    };

    explicit CarController(QObject *parent = 0);
    Q_INVOKABLE void accelerate(ACCELERATE_DIRECTION direction, double power = 1);
    Q_INVOKABLE void turn(TURN_DIRECTION direction, double power = 1);
    Q_INVOKABLE void stop();

    void init();
    void setGPIO(int no, int value);
    void configGPIO(int no, gpio_function function);
    void sendPOST(QUrl url);
    Q_INVOKABLE void reset()
    {
        configGPIO(forward_GPIO(),out);
        configGPIO(backward_GPIO(),out);
        configGPIO(right_GPIO(),out);
        configGPIO(left_GPIO(),out);
    }

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

    bool carConnected() const
    {
        return m_carConnected;
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

public slots:

    void setIpAddress(QString arg)
    {
        if (m_ipAddress != arg) {
            m_ipAddress = arg;
            reset();
            emit ipAddressChanged(arg);
        }
    }
    void setForward_GPIO(int arg)
    {
        if (m_forward_GPIO != arg) {
            setGPIO(m_forward_GPIO,0);
            configGPIO(m_forward_GPIO,in);
            configGPIO(arg,out);
            m_forward_GPIO = arg;
            emit forward_GPIOChanged(arg);
        }
    }
    void setBackward_GPIO(int arg)
    {
        if (m_backward_GPIO != arg) {
            setGPIO(m_backward_GPIO,0);
            configGPIO(m_backward_GPIO,in);
            configGPIO(arg,out);
            m_backward_GPIO = arg;
            emit backward_GPIOChanged(arg);
        }
    }
    void setRight_GPIO(int arg)
    {
        if (m_right_GPIO != arg) {
            setGPIO(m_right_GPIO,0);
            configGPIO(m_right_GPIO,in);
            configGPIO(arg,out);
            m_right_GPIO = arg;
            emit right_GPIOChanged(arg);
        }
    }
    void setLeft_GPIO(int arg)
    {
        if (m_left_GPIO != arg) {
            setGPIO(m_left_GPIO,0);
            configGPIO(m_left_GPIO,in);
            configGPIO(arg,out);
            m_left_GPIO = arg;
            emit left_GPIOChanged(arg);
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
    void setCarConnected(bool arg)
    {
        if (m_carConnected != arg) {
            m_carConnected = arg;
            emit carConnectedChanged(arg);
        }
    }
};

#endif // CARCONTROLLER_H
