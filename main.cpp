#include <iostream>
#include <string>
#include <fstream>
#include "Turing.hpp"

/**
 * @brief 
 * 
 * @param arc Number of arguments
 * @param argv Array of argument
 * @return int 
 */
int main(int argc, char** argv) {
    // Read args
    if(argc != 2) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return 1;
    }

    // Read input file
    std::string filename = argv[1];
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    // Temporarily set alphabet
    std::string alphabet = "";
    AlphabetWrapper::setAlphabet(&alphabet);

    // Read states at top of file
    std::vector<State*> states;
    std::string state;
    std::getline(inputFile, state);
    int emptyLineLength = state.length();
    while(std::getline(inputFile, state)) {
        if(state.length() == emptyLineLength) { // Empty line
            break;
        }
        // Remove the last character from the state
        state = state.substr(0, state.length() - emptyLineLength);
        // std::cout << state << std::endl;
        states.push_back(new State(state));
    }

    // Read language
    std::getline(inputFile, alphabet);
    std::cout << "Alphabet: " << alphabet << std::endl;
    AlphabetWrapper::setAlphabet(&alphabet);

    // Read starting tape
    std::string tape;
    std::getline(inputFile, tape);
    std::cout << "Tape: " << tape << std::endl;

    // Read transitions
    std::string transitionStrings[alphabet.length()];
    int index = 0;
    while(inputFile >> transitionStrings[index % alphabet.length()]) {
        // int transitionStringIndex = index % alphabet.length();
        if(index % alphabet.length() == alphabet.length() - 1) {
            // std::cout << "Setting state " << states.at(index / alphabet.length())->getName() << std::endl;
            std::map<char, Transition> transitions;
            for(int i = 0; i < alphabet.length(); i++) {
                char symbol = alphabet.at(i);
                int digitIndex = 0;
                while (digitIndex < transitionStrings[i].length() && isdigit(transitionStrings[i][digitIndex])) {
                    digitIndex++;
                }
                int targetState = stoi(transitionStrings[i].substr(0, digitIndex)) - 1;
                std::string instruction = transitionStrings[i].substr(digitIndex);
                // std::cout << targetState << instruction << std::endl;
                transitions.emplace(symbol, Transition(transitionStrings[i], states.at(targetState)));
                // std::cout << "When reading symbol " << symbol << ", take action " << instruction << " and move to state " << targetState << ": " << states.at(targetState)->getName() << std::endl;
            }
            states.at(index / alphabet.length())->setTransitions(transitions);
        }
        index++;
    }
    states.shrink_to_fit();

    Turing machine(states, tape);
    std::cout << machine.getCurrentState()->getName() << std::endl;
    return 0;
}