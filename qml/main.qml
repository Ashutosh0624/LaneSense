import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height:600
    title: "ADAS Dashboard"

    Rectangle {
        width: parent.width
        height: parent.height
        color: "#121212"

        Column {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 30

            // 🔼 TOP: Start Button
            Row {
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                Button {
                    text: "Start ADAS"
                    onClicked: manager.startADAS()
                }
            }

            // 🔄 MIDDLE: Two-column layout
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 60
                anchors.topMargin: 30

                // 🔹 LEFT COLUMN: Speedometer
                Column {
                    spacing: 25

                    Speedometer {
                        speed: manager.sensorModel.speed
                    }
                    TrafficSignDisplay {
                        trafficSign: manager.sensorModel.trafficSign
                    }
                }

                // 🔸 RIGHT COLUMN: Distance + Blind Spots
                Column {
                    spacing: 15

                    LiveDataDisplay {
                        label: "Distance"
                        value: manager.sensorModel.objectDistance.toFixed(1) + " m"
                    }

                    LiveDataDisplay {
                        label: "Left Blind Spot"
                        value: manager.sensorModel.leftBlindSpot ? "⚠️" : "✅"
                    }

                    LiveDataDisplay {
                        label: "Right Blind Spot"
                        value: manager.sensorModel.rightBlindSpot ? "⚠️" : "✅"
                    }
                    LaneOffSetDisplay {
                        laneOffset: manager.sensorModel.laneOffset
                    }


                }
            }
        }

        // 🔻 Warning Panel at Bottom
        WarningPanel {
            id: warningPanel
        }

        // 🔁 Connect backend signal to warning panel
        Connections {
            target: manager
            onWarningUpdated: {
                warningPanel.warningText = message
            }
        }
    }
}
