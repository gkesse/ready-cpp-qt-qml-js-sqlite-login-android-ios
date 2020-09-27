//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGQt sGQt;
typedef struct _sGTitleBar sGTitleBar;
typedef struct _sGFont sGFont;
//===============================================
class GManager {
private:
    GManager();
    
public:
    ~GManager();
    static GManager* Instance();
    sGManager* dataGet();
    void styleLoad();
    QIcon pictoLoad(int picto, QColor color = "white");

private:
    static GManager* m_instance;
    sGManager* m_mgr;
    QtAwesome* m_QtAwesome;
};
//===============================================
struct _sGManager {
    sGQt* qt;
    sGTitleBar* title_bar;
    sGFont* font;
};
//===============================================
struct _sGQt {
    QString app_name;
    QString title;
    QString style_file;
    QStackedWidget* page_map;
    int width;
    int height;
};
//===============================================
struct _sGTitleBar {
    QString icon_file;
    QString click_id;
    QString url;
    QColor color;
    int icon_size;
    int maximize_icon;
};
//===============================================
struct _sGFont {
    QString lobster;
};
//===============================================
#endif
//===============================================

