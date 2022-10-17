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
    color: "pink"

    Text {
        id: imageText;
        text: callback.getImageName();
        color: "teal"

        y: 0
        anchors.horizontalCenter: firstRect.horizontalCenter
        font.pointSize: (firstRect.width+firstRect.height)/80; font.bold: true

    }

    Image{
        source: callback.getImageLink();
        anchors.top: firstRect.top; anchors.topMargin: imageText.font.pointSize*1.5;
        anchors.bottom: firstRect.bottom;
        anchors.left: firstRect.left;
        anchors.right: firstRect.right;


    }

}

Rectangle {
    id: buttonOne;
    width: (window.width/2) - (window.width * 0.025) ;
    height: (window.height - firstRect.height*1.125);

    x: window.width * 0.025;
    y: ((firstRect.height*1.085) ) ;
    color : "teal"

    Text {
        id: buttonOneText;
        text: "Source Code"
        color: "pink"

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
    color : "pink"

    Text {
        id: buttonTwoText;
        text: "Steal Image"
        color: "teal"

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
