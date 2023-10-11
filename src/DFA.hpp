#ifndef DFA_HPP
#define DFA_HPP

#include <string>
#include <vector>
#include "State.hpp"

/**
 * @brief Helper class to organize many states together and keep track of current state.
 * 
 * May be redundant? Technically don't need vector/array to hold states, just have states point to each other and a single pointer keeping track of where we are. Future todo: Fold into Turing class and make states directed graph.
 * 
 */
class DFA {
    private:
        std::vector<State*> states;
        State* currentState;

    protected:
        State* accept;
        State* decline;

    public:
        /**
         * @brief Construct a new DFA object with accept and decline states set explicitly. Initial state set to first state in vector.
         * 
         * @param states 
         * @param accept
         * @param decline 
         */
        DFA(std::vector<State*> states, State* accept, State* decline);
        /**
         * @brief Construct a new DFA object. Initial state set to first state in vector. Will automatically search and set states for "Accept" and "Decline".
         * 
         * @param states 
         * @throws State::InvalidStateException when unable to find accept state
         */
        DFA(std::vector<State*> states);
        /**
         * @brief Construct a new DFA object with a single accept state. Initial state set to first state in vector.
         * 
         */
        DFA();
        /**
         * @brief Reads a character and moves to the state defined by the corresponding transition.
         * 
         * @param c Character to parse
         * @return String action to take
         */
        std::string parse(char c);
        /**
         * @brief Get the Current State object
         * 
         * @return State* to current state
         */
        State* getCurrentState();
        /**
         * @brief Set the Current State object
         * 
         * @param state Pointer to new current state 
         * @return State* to current state
         */
        State* setCurrentState(State* state);
};

#endif