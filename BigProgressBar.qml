import QtQuick 2.6
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0

ProgressBar {
    id: pb
        padding: 2
        height : 10
        property string col:"#ffd501"
        property string colBac:"black"
//        colBac: "#eaff7c"
        property int fontSize: 18
        property int borderSize:3

        background: Rectangle {
            id:back
            color: colBac
//            border.color: col
            border.color: "yellow"
            radius: pb.borderSize
        }

        contentItem: Item {
            Rectangle {
                id: rec
                width: pb.value * (pb.width-pb.borderSize) // чтобы не вылезала на border
                height: parent.height
                radius: pb.borderSize
//                color: col
            LinearGradient {
                anchors.fill: parent
                start: Qt.point(0, 0)
                end: Qt.point(pb.width, 0)
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "green" }
                    GradientStop { position: 0.7; color: "yellow" }
                    GradientStop { position: 1.0; color: "red" }
                }
            }
            }

            Label {
                id: valLabel
                anchors.centerIn: parent
                color: col
                font.pixelSize: pb.fontSize
                x:pb.x+pb.width/4
                text: Number(pb.value*100).toString()+"%"
            }
        }

        onValueChanged: {
            if(pb.value < 0.3)
            {
                rec.color="green"
                valLabel.color="red"
            }
            else if(pb.value < 0.6)
            {
                rec.color="yellow"
                valLabel.color="red"
            }
            else{
                rec.color="#ff6d5a"
                valLabel.color="red"
            }
    }
}
