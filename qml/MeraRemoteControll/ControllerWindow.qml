import QtQuick 2.1
import QtQuick.Controls 1.0
import QtSensors 5.0
import MeraCar 1.4

Item {
    id: root
    width: 400
    height: 250

    Accelerometer {
        id: accel

        dataRate: 10

        active: true

        onReadingChanged: {
            car.turn(-accel.reading.y/10)
        }
    }

    Slider {
        id: sliderHorizontal1
        x: 8
        y: 130
        width: 200
        height: 112
        minimumValue: -1
        value: car.gpio_right.PWM - car.gpio_left.PWM
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

    Label {
        id: label1
        x: 36
        y: 20
        text: qsTr("GPIO ") + car.gpio_forward.number

        ProgressBar {
            id: progressBar1
            x: 150
            y: 0
            width: 75
            height: 15
            value: car.gpio_forward.PWM

            Label {
                anchors.centerIn: parent
                text: car.gpio_forward.PWM.toFixed(2)
            }

        }
    }


    Label {
        id: label2
        x: 36
        y: 40
        text: qsTr("GPIO ") + car.gpio_backward.number

        ProgressBar {
            id: progressBar2
            x: 150
            y: 0
            width: 75
            height: 15
            value: car.gpio_backward.PWM

            Label {
                anchors.centerIn: parent
                text: car.gpio_backward.PWM.toFixed(2)
            }
        }
    }






    Label {
        id: label3
        x: 36
        y: 60
        text: qsTr("GPIO ") + car.gpio_right.number

        ProgressBar {
            id: progressBar3
            x: 150
            y: 0
            width: 75
            height: 15
            value: car.gpio_right.PWM

            Label {
                anchors.centerIn: parent
                text: car.gpio_right.PWM.toFixed(2)
            }
        }

    }

    Label {
        id: label4
        x: 36
        y: 80
        text: qsTr("GPIO ") + car.gpio_left.number

        ProgressBar {
            id: progressBar4
            x: 150
            y: 0
            width: 75
            height: 15
            value: car.gpio_left.PWM
            Label {
                anchors.centerIn: parent
                text: car.gpio_left.PWM.toFixed(2)
            }
        }
    }

    Label {
        id: label5
        x: 36
        y: 101
        text: qsTr("Acceleromter Turning")
        CheckBox{
            x: -40
            onCheckedChanged: {
                if(checked){
                    accel.active = true;
                }
                else {
                    accel.active = false;
                }
            }
        }
    }
}
