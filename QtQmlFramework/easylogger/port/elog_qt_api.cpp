#include <QFile>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QTime>
#include <QDate>

static QFile* log_file = 0;

#ifdef __cplusplus
extern "C"
{
#endif

void qt_log_file_create(void)
{
    if( log_file )
    {
        return;
    }

    log_file = new QFile();

    QDir dir(QDir::current());
    QString folder_name("log");

    if( !dir.exists(folder_name) )
    {
        dir.mkdir(folder_name);
    }
    dir.cd(folder_name);

    QDate date = QDate::currentDate();
    QString file_path = dir.path();

    file_path.append("/");
    file_path.append(date.toString("yyyyMMdd-"));
    file_path.append( QTime::currentTime().toString("hhmm") );
    file_path.append( ".log" );

    log_file->setFileName( file_path );

    if( log_file->exists() )
    {
        log_file->open(QIODeviceBase::Append);
    }
    else
    {
        log_file->open(QIODeviceBase::ReadWrite);
    }
}

void qt_log_file_write(uint8_t* dat , uint16_t len)
{
    if( !log_file ) return;

    log_file->write((const char*)dat,len);
    log_file->flush();
}

const char* qt_log_get_rtc_time_str(void)
{
    static QString time_std;

    time_std = QTime::currentTime().toString("hh:mm:ss.zzz");

    return (const char*)time_std.toLocal8Bit().data();
}

#ifdef __cplusplus
}
#endif
