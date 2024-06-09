import QtQuick 2.6
import QtQuick.Controls 2.12

RangeSlider {
    id: control
    from: 0
    to: 100
    first.value: 0
    second.value: 0
    stepSize: 1
    property string backcolor: "#0e5412"
    property string frontcolor: "#21be2b"

    background: Rectangle {
        x: control.leftPadding
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 200
        implicitHeight: 40
        width: control.availableWidth
        height: implicitHeight
        radius: 2
        color: backcolor

        Rectangle {
            x: control.first.visualPosition * parent.width
            width: control.second.visualPosition * parent.width - x
            height: parent.height
            color: frontcolor
            radius: 2
        }
    }

    first.handle: Rectangle {
        id: lefthandle
        x: control.leftPadding + control.first.visualPosition * (control.availableWidth - width)
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 12
        implicitHeight: 40
        radius: 13
        color: control.first.pressed ? "#f6f6a6" : "#f6f6f6"
        border.color: "#bdbebf"
    }

    second.handle: Rectangle {
        id: righthandle
        x: control.leftPadding + control.second.visualPosition * (control.availableWidth - width)
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 12
        implicitHeight: 40
        radius: 13
        color: control.second.pressed ? "#f6f6a6" : "#f6f6f6"
        border.color: "#bdbebf"
    }

    function labelCoord() {
        let coord = control.width / 2
        let min = Math.trunc(first.value)
        let max = Math.trunc(second.value)
        if (0.4 * to < max && max < 0.65 * to) {
            coord = 3 * control.width / 4
        } else if (0.4 * to < min && min < 0.65 * to) {
            coord = 1 * control.width / 4
        } else {
            coord = control.width / 2 - control.width / 10
        }
        return coord
    }

    Label {
        id: valLabel
        //        anchors.horizontalCenter: control.horizontalCenter
        color: "#d2ff06"
        font.pixelSize: 30
        x: labelCoord()
        //        y: -10
        text: {
            let min = first.value
            let max = second.value
            Number(Math.trunc((second.value - first.value))).toString() + "%"
        }
    }
    first.onMoved: {
        console.log(first.value)
        //        console.log(valLabel.x)
    }
    second.onMoved: {
        console.log(second.value)
    }

    function setFirstValue(variable) {
        if (second.value < variable) {
            return false
        }
        setValues(variable, second.value)
        return true
    }

    function getFirstValue() {
        return first.value
    }

    function setSecondValue(variable) {
        if (first.value > variable) {
            return false
        }
        setValues(first.value, variable)
        return true
    }

    function getSecondValue() {
        return second.value
    }
}
