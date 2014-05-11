import QtQuick 2.1
import QtQuick.Controls 1.0

Item {
    id: root
    width: 427
    height: 442
    rotation: 90

    Button {
        id: button6
        x: 216
        y: 199
        width: 172
        height: 65
        text: qsTr("Stop")
        onClicked: {
            car.stop()
        }
    }

    Button {
        id: button5
        x: 14
        y: 171
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
        x: 105
        y: 241
        text: qsTr("Right")
        onClicked: {
            //car.turn(car.RIGHT,1);
            car.turn(1,1);
        }
    }

    Button {
        id: button4
        x: 216
        y: 287
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
        x: 14
        y: 241
        text: qsTr("Left")
        onClicked: {
            //car.turn(car.LEFT,1);
            car.turn(2,1);
        }
    }

    Button {
        id: button1
        x: 216
        y: 102
        width: 172
        height: 73
        text: qsTr("Forward")
        onClicked: {
            car.accelerate(car.FORWARD,1);
        }
    }
}

