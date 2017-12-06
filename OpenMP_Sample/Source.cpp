#include <iostream>
#include <iomanip>
#include <omp.h>
#include <vector>
#include <random>

#define Matrix 	vector<vector<float>>
using namespace std;

// The size of Matrix: Degree * Degree matrix
constexpr int Degree = 100;

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
Matrix GenerateMatrix() {
	std::random_device rd;

	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> RandomDistribution(0.0, 1.0);

	Matrix mat(Degree, vector<float>(Degree, 0));
	for (auto& row : mat) {
		for (int i = 0; i < row.size(); ++i) {
			row[i] = RandomDistribution(mt);
		}
	}
	return mat;
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

int main() {
	// Sampleコード
	Matrix mat_X = GenerateMatrix();
	Matrix mat_Y = GenerateMatrix();
	cout << "init done" << endl;

	Matrix mat(Degree, vector<float>(Degree, 0));
	Standard_Mult(mat, mat_X, mat_Y);
	printMatrix(mat);

	system("PAUSE");
}
