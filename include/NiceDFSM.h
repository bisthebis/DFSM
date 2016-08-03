#ifndef DEF_NICEDFSM
#define DEF_NICEDFSM

#include <map>
#include <string>

struct NiceDFSM
{
	struct State
	{
		bool isAccepting = false;
		std::map<char, int> transitions;
	};

	State states[5];
    int currentState = 0;

    bool process(const std::string& src)
	{
        State* state = &states[currentState];

        for (const char c : src)
        {

            auto nextIt = state->transitions.find(c);
            if (nextIt == state->transitions.end())
                return false;
            else
            {
                currentState = *nextIt;
                state = &states[currentState];
                if (state->isAccepting)
                    return true;
            }

        }
	}

    NiceDFSM()
    {
        states[0].transitions['n'] = 1;
        states[1].transitions['n'] = 2;
        states[2].transitions['n'] = 3;
        states[3].transitions['n'] = 4;
        states[4].isAccepting = true;
    }

};


#endif
