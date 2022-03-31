import QtQuick 2.4
import QtQuick.Controls 6.2

Item {
    width: 800
    height: 200

    property alias scrollView: scrollView
    property alias textArea: textArea
    property bool isAutoScroll: true
    property bool wasScrollBarPressed: false
    property real prevScrollBarPositionWhenPressed: 0.0
    property real currentLinePosition: 0.0

    ScrollView {
        id: scrollView
        anchors.fill: parent

        // ScrollBar.vertical �� ViewLog.qml �֌��J������@��������Ȃ��������� ViewLogForm.ui.qml �֒��Ɏ����B
        // �f�U�C�i�[�ŊJ���Ƃ��̓G���[��h�����߂ɃR�����g�A�E�g���邱�ƁB
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
}
