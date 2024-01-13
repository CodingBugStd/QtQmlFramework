QT += quick

SOURCES += \
        BackendThread.cpp \
        easylogger/port/elog_port.c \
        easylogger/port/elog_qt_api.cpp \
        easylogger/src/elog.c \
        easylogger/src/elog_async.c \
        easylogger/src/elog_buf.c \
        easylogger/src/elog_utils.c \
        main.cpp

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# 文件夹路径
INCLUDEPATH += \
            ./easylogger/inc \
            ./easylogger/port


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    BackendThread.h \
    easylogger/inc/elog.h \
    easylogger/inc/elog_cfg.h \
    easylogger/port/elog_qt_api.h

DISTFILES += \
    UI/default_ui.qml \
    UI/log_monitor.qml \
    UI/main.qml

RESOURCES += \
    UI/default_ui.qml \
    UI/main.qml
