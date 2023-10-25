//===============================================
#ifndef _GBase64_
#define _GBase64_
//===============================================
#include <vector>
#include <string>
//===============================================
typedef unsigned char BYTE;
//===============================================
class GBase64 {
public:
    static std::string encode(const std::vector<BYTE>& buf);
    static std::string encode(const BYTE* buf, unsigned int bufLen);
    static std::vector<BYTE> decode(std::string encoded_string);
};
//===============================================
#endif
//===============================================
