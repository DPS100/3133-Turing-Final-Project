#include "DFA.hpp"

DFA::DFA(std::vector<State*> states) :
    states(states) {
        
    for(const State* state : states) {
        if(state == nullptr) {
            throw InvalidStateException("Null state in creation of DFA");
        }
    }
}