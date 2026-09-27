#include <iostream>
#include <cassert>

class StudentProfile
{
public:
    std::string calculateGradeStatus(double gpa, int totalCredits)
    {
        // Bad Practice: Nested conditions and hardcoded magic numbers
        if (gpa >= 2.0)
        {
            if (totalCredits >= 130)
            {
                return "Eligible for Graduation";
            }
            else
            {
                return "Good Standing - In Progress";
            }
        }
        else
        {
            if (gpa < 1.5)
            {
                return "Academic Dismissal";
            }
            else
            {
                return "Academic Warning";
            }
        }
    }
};

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

#include <iostream>
#include <string>
