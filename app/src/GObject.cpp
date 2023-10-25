//===============================================
#include "GObject.h"
//===============================================
GObject* GObject::m_instance = 0;
//===============================================
GObject::GObject() {
    m_resp.createDoc();
    m_resp.createDatas();
}
//===============================================
GObject::~GObject() {
    clearMap();
}
//===============================================
GObject* GObject::Instance() {
    if(m_instance == 0) {
        m_instance = new GObject;
    }
    return m_instance;
}
//===============================================
void GObject::clearMap() {
    for(int i = 0; i < (int)m_map.size(); i++) {
        GObject* lObj = m_map[i];
        delete lObj;
    }
    m_map.clear();
    m_logs.clearMap();
    m_dataLogs.clearMap();
}
//===============================================
const GLog& GObject::getLogs() const {
    return m_logs;
}
//===============================================
const GLog& GObject::getDataLogs() const {
    return m_dataLogs;
}
//===============================================
GString GObject::getEnv(const GString& _env, const GString& _defaultValue) const {
    char* lEnv = getenv(_env.c_str());
    if(lEnv == 0) return _defaultValue;
    return lEnv;
}
//===============================================
GString GObject::getPath(const GString& _path) const {
    GString lPath = "/home/gkesse/.readydev";
    lPath = sformat("%s%s", lPath.c_str(), _path.c_str());
    return lPath;
}
//===============================================
bool GObject::isTestEnv() const {
    GString lEnv = getEnv("ENV_TYPE");
    if(lEnv == "TEST") return true;
    return false;
}
//===============================================
void GObject::print() const {
    printf("%s\n", serialize().c_str());
}
//===============================================
GObject* GObject::clone() const {return new GObject;}
GString GObject::serialize(const GString& _code) const {return "";}
void GObject::deserialize(const GString& _data, const GString& _code) {}
//===============================================
