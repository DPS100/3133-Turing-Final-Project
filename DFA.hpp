#ifndef DFA_HPP
#define DFA_HPP

#include <string>
#include <vector>
#include "State.hpp"

class DFA {
    private:
        // Techincally don't need vector/array? need to think abt this
        std::vector<State*> states;
        State* currentState;

    protected:
        State* accept;
        State* decline;

    public:

        DFA(std::vector<State*> states, State* accept, State* decline);
        DFA();
        /**
         * @brief Reads a character and moves to the targeted state
         * 
         * @param c 
         * @return String action to take
         */
        std::string parse(char c);
        State* getCurrentState();
        State* setCurrentState(State* state);
};

#endif