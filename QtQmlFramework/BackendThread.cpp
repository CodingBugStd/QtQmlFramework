#include "BackendThread.h"
#include <QVariant>

//唯一实例
BackendThread BackendThread::backendThread;

//UI对象
extern QObject* qmlObj;

//后台线程
void* BackendThread::_main(void*param)
{
    //等待UI启动
    while( !qmlObj );

    qmlObj->setProperty( "testStr" , "Hello Qml , I'm c++ obj." );

    while(1)
    {

    }
    return param;
}

BackendThread::BackendThread() : QObject{NULL}
{
    pthread_create( &_thread , NULL , _main , NULL );
}

BackendThread::~BackendThread()
{

}

void BackendThread::incClickCount()
{
    static int count = 0;
    count++;
    qmlObj->setProperty( "clickCount" , count );
}
