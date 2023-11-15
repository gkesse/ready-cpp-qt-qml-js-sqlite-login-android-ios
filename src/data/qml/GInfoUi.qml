//===============================================
import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
//===============================================
Page {
    id: loginPage

    property string username: "Username"

    background: Rectangle {
        color: backGroundColor
    }

    header: ToolBar {
        background: Rectangle {
            implicitHeight: 50
            implicitWidth: 200
            color: "transparent"
        }

        RowLayout {
            anchors.fill: parent
            Item { Layout.fillWidth: true }

            ToolButton {
                id: control
                font.family: "fontawesome"
                text: qsTr("\uf08b")
                font.pointSize: 30
                rightPadding: 10

                background: Rectangle {
                    color: "transparent"
                }

                contentItem: Text {
                    text: control.text
                    font: control.font
                    opacity: enabled ? 1.0 : 0.3
                    color: mainTextCOlor
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                onClicked: onLogout()
            }
        }
    }


    Text {
        id: welcometext
        text: "Bienvenue, \n" + username
        anchors.centerIn: parent
        font.pointSize: 22
        color: mainTextCOlor
    }
}
//===============================================
