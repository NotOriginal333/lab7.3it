#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void CreateMatrix(int** matrix, int rows, int cols, int minVal, int maxVal) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
}

void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}
int countRowsWithZeros(int** matrix, int k, int n) {
    int count = 0;

    for (int i = 0; i < k; i++) {
        bool hasZero = false;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            count++;
        }
    }

    return count;
}

void findLongestSeriesColumn(int** matrix, int k, int n, int& columnWithMaxSeries) {
    int maxSeriesLength = 0;
    columnWithMaxSeries = -1; 
    int currentSeries = 0;
    for (int j = 0; j < n; j++) {
        currentSeries = 0;
        for (int i = 1; i < k; i++) {
            if (matrix[i][j] == matrix[i-1][j]) {
                currentSeries++;
            }
        }
        if (currentSeries > 0 && maxSeriesLength < currentSeries) {
            columnWithMaxSeries = j;
            maxSeriesLength = currentSeries;
        }
    }
}


int main() {
    srand(static_cast<unsigned>(time(NULL)));

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    int minVal = -10;
    int maxVal = 10;

    int columnWithMaxSeries = -1;

    CreateMatrix(matrix, rows, cols, minVal, maxVal);

    PrintMatrix(matrix, rows, cols);

    cout << "Count zero: " << countRowsWithZeros(matrix, rows, cols) << endl;
    findLongestSeriesColumn(matrix, rows, cols, columnWithMaxSeries);
    cout << "Series(col): " << columnWithMaxSeries << endl;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
