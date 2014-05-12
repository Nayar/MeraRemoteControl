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
        portNo: 8000
        forward_GPIO: 2
        backward_GPIO: 3
        right_GPIO: 4
        left_GPIO: 17

        Component.onCompleted: {
            car.reset();
        }
    }



    Item {
        id: mainArea
        anchors.fill: parent

        Component.onCompleted: {
            mainArea.state = "control"
        }

        states: [
            State {
                name: "control"
                PropertyChanges {
                    target: controllers;
                    x: 0
                    anchors.centerIn: mainArea
                }
                PropertyChanges {
                    target: settings;
                    x : parent.width
                }
            },
            State {
                name: "settings"
                PropertyChanges {
                    target: settings;
                    x : 0
                    anchors.horizontalCenter: mainArea.horizontalCenter
                }
                PropertyChanges {
                    target: controllers;
                    x : -parent.width
                }
            }

        ]

        ControllerWindow{
            id: controllers
            x: 0
            Behavior on x { SmoothedAnimation { velocity: 5000 } }
        }

        SettingsWindow{
            id: settings
            x: parent.width
            height: parent.height
            Behavior on x { SmoothedAnimation { velocity: 5000 } }
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
