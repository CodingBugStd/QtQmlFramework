import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: Screen.width * 0.5 // 设置窗口宽度为屏幕宽度的50%
    height: width * 0.6 // 设置窗口高度为窗口宽度的60%
    title: "Qt Ui Frame Default Window"


    // 其他窗口内容可以在这里添加
    onWidthChanged: {
        // 当窗口宽度改变时的操作可以在这里添加
    }

    onHeightChanged: {
        // 当窗口高度改变时的操作可以在这里添加
    }
}
