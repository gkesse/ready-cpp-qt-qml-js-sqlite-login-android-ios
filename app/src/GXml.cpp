//===============================================
#include "GXml.h"
//===============================================
GXml::GXml() {
    m_doc = 0;
    m_node = 0;
    xmlKeepBlanksDefault(0);
}
//===============================================
GXml::~GXml() {
    clear();
}
//===============================================
void GXml::clear() {
    xmlFreeDoc(m_doc);
}
//===============================================
void GXml::createDoc() {
    clear();
    m_doc = xmlNewDoc(BAD_CAST("1.0"));
    m_node = xmlNewNode(NULL, BAD_CAST("rdv"));
    xmlDocSetRootElement(m_doc, m_node);
}
//===============================================
bool GXml::loadXml(const GString& _data) {
    clear();
    m_doc = xmlParseDoc(BAD_CAST(_data.c_str()));
    if(!m_doc) return false;
    m_node = xmlDocGetRootElement(m_doc);
    if(!m_node) return false;
    return true;
}
//===============================================
void GXml::loadNode(const GString& _data) {
    if(_data.isEmpty()) return;
    int lSize = _data.size();
    xmlNodePtr lNodes;
    xmlParseInNodeContext(m_node, _data.c_str(), lSize, 0, &lNodes);
    xmlNodePtr lNode = lNodes->children;
    while(lNode) {
        xmlAddChild(m_node, xmlCopyNode(lNode, 1));
        lNode = lNode->next;
    }
    xmlFreeNode(lNodes);
}
//===============================================
void GXml::setNode(xmlNodePtr _node) {
    m_node = _node;
}
//===============================================
void GXml::setValue(const GString& _value) {
    xmlNodeSetContent(m_node, BAD_CAST(_value.c_str()));
}
//===============================================
xmlNodePtr GXml::createNode(const GXml& _root, const GString& _path, const GString& _value) {
    if(_path.isEmpty()) return 0;
    GXml lNode;
    lNode.m_node = m_node;
    GString lPath = "";
    if(_path[0] == '/') lPath += "/";
    std::vector<GString> lMap = _path.split("/");

    for(int i = 0; i < (int)lMap.size(); i++) {
        GString lPathI = lMap[i];
        if(i != 0) lPath += "/";
        lPath += lPathI;
        if(!existNode(_root, lPath)) {
            lNode.m_node = lNode.addObj(lPathI);
        }
        else {
            lNode.m_node = getNode(_root, lPath);
        }
    }

    if(_value != "") {
        xmlNodeSetContent(lNode.m_node, BAD_CAST(_value.c_str()));
    }
    return lNode.m_node;
}
//===============================================
bool GXml::existNode(const GXml& _root, const GString& _path) {
    return (countNode(_root, _path) != 0);
}
//===============================================
int GXml::countNode(const GXml& _root, const GString& _path) {
    if(!_root.m_doc) return 0;
    xmlXPathContextPtr lXPathC = xmlXPathNewContext(_root.m_doc);
    if(!lXPathC) return 0;
    xmlNodePtr lRoot = m_node;
    if(_path[0] == '/') lRoot = _root.m_node;
    xmlXPathObjectPtr lXPathO = xmlXPathNodeEval(lRoot, BAD_CAST(_path.c_str()), lXPathC);
    if(!lXPathO) return 0;
    xmlXPathFreeContext(lXPathC);
    int lCount = 0;
    if(lXPathO->nodesetval) {
        lCount = lXPathO->nodesetval->nodeNr;
    }
    xmlXPathFreeObject(lXPathO);
    return lCount;
}
//===============================================
xmlNodePtr GXml::getNode(const GXml& _root, const GString& _path) const {
    if(!_root.m_doc) return 0;
    xmlXPathContextPtr lXPathC = xmlXPathNewContext(_root.m_doc);
    if(!lXPathC) return 0;
    xmlNodePtr lRoot = m_node;
    if(_path[0] == '/') lRoot = _root.m_node;
    xmlXPathObjectPtr lXPathO = xmlXPathNodeEval(lRoot, BAD_CAST(_path.c_str()), lXPathC);
    if(!lXPathO) return 0;
    xmlXPathFreeContext(lXPathC);
    xmlNodePtr lNode = 0;
    if(lXPathO->nodesetval) {
        if(lXPathO->nodesetval->nodeNr) {
            lNode = lXPathO->nodesetval->nodeTab[0];
        }
    }
    xmlXPathFreeObject(lXPathO);
    return lNode;
}
//===============================================
GString GXml::getValue() const {
    GString lValue = (char*)xmlNodeGetContent(m_node);
    return lValue;
}
//===============================================
xmlNodePtr GXml::addObj(const GString& _name) {
    xmlNodePtr lNode = xmlNewNode(NULL, BAD_CAST(_name.c_str()));
    xmlAddChild(m_node, lNode);
    return lNode;
}
//===============================================
void GXml::addData(const GString& _name, const GString& _value) {
    xmlNodePtr lNode = xmlNewNode(NULL, BAD_CAST(_name.c_str()));
    xmlNodeSetContent(lNode, BAD_CAST(_value.c_str()));
    xmlAddChild(m_node, lNode);
}
//===============================================
GString GXml::toString() const {
    xmlChar* lBuffer = NULL;
    int lSize;
    xmlDocDumpFormatMemoryEnc(m_doc, &lBuffer, &lSize, "UTF-8", 4);
    GString lData((char*)lBuffer, lSize);
    xmlFree(lBuffer);
    return lData;
}
//===============================================
GString GXml::toNode(const GXml& _root) const {
    GString lData;
    xmlBufferPtr lBuffer = xmlBufferCreate();
    xmlNodeDump(lBuffer, _root.m_doc, m_node, 0, 1);
    lData = (char*)lBuffer->content;
    xmlBufferFree(lBuffer);
    return lData;
}
//===============================================
