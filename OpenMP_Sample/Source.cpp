#include <iostream>
#include <iomanip>
#include <omp.h>
#include <vector>
#include <random>
#include <time.h>

#define Matrix 	vector<vector<float>>
using namespace std;

// The size of Matrix: Degree * Degree matrix
constexpr int Degree = 2000;
constexpr int Block = 16;
constexpr int FLOAT_BYTE = 4;
constexpr int SET = 32 / FLOAT_BYTE;

// @berief : For debug, show Matrix mat
void printMatrix(Matrix& mat) {
	for (auto& row : mat) {
		cout << "| ";
		for (auto value : row) {
			cout << fixed << setprecision(4) << value << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

// @berief : fill mat with random float values
// @input : Matrix mat
// @output : None
void GenerateMatrix(Matrix& mat) {
	std::random_device rd;

	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> RandomDistribution(0.0, 1.0);

	for (auto& row : mat) {
		for (int i = 0; i < row.size(); ++i) {
			row[i] = RandomDistribution(mt);
		}
	}

}

// @berief : Z = X*Y
// @input : Matrix X, Y, Z
// @output : None
void Standard_Mult(Matrix& Z, Matrix& X, Matrix& Y) {
	for (int i = 0; i < Degree; ++i) {
		for (int j = 0; j < Degree; ++j) {
			for (int k = 0; k < Degree; ++k) {
				Z[i][j] += X[i][k] * Y[k][j];
			}
		}
	}
}

///////////////////////////////////////////////////////////