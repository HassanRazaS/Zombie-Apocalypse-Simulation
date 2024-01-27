#ifndef DISTRICT_H
#define DISTRICT_H

#include <vector>
#include <iostream>
#include "Person.h"

class District {
public:
    District(std::string districtName, int population, double x, double y, double z);
    void initialize(); // Initialize the district with people inside it
    void interactPeople(); // Interact each person of the district
    void movePeople(std::vector<District>& districts); // Move each people to a random adjacent district
    int getIgnorantCount() const; // Getter for number of Ignorant people 
    int getAlarmedCount() const; // Getter for number of Alarmed people 
    int getZombieCount() const; // Getter for number of Zombies
    // Helper functions
    bool isAdjacent(const District& otherDistrict); // Function for checking if the chosen district is adjacent
    std::string getDistrictName() const; // Return the name of the district
    int getPopulation() const; // District population getter
    std::vector<Person> people; // Vector containing each person object

private:
    std::string districtName; // Name of the district
    int population; // Total population of the district
    double x, y, z; // Parameters inherited from main.cpp 
    int zombieCount; // Amount of zombies in the district
    int alarmedCount; // Amount of alarmed people in the district
};

#endif 
