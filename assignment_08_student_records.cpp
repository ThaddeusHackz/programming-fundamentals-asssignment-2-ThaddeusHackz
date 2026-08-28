// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

#include <limits>
#include <sstream>

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0;
    }

    double total = 0;
    for (double score : scores) {
        total += score;
    }

    return total / scores.size();
}

int findStudent(const vector<Student>& students, int studentId) {
    for (int i = 0; i < static_cast<int>(students.size()); i++) {
        if (students[i].id == studentId) {
            return i;
        }
    }

    return -1;
}

void addStudent(vector<Student>& students) {
    Student student;
    int numberOfScores;

    cout << "Student name: ";
    getline(cin, student.name);

    if (student.name.empty()) {
        cout << "Error: Student name cannot be empty." << endl;
        return;
    }

    cout << "Student ID: ";
    if (!(cin >> student.id)) {
        cout << "Error: Student ID must be a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (findStudent(students, student.id) != -1) {
        cout << "Error: A student with this ID already exists." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "How many scores? ";
    if (!(cin >> numberOfScores) || numberOfScores <= 0) {
        cout << "Error: The number of scores must be a positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < numberOfScores; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";

        if (!(cin >> score)) {
            cout << "Error: Scores must be numbers." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        student.scores.push_back(score);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records have been added yet." << endl;
        return;
    }

    cout << string(75, '-') << endl;
    cout << left << setw(20) << "Name"
         << setw(15) << "ID"
         << setw(25) << "Scores"
         << right << setw(10) << "Average" << endl;
    cout << string(75, '-') << endl;

    for (const Student& student : students) {
        ostringstream scoreText;
        for (int i = 0; i < static_cast<int>(student.scores.size()); i++) {
            if (i > 0) {
                scoreText << ", ";
            }
            scoreText << student.scores[i];
        }

        cout << left << setw(20) << student.name
             << setw(15) << student.id
             << setw(25) << scoreText.str()
             << right << setw(10) << fixed << setprecision(2)
             << calculateAverage(student.scores) << endl;
    }

    cout << string(75, '-') << endl;
}

void displayStudentAverage(const vector<Student>& students) {
    int studentId;

    cout << "Enter student ID: ";
    if (!(cin >> studentId)) {
        cout << "Error: Student ID must be a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int position = findStudent(students, studentId);

    if (position == -1) {
        cout << "Error: Student ID not found." << endl;
        return;
    }

    cout << students[position].name << "'s average score: "
         << fixed << setprecision(2)
         << calculateAverage(students[position].scores) << endl;
}

void displayMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Error: Please enter a choice from 1 to 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            displayStudentAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please enter a choice from 1 to 4." << endl;
        }
    }

    return 0;
}
