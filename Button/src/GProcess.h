//===============================================
#ifndef _GProcess_
#define _GProcess_
//===============================================
#include <QObject>
//===============================================
class GProcess : public QObject {
    Q_OBJECT

private:
    GProcess(QObject* parent = 0);

public:
    ~GProcess();
    static GProcess* Instance();

public:
    void run();

private:
    static GProcess* m_instance;
};

#endif
