import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    id: window;
    minimumWidth: 720
    minimumHeight: 480
    visible: true
    title: qsTr("Bing Photo Of The Day Stealer")


Rectangle {
    id: firstRect;
    width: window.width - 50;
    height: window.height - 50;
    y: (window.height - height)/2;
    x: (window.width - width)/2;
    color: "lightgrey"

    Text {
        id: testText;
        text: "Test Text";
        color: "black"

        y: 31
        anchors.horizontalCenter: firstRect.horizontalCenter
        font.pointSize: 24; font.bold: true

    }

    Grid {
            id: colorPicker
            x: 4; anchors.bottom: firstRect.bottom; anchors.bottomMargin: 4
            rows: 2; columns: 4; spacing: 3

            Cell { cellColor: "red"; onClicked: testText.color = cellColor }
            Cell { cellColor: "green"; onClicked: testText.color = cellColor }
            Cell { cellColor: "blue"; onClicked: testText.color = cellColor }
            Cell { cellColor: "yellow"; onClicked: testText.color = cellColor }
            Cell { cellColor: "steelblue"; onClicked: testText.color = cellColor }
            Cell { cellColor: "black"; onClicked: testText.color = cellColor }
            Cell { cellColor: "white"; onClicked: testText.color = cellColor}
            Cell { cellColor: "lightgrey"; onClicked: testText.color = cellColor}
        }
}

}
