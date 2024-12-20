/**
 * @file group5_iteration2.cpp
 * @author Group 5 (Lu Zhang, Darren Ma, Sarah Hammash, Zhan Hao He)
 * @brief Grade Manager
 * @version Final Version
 * @date 12/4/24
 * 
 * @copyright Copyright (c) 2024
 * 
 */


// Include Directives & Namespace STD used in this version (fixed & setprecision will later be implemented)
#include <iostream>
#include <iomanip>
#include <limits> // For std::numeric_limits
using namespace std;

// Functions
void getStudentInfo(string& Name, int& StudentID, string& Class);
void weightedGrading();
void unweightedGrading();
string getLetterGrade(double score, int GradeA, int GradeB, int GradeC, int GradeD);

int main()
{
    string choice = "Y"; // Set to Y to make sure continue works

    do {
        // Get student info
        string Name, Class;
        int StudentID;

        getStudentInfo(Name, StudentID, Class);

        string weightChoice;

        // Find whether assignments are weighted
        cout << "Are assignments weighted in this course? (y/n): ";
        cin >> weightChoice;

        if (weightChoice == "y" || weightChoice == "Y") {
            weightedGrading();
        } else if (weightChoice == "n" || weightChoice == "N") {
            unweightedGrading();
        } else {
            cout << "Invalid Input. Restarting the program.\n";
            continue; // Will restart the loop
        }

        cout << "\nDo you want to continue using this program? (y/n): ";
        cin >> choice;

    } while (choice == "Y" || choice == "y");

}

void getStudentInfo(string& Name, int& StudentID, string& Class) {
    // Add code in which if name isn't letters, or id isn't an integer, ask user to reinput
    while (true) {
        cout << "Enter a name: ";
        cin >> Name;

        cout << "Enter your school ID: ";
        cin >> StudentID;

        if (cin.fail()) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Restart the loop
        }

        cout << "Enter a class: ";
        cin >> Class;

        break; // Break out of the loop if inputs are valid
    }
}

void weightedGrading() {
    // Find the percentage/points required to get each letter grade
    int GradeA, GradeB, GradeC, GradeD;
    cout << "Minimum Percentage required to get an A?: ";
    cin >> GradeA;
    cout << "Minimum Percentage required to get a B?: ";
    cin >> GradeB;
    cout << "Minimum Percentage required to get a C?: ";
    cin >> GradeC;
    cout << "Minimum Percentage required to get a D?: ";
    cin >> GradeD;

    int assignmentWeight, quizWeight, examWeight, projectWeight;
    cout << "Enter the percentage weight of assignments: ";
    cin >> assignmentWeight;
    cout << "Enter the percentage weight of quizzes: ";
    cin >> quizWeight;
    cout << "Enter the percentage weight of exams: ";
    cin >> examWeight;
    cout << "Enter the percentage weight of projects: ";
    cin >> projectWeight;

    // Add checks to make sure weights sum to 100%
    while (assignmentWeight + quizWeight + examWeight + projectWeight != 100) {
        cout << "The weights must add up to 100%. Please re-enter the weights.\n";
        // Loop back to input the weights again if they don't sum to 100.
        cout << "Enter the percentage weight of assignments: ";
        cin >> assignmentWeight;
        cout << "Enter the percentage weight of quizzes: ";
        cin >> quizWeight;
        cout << "Enter the percentage weight of exams: ";
        cin >> examWeight;
        cout << "Enter the percentage weight of projects: ";
        cin >> projectWeight;
    } 

    // Variable Declarations
    char moreInput;
    double totalAssignments = 0, totalQuizzes = 0, totalExams = 0, totalProjects = 0;
    int amountAssignments = 0, amountQuizzes = 0, amountExams = 0, amountProjects = 0;
    double assignmentScore, quizScore, examScore, projectScore;
    double assignmentDecimal, quizDecimal, examDecimal, projectDecimal;
    double tAssignmentWeight, tQuizWeight, tExamWeight, tProjectWeight;
    
    // Allow the user to enter multiple scores until the user chooses to stop
    // Input loop for assignments
    do {
        cout << "Enter your assignment score: ";
        cin >> assignmentScore;
        totalAssignments += assignmentScore;  
        amountAssignments += 1;

        cout << "Do you have more assignment scores to enter? (y/n): ";
        cin >> moreInput;
    } while (moreInput == 'y');

    // Input loop for quizzes
    do {
        cout << "Enter your quiz score: ";
        cin >> quizScore;
        totalQuizzes += quizScore;
        amountQuizzes += 1;

        cout << "Do you have more quiz scores to enter? (y/n): ";
        cin >> moreInput;
    } while (moreInput == 'y');

    // Input loop for exams
    do {
        cout << "Enter your exam score: ";
        cin >> examScore;
        totalExams += examScore;
        amountExams += 1;

        cout << "Do you have more exam scores to enter? (y/n): ";
        cin >> moreInput;
    } while (moreInput == 'y');

    // Input loop for projects
    do {
        cout << "Enter your project score: ";
        cin >> projectScore;
        totalProjects += projectScore;
        amountProjects += 1;

        cout << "Do you have more project scores to enter? (y/n): ";
        cin >> moreInput;
    } while (moreInput == 'y');

    // Output total points
    cout << "\nTotal assignment points: " << totalAssignments << ", Amount of assignments inputted: " << amountAssignments << endl;
    cout << "Total quiz points: " << totalQuizzes << ", Amount of quizzes inputted: " << amountQuizzes << endl;
    cout << "Total exam points: " << totalExams << ", Amount of exams inputted: " << amountExams << endl;
    cout << "Total project points: " << totalProjects << ", Amount of projects inputted: " << amountProjects << endl;

    // Turn percentage weight of categories into decimals, which will be used for grade calculation.
    assignmentDecimal = assignmentWeight / 100.0;
    quizDecimal = quizWeight / 100.0;
    examDecimal = examWeight / 100.0;
    projectDecimal = projectWeight / 100.0;

    // Calculations to find weighted grade (Total points divided by amount of inputs, multiplied by decimal of weight per category)
    tAssignmentWeight = (totalAssignments / amountAssignments) * assignmentDecimal;
    tQuizWeight = (totalQuizzes / amountQuizzes) * quizDecimal;
    tExamWeight = (totalExams / amountExams) * examDecimal;
    tProjectWeight = (totalProjects / amountProjects) * projectDecimal;
    double weightedGrade = tAssignmentWeight + tQuizWeight + tExamWeight + tProjectWeight;
    cout << "Your Weighted Grade is: " << fixed << setprecision(2) << weightedGrade << endl;

    // Grade Placement after final grade is calculated
    string letterGrade = getLetterGrade(weightedGrade, GradeA, GradeB, GradeC, GradeD);
    cout << "You have a " << letterGrade << " in this course." << endl;
}

void unweightedGrading() {
    int TotalPoints;
    int GradeA, GradeB, GradeC, GradeD;

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

    // Since in unweighted grading, all coursework holds the same weight, assignment types does not matter in this portion
    char moreInput;
    int score, totalScore = 0;

    // Warning for score inputs
    cout << "When entering scores, make sure your inputs do not exceed the total points the class is made up of. Doing so will lead to the reset of score inputs.\n";

    do {
        cout << "Enter a score: ";
        cin >> score;
        totalScore += score;

        // As for now, this program ensures score inputs do not exceed the total score cap.
        if (totalScore > TotalPoints) {
            cout << "Your score inputs should not exceed the total amount of points. Please re-enter your scores." << endl;
            totalScore = 0;
        }
        cout << "Total Score: " << totalScore << endl;
        cout << "Do you have more scores to enter? (y/n): ";
        cin >> moreInput;
    } while (moreInput == 'y');

    // Grade Placement after final grade is calculated
    string letterGrade = getLetterGrade(totalScore, GradeA, GradeB, GradeC, GradeD);
    cout << "You have a " << letterGrade << " in this course." << endl;
}

string getLetterGrade(double score, int GradeA, int GradeB, int GradeC, int GradeD) {
    if (score >= GradeA) {
        return "A";
    } else if (score >= GradeB) {
        return "B";
    } else if (score >= GradeC) {
        return "C";
    } else if (score >= GradeD) {
        return "D";
    } else {
        return "F";
    }
}

