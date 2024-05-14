import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

//Item{
//    id: it
//    width: 200
//    property int colSpace: 0
//    property string text
//    property int pixelSize: 12


Label
    {
        id: lab
        text: parent.text
        font.pixelSize: 30
        color: "#21be2b"
//        x: parent.width/10
        anchors.centerIn: parent.Center
//        leftPadding: 10
        Rectangle{
            x: parent.width
            width: 1
            height: lab.height
//            anchors.right: lab.right
        }
    }

//}
