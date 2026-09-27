#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Course Class - Sirf course ki info hold karti hai
class Course
{
public:
    string code;
    string name;

    Course(string c, string n)
    {
        code = c;
        name = n;
    }
};

// Student Class - Student ki info aur uske courses
class Student
{
public:
    int id;
    string name;
    vector<Course> registeredCourses; // Course ki list

    Student(int i, string n)
    {
        id = i;
        name = n;
    }

    // Course add karne ka logic
    void registerCourse(Course c)
    {
        registeredCourses.push_back(c);
        cout << "SUCCESS: " << c.name << " registered for " << name << endl;
    }

    // Registered courses dekhne ka logic
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
            cout << i + 1 << ". " << registeredCourses[i].code << " - " << registeredCourses[i].name << endl;
        }
    }
};

int main()
{
    // 1. Available Courses create karna
    Course c1("CS101", "Introduction to Programming");
    Course c2("CS102", "Data Structures");
    Course c3("MATH101", "Calculus");

    // 2. Student Create karna
    Student s1(101, "Ali");

    int choice;
    do
    {
        cout << "\n===============================" << endl;
        cout << "  SIMPLE COURSE REGISTRATION   " << endl;
        cout << "===============================" << endl;
        cout << "1. View Available Courses" << endl;
        cout << "2. Register for a Course" << endl;
        cout << "3. View My Registered Courses" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice (1-4): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n--- Available Courses ---" << endl;
            cout << "1. " << c1.code << " - " << c1.name << endl;
            cout << "2. " << c2.code << " - " << c2.name << endl;
            cout << "3. " << c3.code << " - " << c3.name << endl;
        }
        else if (choice == 2)
        {
            int courseNum;
            cout << "\nEnter Course Number to Register (1-3): ";
            cin >> courseNum;

            if (courseNum == 1)
                s1.registerCourse(c1);
            else if (courseNum == 2)
                s1.registerCourse(c2);
            else if (courseNum == 3)
                s1.registerCourse(c3);
            else
                cout << "Invalid Course Number!" << endl;
        }
        else if (choice == 3)
        {
            s1.showCourses();
        }
        else if (choice == 4)
        {
            cout << "Exiting program..." << endl;
        }
        else
        {
            cout << "Invalid Choice! Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}