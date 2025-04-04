// Speedometer.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Shapes 1.15

Item {
    id: root
    width: 250
    height: 250

    property real speed: 0.0
    property real maxSpeed: 120.0

    Rectangle {
        id: background
        anchors.fill: parent
        color: "#1a1a1a"
        radius: width / 2
        border.color: "#333"
        border.width: 2
    }

    // Ticks
    Repeater {
        model: 13  // 0 to 120 in 10 steps
        delegate: Rectangle {
            width: 2
            height: 10
            color: "#888"
            x: root.width/2 + Math.cos(index * 15 * Math.PI / 180 - Math.PI/2) * 100 - width/2
            y: root.height/2 + Math.sin(index * 15 * Math.PI / 180 - Math.PI/2) * 100 - height/2
        }
    }

    // Needle (animated)
    Rectangle {
        id: needle
        width: 4
        height: 90
        color: "red"
        radius: 2
        anchors.centerIn: parent

        transform: Rotation {
            id: needleRotation
            origin.x: needle.width / 2
            origin.y: needle.height
            angle: (speed / maxSpeed) * 180
            Behavior on angle {
                NumberAnimation { duration: 200; easing.type: Easing.InOutQuad }
            }
        }
    }

    // Speed Text in Center
    Text {
        text: speed.toFixed(0) + " km/h"
        anchors.centerIn: parent
        font.pixelSize: 22
        font.bold: true
        color: "white"
    }
}
