#include <iostream>
#include <iomanip>

using namespace std;

double** generate_matrix(int n);  //генерація квадратних матриць дійсними числами
void write_matrix(double** matrix, int n);  //виведення квадратних матриць
void increase_diagonal(double** matrix, int n);  //упорядкування діагоналей за збільшенням елементів
void change_diagonals(double** matrix_1, double** matrix_2, int n);  //заміна місцями діагоналей квадратних матриць
void delete_matrix(double** matrix, int n);  //видалення матриць

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	srand(time(NULL));
	double** matrix_1;
	double** matrix_2;
	cout << "Введiть розмiрнiсть квадратних матриць n x n: " << endl;
	int n;
	cin >> n;
	matrix_1 = generate_matrix(n);
	cout << "Перша згенерована матриця n x n:" << endl;
	write_matrix(matrix_1, n);
	matrix_2 = generate_matrix(n);
	cout << "Друга згенерована матриця n x n:" << endl;
	write_matrix(matrix_2, n);
	increase_diagonal(matrix_1, n);
	cout << "Перша матриця n x n з вiдсортованою дiагоналлю:" << endl;
    write_matrix(matrix_1, n);
	increase_diagonal(matrix_2, n);
	cout << "Друга матриця n x n з вiдсортованою дiагоналлю:" << endl;
    write_matrix(matrix_2, n);
	change_diagonals(matrix_1, matrix_2, n);
	cout << "Перша матриця n x n з помiняною дiагоналлю:" << endl;
	write_matrix(matrix_1, n);
	cout << "Друга матриця n x n з помiняною дiагоналлю:" << endl;
	write_matrix(matrix_2, n);
	delete_matrix(matrix_1, n);
	delete_matrix(matrix_2, n);

	return 0;
}

double** generate_matrix(int n) {
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = (rand() % 101 - 0) / 10.0;
		}
	}
	return matrix;
}

void write_matrix(double** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(6) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void increase_diagonal(double** matrix, int n) {
	int i;
	double a;
	bool increase, change;
	increase = false;
	i = 0;
	while (i < n - 1 && !increase) {
		change = false;
		for (int j = 0; j < n - 1 - i; ++j) {
			if (matrix[j][j] > matrix[j + 1][j + 1]) {
				a = matrix[j][j];
				matrix[j][j] = matrix[j + 1][j + 1];
				matrix[j + 1][j + 1] = a;
				change = true;
			}
		}
		if (!change) {
			increase = true;
		}
		i++;
	}
}

void change_diagonals(double** matrix_1, double** matrix_2, int n) {
	double a;
	for (int i = 0; i < n; i++) {
		a = matrix_1[i][i];
		matrix_1[i][i] = matrix_2[i][i];
		matrix_2[i][i] = a;
	}
}

void delete_matrix(double** matrix, int n) {
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}