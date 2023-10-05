#ifndef STATE_HPP
#define STATE_HPP

#include <stdexcept>
#include <string>
#include <vector>
typedef std::string String;

/**
 * @brief State to be used by a DFA. Pretty much a node in a directed graph.
 * 
 */
class State {
    protected:
        String name;
        std::vector<State*> transitions;
        std::vector<char> transitionActions;
        bool terminated = false;
        String* alphabet;

    public:
        /**
         * @brief Construct a new State object. 
         * TODO throw error on transitions not being same size as transitionAction, or taking unknown action.
         * @param size
         * @param name
         * @param transitions 
         * @param transitionActions
         */
        State(String name = "", std::vector<State*> transitions, std::vector<char> transitionActions, String* alphabet);
        State next(char symbol);
        String toString();
        String getName();
        bool isTerminated();
        bool validate();


        const static char NO_OP = 'n';
        const static char RIGHT = '>';
        const static char LEFT = '<';
        const static char READ = 'r';
        const static char WRITE = 'w';
        constexpr static char ACTIONS[] = {NO_OP, RIGHT, LEFT, READ, WRITE};


};

class InvalidStateException : public std::runtime_error {
    public:
        InvalidStateException(const String message) : std::runtime_error(message) {}
};

#endif