#include "BackendThread.h"
#include <windows.h>
#include <QVariant>

//唯一实例
BackendThread BackendThread::backendThread;

//UI对象
extern QObject* qmlObj;

//后台线程
void* BackendThread::_main(void*param)
{
    sem_wait( &backendThread._rootUiCompleted );
    Sleep(100);
    qmlObj->setProperty( "testStr" , "Hello Qml , I'm c++ obj." );

    while(1)
    {

    }
    return param;
}

void BackendThread::incClickCount()
{
    static int count = 0;
    count++;
    qmlObj->setProperty( "clickCount" , count );
}

BackendThread::BackendThread() : QObject{NULL}
{
    sem_init( &_rootUiCompleted , 0 , 0 );
    pthread_create( &_thread , NULL , _main , this );
}

BackendThread::~BackendThread()
{
}

void BackendThread::qmlCompleted()
{
    sem_post( &_rootUiCompleted );
}
