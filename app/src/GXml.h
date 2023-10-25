//===============================================
#ifndef _GXml_
#define _GXml_
//===============================================
#include "GInclude.h"
#include "GString.h"
//===============================================
class GXml {
public:
    GXml();
    virtual ~GXml();
    void clear();
    void createDoc();
    bool loadXml(const GString& _data);
    void loadNode(const GString& _data);
    void setNode(xmlNodePtr _node);
    void setValue(const GString& _value);
    xmlNodePtr createNode(const GXml& _root, const GString& _path, const GString& _value = "");
    bool existNode(const GXml& _root, const GString& _path);
    int countNode(const GXml& _root, const GString& _path);
    xmlNodePtr getNode(const GXml& _root, const GString& _path) const;
    GString getValue() const;
    xmlNodePtr addObj(const GString& _name);
    void addData(const GString& _name, const GString& _value);
    GString toString() const;
    GString toNode(const GXml& _root) const;

protected:
    xmlDocPtr m_doc;
    xmlNodePtr m_node;
};
//===============================================
#endif
//===============================================
