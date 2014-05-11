import QtQuick 2.1
import QtQuick.Controls 1.0
import MeraCar 1.3

ApplicationWindow {
    title: qsTr("Hello World")
    width: 480
    height: 640

    MeraCar {
        id: car
        ipAddress: "192.168.1.3"
        forward_GPIO: 2
        backward_GPIO: 3
        right_GPIO: 4
        left_GPIO: 17
    }

    Button {
        id: button1
        x: 268
        y: 158
        width: 155
        height: 73
        text: qsTr("Forward")
        onClicked: {
            car.accelerate(car.FORWARD,1);
        }
    }

    Button {
        id: button4
        x: 268
        y: 308
        width: 155
        height: 23
        text: qsTr("Reverse")
        onClicked: {
            //car.accelerate(car.BACKWARD,1);
            car.accelerate(1,1);
        }
    }

    Button {
        id: button2
        x: 47
        y: 308
        text: qsTr("Left")
        onClicked: {
            //car.turn(car.LEFT,1);
            car.turn(2,1);
        }
    }

    Button {
        id: button3
        x: 47
        y: 202
        text: qsTr("Right")
        onClicked: {
            //car.turn(car.RIGHT,1);
            car.turn(1,1);
        }
    }



    Button {
        id: button5
        x: 47
        y: 257
        text: qsTr("Front")
        onClicked: {
            //car.turn(car.FRONT,1);
            car.turn(0,1);
        }
    }

    Button {
        id: button6
        x: 154
        y: 379
        width: 172
        height: 65
        text: qsTr("Stop")
        onClicked: {
            car.stop()
        }
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
            MenuItem {
                text: qsTr("Settings")
                onTriggered: {

                }
            }
        }
    }
}
