#ifndef PERSON_H
#define PERSON_H

class Person {
public:
    enum State { IGNORANT, ALARMED, ZOMBIE }; // Using enumunator for 3 states for denizens

    Person(); // Class constructor
    virtual State getState() const; // Getter for getting the state of the person
    void setState(State newState); // Setter for changing the state of the person

    virtual ~Person(); // Define a virtual destructor for polymorphic behavior
private:
    State state; // Contain the state
};

class Zombie : public Person { // Zombie class inheritance for getState() function polymorphism
public:
    State getState() const;
};

class Alarmed : public Person { // Alarmed class inheritance for getState() function polymorphism
public:
    State getState() const;
};

class Ignorant : public Person { // Ignorant class inheritance for getState() function polymorphism
public:
    State getState() const;
};

#endif
