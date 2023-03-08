import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string testStr: ""

    Item{
        Text{
            text: "c/c++设置qml字符串对象测试:" + testStr
        }
    }
}
