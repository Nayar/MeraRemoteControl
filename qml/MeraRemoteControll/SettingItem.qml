import QtQuick 2.2
import QtQuick.Controls 1.1

Item {
    id: root
    width: 400
    height: 400
    Text {
        id: key
        text: qsTr("IP")
    }

    TextInput {
        id: value
        x: 31
        y: 67
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }
}
