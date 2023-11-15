//===============================================
import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
//===============================================
Page {
    id: loginPage

    signal registerClicked()

    background: Rectangle {
        color: backGroundColor
    }

    Rectangle {
        id: iconRect
        width: parent.width
        height: parent.height / 3
        color: backGroundColor

        Text {
            id: icontext
            text: qsTr("\uf143")
            anchors.centerIn: parent
            font.pointSize: 112
            font.family: "fontawesome"
            color: mainAppColor
        }
    }

    ColumnLayout {
        width: parent.width
        anchors.top: iconRect.bottom
        spacing: 15

        GLineEdit {
            id: loginUsername
            icon: "\uf007"
            placeholderText: qsTr("Nom d'utilisateur")
        }

        GLineEdit {
            id: loginPassword
            icon: "\uf023"
            placeholderText: qsTr("Mot de passe")
            echoMode: TextField.PasswordEchoOnEdit
        }

        Item {
            height: 20
        }

        GButtonUi {
            height: 50
            Layout.preferredWidth: loginPage.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "Se connecter"
            baseColor: mainAppColor
            borderColor: mainAppColor
            onClicked: {
                onLogin(loginUsername.text, loginPassword.text)
            }
        }

        GButtonUi {
            height: 50
            Layout.preferredWidth: loginPage.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "S'inscrire"
            baseColor: "transparent"
            borderColor: mainAppColor
            onClicked: {
                stackView.push("qrc:/qml/GRegisterUi.qml", {"username": loginUsername.text, "password": loginPassword.text})
            }
        }

        Text {
            id: name
            text: "<html><style type='text/css'></style><a href='http://google.com'>Mot de passe oublié ?</a></html>"
            linkColor: mainTextCOlor
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 14
            color: mainTextCOlor
            Layout.margins: 10
            onLinkActivated: {
                onForgot(loginUsername.text)
            }
        }
    }
}
//===============================================
