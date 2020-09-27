//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include "GInclude.h"
#include "GTitleBar.h"
//===============================================
class GWindow : public QFrame {
    Q_OBJECT
    
public:
    GWindow(QWidget* parent  = 0);
    ~GWindow();
    
public slots:
    void slotTitleClcik();
    
signals:
    void emitTitleUpdate();
    
private:
    GTitleBar* m_titleBar;
};
//===============================================
#endif
//===============================================

