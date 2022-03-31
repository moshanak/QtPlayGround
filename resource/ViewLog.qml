import QtQuick 2.4
import Qt.example.qobjectSingleton 1.0

ViewLogForm {
    textArea.text: MyApi.logs
/*
    textArea.onTextChanged: {
        console.log("textArea.textChanged")
        console.log(textArea.text.length)
        console.log(textArea.cursorPosition)
        console.log(textArea.lineCount)
        textArea.cursorPosition = textArea.text.length
        //console.log(scrollBarVertical.position)
    }

    textArea.onCursorPositionChanged: {
        console.log("textArea.cursorPositionChanged")
        console.log(textArea.text.length)
        console.log(textArea.cursorPosition)        
    }
*/
}