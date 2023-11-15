//===============================================
import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
//===============================================
TextField {
    id: control

    property alias icon: icon.text

    placeholderText: qsTr("LineEdit")
    Layout.preferredWidth: parent.width - 20
    Layout.alignment: Qt.AlignHCenter
    color: mainTextCOlor
    font.pointSize: 14
    font.family: "fontawesome"
    leftPadding: 30

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 50
        radius: implicitHeight / 2
        color: "transparent"

        Text {
            id: icon
            text: "\uf015"
            font.pointSize: 14
            font.family: "fontawesome"
            color: mainAppColor
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            leftPadding: 10
        }

        Rectangle {
            width: parent.width - 10
            height: 1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            color: mainAppColor
        }
    }
}
//===============================================
