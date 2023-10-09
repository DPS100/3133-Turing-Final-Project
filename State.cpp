#include "State.hpp"
#include <iostream>

// TODO make abstract with abstract function representing the state transition action?
State::State(std::string name, std::map<char, Transition> transitions):
    name(name),
    transitions(checkTransitions(transitions)),
    alphabet(AlphabetWrapper::getAlphabet()) {

}

State::State(std::string name):
    name(name),
    alphabet(AlphabetWrapper::getAlphabet()) {

}

Transition State::next(char symbol) {
    if(alphabet->find(symbol) == std::string::npos) {
        std::string message = "Alphabet does not contain character ";
        throw InvalidStateException(message.append(&symbol, 1));
    }
    return transitions[symbol];
}

std::string State::getName() {
    return name;
}

std::map<char, Transition> State::checkTransitions(std::map<char, Transition> transitions) {
    // Ensure all parameters exist
    if(transitions.size() != alphabet->size()) {
        std::cout << "Transitions is of size " << transitions.size() << " and alphabet is of size " << alphabet->size() << std::endl;
        throw InvalidStateException("Symbols in alphabet must have a single corresponding action");
    }

    for(const std::pair<const char, Transition> i : transitions) {
        Transition transition = i.second;
        if(transition.second == nullptr) {
            throw InvalidStateException("State referenced by transition does not exist");
        }

        if(!AlphabetWrapper::inAlphabet(i.first)) {
            std::cout << "Found transition for character " << transition.first << std::endl;
            throw InvalidStateException("Transition exists for character undefined by alphabet");
        }
    }

    return transitions;
}

void State::setTransitions(std::map<char, Transition> transitions) {
    this->transitions = checkTransitions(transitions);
}