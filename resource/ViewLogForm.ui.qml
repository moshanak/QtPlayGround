import QtQuick 2.4
import QtQuick.Controls 6.2

Item {
    width: 800
    height: 200
    property alias scrollView: scrollView
    property alias textArea: textArea
    property bool test: false
    property real test2: 0.0
    property real test3: -1.0
    property bool lasttext: true
    property int lastpos: 0

    ScrollView {
        id: scrollView
        anchors.fill: parent

        ScrollBar.vertical{
            policy: ScrollBar.AlwaysOn

            onPositionChanged: {
                console.log("test")
                console.log(ScrollBar.vertical.position)
                console.log(ScrollBar.vertical.size)
                //ScrollBar.vertical.position = 1
                console.log(textArea.cursorPosition)
                console.log(ScrollBar.vertical.pressed)
                console.log(textArea.topInset )
                if(ScrollBar.vertical.pressed){
                    test = true
                    test2 = ScrollBar.vertical.position
                    test3 = -1
                }else{
                    if(test){
                        ScrollBar.vertical.position = test2
                        test3 = textArea.lineCount * test2
                        console.log("test3: " + test3)
                        test = false
                    }
                }

                if(0 <= test3){
                    ScrollBar.vertical.position = test3 / textArea.lineCount
                }
            }
        }

/*
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn

        ScrollBar.vertical.onPositionChanged: {
            console.log("test")
            console.log(ScrollBar.vertical.position)
            //ScrollBar.vertical.position = 1
        }
*/

        TextArea {
            id: textArea
            placeholderText: "no log"
            placeholderTextColor: "#800073ff"
            readOnly: true
            selectByMouse: true

            onTextChanged: {
                console.log(textArea.text.length)
                console.log(textArea.cursorPosition)
                if(lasttext){
                    textArea.cursorPosition = textArea.text.length
                }else{
                    textArea.cursorPosition = lastpos
                    console.log("textArea.cursorPosition: " + lastpos)
                }
                if(0 <= test3){
                    scrollView.ScrollBar.vertical.position = test3 / textArea.lineCount
                }
            }
            onCursorPositionChanged:{
                console.log("test" + textArea.cursorPosition)
                if(textArea.cursorPosition != textArea.text.length){
                    if(textArea.cursorPosition != 0){
                        lasttext = false
                        lastpos = textArea.cursorPosition
                        console.log("onCursorPositionChangedtextArea.cursorPosition: " + textArea.cursorPosition)
                    }
                }
            }

        }
    }
}
