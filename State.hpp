#ifndef STATE_HPP
#define STATE_HPP

#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <utility>
typedef std::string String;
typedef std::pair<char, State*> Transition;

/**
 * @brief State to be used by a DFA. Pretty much a node in a directed graph.
 */
class State {
    protected:
        String name;
        std::map<char, Transition> transitions;
        bool terminated = false;
        String* alphabet;

    public:
        /**
         * @brief Construct a new State object. 
         * TODO throw error on transitions not being same size as transitionAction, or taking unknown action.
         * @param size
         * @param name
         * @param transitions Mapped alphabet symbols to target state and transition action to take
         */
        State(String name = "", std::map<char, Transition> transitions, String* alphabet);
        /**
         * @brief Get the next state and corresponding transition action
         * 
         * @param symbol Alphabet symbol that defines the next transition
         * @return Transition
         */
        Transition next(char symbol);
        String getName();
        bool isTerminated();

        const static char NO_OP = 'n';
        const static char RIGHT = '>';
        const static char LEFT = '<';
        const static char READ = 'r';
        const static char WRITE = 'w';
        // TODO write needs an extra character... 
        const static String ACTIONS;
};

class InvalidStateException : public std::runtime_error {
    public:
        InvalidStateException(const String message) : std::runtime_error(message) {}
};

#endif