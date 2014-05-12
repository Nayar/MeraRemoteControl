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
            console.log("car done")
            car.reset();
        }
    }

    MainArea{
        id: mainArea
        anchors.fill: parent
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
