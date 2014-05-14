#ifndef GPIO_H
#define GPIO_H

#include <QObject>

class GPIO : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setNo NOTIFY noChanged)
    Q_PROPERTY(double PWM READ PWM WRITE setPWM NOTIFY PWMChanged)
    Q_PROPERTY(bool state READ state WRITE setState NOTIFY stateChanged)

    int m_no;

    double m_PWM;

    bool m_state;

public:
    explicit GPIO(QObject *parent = 0);

int id() const
{
    return m_no;
}

double PWM() const
{
    return m_PWM;
}

bool state() const
{
    return m_state;
}

signals:

void noChanged(int arg);

void PWMChanged(double arg);

void stateChanged(bool arg);

public slots:

void setNo(int arg)
{
    if (m_no != arg) {
        m_no = arg;
        emit noChanged(arg);
    }
}
void setPWM(double arg)
{
    if (m_PWM != arg) {
        m_PWM = arg;
        emit PWMChanged(arg);
    }
}
void setState(bool arg)
{
    if (m_state != arg) {
        m_state = arg;
        emit stateChanged(arg);
    }
}
};

#endif // GPIO_H
