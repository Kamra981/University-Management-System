#include <iostream>
#include <cassert>

// Function signature (Dummy implementation for now)
bool canRegisterCourse(bool prerequisitePassed, bool feePaid)
{
    // Intentionally returning false to make tests fail initially
    return false;
}

void test_CanRegisterCourse()
{
    // Scenario 1: Both prerequisite and fee paid -> Should return true
    assert(canRegisterCourse(true, true) == true);

    // Scenario 2: Prerequisite passed but fee NOT paid -> Should return false
    assert(canRegisterCourse(true, false) == false);

    std::cout << "All tests passed successfully!\n";
}

int main()
{
    std::cout << "Running TDD Tests...\n";
    test_CanRegisterCourse(); // THIS WILL FAIL (Assertion failed!)
    return 0;
}