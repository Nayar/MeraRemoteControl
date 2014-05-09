import QtQuick 2.1
import QtQuick.Controls 1.0
import MeraCar 1.0

ApplicationWindow {
    title: qsTr("Hello World")
    width: 480
    height: 640

    MeraCar {
        id: car
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Button {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
