#include "DFA.hpp"

DFA::DFA(std::vector<State*> states) :
    states(states),
    currentState(states.at(0)) {
        
    for(const State* state : states) {
        if(state == nullptr) {
            throw InvalidStateException("Null state in creation of DFA");
        }
    }
}

String DFA::parse(char c) {
    Transition t = currentState->next(c);
    currentState = t.second;
    return t.first;
}

State* DFA::getCurrentState() {
    return currentState;
}

State* DFA::setCurrentState(State* state) {
    currentState = state;
    return state;
}