#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "District.h"

class Simulation {
public:
    Simulation(double x, double y, double z, int totalPopulation, int totalDays); // Constructor
    void initialize(); // Distributes the denizens among 4 districts
    void run(); // Run the simulation

private:
    double x, y, z;
    int totalDays; // Total days of the simulation
    int totalPopulation; // The total population in all 4 districts
    std::vector<District> districts; // Vector containing all 4 districts
};

#endif 
