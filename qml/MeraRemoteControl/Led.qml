import QtQuick 2.2

Rectangle {
    id: rectangle1
    x: 68
    y: 8
    width: 10
    height: 10
    border.width: 1
    color: "#000000"
    border.color: "#009900"
    radius: 5
    property bool statusww: true

    onStatuswwChanged: {
        console.log("lol")
        if(rectangle1.statusww == true){
             rectangle1.color = "#ff0000"
        }
        else {
             rectangle1.color = "#0000ff"
        }
    }
}
