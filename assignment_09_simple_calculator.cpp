// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double firstNumber, double secondNumber) {
    return firstNumber + secondNumber;
}

double subtract(double firstNumber, double secondNumber) {
    return firstNumber - secondNumber;
}

double multiply(double firstNumber, double secondNumber) {
    return firstNumber * secondNumber;
}

double divide(double firstNumber, double secondNumber) {
    return firstNumber / secondNumber;
}

double modulus(double firstNumber, double secondNumber) {
    return fmod(firstNumber, secondNumber);
}

double power(double firstNumber, double secondNumber) {
    return pow(firstNumber, secondNumber);
}

void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cout << "Error: Please enter a choice from 1 to 7." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "Error: Please enter a choice from 1 to 7." << endl;
            continue;
        }

        double firstNumber;
        double secondNumber;

        cout << "Enter first number : ";
        if (!(cin >> firstNumber)) {
            cout << "Error: Please enter valid numbers." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout << "Enter second number: ";
        if (!(cin >> secondNumber)) {
            cout << "Error: Please enter valid numbers." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        double result = 0;
        string operation;

        if (choice == 1) {
            result = add(firstNumber, secondNumber);
            operation = "+";
        } else if (choice == 2) {
            result = subtract(firstNumber, secondNumber);
            operation = "-";
        } else if (choice == 3) {
            result = multiply(firstNumber, secondNumber);
            operation = "*";
        } else if (choice == 4) {
            if (secondNumber == 0) {
                cout << "Error: Cannot divide by zero." << endl;
                continue;
            }
            result = divide(firstNumber, secondNumber);
            operation = "/";
        } else if (choice == 5) {
            if (secondNumber == 0) {
                cout << "Error: Cannot calculate modulus by zero." << endl;
                continue;
            }
            result = ::modulus(firstNumber, secondNumber);
            operation = "%";
        } else {
            result = power(firstNumber, secondNumber);
            operation = "^";
        }

        cout << defaultfloat << setprecision(6);
        cout << "Result: " << firstNumber << " " << operation << " "
             << secondNumber << " = " << fixed << setprecision(2)
             << result << endl;
    }

    return 0;
}
