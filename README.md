# Zombie Outbreak Simulation

## Purpose

This project involves the development of a simulation model to study the spread of a zombie infection within a population. This README.md file provides an overview of the requirements specification, use cases, UML diagrams, trend graph, pseudocode, and instructions for running the simulation.

## Requirements Specification

### Inputs

- Initial population size (integer)
- Percentage of initial population infected (float)
- Probability of infection on contact (float)
- Probability of becoming alarmed on contact with infected (float)
- Probability of becoming infected when alarmed and encountering infected (float)
- Simulation duration (integer days)

### Outputs

- Number of infected individuals per district per day (integer)
- Total number of individuals infected throughout the simulation (integer)
- Total number of deaths due to infection (integer)

### Performance Requirements

- Simulate a population of 20,000 individuals.

## Use Cases

### Actors

- User: Initiates and monitors the simulation.
- Simulation System: Conducts the simulation based on user-defined parameters.

### Preconditions

- The system is set up with initial parameters.
- The city is divided into districts with varying populations.

### Flow of Events

1. **User Initialization:**
   - Set simulation parameters.

2. **Simulation Initialization:**
   - Create a simulated city with multiple districts.
   - Initialize districts with unique conditions.

3. **Simulation Execution:**
   - Run the simulation for the specified number of days.
   - Simulate interactions and movements of individuals.
   - Record data at the end of each day.

4. **Data Collection:**
   - Collect and record data at the end of each day.

5. **Results Output:**
   - Generate an output file ("outbreak_data.csv") with the simulation summary.

### Postconditions

- The simulation completes after the specified number of days.
- The output file provides insights into the spread of the zombie outbreak.

### Alternative Flows

- Notify the user in case of errors during the simulation.

### Exception Handling

- Log errors in the console if they occur during the simulation.

## UML Diagrams

included in files as ZombieUML

### Simulation and District Class Relationship

This indicates that a Simulation object contains and owns multiple District objects. The composition relationship is represented by a line connecting Simulation to District with a filled diamond shape on the Simulation end of the line. The diamond shape indicates composition.

### Simulation and Person Class Relationship

This represents a dependency relationship where the Simulation class depends on the Person class, even though there is no direct association between them. The dashed line connecting Simulation to Person with an arrowhead indicates this dependency. The arrowhead points from Simulation to Person to show the direction of the dependency.

### District and Person Class Relationship

This represents an association where a District object is associated with multiple Person objects. The solid line connecting District to Person indicates this association. The association suggests that the district class has a collection of Person objects as part of its attributes or members.

### Person and Zombie, Alarmed, Ignorant Class Relationship

Zombie, Alarmed, and Ignorant inherit from the Person class and share common attributes and methods. The arrowhead on the line points from the subclasses to the superclass to indicate the direction of the inheritance relationship.

## Trend Graph

Included in the files as zombieGraph and zombieData

## Pseudocode

### 1. District.h

```cpp
class District {
    District(string districtName, int population, double x, double y, double z)
        // Initialize the District with given parameters.

    void initialize()
        // Initialize the district by setting up initial conditions.

    void interactPeople()
        // Simulate interactions between people within the district.

    void movePeople(vector<District>& districts)
        // Simulate movement of people between districts.

    int getIgnorantCount() const
        // Return the count of people in the Ignorant state.

    int getAlarmedCount() const
        // Return the count of people in the Alarmed state.

    int getZombieCount() const
        // Return the count of people in the Zombie state.

    bool isAdjacent(const District& otherDistrict)
        // Check if the current district is adjacent to the given district.

    string getDistrictName() const
        // Get the name of the district.

    int getPopulation() const
        // Get the total population of the district.
}

```

### 2. Person.h

```cpp
class Person {
    Person()
        // Initialize a person in the Ignorant state.

    State getState() const
        // Get the current state of the person.

    void setState(State newState)
        // Set the state of the person.

    virtual ~Person()
        // Virtual destructor for polymorphic behavior.

    // Zombie, Alarmed, Ignorant class definitions...
}

```

### 3. Simulation.h

```cpp
class Simulation {
    Simulation(double x, double y, double z, int totalPopulation, int totalDays)
        // Initialize the simulation with given parameters.

    void initialize()
        // Initialize all districts in the simulation.

    void run()
        // Run the simulation for the specified number of days.
}


```

### 4. District.cpp

```cpp
bool randomEvent(double probability)
    // Simulate a random event based on the given probability.

District::District(string districtName, int population, double x, double y, double z)
    // Initialize the district with the given parameters.

void District::initialize()
    // Set up initial conditions for the district.

void District::interactPeople()
    // Simulate interactions between people within the district.

void District::movePeople(vector<District>& districts)
    // Simulate movement of people between districts.

bool District::isAdjacent(const District& otherDistrict)
    // Check if the current district is adjacent to the given district.

string District::getDistrictName() const
    // Get the name of the district.

int District::getPopulation() const
    // Get the total population of the district.

int District::getIgnorantCount() const
    // Return the count of people in the Ignorant state.

int District::getAlarmedCount() const
    // Return the count of people in the Alarmed state.

int District::getZombieCount() const
    // Return the count of people in the Zombie state.

```
### 5. Person.cpp

```cpp
Person::Person()
    // Initialize a person in the Ignorant state.

Person::State Person::getState() const
    // Get the current state of the person.

void Person::setState(State newState)
    // Set the state of the person.

Person::~Person()
    // Destructor for Person class.

Person::State Zombie::getState() const
    // Get the state of the Zombie.

Person::State Alarmed::getState() const
    // Get the state of the Alarmed.

Person::State Ignorant::getState() const
    // Get the state of the Ignorant.
```

### 6. Simulation.cpp

```cpp
Simulation::Simulation(double x, double y, double z, int totalPopulation, int totalDays)
    // Initialize the simulation with the given parameters.

void Simulation::initialize()
    // Initialize all districts in the simulation.

void Simulation::run()
    // Run the simulation for the specified number of days.

```

### 7. main.cpp

```cpp
int main()
  // Main function to set simulation parameters, create, and run the simulation.
```



