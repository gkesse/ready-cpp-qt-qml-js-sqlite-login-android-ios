//===============================================
#ifndef _GPicto_
#define _GPicto_
//===============================================
#include <QtAwesome.h>
#include <QObject>
//===============================================
class GPicto : public QObject {
    Q_OBJECT

private:
    GPicto();

public:
    ~GPicto();

public:
    static GPicto* Instance();

private:
    void createObjects();

public:
    void setColor(const QColor& color);
    QIcon getPicto(const int& picto) const;
    QIcon getPicto(const QString& picto) const;

private:
    static GPicto* m_instance;
    QtAwesome* m_picto;
    QColor m_color;
};
//===============================================
#endif
//===============================================
