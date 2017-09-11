//===============================================
#ifndef _GStyle_
#define _GStyle_
//===============================================
#include <QObject>
//===============================================
class GStyle : public QObject {
    Q_OBJECT

private:
    GStyle(QObject* parent = 0);

public:
    ~GStyle();
    static GStyle* Instance();

public:
    void load();
    
private:
    static GStyle* m_instance;
};

#endif
