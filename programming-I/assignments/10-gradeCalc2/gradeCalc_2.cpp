//*****************************************************************************************************
//
//		This program is a grade calculator program for a computer programming course that uses
//      functions to calculate the final grade. The program takes in four grades as percentages and
//      uses predefined weights to calculate the weighted grades for each deliverable. The final grade
//      is then displayed as a percentage.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

void readGrades(float &, float &, float &, float &);                                  // pass bye reference ( & )
void calcWeights(float &, float &, float &, float &, float, float, float, float);     // changes the values of the variables in their memory locations permenantly
float calcFind(float, float, float, float);                                           // pass by value are used for functions to copy the values
void displayResults(float);                                                           // of the variables in their memory locations and use them in the function

//*****************************************************************************************************

int main() {
    const int ASSIGN_PERCENT = 15,
              TEST_PERCENT = 50,
              EXAM_PERCENT = 30,
              PARTIC_PERCENT = 5;
    float assign,
        test,
        exam,
        partic,
        finalGrade;

    cout << "Grade Calculator - Computer Programming I \n"
         << endl;

    cout << "The weight of each deliverable on their final grade \n\n"
         << "\t"
         << "Programmig Assignments: " << ASSIGN_PERCENT << "% \n"
         << "\t"
         << "Chapter Tests: " << TEST_PERCENT << "% \n"
         << "\t"
         << "Final Exam: " << EXAM_PERCENT << "% \n"
         << "\t"
         << "Class Participation: " << PARTIC_PERCENT << "% \n"
         << endl;

    readGrades(assign, test, exam, partic);
    calcWeights(assign, test, exam, partic, ASSIGN_PERCENT, TEST_PERCENT, EXAM_PERCENT, PARTIC_PERCENT);
    finalGrade = calcFind(assign, test, exam, partic);

    cout << "\n\n\t" << assign << "% in Programming Assignments" << endl
         << "\t" << test << "% in Chapter Tests" << endl
         << "\t" << exam << "% in Final Exam" << endl
         << "\t" << partic << "% in Class Participation \n\n"
         << endl;

    displayResults(finalGrade);

    return 0;
}

//*****************************************************************************************************

void readGrades(float &assign, float &test, float &exam, float &partic) {
    cout << "What is the graded percentage (out of 100%) for Programming Assignments? ";
    cin >> assign;

    cout << "What is the graded percentage (out of 100%) for Chapter Tests? ";
    cin >> test;

    cout << "What is the graded percentage (out of 100%) for Final Exam? ";
    cin >> exam;

    cout << "What is the graded percentage (out of 100%) for Class Participation? ";
    cin >> partic;
}

//*****************************************************************************************************

void calcWeights(float &assign, float &test, float &exam, float &partic,
                 float ASSIGN_PERCENT, float TEST_PERCENT, float EXAM_PERCENT, float PARTIC_PERCENT) {
    assign = assign * ASSIGN_PERCENT / 100;     // e.g. 75 * 15 / 100 = 11.25 (11.25% out of 15%)

    test = test * TEST_PERCENT / 100;     // e.g. 85 * 50 / 100 = 42.5 (42.5% out of 50%)

    exam = exam * EXAM_PERCENT / 100;     // e.g. 95 * 30 / 100 = 28.5 (28.5% out of 30%)

    partic = partic * PARTIC_PERCENT / 100;     // e.g. 90 * 5 / 100 = 4.5 (4.5% out of 5%)
}

//*****************************************************************************************************

float calcFind(float assign, float test, float exam, float partic) {
    return assign + test + exam + partic;     // e.g. 11.25 + 42.5 + 28.5 + 4.5 = 86.75 (86.75% out of 100%)
}

//*****************************************************************************************************

void displayResults(float finalGrade) {
    cout << "Final Grade: " << finalGrade << "%" << endl;
}

//*****************************************************************************************************
/*

Grade Calculator - Computer Programming I

The weight of each deliverable on their final grade

        Programmig Assignments: 15%
        Chapter Tests: 50%
        Final Exam: 30%
        Class Participation: 5%

What is the graded percentage (out of 100%) for Programming Assignments? 100
What is the graded percentage (out of 100%) for Chapter Tests? 100
What is the graded percentage (out of 100%) for Final Exam? 100
What is the graded percentage (out of 100%) for Class Participation? 100


        15% in Programming Assignments
        50% in Chapter Tests
        30% in Final Exam
        5% in Class Participation


Final Grade: 100%

//*****************************************************************************************************

Grade Calculator - Computer Programming I

The weight of each deliverable on their final grade

        Programmig Assignments: 15%
        Chapter Tests: 50%
        Final Exam: 30%
        Class Participation: 5%

What is the graded percentage (out of 100%) for Programming Assignments? 85
What is the graded percentage (out of 100%) for Chapter Tests? 90
What is the graded percentage (out of 100%) for Final Exam? 95
What is the graded percentage (out of 100%) for Class Participation? 100


        12.75% in Programming Assignments
        45% in Chapter Tests
        28.5% in Final Exam
        5% in Class Participation


Final Grade: 91.25%

//*****************************************************************************************************

Grade Calculator - Computer Programming I

The weight of each deliverable on their final grade

        Programmig Assignments: 15%
        Chapter Tests: 50%
        Final Exam: 30%
        Class Participation: 5%

What is the graded percentage (out of 100%) for Programming Assignments? 75
What is the graded percentage (out of 100%) for Chapter Tests? 85
What is the graded percentage (out of 100%) for Final Exam? 95
What is the graded percentage (out of 100%) for Class Participation? 90


        11.25% in Programming Assignments
        42.5% in Chapter Tests
        28.5% in Final Exam
        4.5% in Class Participation


Final Grade: 86.75%

*/