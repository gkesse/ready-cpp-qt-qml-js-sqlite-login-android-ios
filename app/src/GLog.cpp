//===============================================
#include "GLog.h"
#include "GCode.h"
//===============================================
GLog::GLog() {

}
//===============================================
GLog::~GLog() {
    clearMap();
}
//===============================================
GLog* GLog::clone() const {
    return new GLog;
}
//===============================================
void GLog::clearMap() {
    for(int i = 0; i < (int)m_map.size(); i++) {
        GLog* lObj = m_map[i];
        delete lObj;
    }
    m_map.clear();
}
//===============================================
void GLog::setObj(const GLog& _obj) {
    m_type = _obj.m_type;
    m_side = _obj.m_side;
    m_msg = _obj.m_msg;
}
//===============================================
void GLog::loadFromMap(int i) {
    if(i >= 1 && i <= (int)m_map.size()) {
        GLog* lObj = m_map[i - 1];
        setObj(*lObj);
    }
}
//===============================================
void GLog::loadToMap(int i) {
    if(i >= 1 && i <= (int)m_map.size()) {
        GLog* lObj = m_map[i - 1];
        lObj->setObj(*this);
    }
}
//===============================================
void GLog::addError(const GString& _msg) {
    GLog* lObj = new GLog;
    lObj->m_type = "error";
    lObj->m_side = "server_cpp";
    lObj->m_msg = _msg;
    m_map.push_back(lObj);
}
//===============================================
void GLog::addLog(const GString& _msg) {
    GLog* lObj = new GLog;
    lObj->m_type = "log";
    lObj->m_side = "server_cpp";
    lObj->m_msg = _msg;
    m_map.push_back(lObj);
}
//===============================================
void GLog::addData(const GString& _msg) {
    GLog* lObj = new GLog;
    lObj->m_type = "data";
    lObj->m_side = "server_cpp";
    lObj->m_msg = _msg;
    m_map.push_back(lObj);
}
//===============================================
void GLog::addLogs(const GLog& _obj) {
    for(int i = 0; i < (int)_obj.m_map.size(); i++) {
        GLog* lObj = _obj.m_map[i];
        GLog* lNew = new GLog;
        lNew->setObj(*lObj);
        m_map.push_back(lNew);
    }
}
//===============================================
bool GLog::hasErrors() const {
    for(int i = 0; i < (int)m_map.size(); i++) {
        GLog* lObj = m_map[i];
        if(lObj->m_type == "error") return true;
    }
    return false;
}
//===============================================
bool GLog::hasLogs() const {
    for(int i = 0; i < (int)m_map.size(); i++) {
        GLog* lObj = m_map[i];
        if(lObj->m_type == "log") return true;
    }
    return false;
}
//===============================================
bool GLog::hasDatas() const {
    for(int i = 0; i < (int)m_map.size(); i++) {
        GLog* lObj = m_map[i];
        if(lObj->m_type == "data") return true;
    }
    return false;
}
//===============================================
void GLog::print() const {
    for(int i = 0; i < (int)m_map.size(); i++) {
        GLog* lObj = m_map[i];
        printf("[%-5s] : %s\n", lObj->m_type.c_str(), lObj->m_msg.c_str());
    }
}
//===============================================
GString GLog::serialize(const GString& _code) const {
    GCode lDom;
    lDom.createDoc();
    lDom.addData(_code, "type", m_type);
    lDom.addData(_code, "side", m_side);
    lDom.addData(_code, "msg", m_msg.toBase64());
    lDom.addLog(_code, m_map);
    return lDom.toString();
}
//===============================================
void GLog::deserialize(const GString& _data, const GString& _code) {
    GCode lDom;
    lDom.loadXml(_data);
    m_type = lDom.getData(_code, "type");
    m_side = lDom.getData(_code, "side");
    m_msg = lDom.getData(_code, "msg").fromBase64();
    lDom.getLog(_code, m_map, this);
}
//===============================================
