//===============================================
#ifndef _GLog_
#define _GLog_
//===============================================
#include "GInclude.h"
#include "GString.h"
//===============================================
class GLog {
public:
    GLog();
    ~GLog();
    GLog* clone() const;
    void clearMap();
    void setObj(const GLog& _obj);
    void loadFromMap(int i);
    void loadToMap(int i);
    void addError(const GString& _msg);
    void addLog(const GString& _msg);
    void addData(const GString& _msg);
    void addLogs(const GLog& _obj);
    bool hasErrors() const;
    bool hasLogs() const;
    bool hasDatas() const;
    void print() const;
    GString serialize(const GString& _code = "logs") const;
    void deserialize(const GString& _data, const GString& _code = "logs");

private:
    GString m_type;
    GString m_side;
    GString m_msg;
    std::vector<GLog*> m_map;
};
//===============================================
#endif
//===============================================
