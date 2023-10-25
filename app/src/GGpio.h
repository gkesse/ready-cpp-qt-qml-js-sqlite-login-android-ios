//===============================================
#ifndef _GGpio_
#define _GGpio_
//===============================================
#include "GObject.h"
//===============================================
class GGpio : public GObject {
public:
    GGpio();
    ~GGpio();
    void writeGPIO(std::string _path, std::string _filename, std::string _value);
};
//===============================================
#endif
//===============================================
