#include "DFA.hpp"

DFA::DFA(std::vector<State*> states, State* accept, State* decline) :
    states(states),
    currentState(states.at(0)),
    accept(accept),
    decline(decline) {
        
    for(const State* state : states) {
        if(state == nullptr) {
            throw InvalidStateException("Null state in creation of DFA");
        }
    }

    if(accept == nullptr || decline == nullptr) {
        throw InvalidStateException("Null state in creation of DFA");
    }
}

DFA::DFA() {
    State* accept = new State(std::string("Accept"), std::map<char, Transition>());
    states.push_back(accept);
    currentState = accept;
}

std::string DFA::parse(char c) {
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