import QtQuick
import QtQuick.Window
import SceneGraph

import QtQuick.Controls
import Qt.labs.platform as Platform

Item {
    SceneGraph {
    }

    Button {
        id: button
        x: 263
        y: 228
        text: qsTr("Button")
        onClicked: {
            console.log("test")
            test.open()
        }
    }

    Platform.ColorDialog{
        id: test
    }
}
