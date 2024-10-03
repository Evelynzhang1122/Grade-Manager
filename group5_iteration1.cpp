/**
 * @file group5_iteration1.cpp
 * @author Group 5 (Lu Zhang, Darren Ma, Sarah Hammash, Zhan Hao He)
 * @brief Grade Manager
 * @version 0.1
 * @date 10/2/24
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
    string Name, Class, weighted;
    int StudentID, TotalPoints, GradeA, GradeB, GradeC, GradeD, GradeF;

// Add code in which if name isn't letters, or id isn't an integer, ask user to reinput

    cout << "Enter a name: ";
    cin >> Name;

    cout << "Enter your school ID: ";
    cin >> StudentID;

    cout << "Enter a class: ";
    cin >> Class;

// Find whether assignments are weighted
// If all assignments hold equal weight, go by a point-based system (easier to code)
// If assignments hold different weight, add percentages of how much does assignments, tests, projects, etc. make up the grade (up to 100%)
// Determine how the class is graded
// Find the percentage/points required to get each letter grade

    cout << "Are assignments weighted in this course? (yes/no): ";
    cin >> weighted;

    if (weighted == "yes") {

        cout << "How much points is the class made up of?: ";
        cin >> TotalPoints;
        cout << "Minimum Percentage required to get an A?: ";
        cin >> GradeA;
        cout << "Minimum Percentage required to get a B?: ";
        cin >> GradeB;
        cout << "Minimum Percentage required to get a C?: ";
        cin >> GradeC;
        cout << "Minimum Percentage required to get a D?: ";
        cin >> GradeD;

        int assignmentWeight, examWeight, projectWeight;
        cout << "Enter the percentage weight of assignments: ";
        cin >> assignmentWeight;
        cout << "Enter the percentage weight of exams: ";
        cin >> examWeight;
        cout << "Enter the percentage weight of projects: ";
        cin >> projectWeight;

        // Add checks to make sure weights sum to 100%
      if (assignmentWeight + examWeight + projectWeight != 100) {
            cout << "The weights must add up to 100%. Please re-enter the weights.\n";
            // Loop back to input the weights again if they don't sum to 100.
        } 
    } else if (weighted == "no") {

        cout << "How much points is the class made up of?: ";
        cin >> TotalPoints;
        cout << "Minimum Points required to get an A?: ";
        cin >> GradeA;
        cout << "Minimum Points required to get a B?: ";
        cin >> GradeB;
        cout << "Minimum Points required to get a C?: ";
        cin >> GradeC;
        cout << "Minimum Points required to get a D?: ";
        cin >> GradeD;
        
        int assignmentPoints, examPoints, projectPoints;
        cout << "Enter the amount of points your assignments make up in the course: ";
        cin >> assignmentPoints;
        cout << "Enter the amount of points your exams make up in the course: ";
        cin >> examPoints;
        cout << "Enter the amount of points your projects make up in the course: ";
        cin >> projectPoints;
        // Non-weighted system: Simple percentage-based calculation

    } else {
    cout << "This question must be answered properly. Please try again.\n";
    // Loop back to input for weighted/unweighted question
    }
// Later in the code: user output of whether they are doing good, or need to do better in the course
// Also add code later to see if there are any other courses to test
}
