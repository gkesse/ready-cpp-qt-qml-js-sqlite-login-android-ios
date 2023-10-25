//===============================================
#ifndef _GTest_
#define _GTest_
//===============================================
#include "GObject.h"
//===============================================
class GTest : public GObject {
public:
    GTest();
    ~GTest();
    void run(int _argc, char** _argv, char** _envs);
    void runTest(int _argc, char** _argv, char** _envs);
    void runConsole(int _argc, char** _argv, char** _envs);
    void runMainWindow(int _argc, char** _argv, char** _envs);
};
//===============================================
#endif
//===============================================
