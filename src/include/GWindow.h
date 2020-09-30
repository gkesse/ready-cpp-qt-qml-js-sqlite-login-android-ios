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
    
private:
    void createPage();
    void addPage(QString key, QWidget* widget);
    
public slots:
    void slotTitleClcik();
    
signals:
    void emitTitleUpdate();
    
private:
    GTitleBar* m_titleBar;
    QVBoxLayout* m_mainLayout;
};
//===============================================
#endif
//===============================================

