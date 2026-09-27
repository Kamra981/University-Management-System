#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Course Class with Capacity Logic
class Course
{
public:
    string code;
    string name;
    int maxCapacity;
    int enrolledCount;

    Course(string c, string n, int cap)
    {
        code = c;
        name = n;
        maxCapacity = cap;
        enrolledCount = 0; // Initially 0 students enrolled
    }

    bool isFull()
    {
        return enrolledCount >= maxCapacity;
    }
};

// Student Class with Duplicate Check and Drop Course Logic
class Student
{
public:
    int id;
    string name;
    vector<Course *> registeredCourses; // Pointers use kar rahe hain taaki main list me update ho

    Student(int i, string n)
    {
        id = i;
        name = n;
    }

    // 1. Check if Course is already registered (Duplicate Check)
    bool isAlreadyRegistered(string courseCode)
    {
        for (int i = 0; i < registeredCourses.size(); i++)
        {
            if (registeredCourses[i]->code == courseCode)
            {
                return true;
            }
        }
        return false;
    }

    // 2. Register Course Logic
    void registerCourse(Course &c)
    {
        // Validation Check 1: Duplicate Course
        if (isAlreadyRegistered(c.code))
        {
            cout << "\n[ERROR] You are ALREADY registered in " << c.name << endl;
            return;
        }

        // Validation Check 2: Seat Capacity
        if (c.isFull())
        {
            cout << "\n[ERROR] Cannot register! " << c.name << " is FULL." << endl;
            return;
        }

        // Success Path
        registeredCourses.push_back(&c);
        c.enrolledCount++; // Capacity count increment
        cout << "\n[SUCCESS] Successfully registered for " << c.name << endl;
    }

    // 3. Drop Course Logic
    void dropCourse(string courseCode)
    {
        for (int i = 0; i < registeredCourses.size(); i++)
        {
            if (registeredCourses[i]->code == courseCode)
            {
                registeredCourses[i]->enrolledCount--; // Decrease enrollment count
                cout << "\n[SUCCESS] Dropped course: " << registeredCourses[i]->name << endl;
                registeredCourses.erase(registeredCourses.begin() + i); // Remove from list
                return;
            }
        }
        cout << "\n[ERROR] You are not enrolled in this course!" << endl;
    }

    // 4. Show Registered Courses
    void showCourses()
    {
        cout << "\n--- Courses for " << name << " (ID: " << id << ") ---" << endl;
        if (registeredCourses.empty())
        {
            cout << "No courses registered yet." << endl;
            return;
        }
        for (int i = 0; i < registeredCourses.size(); i++)
        {
            cout << i + 1 << ". " << registeredCourses[i]->code << " - " << registeredCourses[i]->name << endl;
        }
    }
};

int main()
{
    // 1. Available Courses setup (Code, Name, Max Capacity)
    vector<Course> availableCourses = {
        Course("CS101", "Introduction to Programming", 2), // Max 2 students
        Course("CS102", "Data Structures", 1),             // Max 1 student
        Course("MATH101", "Calculus", 3)                   // Max 3 students
    };

    // 2. Dummy Student Setup
    Student s1(101, "Ali");

    int choice;
    do
    {
        cout << "\n======================================" << endl;
        cout << "  COURSE REGISTRATION SYSTEM (PHASE 2) " << endl;
        cout << "======================================" << endl;
        cout << "1. View Available Courses & Seat Status" << endl;
        cout << "2. Register for a Course" << endl;
        cout << "3. Drop a Course" << endl;
        cout << "4. View My Registered Courses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice (1-5): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n--- Available Courses ---" << endl;
            for (int i = 0; i < availableCourses.size(); i++)
            {
                cout << i + 1 << ". " << availableCourses[i].code << " - " << availableCourses[i].name
                     << " [Seats: " << availableCourses[i].enrolledCount << "/" << availableCourses[i].maxCapacity << "]" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "\n=== Choose Course to Register ===" << endl;
            for (int i = 0; i < availableCourses.size(); i++)
            {
                cout << i + 1 << ". " << availableCourses[i].code << " - " << availableCourses[i].name << endl;
            }
            int courseNum;
            cout << "Enter Choice (1-" << availableCourses.size() << "): ";
            cin >> courseNum;

            if (courseNum >= 1 && courseNum <= availableCourses.size())
            {
                s1.registerCourse(availableCourses[courseNum - 1]);
            }
            else
            {
                cout << "\n[ERROR] Invalid Course Choice!" << endl;
            }
        }
        else if (choice == 3)
        {
            if (s1.registeredCourses.empty())
            {
                cout << "\nYou have no courses to drop." << endl;
            }
            else
            {
                s1.showCourses();
                string codeToDrop;
                cout << "\nEnter Course Code to Drop (e.g. CS101): ";
                cin >> codeToDrop;
                s1.dropCourse(codeToDrop);
            }
        }
        else if (choice == 4)
        {
            s1.showCourses();
        }
        else if (choice == 5)
        {
            cout << "Exiting program..." << endl;
        }
        else
        {
            cout << "\n[ERROR] Invalid Choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}