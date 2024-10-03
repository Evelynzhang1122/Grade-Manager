/**
 * @file group5_iteration1.cpp
 * @author Group 5 (Lu Zhang, Darren Ma, Sarah Hammash, Zhan Hao He)
 * @brief Grade Manager
 * @version 0.1
 * @date 9/28/24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// Include Directives & Namespace STD used in this version
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string Name, Class;
    int StudentID, TotalPoints, GradeA, GradeB, GradeC, GradeD, GradeF;

// Add code in which if name isn't letters, or id isn't an integer, ask user to reinput

    cout << "Enter a name: ";
    cin >> Name;

    cout << "Enter your school ID: ";
    cin >> StudentID;

    cout << "Enter a class: ";
    cin >> Class;

// Determine how the class is graded
// Find the percentage required to get each letter grade

    cout << "Minimum Percentage required to get an A?: ";
    cin >> GradeA;
    cout << "Minimum Percentage required to get a B?: ";
    cin >> GradeB;
    cout << "Minimum Percentage required to get a C?: ";
    cin >> GradeC;
    cout << "Minimum Percentage required to get a D?: ";
    cin >> GradeD;
    cout << "Minimum Percentage required to get a F?: ";
    cin >> GradeF;
    cout << "How much points is the class made up of?: ";
    cin >> TotalPoints;


// Find whether assignments are weighted
// If all assignments hold equal weight, go by a point-based system (easier to code)
// If assignments hold different weight, add percentages of how much does assignments, tests, projects, etc. make up the grade (up to 100%)

    cout << "Are assignments weighted in this course? (yes/no): ";
    

// Later in the code: user output of whether they are doing good, or need to do better in the course
// Also add code later to see if there are any other courses to test

}