#include "Person.h"

// Person class methods
Person::Person() : state(IGNORANT) {}

Person::State Person::getState() const {
    return state;
}

void Person::setState(State newState) {
    state = newState;
}

Person::~Person() {}

// Zombie class methods
Person::State Zombie::getState() const {
    return ZOMBIE;
}

// Alarmed class methods
Person::State Alarmed::getState() const {
    return ALARMED;
}

// Ignorant class methods
Person::State Ignorant::getState() const {
    return IGNORANT;
}
