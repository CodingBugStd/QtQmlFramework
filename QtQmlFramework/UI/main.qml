import QtQuick
import QtQuick.Controls
import QtQml

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string testStr: ""
    property int clickCount: 0

    //qml对象构建完成，向后台线程发送信号
    Component.onCompleted:{
        backend.qmlCompleted()
    }

    Item{
        Text{
            text: "c/c++设置qml字符串对象测试:" + testStr
        }
        Button{
            width:200
            y:40
            text: "调用c/c++方法:" + clickCount
            onClicked: {
                backend.incClickCount()
            }
        }
    }
}
