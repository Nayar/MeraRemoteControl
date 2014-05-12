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
        y: 70
        width: 200
        height: 112
        minimumValue: -1
        value: 0
        anchors.horizontalCenterOffset: -92
        anchors.horizontalCenter: parent.horizontalCenter
        onFocusChanged: {
            value: 0
        }
    }

    Slider {
        id: sliderVertical1
        x: 314
        y: 70
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
        x: 100
        y: 8
    }
}
