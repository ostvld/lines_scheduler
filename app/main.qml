import QtQuick 2.8
import QtQuick.Window 2.1
import QtQuick.Controls 2.1
import Qt.labs.settings 1.0
import CSC 1.0
import Integrity 1.0
import CoreProxy 0.1


Window {
    id: window
    visible: true
    width: 640
    height: 480

    Rectangle {
        anchors.fill: parent
        color: "black"
    }


    CoreProxy
    {
        id: coreProxy
    }

    Component.onCompleted: {
    }

    IntegrityView
    {
        id : button1
        coreProxy: coreProxy
    }

}
