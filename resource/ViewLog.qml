import QtQuick
import Logger

ViewLogForm {
    textArea.text: Logger.logs

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
        Logger.logs = ""
    }

    onIsAutoScrollChanged: {
        switchAutoScroll.checked = isAutoScroll
    }

}