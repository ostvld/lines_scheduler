import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CSC 1.0
import CoreProxy 0.1

GridLayout {
    id: grid
    x: 20
    y: 20
    columnSpacing: 10
    rowSpacing: -2

    property CoreProxy coreProxy
    property Model m_modelMediator
    property int pixelSize: 30

    property int objId: 0
    property bool isShowLabel: false
    property int week: 0
    property int maxValue: 100

    property int line1From: 0
    property int line1To: 0

    property int line2MWFrom: 0
    property int line2MWTo: 0

    property int line2MarsFrom: 0
    property int line2MarsTo: 0

    property int line2CrispFrom: 0
    property int line2CrispTo: 0

    property int line3MWFrom: 0
    property int line3MWTo: 0

    property int line3MarsFrom: 0
    property int line3MarsTo: 0

    property int line3SNKFrom: 0
    property int line3SNKTo: 0

    rows: 19
    columns: 8

    Component.onCompleted: {

        console.log("Core version")
        console.log(grid.coreProxy.coreVersion())
        //        coreProxy.slotInfo(
        //                    /*                    "objId:" + objId + "     week:" + week
        //                    + "     maxValue:" + maxValue + "     line1From:" + line1From
        //                    + "     line1To:" + line1To + "     line2MWFrom:" + line2MWFrom
        //                    + "     line2MWTo:" + line2MWTo + "     line2MarsFrom:" + line2MarsFrom
        //                    + "     line2MarsTo:" + line2MarsTo + "     line2CrispFrom:" + line2CrispFrom
        //                    + "     line2CrispTo:" + line2CrispTo + "     line3MWFrom:" + line3MWFrom
        //                    + "     line3MWTo:" + line3MWTo + "     line3MarsFrom:" + line3MarsFrom
        //                    + "     line3MarsTo:" + line3MarsTo + "     line3SNKFrom:" + line3SNKFrom
        //                    + "     line3SNKTo:" + line3SNKTo + */ "      complited. ")
    }

    //    Label {
    //        text: qsTr(" ")
    //        color: "#21be2b"
    //        visible: isShowLabel
    //        font.pixelSize: grid.pixelSize
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 0
    //        Layout.column: 0
    //    }

    //    Label {
    //        text: qsTr('Line 1')
    //        color: "#21be2b"
    //        visible: isShowLabel
    //        font.pixelSize: grid.pixelSize
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 1
    //        Layout.column: 0
    //    }

    //    Label {
    //        text: qsTr('Line 2 MW')
    //        color: "#21be2b"
    //        visible: isShowLabel
    //        font.pixelSize: grid.pixelSize
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 2
    //        Layout.column: 0
    //    }

    //    Label {
    //        text: qsTr('Line 2 Mars')
    //        color: "#21be2b"
    //        visible: isShowLabel
    //        font.pixelSize: grid.pixelSize
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 3
    //        Layout.column: 0
    //    }

    //    Label {
    //        text: qsTr('Line 2 Crisp')
    //        color: "#21be2b"
    //        visible: isShowLabel
    //        font.pixelSize: grid.pixelSize
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 4
    //        Layout.column: 0
    //    }

    //    Label {
    //        text: qsTr('Line 3 MW')
    //        color: "#21be2b"
    //        visible: isShowLabel
    //        font.pixelSize: grid.pixelSize
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 5
    //        Layout.column: 0
    //    }

    //    Label {
    //        text: qsTr('Line 3 Mars')
    //        color: "#21be2b"
    //        visible: isShowLabel
    //        font.pixelSize: grid.pixelSize
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 6
    //        Layout.column: 0
    //    }

    //    Label {
    //        text: qsTr('Line 3 SNK')
    //        color: "#21be2b"
    //        visible: isShowLabel
    //        font.pixelSize: grid.pixelSize
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 7
    //        Layout.column: 0
    //    }

    //    CSCLabelRightBorder {
    //        id: mon
    //        text: qsTr('Mon.')
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 0
    //        Layout.column: 1
    //    }

    //    CSCLabelRightBorder {
    //        text: qsTr('Tue.')
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 0
    //        Layout.column: 2
    //    }

    //    CSCLabelRightBorder {
    //        text: qsTr('Wed.')
    //        Layout.fillHeight: false
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 0
    //        Layout.column: 3
    //    }

    //    CSCLabelRightBorder {
    //        text: qsTr('Thu.')
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 0
    //        Layout.column: 4
    //    }

    //    CSCLabelRightBorder {
    //        text: qsTr('Fri.')
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 0
    //        Layout.column: 5
    //    }

    //    CSCLabelRightBorder {
    //        text: qsTr('Sat.')
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 0
    //        Layout.column: 6
    //    }

    //    CSCLabelRightBorder {
    //        text: qsTr('Sun.')
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.columnSpan: 1
    //        Layout.rowSpan: 1
    //        Layout.row: 0
    //        Layout.column: 7
    //    }

    //    CSCCustomRangeSlider {
    //        id: line1

    //        //        signal line1FirstMoved(int objId, int real)
    //        first.value: line1From
    //        second.value: line1To
    //        to: maxValue
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.row: 1
    //        Layout.column: 1
    //        Layout.columnSpan: 7
    //        Layout.rowSpan: 1
    //        first.onMoved: {
    //            parent.setVal()
    //            //            modelMediator.setFi(objId)
    //            m_modelMediator.setLineValueByName(objId, "Line1From", first.value)
    //        }
    //        second.onMoved: {
    //            m_modelMediator.setLineValueByName(objId, "Line1To", second.value)
    //        }
    //    }

    //    CSCCustomRangeSlider {
    //        id: line2MW
    //        first.value: line2MWFrom
    //        second.value: line2MWTo
    //        to: maxValue
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.row: 2
    //        Layout.column: 1
    //        Layout.columnSpan: 7
    //        Layout.rowSpan: 1
    //        first.onMoved: {
    //            parent.setVal()
    //            //            modelMediator.setFi(objId)
    //            m_modelMediator.setLineValueByName(objId, "Line2MWFrom",
    //                                               first.value)
    //        }
    //        second.onMoved: {
    //            m_modelMediator.setLineValueByName(objId, "Line2MWTo", second.value)
    //        }
    //    }

    //    CSCCustomRangeSlider {
    //        id: line2Mars
    //        first.value: line2MarsFrom
    //        second.value: line2MarsTo
    //        to: maxValue
    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.row: 3
    //        Layout.column: 1
    //        Layout.columnSpan: 7
    //        Layout.rowSpan: 1
    //        first.onMoved: {
    //            parent.setVal()
    //            //            modelMediator.setFi(objId)
    //            m_modelMediator.setLineValueByName(objId, "Line2MarsFrom",
    //                                               first.value)
    //        }
    //        second.onMoved: {
    //            m_modelMediator.setLineValueByName(objId, "Line2MarsTo",
    //                                               second.value)
    //        }
    //    }

    //    CSCCustomRangeSlider {
    //        id: line2Crisp
    //        first.value: line2CrispFrom
    //        second.value: line2CrispTo
    //        to: maxValue

    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.row: 4
    //        Layout.column: 1
    //        Layout.columnSpan: 7
    //        Layout.rowSpan: 1
    //        first.onMoved: {
    //            parent.setVal()
    //            //            modelMediator.setFi(objId)
    //            m_modelMediator.setLineValueByName(objId, "Line2CrispFrom",
    //                                               first.value)
    //        }
    //        second.onMoved: {
    //            m_modelMediator.setLineValueByName(objId, "Line2CrispTo",
    //                                               second.value)
    //        }
    //    }

    //    CSCCustomRangeSlider {
    //        id: line3MW
    //        first.value: line3MWFrom
    //        second.value: line3MWTo
    //        to: maxValue

    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.row: 5
    //        Layout.column: 1
    //        Layout.columnSpan: 7
    //        Layout.rowSpan: 1
    //        first.onMoved: {
    //            parent.setVal()
    //            //            modelMediator.setFi(objId)
    //            m_modelMediator.setLineValueByName(objId, "Line3MWFrom",
    //                                               first.value)
    //        }
    //        second.onMoved: {
    //            m_modelMediator.setLineValueByName(objId, "Line3MWTo", second.value)
    //        }
    //    }

    //    CSCCustomRangeSlider {
    //        id: line3Mars
    //        first.value: line3MarsFrom
    //        second.value: line3MarsTo
    //        to: maxValue

    //        Layout.fillHeight: true
    //        Layout.fillWidth: true
    //        Layout.row: 6
    //        Layout.column: 1
    //        Layout.columnSpan: 7
    //        Layout.rowSpan: 1
    //        first.onMoved: {
    //            parent.setVal()
    //            //            modelMediator.setFi(objId)
    //            m_modelMediator.setLineValueByName(objId, "Line3MarsFrom",
    //                                               first.value)
    //        }
    //        second.onMoved: {
    //            m_modelMediator.setLineValueByName(objId, "Line3MarsTo",
    //                                               second.value)
    //        }
    //    }
    CSCCustomRangeSlider {

        signal infoClicked(string str)
        id: line3SNK
        objectName: "line3SNK"
        first.value: line3SNKFrom
        second.value: line3SNKTo
        to: maxValue

        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.row: 7
        Layout.column: 1
        Layout.columnSpan: 7
        Layout.rowSpan: 1
        first.onMoved: {
            console.log("Core version")
            console.log(grid.coreProxy.coreVersion())
            grid.coreProxy.setInfo("test")
            //            parent.setVal()
            //            modelMediator.setFi(objId)
            //            m_modelMediator.setLineValueByName(objId, "Line3SNKFrom",
            //                                               first.value)
        }
        second.onMoved: {
            console.log("Core version")
            console.log(grid.coreProxy.coreVersion())
            grid.coreProxy.setInfo("test")
            //            m_modelMediator.setLineValueByName(objId, "Line3SNKTo",
            //                                               second.value)
        }
    }
}
