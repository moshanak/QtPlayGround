import QtQuick 2.4
import QtQuick.Controls 6.2

Item {
    id: item1
    width: 1000
    height: 200
    property alias scrollView: scrollView
    property alias textArea: textArea
    property alias buttonClearLogs: buttonClearLogs
    property alias switchAutoScroll: switchAutoScroll
    property bool isAutoScroll: true
    property bool wasScrollBarPressed: false
    property real prevScrollBarPosition: 0.0
    property real prevScrollBarPositionWhenPressed: 0.0
    property real currentLinePosition: 0.0

    ScrollView {
        id: scrollView
        anchors.fill: parent

        // ScrollBar.vertical を ViewLog.qml へ公開する方法が分からなかったため ViewLogForm.ui.qml へ直に実装。
        // デザイナーで開くときはエラーを防ぐためにコメントアウトすること。
        ScrollBar.vertical{
            policy: ScrollBar.AlwaysOn
            onPositionChanged: {
                if(ScrollBar.vertical.pressed){
                    wasScrollBarPressed = true
                    prevScrollBarPositionWhenPressed = ScrollBar.vertical.position
                }else{
                    if(wasScrollBarPressed){
                        isAutoScroll = false
                        currentLinePosition = textArea.lineCount * prevScrollBarPositionWhenPressed
                        wasScrollBarPressed = false
                    }

                    if(!isAutoScroll){
                        ScrollBar.vertical.position = currentLinePosition / textArea.lineCount
                    }
                }
                prevScrollBarPosition = ScrollBar.vertical.position
            }
        }

        TextArea {
            id: textArea
            placeholderText: "no log"
            placeholderTextColor: "#800073ff"
            readOnly: true
            selectByMouse: true
        }
    }

    Switch {
        id: switchAutoScroll
        text: "auto scroll"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 20
        checked: true
    }

    Button {
        id: buttonClearLogs
        text: "clear logs"
        anchors.left: switchAutoScroll.left
        anchors.top: switchAutoScroll.bottom
    }
}
