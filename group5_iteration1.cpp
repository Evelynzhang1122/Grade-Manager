/**
 * @file group5_iteration2.cpp
 * @author Group 5 (Lu Zhang, Darren Ma, Sarah Hammash, Zhan Hao He)
 * @brief Grade Manager
 * @version Final Version
 * @date 11/27/24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// Include Directives & Namespace STD used in this version (fixed & SetPrecision will later be implemented)
#include <iostream>
#include <iomanip>
#include <limits> // For std::numeric_limits
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

    if (cin.fail()) {  // will fail if the input is not an int. It will then restart by calling the main funciton
        cout << "Invalid input. Please Restart" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discards the invalid input
        //Source: https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
        main();
    }

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
        
        // Allow the user to enter multiple scores until the user chooses to stop
        // Based off the assumption that the scores are out of 100 points each.
            char moreInput;
            double totalAssignments = 0, totalQuizzes = 0, totalExams = 0, totalProjects = 0;
            int amountAssignments = 0, amountQuizzes = 0, amountExams = 0, amountProjects = 0;
            double assignmentScore, quizScore, examScore, projectScore;
            double assignmentDecimal, quizDecimal, examDecimal, projectDecimal;
            double tAssignmentWeight, tQuizWeight, tExamWeight, tProjectWeight;
            
        // input loop of homework
        do {
            cout << "Enter your assignment score: ";
            cin >> assignmentScore;
            totalAssignments += assignmentScore;  // 累加分数
            amountAssignments += 1;

            cout << "Do you have more assignment scores to enter? (y/n): ";
            cin >> moreInput;
        } while (moreInput == 'y');

        // input loop of quiz
        do {
            cout << "Enter your quiz score: ";
            cin >> quizScore;
            totalQuizzes += quizScore;
            amountQuizzes += 1;

            cout << "Do you have more quiz scores to enter? (y/n): ";
            cin >> moreInput;
        } while (moreInput == 'y');

        // input loop of exam
        do {
            cout << "Enter your exam score: ";
            cin >> examScore;
            totalExams += examScore;
            amountExams += 1;

            cout << "Do you have more exam scores to enter? (y/n): ";
            cin >> moreInput;
        } while (moreInput == 'y');

        // input loop of project
        do {
            cout << "Enter your project score: ";
            cin >> projectScore;
            totalProjects += projectScore;
            amountProjects += 1;

            cout << "Do you have more project scores to enter? (y/n): ";
            cin >> moreInput;
        } while (moreInput == 'y');

        // input total points
        cout << "Total assignment points: " << totalAssignments << ", Amount of assignments inputted: " << amountAssignments << endl;
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

        if (weightedGrade >= GradeA) {
            cout << "You have an A in this course." << endl;
        } else if (weightedGrade < GradeA && weightedGrade >= GradeB) {
            cout << "You have a B in this course." << endl;
        } else if (weightedGrade < GradeB && weightedGrade >= GradeC) {
            cout << "You have a C in this course." << endl;
        } else if (weightedGrade < GradeC && weightedGrade >= GradeD) {
            cout << "You have a D in this course." << endl;
        } else if (weightedGrade < GradeD) {
            cout << "You have a F in this course." << endl;
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
        

        // Since in unweighted grading, all coursework holds the same weight, assignment types will most likely not matter in this portion and will probably be erased.
        char moreInput;
        int score, totalScore = 0;

        // Warning for score inputs
        cout << "When entering scores, make sure your inputs do not exceed the total points the class is made up of. Doing so will lead to the reset of score inputs.\n";

        do {
            cout << "Enter a score: ";
            cin >> score;
            totalScore += score;

        // Should look into a feature that allows changes in scores to avoid having user input all scores again if a small number error was made
        // As for now, this program essentially makes sure score inputs does not exceed the total score cap.
            if (totalScore > TotalPoints) {
                cout << "Your score inputs should not exceed the total amount of points. Please re-enter your scores." << endl;
                totalScore = 0;
            }

            cout << "Total Score: " << totalScore << endl;
            cout << "Do you have more scores to enter? (y/n): ";
            cin >> moreInput;
        } while (moreInput == 'y');

        // Non-weighted system: Simple point-based calculation
        // Make sure to add code that prevents users from inputting a total score that exceeds the amount user previously mentioned 
        // (ex: if assignments is worth 200 points, user inputs should not exceed 200)

    } else {
    cout << "This question must be answered properly. Please try again.\n";
    // Loop back to input for weighted/unweighted question
    }
// Later in the code: user output of whether they are doing good, or need to do better in the course
// Also add code later to see if there are any other courses to test
// Use functions so we can simplify the structure of the program and be able to use certain parts again
// Can also potentially add a feature in which we allow the user to input the name of the coursework before asking for score so they do not get confused.
}
