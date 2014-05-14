import QtQuick 2.1
import QtQuick.Controls 1.0
import QtSensors 5.0
import MeraCar 1.4

Item {
    id: root
    width: 400
    height: 250

    Slider {
        id: sliderHorizontal1
        x: 8
        y: 130
        width: 200
        height: 112
        minimumValue: -1
        value: 0
        anchors.horizontalCenterOffset: -92
        anchors.horizontalCenter: parent.horizontalCenter
        onValueChanged: {
            car.turn(value)
        }
    }

    Slider {
        id: sliderVertical1
        x: 314
        y: 119
        minimumValue: -1
        value: 0
        width: 78
        height: 123
        orientation: 0
        onValueChanged: {
            car.accelerate(value)
        }
    }

    ProgressBar {
        id: progressBar1
        x: 150
        y: 12
        width: 75
        height: 15
        value: car.forward_GPIOPWM
    }

    Label {
        id: label1
        x: 36
        y: 12
        text: qsTr("GPIO Forward")
    }

    ProgressBar {
        id: progressBar2
        x: 150
        y: 41
        width: 75
        height: 15
    }

    Label {
        id: label2
        x: 36
        y: 41
        text: qsTr("GPIO Forward")
    }

    ProgressBar {
        id: progressBar3
        x: 150
        y: 70
        width: 75
        height: 15
    }

    Label {
        id: label3
        x: 36
        y: 70
        text: qsTr("GPIO Forward")
    }

    ProgressBar {
        id: progressBar4
        x: 150
        y: 99
        width: 75
        height: 15
    }

    Label {
        id: label4
        x: 36
        y: 99
        text: qsTr("GPIO Forward")
    }
}
