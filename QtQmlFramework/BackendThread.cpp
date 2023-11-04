#include "BackendThread.h"
#include <unistd.h>
#include <QVariant>
#include <QDebug>

void BackendThread::setBackendQmlObj(QObject* qmlObj)
{
    _qmlObj = qmlObj;
}

//后台线程
void BackendThread::_threadFunc()
{
    sleep(1);
    _qmlObj->setProperty( "testStr" , "Hello Qml , I'm c++ obj." );

    while(1)
    {
    }
    return;
}

void BackendThread::incClickCount()
{
    static int count = 0;
    count++;
    _qmlObj->setProperty( "clickCount" , count );
}

BackendThread::BackendThread() : QObject{NULL}
{
    _thread = 0;
    _qmlObj = 0;
}

void BackendThread::backendStart()
{
    _thread = new std::thread(&BackendThread::_threadFunc , this);
    _thread->detach();      //分离子线程
}

BackendThread::~BackendThread()
{
}

void BackendThread::qmlCompleted()
{
}
