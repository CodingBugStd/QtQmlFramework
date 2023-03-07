#include "BackendThread.h"

//唯一实例
BackendThread BackendThread::backendThread;

//后台线程
void* BackendThread::_main(void*param)
{
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

void BackendThread::interfaceDemo()
{

}
