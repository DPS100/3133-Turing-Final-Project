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
        if(head == tape.size()) {
            tape.push_back(AlphabetWrapper::getAlphabet()->at(0));
        }
        return tape.at(head);
    } else {
        if(-head - 1 == negativeTape.size()) {
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
        negativeTape.reserve(-head - 1);  
        negativeTape.at(-head - 1) = symbol;
    }
}

void Turing::move(bool positive) {
    positive ? head++ : head--;
}

bool Turing::run() {
    while(this->getCurrentState() != this->accept && this->getCurrentState() != this->decline) {
        printTape();
        std::cout << this->step(false)->getName() << std::endl;
    }
    return this->getCurrentState() == this->accept;
}

State* Turing::step(bool print) {
    // Execute instruction
    char symbol = read();
    if(print) {
        std::cout << this->getCurrentState()->getName() << std::endl;
        printTape();
    }
    std::string action = this->parse(symbol);
    switch(action.at(0)) {
        case State::Action::RIGHT:
            move(true);
            break;
        case State::Action::LEFT:
            move(false);
            break;
        case State::Action::WRITE:
            tape.at(head) = action.at(1);
            break;
        default:
        case State::Action::NO_OP:
            break;
    }
    return this->getCurrentState();
}

State* Turing::step() {
    return step(false);
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

void Turing::printTape() {
    for(int i = (head < 0 ? head : 0); i < tape.size(); i++) {
        char c;
        if(i < 0) {
            c = negativeTape.at(-i - 1);
        } else {
            c = tape.at(i);
        }
        if(i == head) {
            std::cout << '[' <<  c << ']';
        } else {
            std::cout << c;
        }
    }
    std::cout << std::endl;
}

void Turing::populateTape(std::string input) {
    for(int i = 0; i < input.size(); i++) {
        tape.at(i) = input.at(i);
    }
}