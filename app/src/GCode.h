//===============================================
#ifndef _GCode_
#define _GCode_
//===============================================
#include "GXml.h"
//===============================================
class GLog;
class GObject;
//===============================================
class GCode : public GXml {
public:
    GCode();
    ~GCode();
    xmlNodePtr createDatas();
    xmlNodePtr createCode(const GString& _code);
    void addData(const GString& _code, const GString& _name, const GString& _value);
    void addMap(const GString& _code, const std::vector<GObject*>& _map);
    void addLog(const GString& _code, const std::vector<GLog*>& _map);
    GString getData(const GString& _code, const GString& _name) const;
    void getMap(const GString& _code, std::vector<GObject*>& _map, GObject* _obj);
    void getLog(const GString& _code, std::vector<GLog*>& _map, GLog* _obj);
    void loadData(const GString& _data);
    GString toDatas(const GString& _data) const;
    GString toCode(const GString& _data) const;
    bool hasDatas();
};
//===============================================
#endif
//===============================================
