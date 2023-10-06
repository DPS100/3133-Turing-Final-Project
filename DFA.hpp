#ifndef DFA_HPP
#define DFA_HPP

#include <vector>
#include "State.hpp"

class DFA {
    private:
        std::vector<State*> states;
        State* currentState;

    public:

        DFA(std::vector<State*> states);
        /**
         * @brief 
         * 
         * @param c 
         * @return String action to take
         */
        String parse(char c);
        State* getCurrentState();
        State* setCurrentState(State* state);
};

#endif