// WarningPanel.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: panel
    width: parent.width
    height: 60
    color: warningText.length > 0 ? "#b00020" : "transparent"
    visible: warningText.length > 0
    radius: 5
    anchors.bottom: parent.bottom
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottomMargin: 10
    z: 100

    property string warningText: ""

    Behavior on color {
        ColorAnimation { duration: 200 }
    }

    Text {
        anchors.centerIn: parent
        text: warningText
        color: "white"
        font.pixelSize: 18
        font.bold: true
    }

    // ✅ Auto-clear Timer
    Timer {
        id: clearTimer
        interval: 3000  // 3 seconds
        running: warningText.length > 0
        repeat: false
        onTriggered: warningText = ""
    }

    // 🔁 Restart timer whenever warningText changes
    onWarningTextChanged: {
        if (warningText.length > 0) {
            clearTimer.restart()
        }
    }
}
