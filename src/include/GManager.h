//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGQt sGQt;
//===============================================
class GManager {
private:
    GManager();
    
public:
    ~GManager();
    static GManager* Instance();
    sGManager* dataGet();

private:
    static GManager* m_instance;
    sGManager* m_mgr;
};
//===============================================
struct _sGManager {
    sGQt* qt;
};
//===============================================
struct _sGQt {
    QString app_name;
    QString title;
    int width;
    int height;
};
//===============================================
#endif
//===============================================

