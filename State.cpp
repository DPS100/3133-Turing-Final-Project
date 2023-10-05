#include "State.hpp"



State::State(String name = "", std::vector<State*> transitions, std::vector<char> transitionActions, String* alphabet):
    name(name),
    transitions(transitions),
    transitionActions(transitionActions), 
    alphabet(alphabet){
        // Check alphabet exists
        if(alphabet == nullptr) {
            throw InvalidStateException("Alphabet not defined");
        }

        if(transitionActions.size() != transitionActions.size()) {
            throw InvalidStateException("Transitions must have a single corresponding action");
        }

        if(transitions == nullptr) {
            throw InvalidStateException("Transitions not defined");
        }

        if(transitionActions == nullptr) {
            throw InvalidStateException("Transition actions not defined");
        }

        for(int i = 0;)
        // Check arrays are the same size
}