import QtQuick 2.8
import QtQuick.Controls 2.1 as Controls
import QtQuick.Layouts 1.12
import CSC 1.0
import CoreProxy 0.1


/*
 * Кнопка с иконками
 */
Rectangle {

    id: main

    property CoreProxy coreProxy

    color: "green"
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
    //    anchors {
    //        left: parent.left
    //        top: parent.top
    //        right: parent.right
    //        bottom: parent.bottom
    //        //        anchors.fill: parent
    //    }
    GridLayout {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        id: grid
        //        x: 20
        //        y: 20
        //        columnSpacing: 10

        //        rowSpacing: -2
        CSCButton {
            id: control
            text: "IntegrityView: " + this.name
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 0
            Layout.column: 0
        }

        CSCHederButton {
            id: save
            text: qsTr("Save")
            //                    onClicked: myModel.submit()
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 0
            signal infoClicked(string str)

            enabled: false

            //            anchors {
            //                left: parent.left
            //                top: parent.top
            //                right: parent.right
            //                bottom: parent.bottom
            //                //        anchors.fill: parent
            //            }
            onClicked: {
                console.log("click")

                //                        infoClicked("Information")
                //            myModel.saveAll()
            }
        }

        CSCCustomRangeSlider {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 3
            Layout.column: 0
        }

        WeekWidget {
            coreProxy: main.coreProxy
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 4
            Layout.column: 0
        }
    }

    Connections {
        target: control
        function onClicked() {
            console.log("Core version")
            console.log(coreProxy.coreVersion())
        }
    }

    Component.onCompleted: {
        console.log("Core version")
        console.log(coreProxy.coreVersion())
    }
}
