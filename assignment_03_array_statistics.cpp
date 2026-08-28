// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

double calculateSum(const double numbers[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += numbers[i];
    }

    return total;
}

double calculateAverage(const double numbers[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += numbers[i];
    }

    return total / size;
}

double findMaximum(const double numbers[], int size) {
    double maximum = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    return maximum;
}

double findMinimum(const double numbers[], int size) {
    double minimum = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }

    return minimum;
}

int main() {
    int size;
    double numbers[MAX_SIZE];

    cout << "How many numbers? ";
    if (!(cin >> size) || size <= 0) {
        cout << "Error: The number of values must be a positive integer." << endl;
        return 0;
    }

    if (size > MAX_SIZE) {
        cout << "Error: You can enter at most " << MAX_SIZE << " numbers." << endl;
        return 0;
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        if (!(cin >> numbers[i])) {
            cout << "Error: Please enter valid numbers only." << endl;
            return 0;
        }
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers, size) << endl;
    cout << "Average: " << calculateAverage(numbers, size) << endl;
    cout << "Maximum: " << findMaximum(numbers, size) << endl;
    cout << "Minimum: " << findMinimum(numbers, size) << endl;

    return 0;
}
