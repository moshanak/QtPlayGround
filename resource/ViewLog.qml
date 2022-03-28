import QtQuick 2.4
import Qt.example.qobjectSingleton 1.0

ViewLogForm {

    Component.onCompleted: {
        console.log(MyApi.doSomething())
    }
}