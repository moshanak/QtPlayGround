import QtQuick 2.4
import QtQuick.Controls 6.2

Item {
    width: 800
    height: 200
    property alias textArea: textArea

    ScrollView {
        id: scrollView
        anchors.fill: parent

        TextArea {
            id: textArea
            placeholderText: "no log"
            placeholderTextColor: "#800073ff"
            readOnly: true
        }
    }
}
