#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    Matrix(int m, int n) : rows(m), cols(n) {
        data.resize(m, vector<double>(n, 0));
    }

    void input() {
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }
    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << std::endl;
        }
    }
    int getRows() const {
        return rows;
    }
    int getCols() const {
        return cols;
    }
};

int main() {
    int m, n;
    cout << "Enter rows and columns for Matrix A: ";
    cin >> m >> n;

    Matrix matA(m, n);Matrix matB(n, m);Matrix matC(m, m);
    matA.input();
    matB.input();
    matC = matA * matB;
    cout << "Matrix A:" << endl;
    matA.print();
    cout << "Matrix B:" << endl;
    matB.print();
    cout << "Matrix C (A * B):" << endl;
    matC.print();

    return 0;
}
