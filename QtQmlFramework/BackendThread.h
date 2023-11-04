#ifndef BACKENDTHREAD_H
#define BACKENDTHREAD_H

#include <iostream>
#include <thread>
#include <QObject>
#include <pthread.h>
#include <semaphore.h>

class BackendThread : public QObject
{
    Q_OBJECT
public:
    BackendThread();
    ~BackendThread();

    void setBackendQmlObj(QObject* qmlObj);
    void backendStart();

//对qml开放的接口
public:
    Q_INVOKABLE void qmlCompleted();
    Q_INVOKABLE void incClickCount();

private:
    void            _threadFunc();
    std::thread*    _thread;
    QObject*        _qmlObj;
};

#endif // BACKENDTHREAD_H
