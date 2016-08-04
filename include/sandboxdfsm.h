#ifndef SANDBOXDFSM_H
#define SANDBOXDFSM_H

#include <vector>
#include <string>

/** @brief Stores transitions function as Int -> Int. It must return -1 if input isn't accepted, else the ID of next state.
 * It also stores a bool telling if SandboxFSM::parse must return true when the last string is processed and the current state is this one.
 * Should only be used in SandboxDFSM
 *
 *  @see SandboxDFSM
 */

struct SandboxedState
{
    /**
     * @brief Trival constructor taking transition function and accepting value.
     * @param transition : Transition function : either a function pointer or a lambda. Must be int -> int
     * @param accept : Tell if the state is a correct last state.
     */
    SandboxedState(int (*transition)(int), bool accept) : transition(transition), accept(accept) {}
    /**
     * @brief Transition function pointer of type int -> int. For readability, lambdas are strongly advised.
     */
    int (*transition)(int);
    /**
     * @brief Boolean telling if a string being in this state after being entirely processed should be accepted.
     */
    bool accept = false;
};


/** @brief
 * Class storing an array of SandboxedState, given at construction-time. These are function receiving an input and telling what the next state number is.
 * An existing instance can only be modified by assignating it to a new value.
 *
 *
 */
class SandboxDFSM
{

    public:
        /** @brief
         * Construct a new Deterministic Finite State Machine.
         *
         * @param states : all possible states and their transitions functions.
         * @see SandboxedState
         *
         */
        SandboxDFSM(const std::vector<SandboxedState>& states) : states(states){}

        /**
         * @brief Read a string from beginning to end and decide to accept it or not.
         * @param str : string to pare
         * @return true if the string is accepted (all chars processed and last-state is accepting), false otherwise.
         */

        bool parse(const std::string& str) const;
    private:
        std::vector<SandboxedState> states;





};

#endif // SANDBOXDFSM_H
