import QtQuick 2.2
import QtQuick.Controls 1.1
import MeraCar 1.4

Grid {
    id: grid1
    columns: 2
    spacing: 5
    rowSpacing: 25
    columnSpacing: 25
    horizontalItemAlignment: Grid.AlignHCenter
    verticalItemAlignment: Grid.AlignHCenter

    Text {
        id: text1
        x: 51
        y: 117
        text: qsTr("Text")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit1
        x: 166
        y: 120
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 86
        y: 193
        text: qsTr("Text")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit2
        x: 100
        y: 176
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    Text {
        id: text3
        x: 88
        y: 193
        text: qsTr("Text")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit3
        x: 160
        y: 178
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    Text {
        id: text4
        x: 129
        y: 193
        text: qsTr("Text")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit4
        x: 101
        y: 201
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    Text {
        id: text5
        x: 69
        y: 206
        text: qsTr("Text")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit5
        x: 93
        y: 190
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }
}
