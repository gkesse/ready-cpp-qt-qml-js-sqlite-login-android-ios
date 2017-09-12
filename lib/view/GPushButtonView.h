//===============================================
#ifndef _GPushButtonView_
#define _GPushButtonView_
//===============================================
#include <QWidget>
//===============================================
namespace Ui {
class GPushButtonView;
}
//===============================================
class GPushButtonView : public QWidget {
    Q_OBJECT

private:
    GPushButtonView(QWidget *parent = 0);

public:
    ~GPushButtonView();
    static GPushButtonView* Instance();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createObjects();
    void createConnections();

public slots:
    void createSlot();
    void readSlot();
    void updateSlot();
    void deleteSlot();

private:
    static GPushButtonView* m_instance;
    Ui::GPushButtonView *ui;
};
//===============================================
#endif
//===============================================
