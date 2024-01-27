#include "District.h"
#include <cstdlib>
#include <iostream>

bool randomEvent(double probability) { // Function to check if the person is turning into a zombie or not
    double randomValue = static_cast<double>(rand()) / RAND_MAX; // Gets random number(float) between 0 and 1
    return randomValue < probability; // Compares the values and returns the result
}

District::District(std::string districtName, int population, double x, double y, double z) : districtName(districtName), population(population), x(x), y(y), z(z), zombieCount(0), alarmedCount(0) {
    people.resize(population); // Constructor
}

void District::initialize() {
    // Only initialize a single zombie in Medical Hill
    if (districtName == "MEDICAL_HILL") { // Check if the district is MEDICAL HILL
        people[0].setState(Person::ZOMBIE); // Set the first person's state to ZOMBIE
        zombieCount++; // Adds the zombie count of the district
    }

    // Only initialize a single alarmed person in University
    if (districtName == "UNIVERSITY") { // Check if the district is UNIVERSITY 
        int alarmedIndex = rand() % population; // Get the index for a random person in the district
        people[alarmedIndex].setState(Person::ALARMED); // Change the person's state to ALARMED
        alarmedCount++; // Adds the Alarmed person count of the district
    }
}

void District::interactPeople() { // Function for interatcing people in each district
    try {
        std::vector<Person> newPeople = people; // All denizens inside the district
        for (int i = 0; i < population; ++i) { // Iterates through each person

            if (people[i].getState() == Person::IGNORANT) { // Case where the person is IGNORANT
                int targetIndex = rand() % population; // Get random person in the district

                if (randomEvent(x) && newPeople[targetIndex].getState() != Person::ZOMBIE) { // If the IGNORANT person gets bitten by a zombie
                    newPeople[i].setState(Person::ZOMBIE); // Set the state to Zombie
                    zombieCount++; // Add the zombie count
                } else if (newPeople[targetIndex].getState() == Person::ALARMED && randomEvent(y)) { // if the IGNORANT person escapes a zombie and becomes ALARMED
                    newPeople[i].setState(Person::ALARMED); // Set the state to Alarmed
                    alarmedCount++; // Add the alarmed people count
                } else if (newPeople[targetIndex].getState() == Person::IGNORANT && randomEvent(y)) { // If the IGNORANT person encounter another ALARMED person 
                    newPeople[targetIndex].setState(Person::ALARMED); // Set the state to Alarmed
                    alarmedCount++; // Add the alarmed people count
                }
            } else if (people[i].getState() == Person::ALARMED) { // If the person state is ALARMED
                // Check for transitioning to Ignorant or remaining Alarmed
                int targetIndex = rand() % population; // Get random person
                if (randomEvent(y) && newPeople[targetIndex].getState() == Person::IGNORANT) { // When the Alarmed person encounters an Ignorant person
                    newPeople[targetIndex].setState(Person::ALARMED); // The random person state to ALARMED
                    alarmedCount++; // Add the count for the Alarmed
                } else if (newPeople[targetIndex].getState() == Person::ZOMBIE && randomEvent(y)) { // When the Alarmed person escapes a zombie
                    newPeople[i].setState(Person::ALARMED); // Set the person to Alarmed 
                    alarmedCount++; // Add the count for alarmed
                }
            }
        }

        people = newPeople;
    } catch (const std::exception& e) {
        std::cerr << "Error during interaction: " << e.what() << std::endl;
    }
}



void District::movePeople(std::vector<District>& districts) {
    try {
        std::vector<Person> newPeople(population); // Temporary storage for updated people

        for (int i = 0; i < population; ++i) { // Iterate through each person
            int targetDistrictIndex = rand() % districts.size();

            // Find a valid adjacent district
            while (!isAdjacent(districts[targetDistrictIndex])) {
                targetDistrictIndex = rand() % districts.size();
            }

            // Randomly select a person from the target district and move them
            int targetPersonIndex = rand() % districts[targetDistrictIndex].people.size();
            newPeople[i] = districts[targetDistrictIndex].people[targetPersonIndex];
        }

        people = newPeople; // Update the current district's people
    } catch (const std::exception& e) {
        std::cerr << "Error during movement: " << e.what() << std::endl;
    }
}

bool District::isAdjacent(const District& otherDistrict) {
    // Define an unordered map to store the adjacency relationships
    std::unordered_map<std::string, std::vector<std::string> > adjacencyMap;
    // Fill the adjacency map manually
    adjacencyMap["DOWNTOWN"].push_back("BURBS");
    adjacencyMap["DOWNTOWN"].push_back("UNIVERSITY");

    adjacencyMap["BURBS"].push_back("MEDICAL_HILL");
    adjacencyMap["BURBS"].push_back("DOWNTOWN");

    adjacencyMap["MEDICAL_HILL"].push_back("UNIVERSITY");
    adjacencyMap["MEDICAL_HILL"].push_back("BURBS");

    adjacencyMap["UNIVERSITY"].push_back("DOWNTOWN");
    adjacencyMap["UNIVERSITY"].push_back("MEDICAL_HILL");
    // Get the names of the current and other districts
    const std::string& thisDistrictName = this->getDistrictName();
    const std::string& otherDistrictName = otherDistrict.getDistrictName();

    // Check if the other district is adjacent to this district
    std::unordered_map<std::string, std::vector<std::string> >::iterator it = adjacencyMap.find(thisDistrictName);
    if (it != adjacencyMap.end()) {
        const std::vector<std::string>& adjacentDistricts = it->second;
        return std::find(adjacentDistricts.begin(), adjacentDistricts.end(), otherDistrictName) != adjacentDistricts.end();
    }
    return false; // Not adjacent
}

std::string District::getDistrictName() const {
    return districtName;
}

int District::getPopulation() const {
    return population;
}

int District::getIgnorantCount() const {
    int count = 0;
    for (size_t i = 0; i < people.size(); ++i) {
        if (people[i].getState() == Person::IGNORANT) {
            count++;
        }
    }
    return count;
}

int District::getAlarmedCount() const {
    int count = 0;
    for (size_t i = 0; i < people.size(); ++i) {
        if (people[i].getState() == Person::ALARMED) {
            count++;
        }
    }
    return count;
}

int District::getZombieCount() const {
    return zombieCount;
}
