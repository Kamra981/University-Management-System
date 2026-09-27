#include <iostream>
#include <string>

class StudentProfile
{
private:
    const double MIN_GPA_REQUIRED = 2.0;
    const double DISMISSAL_THRESHOLD_GPA = 1.5;
    const int GRADUATION_CREDITS = 130;

public:
    std::string calculateGradeStatus(double gpa, int totalCredits) const
    {
        // Refactored using Guard Clauses for better readability
        if (gpa < DISMISSAL_THRESHOLD_GPA)
        {
            return "Academic Dismissal";
        }

        if (gpa < MIN_GPA_REQUIRED)
        {
            return "Academic Warning";
        }

        if (totalCredits >= GRADUATION_CREDITS)
        {
            return "Eligible for Graduation";
        }

        return "Good Standing - In Progress";
    }
};

// Verification Driver
int main()
{
    StudentProfile student;
    std::cout << "Status 1: " << student.calculateGradeStatus(3.5, 132) << "\n"; // Eligible for Graduation
    std::cout << "Status 2: " << student.calculateGradeStatus(1.2, 50) << "\n";  // Academic Dismissal
    return 0;
}