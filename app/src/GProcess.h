//===============================================
#ifndef _GProcess_
#define _GProcess_
//===============================================
#include "GObject.h"
//===============================================
class GProcess : public GObject {
public:
    GProcess();
    ~GProcess();
    void init();
    void clean();
    void run(int _argc, char** _argv, char** _envs);
    void runTest(int _argc, char** _argv, char** _envs);
};
//===============================================
#endif
//===============================================
