//===============================================
#include "GCode.h"
#include "GLog.h"
#include "GObject.h"
//===============================================
GCode::GCode()
: GXml() {

}
//===============================================
GCode::~GCode() {

}
//===============================================
xmlNodePtr GCode::createDatas() {
    GCode lDom;
    lDom.m_node = getNode(*this, sformat("/rdv/datas"));
    if(!lDom.m_node) {
        lDom.m_node = lDom.createNode(*this, sformat("/rdv/datas"));
    }
    return lDom.m_node;
}
//===============================================
xmlNodePtr GCode::createCode(const GString& _code) {
    GCode lDom;
    lDom.m_node = getNode(*this, sformat("/rdv/datas/data[code='%s']", _code.c_str()));
    if(!lDom.m_node) {
        lDom.m_node = createDatas();
        lDom.m_node = lDom.addObj("data");
        lDom.GXml::addData("code", _code);
    }
    return lDom.m_node;
}
//===============================================
void GCode::addData(const GString& _code, const GString& _name, const GString& _value) {
    if(_value.isEmpty()) return;
    GCode lDom;
    lDom.m_node = getNode(*this, sformat("/rdv/datas/data[code='%s']/%s", _code.c_str(), _name.c_str()));
    if(!lDom.m_node) {
        lDom.m_node = createCode(_code);
        lDom.GXml::addData(_name, _value);
    }
    else {
        lDom.setValue(_value);
    }
}
//===============================================
void GCode::addMap(const GString& _code, const std::vector<GObject*>& _map) {
    int lSize = (int)_map.size();
    if(!lSize) return;

    GCode lDom;
    lDom.m_node = getNode(*this, sformat("/rdv/datas/data[code='%s']/map", _code.c_str()));
    if(!lDom.m_node) {
        lDom.m_node = createCode(_code);
        lDom.m_node = lDom.addObj("map");
    }

    for(int i = 0; i < lSize; i++) {
        GObject* lObj = _map[i];
        GString lData = lObj->serialize(_code);
        lData = toDatas(lData);
        lDom.loadNode(lData);
    }
}
//===============================================
void GCode::addLog(const GString& _code, const std::vector<GLog*>& _map) {
    int lSize = (int)_map.size();
    if(!lSize) return;

    GCode lDom;
    lDom.m_node = getNode(*this, sformat("/rdv/datas/data[code='%s']/map", _code.c_str()));
    if(!lDom.m_node) {
        lDom.m_node = createCode(_code);
        lDom.m_node = lDom.addObj("map");
    }

    for(int i = 0; i < lSize; i++) {
        GLog* lObj = _map[i];
        GString lData = lObj->serialize(_code);
        lData = toDatas(lData);
        lDom.loadNode(lData);
    }
}
//===============================================
GString GCode::getData(const GString& _code, const GString& _name) const {
    GCode lDom;
    lDom.m_node = getNode(*this, sformat("/rdv/datas/data[code='%s']/%s", _code.c_str(), _name.c_str()));
    if(!lDom.m_node) return "";
    return lDom.getValue();
}
//===============================================
void GCode::getMap(const GString& _code, std::vector<GObject*>& _map, GObject* _obj) {
    _obj->clearMap();

    int lCount = countNode(*this, sformat("/rdv/datas/data[code='%s']/map/data", _code.c_str()));

    if(!lCount) return;

    for(int i = 0; i < lCount; i++) {
        GCode lDom;
        lDom.m_node = getNode(*this, sformat("/rdv/datas/data[code='%s']/map/data[position()=%d]", _code.c_str(), i + 1));
        GString lData = lDom.toNode(*this);
        lData = toCode(lData);
        GObject* lObj = _obj->clone();
        lObj->deserialize(lData, _code);
        _map.push_back(lObj);
    }
}
//===============================================
void GCode::getLog(const GString& _code, std::vector<GLog*>& _map, GLog* _obj) {
    _obj->clearMap();

    int lCount = countNode(*this, sformat("/rdv/datas/data[code='%s']/map/data", _code.c_str()));

    if(!lCount) return;

    for(int i = 0; i < lCount; i++) {
        GCode lDom;
        lDom.m_node = getNode(*this, sformat("/rdv/datas/data[code='%s']/map/data[position()=%d]", _code.c_str(), i + 1));
        GString lData = lDom.toNode(*this);
        lData = toCode(lData);
        GLog* lObj = _obj->clone();
        lObj->deserialize(lData, _code);
        _map.push_back(lObj);
    }
}
//===============================================
void GCode::loadData(const GString& _data) {
    if(_data.isEmpty()) return;
    GCode lDom;
    lDom.m_node = createDatas();
    GString lData = toDatas(_data);
    lDom.loadNode(lData);
}
//===============================================
GString GCode::toDatas(const GString& _data) const {
    if(_data.isEmpty()) return "";
    GCode lDom;
    GCode lDomC;
    lDom.loadXml(_data);
    lDomC.m_node = lDom.getNode(lDom, sformat("/rdv/datas"));
    return lDomC.toNode(lDom);
}
//===============================================
GString GCode::toCode(const GString& _data) const {
    if(_data.isEmpty()) return "";
    GCode lDom;
    GCode lDomC;
    lDom.createDoc();
    lDom.createDatas();
    lDomC.m_node = lDom.getNode(lDom, sformat("/rdv/datas"));
    GString lData = sformat("<rdv>%s</rdv>", _data.c_str());
    lDomC.loadNode(lData);
    return lDom.toString();
}
//===============================================
bool GCode::hasDatas() {
    return existNode(*this, sformat("/rdv/datas/data[code]"));
}
//===============================================
