#ifndef DFA_HPP
#define DFA_HPP

#include <vector>
#include "State.hpp"

class DFA {
    private:
        std::vector<State*> states;

    public:

        DFA(std::vector<State*> states);
};

#endif