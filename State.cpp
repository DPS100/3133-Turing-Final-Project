#include "State.hpp"

State::State(String name = "", std::map<char, Transition> transitions):
    name(name),
    transitions(transitions),
    alphabet(AlphabetWrapper::getAlphabet()) {
 
    // Ensure all parameters exist
    if(transitions.size() != alphabet->size()) {
        throw InvalidStateException("Symbols in alphabet must have a single corresponding action");
    }

    for(const std::pair<const char, Transition> i : transitions) {
        Transition transition = i.second;
        if(transition.second == nullptr) {
            throw InvalidStateException("State referenced by transition does not exist");
        }

        if(!AlphabetWrapper::inAlphabet(transition.first)) {
            throw InvalidStateException("Transition exists for character undefined by alphabet");
        }
    }
}

Transition State::next(char symbol) {
    if(alphabet->find(symbol) == String::npos) {
        String message = "Alphabet does not contain character ";
        throw InvalidStateException(message.append(&symbol, 1));
    }
    return transitions[symbol];
}

String State::getName() {
    return name;
}

bool State::isTerminated() {
    return terminated;
}