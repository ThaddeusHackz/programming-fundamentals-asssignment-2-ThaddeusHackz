// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[][MAX_SIZE], int rows, int columns, const string& name) {
    cout << "Enter the values for matrix " << name << ":" << endl;

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cout << "Enter element " << name << "[" << row << "][" << column << "]: ";
            cin >> matrix[row][column];
        }
    }
}

void displayMatrix(const int matrix[][MAX_SIZE], int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cout << setw(8) << matrix[row][column];
        }
        cout << endl;
    }
}

void transposeMatrix(const int matrix[][MAX_SIZE], int transpose[][MAX_SIZE],
                     int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            transpose[column][row] = matrix[row][column];
        }
    }
}

void addMatrices(const int first[][MAX_SIZE], const int second[][MAX_SIZE],
                 int result[][MAX_SIZE], int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            result[row][column] = first[row][column] + second[row][column];
        }
    }
}

void multiplyMatrices(const int first[][MAX_SIZE], const int second[][MAX_SIZE],
                      int result[][MAX_SIZE], int rowsA, int columnsA, int columnsB) {
    for (int row = 0; row < rowsA; row++) {
        for (int column = 0; column < columnsB; column++) {
            result[row][column] = 0;

            for (int position = 0; position < columnsA; position++) {
                result[row][column] += first[row][position] * second[position][column];
            }
        }
    }
}

bool validDimension(int value) {
    return value >= 1 && value <= MAX_SIZE;
}

int main() {
    int choice;
    int rows;
    int columns;
    int matrixA[MAX_SIZE][MAX_SIZE] = {};
    int matrixB[MAX_SIZE][MAX_SIZE] = {};
    int result[MAX_SIZE][MAX_SIZE] = {};

    cout << "============================" << endl;
    cout << "     MATRIX OPERATIONS" << endl;
    cout << "============================" << endl;
    cout << "1. Transpose a matrix" << endl;
    cout << "2. Add two matrices" << endl;
    cout << "3. Multiply two matrices" << endl;
    cout << "Select an operation (1-3): ";

    if (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "Error: Invalid menu choice." << endl;
        return 0;
    }

    cout << "Enter number of rows: ";
    if (!(cin >> rows)) {
        cout << "Error: Matrix dimensions must be whole numbers." << endl;
        return 0;
    }

    cout << "Enter number of columns: ";
    if (!(cin >> columns)) {
        cout << "Error: Matrix dimensions must be whole numbers." << endl;
        return 0;
    }

    if (!validDimension(rows) || !validDimension(columns)) {
        cout << "Error: Matrix dimensions must be from 1 to 10." << endl;
        return 0;
    }

    if (choice == 1) {
        readMatrix(matrixA, rows, columns, "A");
        transposeMatrix(matrixA, result, rows, columns);

        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(matrixA, rows, columns);
        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(result, columns, rows);

    } else if (choice == 2) {
        readMatrix(matrixA, rows, columns, "A");
        readMatrix(matrixB, rows, columns, "B");
        addMatrices(matrixA, matrixB, result, rows, columns);

        cout << "\nSum of the Matrices:" << endl;
        displayMatrix(result, rows, columns);

    } else {
        int columnsB;
        cout << "Enter number of columns in matrix B: ";
        if (!(cin >> columnsB)) {
            cout << "Error: Matrix dimensions must be whole numbers." << endl;
            return 0;
        }

        if (!validDimension(columnsB)) {
            cout << "Error: Matrix dimensions must be from 1 to 10." << endl;
            return 0;
        }

        readMatrix(matrixA, rows, columns, "A");
        readMatrix(matrixB, columns, columnsB, "B");
        multiplyMatrices(matrixA, matrixB, result, rows, columns, columnsB);

        cout << "\nProduct of the Matrices:" << endl;
        displayMatrix(result, rows, columnsB);
    }

    return 0;
}
