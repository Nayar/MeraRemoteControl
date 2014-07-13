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

        active: false

        onReadingChanged: {
            car.turn(-accel.reading.y/10)
        }
    }

    Slider {
        id: sliderHorizontal1
        x: 47
        y: 147
        width: 200
        height: 56
        minimumValue: -1
        value: car.gpio_right.PWM - car.gpio_left.PWM
        anchors.horizontalCenterOffset: -53
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
        x: 37
        y: 45
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
        x: 37
        y: 65
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
        x: 37
        y: 85
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
        x: 37
        y: 105
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



    CheckBox{
        x: 37
        y: 126
        text: "Accelerometer active"
        onCheckedChanged: {
            if(checked){
                accel.active = true;
            }
            else {
                accel.active = false;
            }
        }
    }


    Label {
        id: label6
        x: 36
        y: 24
        text: qsTr("WebIOPi IP Address: ") + car.ipAddress
    }

    Label {
        id: label7
        x: 250
        y: 24
        text: qsTr("Port: ") + car.portNo
    }
}
