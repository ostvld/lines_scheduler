import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import cpp.Model 1.0

ApplicationWindow {
	width: 640
	height: 480
	visible: true
	title: qsTr("Scroll")
	visibility: "Maximized"

	Model {
		id: myModel
		onDataChanged: enabledButtom()
		onDataSaveOrRevert: desabledButtom()
	}

	Rectangle {
		anchors.fill: parent
		color: "black"
	}

	ScrollView {
		anchors.fill: parent
		ScrollBar.horizontal.policy: ScrollBar.AlwaysOn
		ScrollBar.vertical.policy: ScrollBar.AlwaysOn

		ListView {
			id: listView
			objectName: "ListView"

			width: parent.width
			model: myModel
			orientation: ListView.Horizontal
			anchors.centerIn: parent
			delegate: WeekWidget {

				function isVisible() {
					if (index === 0) {
						return true
					}
					return false
				}

				function setVal() {
					console.log("test")
					//                parent.saveVal(objId, currentVal);
				}

				m_modelMediator: myModel
				//            maxValue: myModel.maxVal()
				maxValue: model.MaxLineValue
				objId: model.ObjId
				isShowLabel: isVisible()

				line1From: model.Line1From
				line1To: model.Line1To

				line2MWFrom: model.Line2MWFrom
				line2MWTo: model.Line2MWTo

				line2MarsFrom: model.Line2MarsFrom
				line2MarsTo: model.Line2MarsTo

				line2CrispFrom: model.Line2CrispFrom
				line2CrispTo: model.Line2CrispTo

				line3MWFrom: model.Line3MWFrom
				line3MWTo: model.Line3MWTo

				line3MarsFrom: model.Line3MarsFrom
				line3MarsTo: model.Line3MarsTo

				line3SNKFrom: model.Line3SNKFrom
				line3SNKTo: model.Line3SNKTo


				/* С помощью объекта Connections
			 * Устанавливаем соединение с классом ядра приложения
			 * */
				//            Connections {
				//                target: appCore // Указываем целевое соединение
				//                /* Объявляем и реализуем функцию, как параметр
				//                 * объекта и с имененем похожим на название сигнала
				//                 * Разница в том, что добавляем в начале on и далее пишем
				//                 * с заглавной буквы
				//                 * */
				//                onSendToQml: {
				//                    labelCount.text = count // Устанавливаем счётчик в текстовый лейбл
				//                    }
				//                }
			}
		}
	}

	header: Rectangle {
		anchors.left: parent.left
		anchors.right: parent.right
		height: 80
		color: "black"
		RowLayout {

			HederButton {
				id: save
				text: qsTr("Save")
				//                    onClicked: myModel.submit()
				signal infoClicked(string str)

				enabled: false

				onClicked: {
					//                        infoClicked("Information")
					myModel.saveAll()
				}
			}

			HederButton {
				id: revert
				text: qsTr("Revert")
				enabled: false
				//                    onClicked: myModel.revert()
				onClicked: {
					//                        infoClicked("Information")
					myModel.revertAll()
				}
			}

			HederButton {
				id: add
				text: qsTr("Add")
				enabled: true
				//                    onClicked: myModel.revert()
				onClicked: {
					//                        infoClicked("Information")
					myModel.addNew()
				}
			}
		}
	}

	function enabledButtom() {
		console.log("Data changed!")
		save.enabled = true
		revert.enabled = true
	}

	function desabledButtom() {
		save.enabled = false
		revert.enabled = false
	}

	//    Connections {
	//        target: modelMediator
	//        // Указываем целевое соединение
	//        /* Объявляем и реализуем функцию, как параметр
	//         * объекта и с имененем похожим на название сигнала
	//         * Разница в том, что добавляем в начале on и далее пишем
	//         * с заглавной буквы
	//         * */
	//        dataChanged: enabledButtom ()
	//        modelMediator.dataChanged: {}
	//    }

	//    footer:
	//        Rectangle{
	//            anchors.left: parent.left
	//            anchors.right: parent.right
	//            height: 100
	//            color: "red"

	//            RowLayout {
	//                spacing: 50

	//                Control {
	//                padding: 10
	//                contentItem: Button {
	//                    text: "Ok"
	//                    onClicked: myModel.submit()

	//                    }
	//                }
	//                Button {
	//                    text: "Cancel"
	//                    onClicked: myModel.revert()
	//                }
	//            }
	//        }
	Component.onCompleted: {
		myModel.slotInfo("test")
	}
}
