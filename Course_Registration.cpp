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

// #include <iostream>
// #include <string>

// class StudentProfile {
// private:
//     const double MIN_PASSING_GPA = 2.0;
//     const double DISMISSAL_THRESHOLD_GPA = 1.5;
//     const int GRADUATION_CREDITS = 130;

// public:
//     std::string calculateGradeStatus(double gpa, int totalCredits) const {
//         // Refactored using Guard Clauses for better readability
//         if (gpa < DISMISSAL_THRESHOLD_GPA) {
//             return "Academic Dismissal";
//         }

//         if (gpa < MIN_PASSING_GPA) {
//             return "Academic Warning";
//         }

//         if (totalCredits >= GRADUATION_CREDITS) {
//             return "Eligible for Graduation";
//         }

//         return "Good Standing - In Progress";
//     }
// };

// // Verification Driver
// int main() {
//     StudentProfile student;
//     std::cout << "Status 1: " << student.calculateGradeStatus(3.5, 132) << "\n"; // Eligible for Graduation
//     std::cout << "Status 2: " << student.calculateGradeStatus(1.2, 50)  << "\n"; // Academic Dismissal
//     return 0;
// }