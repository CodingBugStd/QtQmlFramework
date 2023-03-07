#ifndef BACKENDTHREAD_H
#define BACKENDTHREAD_H

#include <QObject>
#include <pthread.h>

class BackendThread : public QObject
{
    Q_OBJECT
public:
    static BackendThread backendThread;

//对qml开放的接口
public:
    Q_INVOKABLE void interfaceDemo();

//线程
private:
    static void* _main(void*);
    pthread_t   _thread;

//单例模式相关
private:
    BackendThread();
    ~BackendThread();
};

#endif // BACKENDTHREAD_H
