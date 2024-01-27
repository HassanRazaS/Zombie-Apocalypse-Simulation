#include "Simulation.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

Simulation::Simulation(double x, double y, double z, int totalPopulation, int totalDays) : x(x), y(y), z(z), totalPopulation(totalPopulation), totalDays(totalDays)
{
  int downtownPopulation = totalPopulation * 0.3;
  int burbsPopulation = totalPopulation * 0.4;
  int medicalHillPopulation = totalPopulation * 0.2;
  int universityPopulation = totalPopulation * 0.1;

  districts.push_back(District("DOWNTOWN", downtownPopulation, x, y, z));
  districts.push_back(District("BURBS", burbsPopulation, x, y, z));
  districts.push_back(District("MEDICAL_HILL", medicalHillPopulation, x, y, z));
  districts.push_back(District("UNIVERSITY", universityPopulation, x, y, z));

  initialize();
}

void Simulation::initialize() {
    for (size_t i = 0; i < districts.size(); ++i) {
        districts[i].initialize();
    }
}

void Simulation::run() {
    try {
        std::ofstream outputFile("outbreak_data.csv");
        if (!outputFile.is_open()) {
            throw std::runtime_error("Unable to open the output file!");
        }
        outputFile << "** Outbreak Simulation **\n\n";
        outputFile << "Total Population: " << totalPopulation << "\n";
        outputFile << "Total Days: " << totalDays << "\n\n";
        outputFile << "Day\tDistrict\tIgnorant\tAlarmed\tZombies\n";

        for (size_t i = 0; i < districts.size(); ++i) {
            District& currentDistrict = districts[i];
            currentDistrict.initialize();

            int ignorantCount = currentDistrict.getPopulation() - 2;
            int alarmedCount = (currentDistrict.getDistrictName() == "UNIVERSITY") ? 2 : 0;
            int zombieCount = (currentDistrict.getDistrictName() == "MEDICAL_HILL") ? 1 : 0;

            outputFile << "-------------------------------------------------------------\n";
            outputFile << "Initial: District: " << currentDistrict.getDistrictName() << "\n";
            outputFile << "-------------------------------------------------------------\n";
            outputFile << "Ignorant: " << ignorantCount << "\n";
            outputFile << "Alarmed: " << alarmedCount << "\n";
            outputFile << "Zombies: " << zombieCount << "\n\n";
        }

        for (int day = 1; day <= totalDays; ++day) {
            for (size_t i = 0; i < districts.size(); ++i) {
                districts[i].interactPeople();
            }

            for (size_t i = 0; i < districts.size(); ++i) {
                districts[i].movePeople(districts);
                int ignorantCount = districts[i].getIgnorantCount();
                int alarmedCount = districts[i].getAlarmedCount();
                int zombieCount = districts[i].getZombieCount();

                outputFile << "-------------------------------------------------------------\n";
                outputFile << "Day " << day << ", District: " << districts[i].getDistrictName() << "\n";
                outputFile << "-------------------------------------------------------------\n";
                outputFile << "Ignorant: " << ignorantCount << "\n";
                outputFile << "Alarmed: " << alarmedCount << "\n";
                outputFile << "Zombies: " << zombieCount << "\n\n";

                outputFile << day << ", " << districts[i].getDistrictName() << ", "
                           << ignorantCount << ", " << alarmedCount << ", " << zombieCount << "\n";
            }
        }

        outputFile.close();
        std::cout << "Outbreak data saved to 'outbreak_data.csv'.\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
