#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <QObject>

class CarController : public QObject
{
    Q_OBJECT
    Q_ENUMS(TURN_DIRECTION)
    Q_ENUMS(ACCELERATE_DIRECTION)
public:
    enum TURN_DIRECTION {
        LEFT,
        RIGHT
    };

    enum ACCELERATE_DIRECTION {
        FORWARD,
        BACKWARD
    };
    explicit CarController(QObject *parent = 0);
    void accelerate(ACCELERATE_DIRECTION direction, double power);
    void turn(TURN_DIRECTION direction, double power);
    void stop();

signals:

public slots:

};

#endif // CARCONTROLLER_H
