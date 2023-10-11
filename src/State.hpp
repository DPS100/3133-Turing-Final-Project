#ifndef STATE_HPP
#define STATE_HPP

#include <stdexcept>
#include <string>
#include <map>
#include "AlphabetWrapper.hpp"

class State;

/**
 * @brief
 * 
 * @param std::string Action to take before transition
 * @param State* Target state to transition to
 */
typedef std::pair<std::string, State*> Transition;

/**
 * @brief State to be used by a DFA. Pretty much a node in a directed graph.
 */
class State {
    protected:
        std::string name;
        std::map<char, Transition> transitions;
        std::string* alphabet;
        /**
         * @brief Helper to validate all transitions.
         * 
         * @param transitions 
         * @return std::map<char, Transition> 
         * @throws State::InvalidStateException if a transition is not valid
         */
        std::map<char, Transition> checkTransitions(std::map<char, Transition> transitions);

    public:
        /**
         * @brief Construct a new State object. 
         * @param name
         * @param transitions Mapped alphabet symbols and corresponding transition
         */
        State(std::string name, std::map<char, Transition> transitions);
        /**
         * @brief Construct an empty State object
         * 
         */
        State(std::string name);
        /**
         * @brief Peek the next state and corresponding transition action
         * 
         * @param symbol Alphabet symbol that defines the next transition
         * @return Transition
         */
        Transition next(char symbol);
        /**
         * @brief Get this state's name
         * 
         * @return std::string 
         */
        std::string getName();
        /**
         * @brief Set the Transitions object
         * 
         * @param transitions 
         */
        void setTransitions(std::map<char, Transition> transitions);

        /**
         * @brief Four defined actions the turing machine can make
         * 
         */
        enum Action{
            NO_OP = 'N',
            RIGHT = '>',
            LEFT = '<',
            WRITE = 'W'
        };
};


class InvalidStateException : public std::runtime_error {
    public:
        InvalidStateException(const std::string message) : std::runtime_error(message) {}
};

#endif