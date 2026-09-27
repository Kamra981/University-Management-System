#include <iostream>
#include <cassert>

// Actual implementation logic
bool canRegisterCourse(bool prerequisitePassed, bool feePaid)
{
    return prerequisitePassed && feePaid;
}

void test_CanRegisterCourse()
{
    // Scenario 1: Both prerequisite and fee paid -> Should return true
    assert(canRegisterCourse(true, true) == true);

    // Scenario 2: Prerequisite passed but fee NOT paid -> Should return false
    assert(canRegisterCourse(true, false) == false);

    std::cout << "All TDD tests PASSED successfully!\n";
}

int main()
{
    std::cout << "Running TDD Tests...\n";
    test_CanRegisterCourse(); // THIS WILL PASS
    return 0;
}