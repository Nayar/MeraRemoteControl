import QtQuick 2.2
import QtQuick.Controls 1.1
import MeraCar 1.4

Flickable {
    width: 400
    height: 400
    contentHeight: grid1.height + 100

    property variant gpio_model : [2,3,4,7,8,9,10,11,17,18,22,23,24]


    Grid {
        y : 8
        anchors.horizontalCenter: parent.horizontalCenter
        id: grid1
        columns: 2
        spacing: 5
        rowSpacing: 25
        columnSpacing: 25
        horizontalItemAlignment: Grid.AlignHCenter

        Label  {
            id: text1
            x: 51
            y: 117
            text: qsTr("WebIOPI IP")
            font.pixelSize: 12
        }

        TextEdit {
            id: textEditIpAddress
            x: 166
            y: 120
            width: 125
            height: 20
            text: car.ipAddress
            font.pixelSize: 12

            Rectangle{
                anchors.fill: parent
                color: "#ffffff"
                z: -1
                radius: 3
                border.color: "#005500"
            }
        }

        Label  {
            id: text2
            x: 86
            y: 193
            text: qsTr("WebIOPI Port")
            font.pixelSize: 12
        }

        TextEdit {
            id: textEditPortNo
            x: 100
            y: 176
            width: 125
            height: 20
            text: car.portNo
            font.pixelSize: 12

            Rectangle{
                anchors.fill: parent
                color: "#ffffff"
                z: -1
                radius: 3
                border.color: "#005500"
            }
        }

        Label  {
            id: textUsername
            x: 51
            y: 117
            text: qsTr("WebIOPI Username")
            font.pixelSize: 12
        }

        TextEdit {
            id: textEditUsername
            x: 166
            y: 120
            width: 125
            height: 20
            text: car.username
            font.pixelSize: 12

            Rectangle{
                anchors.fill: parent
                color: "#ffffff"
                z: -1
                radius: 3
                border.color: "#005500"
            }
        }

        Label  {
            id: textPassword
            x: 51
            y: 117
            text: qsTr("WebIOPI Password")
            font.pixelSize: 12
        }

        TextEdit {
            id: textEditPassword
            x: 166
            y: 120
            width: 125
            height: 20
            text: car.password
            font.pixelSize: 12

            Rectangle{
                anchors.fill: parent
                color: "#ffffff"
                z: -1
                radius: 3
                border.color: "#005500"
            }
        }

        Label  {
            id: textGPIOForward
            x: 88
            y: 193
            text: qsTr("GPIO Forward")
            font.pixelSize: 12
        }

        ComboBox{
            id: comboGPIOForward
            model: gpio_model
            currentIndex: gpio_model.indexOf(car.gpio_forward.number.valueOf())
            onCurrentTextChanged: {
                car.gpio_forward.setNumber(comboGPIOForward.currentText.valueOf())
            }
        }

        Label  {
            id: text4
            x: 129
            y: 193
            text: qsTr("GPIO Backward")
            font.pixelSize: 12
        }

        ComboBox{
            id: comboGPIOBackward
            model: gpio_model
            currentIndex: gpio_model.indexOf(car.gpio_backward.number.valueOf())
            onCurrentTextChanged: {
                car.gpio_backward.setNumber(comboGPIOBackward.currentText.valueOf())
            }
        }

        Label  {
            id: text6
            x: 69
            y: 206
            text: qsTr("GPIO Right")
            font.pixelSize: 12
        }

        ComboBox{
            id: comboGPIORight
            model: gpio_model
            currentIndex: gpio_model.indexOf(car.gpio_right.number.valueOf())
            onCurrentTextChanged: {
                car.gpio_right.setNumber(comboGPIORight.currentText.valueOf())
            }
        }

        Label  {
            id: text5
            x: 69
            y: 206
            text: qsTr("GPIO Left")
            font.pixelSize: 12
        }

        ComboBox{
            id: comboGPIOLeft
            model: gpio_model
            currentIndex: gpio_model.indexOf(car.gpio_left.number.valueOf())
            onCurrentTextChanged: {
                car.gpio_left.setNumber(comboGPIOLeft.currentText.valueOf())
            }
        }
    }
    Button {
        id: button1
        x: 101
        width: 198
        height: 52
        anchors.top: grid1.bottom
        anchors.horizontalCenter: grid1.horizontalCenter
        text: qsTr("Done")
        onClicked: {
//            car.setForward_GPIO(comboGPIOForward.currentText)
//            car.setBackward_GPIO(comboGPIOBackward.currentText)
//            car.setRight_GPIO(comboGPIORight.currentText)
//            car.setLeft_GPIO(comboGPIOLeft.currentText)
            car.setIpAddress(textEditIpAddress.text)
            car.setPortNo(textEditPortNo.text.valueOf())
            car.setUsername(textEditUsername.text)
            car.setPassword(textEditPassword.text)
            car.connect();
            mainArea.state = "control"
        }

        anchors.horizontalCenterOffset: 0
        anchors.topMargin: 30
    }
}
