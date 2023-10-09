#ifndef TAPE_HPP
#define TAPE_HPP

#include "AlphabetWrapper.hpp"
#include "DFA.hpp"
#include <vector>
#include <string>

class Turing : public DFA{
    private:
        std::vector<char> tape;
        std::vector<char> negativeTape;
        int head;

    public:
        Turing();
        Turing(std::string input);
        Turing(std::vector<State*> states, State* accept, State* decline);
        Turing(std::vector<State*> states, State* accept, State* decline, std::string input);
        /**
         * @brief Read the current symbol the head of the machine is pointing to
         * 
         * @return char 
         */
        char read();
        /**
         * @brief Write a symbol to the tape that the head of the machine is pointing to
         * 
         * @param symbol 
         */
        void write(char symbol);
        /**
         * @brief Move the head of the tape
         * 
         * @param positive Moves in the positive direction if true, negative direction if false
         */
        void move(bool positive);
        /**
         * @brief Run the turing machine until a halt occurs.
         * @warning Halting is not garaunteed. May hang program.
         * 
         * @return true 
         * @return false 
         */
        bool run();
        /**
         * @brief Run the turing machine until a halt occurs.
         * @warning Halting is not garaunteed. May hang program.
         * 
         * @param msDelay Millisecond delay between steps when printing to console. Set to 0 to disable printing.
         * @return true 
         * @return false 
         */
        bool run(int msDelay);
        /**
         * @brief Advance one step on the turing machine, and return the current state
         * 
         * @return State* 
         */
        State* step();
        /**
         * @brief Get the Tape object
         * 
         * @return std::string String representation of tape
         */
        std::string getTape();
};

#endif