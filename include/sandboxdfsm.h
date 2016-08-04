/**
  *     \file sandboxdfsm.h
  *     \author Boris Martin
  *     \brief Sandbox class where all transitions are defined as int->int, where input is char and output is ID of next state
  *
  */

#ifndef SANDBOXDFSM_H
#define SANDBOXDFSM_H

#include <vector>
#include <string>

/** @brief Stores transitions function. It must return -1 if input isn't accepted, else the ID of next state.
 *
 *
 *
 *
 *
 */
struct State
{
    State(int (*transition)(int), bool accept) : transition(transition), accept(accept) {}
    int (*transition)(int);
    bool accept = false;
};


class SandboxDFSM
{

    public:
        SandboxDFSM(const std::vector<State>& states) : states(states){}
        bool parse(const std::string& str) const;
    private:
        std::vector<State> states;





};

#endif // SANDBOXDFSM_H
