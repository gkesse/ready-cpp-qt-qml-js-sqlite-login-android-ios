//===============================================
import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
//===============================================
Page {
    id: passswordPage

    property alias username: registeredUsername.text

    background: Rectangle {
        color: backGroundColor
    }

    footer: ToolBar {
        background: Rectangle {
            implicitHeight: 50
            implicitWidth: 200
            color: "transparent"
        }

        RowLayout {
            anchors.fill: parent

            ToolButton {
                id: control
                font.family: "fontawesome"
                text: qsTr("\uf060")
                font.pointSize: 24
                rightPadding: 10

                contentItem: Text {
                    text: control.text
                    font: control.font
                    opacity: enabled ? 1.0 : 0.3
                    color: mainTextCOlor
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    color: "transparent"
                }

                onClicked: onLogout()
            }

            Item { Layout.fillWidth: true }
        }
    }

    Text {
        id: resetText
        text: qsTr("Récupération")
        font.pointSize: 24
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        color: mainTextCOlor
    }

    ColumnLayout {
        width: parent.width
        anchors.top: resetText.bottom
        anchors.topMargin: 30
        spacing: 20

        GLineEdit {
            id: registeredUsername
            icon: "\uf007"
            placeholderText: qsTr("Nom d'utilisateur")
        }

        GLineEdit {
            id: registeredHint
            icon: "\uf023"
            placeholderText: qsTr("Question secrète")
            echoMode: TextField.PasswordEchoOnEdit
        }

        Item {
            height: 20
        }

        GButtonUi {
            height: 50
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "Récupérer"
            baseColor: mainAppColor
            borderColor: mainAppColor
            onClicked: {
                var lPassword = onRetrieval(registeredUsername.text, registeredHint.text)

                if(lPassword !== "") {
                    helpText.visible = true
                    password.visible = true
                    password.text = lPassword
                }
            }
        }

        Item {
            height: 40
        }

        Text {
            id: helpText
            text: qsTr("Votre mot de passe est:")
            font.pointSize: 16
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignLeft
            leftPadding: 15
            color: mainTextCOlor
            visible: false
        }

        Text {
            id: password
            font.pointSize: 13
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignLeft
            leftPadding: 15
            color: mainTextCOlor
            visible: false
        }

        Item {
            height: 20
        }
    }
}
//===============================================
