//===============================================
#ifndef _GOpenGL_
#define _GOpenGL_
//===============================================
#include <QWidget>
//===============================================
namespace Ui {
class GOpenGL;
}
//===============================================
class GOpenGL : public QWidget {
    Q_OBJECT

private:
    GOpenGL(QWidget *parent = 0);

public:
    ~GOpenGL();
    static GOpenGL* Instance();

protected:
    void closeEvent(QCloseEvent *event);

private:
    static GOpenGL* m_instance;
    Ui::GOpenGL *ui;
};
//===============================================
#endif
//===============================================
