import QtQuick 2.1
import QtQuick.Controls 1.0
import QtSensors 5.0
import MeraCar 1.4

Item {
    id: root
    width: 400
    height: 250

    Accelerometer{
        id: accel1

        dataRate: 50

        active: true
    }

    Item {
        anchors.centerIn: parent
        Button {
            id: button6
            x: 15
            y: -19
            width: 172
            height: 44
            text: qsTr("Stop")
            onClicked: {
                car.stop()
            }
        }

        Button {
            id: button5
            x: -190
            y: -19
            width: 171
            height: 44
            text: qsTr("Front")
            onClicked: {
                //car.turn(car.FRONT,1);
                car.turn(MeraCar.FRONT,1);
            }
        }

        Button {
            id: button3
            x: -190
            y: 41
            width: 80
            height: 29
            text: qsTr("Right")
            onClicked: {
                //car.turn(car.RIGHT,1);
                car.turn(MeraCar.RIGHT,1);
            }
        }

        Button {
            id: button4
            x: 76
            y: 41
            width: 83
            height: 29
            text: qsTr("Reverse")
            onClicked: {
                //car.accelerate(car.BACKWARD,1);
                car.accelerate(MeraCar.BACKWARD,1);
            }
        }

        Button {
            id: button2
            x: -190
            y: -65
            width: 80
            height: 29
            text: qsTr("Left")
            onClicked: {
                //car.turn(car.LEFT,1);
                car.turn(MeraCar.LEFT,1);
            }
        }

        Button {
            id: button1
            x: 83
            y: -59
            width: 74
            height: 23
            text: qsTr("Forward")
            onClicked: {
                car.accelerate(MeraCar.FORWARD,1);
            }
        }

        Label {
            id: label1
            x: -180
            y: -93
            text: qsTr("Label")
        }
    }
}
