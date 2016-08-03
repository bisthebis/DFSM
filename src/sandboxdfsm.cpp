#include "sandboxdfsm.h"


bool SandboxDFSM::parse(const std::string& str)
{

    int currentState = 0;
    for (char c : str)
    {
        currentState = states[currentState].transition(c);
        if (currentState < 0)
            return false;
    }

    return states[currentState].accept;



}
