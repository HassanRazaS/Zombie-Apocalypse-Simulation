#include "Simulation.h"
#include <iostream>

int user() {
    // Set simulation parameters
    int totalDays = 30; 
    int totalPopulation = 2000;
    float x = 0.6; // the likelihood of an ignorant person becoming a zombie on an encounter with zombies - 80%
    float y = 0.6; // the likelihood of an ignorant person becoming alarmed if alerted by an alarmed person - 50%
    float z = 0.3; // the likelihood of an alarmed person becoming a zombie when encounters a zombie - 30%

    // Create and run the simulation
    Simulation simulation(x, y, z, totalPopulation, totalDays);
    simulation.run();

    return 0;
}
