import QtQuick 2.15
import QtQuick.Window 2.15




Window {


    id: window;
    minimumWidth: 720
    minimumHeight: 480
    visible: true
    title: {callback.planForImageTheft();
        qsTr("Bing Photo Of The Day Stealer")}
    //title: callback.test();


Rectangle {
    id: firstRect;
    width: window.width - (window.width * 0.05);
    height: (window.height/1.3) - (window.height * 0.025);
    x: ((window.width - width)/2);
    y: window.height * 0.025;
    color: "lightgrey"

    Text {
        id: testText;
        text: callback.getImageName();
        color: "black"

        y: 31
        anchors.horizontalCenter: firstRect.horizontalCenter
        font.pointSize: (firstRect.width+firstRect.height)/80; font.bold: true

    }

    Grid {
            id: colorPicker
            x: 20; anchors.bottom: firstRect.bottom; anchors.bottomMargin: 4
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

Rectangle {
    id: buttonOne;
    width: (window.width/2) - (window.width * 0.025) ;
    height: (window.height - firstRect.height*1.125);

    x: window.width * 0.025;
    y: ((firstRect.height*1.085) ) ;
    color : "blue"

    Text {
        id: buttonOneText;
        text: "Source Code"
        color: "black"

        anchors.verticalCenter: buttonOne.verticalCenter
        anchors.horizontalCenter: buttonOne.horizontalCenter
        font.pointSize: (buttonOne.width+ buttonOne.height)/40; font.bold: true

    }

}

Rectangle {
    id: buttonTwo;
    width: (window.width/2) - (window.width * 0.05);
    height: (window.height - firstRect.height*1.125);

    x: (buttonOne.width ) + (window.width * 0.05);
    y: (firstRect.height*1.085);
    color : "red"

    Text {
        id: buttonTwoText;
        text: "Steal Image"
        color: "black"

        anchors.verticalCenter:  buttonTwo.verticalCenter
        anchors.horizontalCenter: buttonTwo.horizontalCenter
        font.pointSize: (buttonTwo.width+buttonTwo.height)/40; font.bold: true

    }

    MouseArea{
        anchors.fill: parent;
        onClicked: {
            callback.exicutePlan();
        }
    }
}

}
