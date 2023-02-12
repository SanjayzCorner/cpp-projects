//*****************************************************************************************************
//
//		This program is a survey that collects the number of cricket matches played by
// college
//      students in a year. The user inputs the number of students surveyed and their names and the
//      number of matches they played. The program then displays the names and number of matches
//      played by each student, the student who played the most matches, the average number of
//      matches played by all students, and the names and number of matches played in ascending
//      order. It uses arrays, pointers, and functions such as input, display, displayMostMatches,
//      mean, and sortStudents.
//
//*****************************************************************************************************

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void input(string names[], int matches[], int size);
void display(const string names[], const int matches[], int size);
void displayMostMatches(const string names[], const int matches[], int size);
double mean(const int matches[], int num);
void sortStudents(string names[], int matches[], int size);

//*****************************************************************************************************

int main() {
    int size,
        *matches = nullptr;
    double average;
    string *names = nullptr;

    cout << "------------------------------------------------- \n"
         << " Cricket Matches College Students Play in a Year \n"
         << "-------------------------------------------------" << endl;
    do {
        cout << "How many students were surveyed? (1-5000): ";
        cin >> size;

        if (size <= 0 || size > 5000)
            cerr << "\n"
                 << "Error: Invalid Entry" << endl
                 << endl;     // cerr is unbuffered and best for error handling
        cin.ignore();
    } while (size <= 0 || size > 5000);

    names = new string[size];     // new operator to dynamically allocate memory on the heap
    matches = new int[size];      // to ensure sufficient memory for storing the data

    // Dynamic memory allocation is necessary because allocating memory on the stack (In C++, arrays
    // declared inside a function are stored on the stack by default) would result in a stack
    // overflow error if the amount of memory needed is too large.
    input(names, matches, size);

    cout << "\n"
         << "------------------------------------------------- \n"
         << "\t"
         << "Student Names & Matches Played \n"
         << "-------------------------------------------------" << endl;
    display(names, matches, size);

    cout << "\n"
         << "------------------------------------------------- \n"
         << "\t"
         << "Student Who Played Most Matches \n"
         << "-------------------------------------------------" << endl;
    displayMostMatches(names, matches, size);

    cout << "\n"
         << "------------------------------------------------- \n"
         << "\t"
         << "Average Matches Played for Students \n"
         << "-------------------------------------------------" << endl;
    average = mean(matches, size);
    cout << "Average: " << average << endl;

    cout << "\n"
         << "------------------------------------------------- \n"
         << "Student Names & Matches Played ~ Ascending Order \n"
         << "-------------------------------------------------" << endl;
    sortStudents(names, matches, size);
    display(names, matches, size);

    delete[] names;      // delete operator to deallocate memory on the heap to prevent memory leaks
    names = nullptr;     // set the pointer to nullptr to prevent dangling pointers
    delete[] matches;
    matches = nullptr;

    return 0;
}

//*****************************************************************************************************

void input(string names[], int matches[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "\n"
             << "Enter name of student " << i + 1 << ": ";
        getline(cin, names[i]);

        while (true) {
            cout << "Enter number of matches for " << names[i] << ": ";
            cin >> matches[i];
            cin.ignore();

            if (matches[i] >= 0)
                break;
            else
                cerr << "\n"
                     << "Error: Invalid Entry \n"
                     << endl;
        }
    }
}

//*****************************************************************************************************

void display(const string names[], const int matches[], int size) {
    for (int i = 0; i < size; ++i)
        cout << i + 1 << "  " << setfill('.') << setw(30) << left << names[i]
             << " Matches: " << matches[i] << endl;
}

//*****************************************************************************************************

void displayMostMatches(const string names[], const int matches[], int size) {
    int max = matches[0],
        temp = 0;

    for (int i = 0; i < size; ++i) {
        if (matches[i] > max) {
            max = matches[i];
            temp = i;
        }
    }

    cout << temp + 1 << "  " << setfill('.') << setw(30) << left << names[temp]
         << " Matches: " << matches[temp] << endl;
}

//*****************************************************************************************************

double mean(const int matches[], int size) {
    double sum = 0;

    for (int i = 0; i < size; ++i)
        sum += matches[i];

    return sum / size;
}

//*****************************************************************************************************

void sortStudents(string names[], int matches[], int size) {     // selection sort algorithm (time complexity: O(n^2)
    int minIndex,
        minValueMatches;
    string minValueNames;

    for (int startScan = 0; startScan < (size - 1); ++startScan) {
        minIndex = startScan;
        minValueNames = names[minIndex];
        minValueMatches = matches[minIndex];
        for (int index = startScan + 1; index < size; ++index) {
            if (names[index] < minValueNames) {
                minValueNames = names[index];
                minValueMatches = matches[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValueNames;
        matches[minIndex] = matches[startScan];
        matches[startScan] = minValueMatches;
    }
}

//*****************************************************************************************************

/*

-------------------------------------------------
Cricket Matches College Students Play in a Year
-------------------------------------------------
How many students were surveyed? (1-5000): 0

Error: Invalid Entry

How many students were surveyed? (1-5000): -1

Error: Invalid Entry

How many students were surveyed? (1-5000): 10000

Error: Invalid Entry

How many students were surveyed? (1-5000): 5

Enter name of student 1: Ragland, Nicholas
Enter number of matches for Ragland, Nicholas: -1

Error: Invalid Entry

//*****************************************************************************************************

-------------------------------------------------
 Cricket Matches College Students Play in a Year
-------------------------------------------------
How many students were surveyed? (1-5000): 5

Enter name of student 1: Ragland, Nicholas
Enter number of matches for Ragland, Nicholas: 23

Enter name of student 2: Smith, John
Enter number of matches for Smith, John: 28

Enter name of student 3: Zhang, Xiu Ying
Enter number of matches for Zhang, Xiu Ying: 21

Enter name of student 4: Evans, Olivia
Enter number of matches for Evans, Olivia: 30

Enter name of student 5: Song, Mona
Enter number of matches for Song, Mona: 26

-------------------------------------------------
        Student Names & Matches Played
-------------------------------------------------
1  Ragland, Nicholas............. Matches: 23
2  Smith, John................... Matches: 28
3  Zhang, Xiu Ying............... Matches: 21
4  Evans, Olivia................. Matches: 30
5  Song, Mona.................... Matches: 26

-------------------------------------------------
        Student Who Played Most Matches
-------------------------------------------------
4  Evans, Olivia................. Matches: 30

-------------------------------------------------
        Average Matches Played for Students
-------------------------------------------------
Average: 25.6

-------------------------------------------------
Student Names & Matches Played ~ Ascending Order
-------------------------------------------------
1  Evans, Olivia................. Matches: 30
2  Ragland, Nicholas............. Matches: 23
3  Smith, John................... Matches: 28
4  Song, Mona.................... Matches: 26
5  Zhang, Xiu Ying............... Matches: 21

*/