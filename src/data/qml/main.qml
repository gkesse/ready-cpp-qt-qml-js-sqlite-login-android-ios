//===============================================
import QtQuick
import QtQuick.Controls.Basic
import QtQuick.LocalStorage
//===============================================
import "qrc:/js/GBackend.js" as GBackendJS
//===============================================
ApplicationWindow {
    id: rootWindow
    width: 300
    height: 600
    visible: true
    title: qsTr("ReadyApp")

    property color backGroundColor : "#394454"
    property color mainAppColor: "#6fda9c"
    property color mainTextCOlor: "#f0f0f0"
    property color popupBackGroundColor: "#b44"
    property color popupTextCOlor: "#ffffff"
    property var backendJS: GBackendJS.getObj()

    FontLoader {
        id: fontAwesome
        source: "qrc:/font/fontawesome-webfont.ttf"
    }

    StackView {
        id: stackView
        focus: true
        anchors.fill: parent
    }

    Component.onCompleted: {
        stackView.push("qrc:/qml/GLoginUi.qml")
        if(!backendJS.openDatabase()) {
            popup.popMessage = backendJS.getErrors()
            popup.open()
            return
        }
    }

    Popup {
        id: popup
        property alias popMessage: message.text

        background: Rectangle {
            implicitWidth: rootWindow.width
            implicitHeight: 60
            color: popupBackGroundColor
        }

        y: (rootWindow.height - 60)
        modal: true
        focus: true
        closePolicy: Popup.CloseOnPressOutside

        Text {
            id: message
            anchors.centerIn: parent
            font.pointSize: 12
            color: popupTextCOlor
        }

        onOpened: popupClose.start()
    }

    Timer {
        id: popupClose
        interval: 2000
        onTriggered: popup.close()
    }

    function onLogin(_username, _password) {
        if(!backendJS.onLogin(_username, _password)) {
            popup.popMessage = backendJS.getErrors()
            popup.open()
            return
        }

        onInfo(_username)
    }

    function onRegister(_username, _password, _password2, _passwordHint) {
        if(!backendJS.onRegister(_username, _password, _password2, _passwordHint)) {
            popup.popMessage = backendJS.getErrors()
            popup.open()
            return
        }

        onInfo(_username)
    }

    function onInfo(_username) {
        stackView.replace("qrc:/qml/GInfoUi.qml", {"username": _username})
    }

    function onLogout() {
        stackView.replace("qrc:/qml/GLoginUi.qml")
    }

    function onForgot(_username) {
        stackView.replace("qrc:/qml/GForgotUi.qml", {"username": _username})
    }

    function onRetrieval(_username, _passwordHint) {
        var lPassword = backendJS.onRetrieval(_username, _passwordHint)
        if(lPassword === "") {
            popup.popMessage = backendJS.getErrors()
            popup.open()
        }

        return lPassword
    }
}
//===============================================
