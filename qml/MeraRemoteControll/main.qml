import QtQuick 2.1
import QtQuick.Controls 1.0
import MeraCar 1.4

ApplicationWindow {
    id: applicationWindow1
    title: qsTr("Hello World")
    width: 480
    height: 640

    MeraCar {
        id: car
        username: "webiopi"
        password: "raspberry"
        ipAddress: "192.168.1.3"
        forward_GPIO: 2
        backward_GPIO: 3
        right_GPIO: 4
        left_GPIO: 17
    }



    Item {
        id: mainArea
        anchors.fill: parent

        states: [
            State {
                name: "control"
                PropertyChanges {
                    target: controllers
                    x: 0
                }
                PropertyChanges {
                    target: settings
                    x : -applicationWindow1.width
                }
            },
            State {
                name: "settings"
                PropertyChanges {
                    target: settings
                    x : 0
                }
                PropertyChanges {
                    target: controllers
                    x : -applicationWindow1.width
                }
            }
        ]

        Item {
            id: settings
            x: -applicationWindow1.width
        }

        Item {
            id: controllers
            x : 0
        }

        Item {
            id: item1
            x: 31
            y: 54
            width: 427
            height: 442
            rotation: 90
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Button {
                id: button6
                x: 111
                y: 250
                width: 172
                height: 65
                text: qsTr("Stop")
                onClicked: {
                    car.stop()
                }
            }

            Button {
                id: button5
                x: -60
                y: 87
                text: qsTr("Front")
                onClicked: {
                    //car.turn(car.FRONT,1);
                    car.turn(0,1);
                }
            }

            Button {
                id: button3
                x: 12
                y: 32
                text: qsTr("Right")
                onClicked: {
                    //car.turn(car.RIGHT,1);
                    car.turn(1,1);
                }
            }

            Button {
                id: button4
                x: 161
                y: 138
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
                x: 21
                y: 138
                text: qsTr("Left")
                onClicked: {
                    //car.turn(car.LEFT,1);
                    car.turn(2,1);
                }
            }

            Button {
                id: button1
                x: 266
                y: 7
                width: 155
                height: 73
                text: qsTr("Forward")
                onClicked: {
                    car.accelerate(car.FORWARD,1);
                }
            }
        }
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Control")
                onTriggered: {
                    mainArea.state = "control"
                }
            }
            MenuItem {
                text: qsTr("Settings")
                onTriggered: {
                    mainArea.state = "settings"
                }
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
}
