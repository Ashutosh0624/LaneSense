import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: container
    width: 200
    height: 80
    radius: 10
    color: "#2d2d30"
    border.color: "#555"
    border.width: 1

    property string label: "Label"
    property string value: "--"

    Column {
        anchors.centerIn: parent
        spacing: 4

        Text {
            text: container.label
            color: "#ccc"
            font.pixelSize: 14
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            text: container.value
            color: "white"
            font.bold: true
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
