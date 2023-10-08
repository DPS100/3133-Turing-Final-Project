#ifndef STATE_HPP
#define STATE_HPP

#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "AlphabetWrapper.hpp"

class State;

typedef std::pair<std::string, State*> Transition;

/**
 * @brief State to be used by a DFA. Pretty much a node in a directed graph.
 */
class State {
    protected:
        std::string name;
        std::map<char, Transition> transitions;
        std::string* alphabet;

    public:
        /**
         * @brief Construct a new State object. 
         * @param name
         * @param transitions Mapped alphabet symbols to target state and transition action to take
         */
        State(std::string name, std::map<char, Transition> transitions);
        /**
         * @brief Get the next state and corresponding transition action
         * 
         * @param symbol Alphabet symbol that defines the next transition
         * @return Transition
         */
        Transition next(char symbol);
        std::string getName();
        bool isTerminated();

        enum Action{
            NO_OP = 'n',
            RIGHT = '>',
            LEFT = '<',
            WRITE = 'w'
        };
};


class InvalidStateException : public std::runtime_error {
    public:
        InvalidStateException(const std::string message) : std::runtime_error(message) {}
};

#endif