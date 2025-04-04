// qml/LaneOffsetDisplay.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: container
    width: 200
    height: 100
    color: "#2b2b2b"
    radius: 10
    border.color: "#666"
    border.width: 1

    property int laneOffset: 0

    Row {
        anchors.centerIn: parent
        spacing: 20

        Rectangle {
            width: 50
            height: 60
            color: laneOffset === -1 ? "red" : "#444"
            radius: 5
            Text {
                anchors.centerIn: parent
                text: "←"
                font.pixelSize: 20
                color: "white"
            }
        }

        Rectangle {
            width: 50
            height: 60
            color: laneOffset === 0 ? "#00c853" : "#444"
            radius: 5
            Text {
                anchors.centerIn: parent
                text: "⬤"
                font.pixelSize: 20
                color: "white"
            }
        }

        Rectangle {
            width: 50
            height: 60
            color: laneOffset === 1 ? "red" : "#444"
            radius: 5
            Text {
                anchors.centerIn: parent
                text: "→"
                font.pixelSize: 20
                color: "white"
            }
        }
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 5
        text: laneOffset === -1 ? "Left Lane Drift" :
              laneOffset === 1 ? "Right Lane Drift" : "Center Lane"
        color: "lightgray"
        font.pixelSize: 12
    }
}
