// qml/TrafficSignDisplay.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: container
    width: 200
    height: 90
    radius: 10
    color: "#222"
    border.color: "#aaa"
    border.width: 2

    property string trafficSign: "NONE"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Traffic Sign"
            color: "lightgray"
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }

        Rectangle {
            width: 60
            height: 45
            radius: 28
            color: trafficSign === "STOP" ? "red" :
                   trafficSign === "YIELD" ? "orange" :
                   trafficSign === "SPEED_60" ? "#3366ff" :
                   "#444"

            Text {
                anchors.centerIn: parent
                text: trafficSign === "NONE" ? "—" : trafficSign
                color: "white"
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }
}
