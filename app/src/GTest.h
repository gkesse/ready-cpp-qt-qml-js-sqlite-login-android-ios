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
    void runBase64(int _argc, char** _argv, char** _envs);
    void runSleep(int _argc, char** _argv, char** _envs);
    void runEnvs(int _argc, char** _argv, char** _envs);
    void runGpio(int _argc, char** _argv, char** _envs);
};
//===============================================
#endif
//===============================================
