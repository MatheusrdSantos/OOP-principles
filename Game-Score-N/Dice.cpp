#include "Dice.h"
Dice::Dice():rd(), gen(rd()), dis(1, 6) {}



int Dice::throwDice() {
    this->value = dis(gen);
    cout<<"Dice: "<<this->value<<endl;
    return this->value;
}

int Dice::getValue() {
    return this->value;
}