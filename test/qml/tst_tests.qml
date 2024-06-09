import QtTest 1.2
import QtQuick 2.8
import QtQuick.Controls 2.1 as Controls
import CSC 1.0
import Integrity 1.0
import CoreProxy 0.1

Rectangle {

    TestCase {

        name: "MathTests"

        CoreProxy {
            id: coreProxy
        }

        IntegrityView {
            id: button1
            coreProxy: coreProxy
        }

        function test_mathQmlTest() {
            var tst = myContextProperty
            var version = coreProxy.coreVersion()
            var textName = button1.text
            compare(2 + 2, 4, "2 + 2 = 4")
            compare(tst, true)
            compare(version, "0.1.0.0_fake")
        }
    }

    TestCase {

        name: "MathTests2"

        CoreProxy {
            id: coreProxy2
        }

        IntegrityView {
            id: button2
            coreProxy: coreProxy2
        }

        function test_mathQmlTest() {
            var tst = myContextProperty
            var version = coreProxy2.coreVersion()
            var textName = button2.text
            compare(2 + 2, 4, "2 + 2 = 4")
            compare(tst, true)
            compare(version, "0.1.0.0_fake")
            //            compare(textName, "IntegrityView:CSCButton")
        }
    }

    TestCase {

        name: "MathTests3"

        CoreProxy {
            id: coreProxy3
        }

        IntegrityView {
            id: button3
            coreProxy: coreProxy3
        }

        function test_mathQmlTest() {
            var tst = myContextProperty
            var version = coreProxy3.coreVersion()
            var textName = button1.text
            compare(2 + 2, 4, "2 + 2 = 4")
            compare(tst, true)
            compare(version, "0.1.0.0_fake")
            //            compare(textName, "IntegrityView: CSCButton")
        }
    }

    TestCase {

        name: "RangeSlider_NotValidFirst"
        CSCCustomRangeSlider {
            id: slider
        }

        function test_NotValidFirst() {
            let resulte = slider.setFirstValue(5)
            compare(resulte, false)
            compare(slider.getFirstValue(), 0)
            compare(slider.getSecondValue(), 0)
        }
    }

    TestCase {

        name: "RangeSlider_ValidFirstAndSecond"
        CSCCustomRangeSlider {
            id: validFirstAndSecond
        }

        function test_ValidFirstAndSecond() {

            compare(validFirstAndSecond.getFirstValue(), 0)
            compare(validFirstAndSecond.getSecondValue(), 0)
            let resulteSecond = validFirstAndSecond.setSecondValue(75)
            compare(resulteSecond, true)
            compare(validFirstAndSecond.getSecondValue(), 75)
            let resulteFirst = validFirstAndSecond.setFirstValue(5)
            compare(resulteFirst, true)
            compare(validFirstAndSecond.getFirstValue(), 5)
        }
    }
}
