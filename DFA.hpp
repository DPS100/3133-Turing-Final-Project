#ifndef DFA_HPP
#define DFA_HPP

#include <vector>
#include "State.hpp"

class DFA {
    private:
        // Techincally don't need vector/array? need to think abt this
        std::vector<State*> states;
        State* currentState;

    public:

        DFA(std::vector<State*> states);
        DFA();
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