import QtQuick 2.4
import Qt.example.qobjectSingleton 1.0

ViewLogForm {
    textArea.text: MyApi.logs

    textArea.onTextChanged: {
        if(isAutoScroll) {
            textArea.cursorPosition = textArea.text.length
        }
    }

    switchAutoScroll.onToggled: {
        if(!switchAutoScroll.checked){
            currentLinePosition = textArea.lineCount * prevScrollBarPosition
        }
        isAutoScroll = switchAutoScroll.checked
    }

    buttonClearLogs.onClicked: {
        currentLinePosition = 0.0
        MyApi.logs = ""
    }

    onIsAutoScrollChanged: {
        switchAutoScroll.checked = isAutoScroll
    }

}