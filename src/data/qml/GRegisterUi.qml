//===============================================
import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
//===============================================
Page {
    id: registerPage

    property alias username: registerUsername.text
    property alias password: registerPassword.text

    background: Rectangle {
        color: backGroundColor
    }

    Text {
        id: signupText
        text: qsTr("Inscription")
        font.pointSize: 24
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        color: mainTextCOlor
    }

    ColumnLayout {
        width: parent.width
        anchors.top: signupText.bottom
        anchors.topMargin: 30
        spacing: 25

        GLineEdit {
            id: registerUsername
            icon: "\uf007"
            placeholderText: qsTr("Nom d'utilisateur")
        }

        GLineEdit {
            id: registerPassword
            icon: "\uf023"
            placeholderText: qsTr("Mot de passe")
            echoMode: TextField.PasswordEchoOnEdit
        }

        GLineEdit {
            id: registerPassword2
            icon: "\uf023"
            placeholderText: qsTr("Confirmation")
            echoMode: TextField.PasswordEchoOnEdit
        }

        GLineEdit {
            id: passwordHint
            icon: "\uf05a"
            placeholderText: qsTr("Question secrète")
        }

        Item {
            height: 20
        }

        GButtonUi {
            height: 50
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "S'inscrire"
            baseColor: mainAppColor
            borderColor: mainAppColor
            onClicked: onRegister(registerUsername.text, registerPassword.text, registerPassword2.text, passwordHint.text)
        }

        GButtonUi {
            height: 50
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "Annuler"
            baseColor: "transparent"
            borderColor: mainAppColor
            onClicked: stackView.pop()
        }
    }
}
//===============================================
