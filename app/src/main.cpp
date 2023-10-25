//===============================================
#include "GProcess.h"
//===============================================
int main(int _argc, char** _argv, char** _envs) {
    GProcess lProcess;
    lProcess.init();
    lProcess.run(_argc, _argv, _envs);
    lProcess.clean();
    lProcess.getLogs().print();
    return 0;
}
//===============================================
