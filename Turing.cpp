#include "Turing.hpp"

#include <iostream>

Turing::Turing(std::string input) :
    head(0),
    tape(std::vector<char>(input.size())){
    populateTape(input);
}

Turing::Turing() {
    *this = Turing("");
}

Turing::Turing(std::vector<State*> states, std::string input) :
    DFA(states),
    tape(std::vector<char>(input.size())){
    populateTape(input);
}

Turing::Turing(std::vector<State*> states, State* accept, State* decline) :
    DFA(states, accept, decline) {
    populateTape("");
}

Turing::Turing(std::vector<State*> states, State* accept, State* decline, std::string input) :
    DFA(states, accept, decline) {
    populateTape(input);
}

char Turing::read() {
    // If head is out of range, write the first (presumably blank) character
    if(head >= 0) {
        if(head > tape.size()) {
            tape.push_back(AlphabetWrapper::getAlphabet()->at(0));
        }
        return tape.at(head);
    } else {
        if(-head > negativeTape.size()) {
            negativeTape.push_back(AlphabetWrapper::getAlphabet()->at(0));
        }
        return negativeTape.at(-head - 1);
    }
}

void Turing::write(char symbol) {
    if(head >= 0) {
        tape.reserve(head);
        tape.at(head) = symbol;
    } else {
        negativeTape.reserve(-head);  
        negativeTape.at(-head) = symbol;
    }
}

void Turing::move(bool positive) {
    positive ? head++ : head--;
}

bool Turing::run() {
    while(this->getCurrentState() != this->accept && this->getCurrentState() != this->decline) {
        std::cout << this->step()->getName() << std::endl;
    }
    for(const char c : tape) {
        std::cout << c;
    }
    std::cout << std::endl;
    return this->getCurrentState() == this->accept;
}

State* Turing::step() {
    // Execute instruction
    std::string action = this->parse(read());
    switch(action.at(0)) {
        case State::Action::RIGHT:
            head++;
            break;
        case State::Action::LEFT:
            head--;
            break;
        case State::Action::WRITE:
            tape.at(head) = action.at(1);
        default:
        case State::Action::NO_OP:
            break;
    }
    return this->getCurrentState();
}

std::string Turing::getTape() {
    std::string tapeString = "";
    for(const char c : Turing::negativeTape) {
        std::string tempString = std::string(1, c);
        tempString.append(tapeString);
        tapeString = tempString;
    }
    for(const char c : Turing::tape) {
        tapeString.append(std::string(1,c));
    }
    return tapeString;
}

void Turing::populateTape(std::string input) {
    for(int i = 0; i < input.size(); i++) {
        tape.at(i) = input.at(i);
    }
}