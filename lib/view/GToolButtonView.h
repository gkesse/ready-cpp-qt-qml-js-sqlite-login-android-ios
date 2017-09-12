//===============================================
#ifndef _GToolButtonView_
#define _GToolButtonView_
//===============================================
#include <QWidget>
//===============================================
namespace Ui {
class GToolButtonView;
}
//===============================================
class GToolButtonView : public QWidget {
    Q_OBJECT

private:
    GToolButtonView(QWidget *parent = 0);

public:
    ~GToolButtonView();
    static GToolButtonView* Instance();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createObjects();
    void createConnexions();

public slots:
    void facebookSlot();
    void skypeSlot();
    void githubSlot();
    void linkedinSlot();

private:
    static GToolButtonView* m_instance;
    Ui::GToolButtonView *ui;
};
//===============================================
#endif
//===============================================
