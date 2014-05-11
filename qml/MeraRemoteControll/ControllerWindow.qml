import QtQuick 2.1
import QtQuick.Controls 1.0

Item {
    id: root
    width: 400
    height: 250

    Item {
        anchors.centerIn: parent
        Button {
            id: button6
            x: -13
            y: -30
            width: 172
            height: 65
            text: qsTr("Stop")
            onClicked: {
                car.stop()
            }
        }

        Button {
            id: button5
            x: -190
            y: -115
            width: 171
            height: 44
            text: qsTr("Front")
            onClicked: {
                //car.turn(car.FRONT,1);
                car.turn(0,1);
            }
        }

        Button {
            id: button3
            x: -99
            y: -65
            width: 80
            height: 29
            text: qsTr("Right")
            onClicked: {
                //car.turn(car.RIGHT,1);
                car.turn(1,1);
            }
        }

        Button {
            id: button4
            x: -13
            y: 41
            width: 172
            height: 29
            text: qsTr("Reverse")
            onClicked: {
                //car.accelerate(car.BACKWARD,1);
                car.accelerate(1,1);
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
                car.turn(2,1);
            }
        }

        Button {
            id: button1
            x: -13
            y: -115
            width: 170
            height: 79
            text: qsTr("Forward")
            onClicked: {
                car.accelerate(car.FORWARD,1);
            }
        }
    }
}
