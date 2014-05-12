import QtQuick 2.1
import QtQuick.Controls 1.0
import QtSensors 5.0
import MeraCar 1.4

Item {
    id: root
    width: 400
    height: 250

    Button {
        id: button6
        x: 213
        y: 103
        width: 172
        height: 44
        text: qsTr("Stop")
        onClicked: {
            car.stop()
        }
    }

    Button {
        id: button5
        x: 8
        y: 103
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
        x: 8
        y: 163
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
        x: 274
        y: 163
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
        x: 8
        y: 57
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
        x: 281
        y: 63
        width: 74
        height: 23
        text: qsTr("Forward")
        onClicked: {
            car.accelerate(MeraCar.FORWARD,1);
        }
    }
}
