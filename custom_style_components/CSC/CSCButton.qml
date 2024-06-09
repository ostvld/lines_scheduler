import QtQuick 2.8
import QtQuick.Controls 2.1 as Controls

Controls.Button {
    id: control

    property string name: "CSCButton"

    background: Rectangle {
            anchors.fill: parent
            opacity: enabled ? 1 : 0.3
            color: "#00aa00"
        }
}
