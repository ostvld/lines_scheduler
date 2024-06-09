import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Button {

    //    Layout.leftMargin: 20
    //    Layout.topMargin: 20
    //    Layout.rightMargin: 0
    //    Layout.bottomMargin: 20
    flat: true

    contentItem: Text {
        text: parent.text
        color: enabled ? "#d2ff06" : "#758c03"
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        color: parent.down && enabled ? "#0e5412" : "black"
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 1
        radius: 2

        //        border.width: 1
        //        border.color: "#0e5412"
        Rectangle {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: 3
            color: "#0e5412"
        }
    }
    onClicked: {
        console.log("click")
    }
}
