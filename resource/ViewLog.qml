import QtQuick 2.4
import Qt.example.qobjectSingleton 1.0

ViewLogForm {
    textArea.text: MyApi.logs
    textArea.onTextChanged: {
        if(isAutoScroll) {
            textArea.cursorPosition = textArea.text.length
        }
    }
}