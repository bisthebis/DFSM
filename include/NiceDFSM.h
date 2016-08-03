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

    bool parse(const std::string& src)
	{
        State* state = &states[currentState];

        for (const char c : src)
        {

            auto nextIt = state->transitions.find(c);
            if (nextIt == state->transitions.end())
                return false;
            else
            {
                currentState = nextIt->second;
                state = &states[currentState];
                //if (state->isAccepting) /*We return true IF and ONLY IF the string has been entirely processed. (case "nicee" */
                //    return true;
            }

        }

        return state->isAccepting ? true : false;
	}

    NiceDFSM()
    {
        states[0].transitions['n'] = 1;
        states[1].transitions['i'] = 2;
        states[2].transitions['c'] = 3;
        states[3].transitions['e'] = 4;
        states[4].isAccepting = true;
    }

};


#endif
