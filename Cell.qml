import QtQuick 2.15
Item {
    id: container;
    property alias cellColor: rectangle.color;
    signal clicked(cellColor: color);

    width: 40;
    height: 25;

    Rectangle {
        id: rectangle;
        border.color: "white";
        anchors.fill: parent;
    }

    MouseArea{
        anchors.fill: parent;
        onClicked: {
            callback.test();
            container.clicked(container.cellColor)
        }
    }
}
