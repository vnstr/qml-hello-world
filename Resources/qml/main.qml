import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: "Hello World"

    Text {
        text: "Hello, World!"
        font.pixelSize: 40
        anchors.centerIn: parent
    }
}

