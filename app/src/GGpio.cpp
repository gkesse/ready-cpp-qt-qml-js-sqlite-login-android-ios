//===============================================
#include "GGpio.h"
//===============================================
GGpio::GGpio()
: GObject() {

}
//===============================================
GGpio::~GGpio() {

}
//===============================================
void GGpio::writeGPIO(std::string _path, std::string _filename, std::string _value) {
   std::fstream fs;
   fs.open((_path + _filename).c_str(), std::fstream::out);
   fs << _value;
   fs.close();
}
//===============================================
