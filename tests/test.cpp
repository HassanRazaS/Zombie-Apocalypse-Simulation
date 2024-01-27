#include "gtest/gtest.h"
#include "Person.h"
#include "District.h"
#include "Simulation.h"

class PersonTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {}
};

// Test default state of Person as Ignorant
TEST_F(PersonTest, DefaultStateIsIgnorant) {
    Person person; // Initialiaze the person instance
    EXPECT_EQ(person.getState(), Person::IGNORANT); // Validate the default value
}

// Test setting and getting state of Person
TEST_F(PersonTest, SetAndGetState) {
    Person person; // Initialize the person instance
    person.setState(Person::ALARMED); // Set the state to ALARMED
    EXPECT_EQ(person.getState(), Person::ALARMED); // Expect the person's state to be ALARMED
}

class DistrictTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

// Test initialization and getters for District
TEST_F(DistrictTest, InitializationAndGetters) {
    District district("TestDistrict", 100, 0.5, 0.5, 0.3); // Initialize a district with some parameters
    EXPECT_EQ(district.getDistrictName(), "TestDistrict"); // Check the name of the district
    EXPECT_EQ(district.getPopulation(), 100); // Check the population of the district
    EXPECT_EQ(district.getZombieCount(), 0); // Check the zombie count of the district
    EXPECT_EQ(district.getAlarmedCount(), 0); // Check the alarmed count of the district
    EXPECT_EQ(district.getIgnorantCount(), 100); // Check the ignorant count of the district
}

TEST_F(DistrictTest, InteractionsBetweenPeople) {
    // Create a district with a certain population and parameters
    District district("TestDistrict", 100, 0.5, 0.5, 0.3);

    // Perform interactions between people in the district for a certain number of iterations
    // Ensure these interactions change the state of some individuals
    for (int i = 0; i < 10; ++i) {
        district.interactPeople();
    }

    // Validate if after interactions, the counts of Ignorant, Alarmed, and Zombies have changed
    // Modify the assertions based on the expected behavior of interactions in your simulation
    EXPECT_NE(district.getIgnorantCount(), 100); // Ignorant count should change after interactions
    EXPECT_NE(district.getAlarmedCount(), 0);    // Alarmed count should change after interactions
    EXPECT_NE(district.getZombieCount(), 0);     // Zombie count should change after interactions
}

TEST_F(DistrictTest, DistrictMovementBetweenAdjacentDistricts) {
    // Create a vector of districts representing adjacent districts
    std::vector<District> adjacentDistricts;
    adjacentDistricts.emplace_back("District1", 100, 0.5, 0.5, 0.3);
    adjacentDistricts.emplace_back("District2", 150, 0.6, 0.4, 0.2);

    // Create a district and move people to adjacent districts
    District district("TestDistrict", 100, 0.5, 0.5, 0.3);
    district.movePeople(adjacentDistricts);

    // Validate if people have moved to adjacent districts
    // Adjust the assertions based on the expected behavior of movement in your simulation
    EXPECT_NE(district.getPopulation(), 100); // Population should change after movement
    EXPECT_EQ(district.getPopulation(), 0);   // District should be empty after movement
}

TEST_F(DistrictTest, InitializationWithSpecificState) {
    // Create a district with a specific initial state for some people
    District district("TestDistrict", 100, 0.5, 0.5, 0.3);
    // Initialize some people as Zombies or Alarmed
    // Adjust the initialization based on the expected behavior of your simulation
    district.initialize(); // Initialize people

    // Validate if after initialization, the counts of Ignorant, Alarmed, and Zombies are as expected
    // Modify the assertions based on the expected initialization of your simulation
    EXPECT_NE(district.getZombieCount(), 0);  // Ensure some Zombies were initialized
    EXPECT_NE(district.getAlarmedCount(), 0); // Ensure some Alarmed people were initialized
    EXPECT_EQ(district.getIgnorantCount(), 100 - district.getZombieCount() - district.getAlarmedCount());
}

// Main function for running all the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
