//===============================================
#ifndef _GMainWindow_
#define _GMainWindow_
//===============================================
#include "GInclude.h"
//===============================================
namespace Ui {
class GMainWindow;
}
//===============================================
class GMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit GMainWindow(QWidget *parent = nullptr);
    ~GMainWindow();

private:
    Ui::GMainWindow *ui;
};
//===============================================
#endif
//===============================================
