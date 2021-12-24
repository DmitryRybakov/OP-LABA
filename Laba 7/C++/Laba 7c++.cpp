//Варіант 28
//В масиві цілих чисел B(n) знайти число, яке зустрічається найбільш часто. Якщо таких чисел декілька,
//то визначити найменше із них.


#include <iostream>
#include <locale.h>
#include <iomanip>

using namespace std;

int* generate_arr(int n);  //функція генерації масиву
void write_arr(int* B, int n);  //функція виводу масиву
int find(int* B, int n, int min_often); //функція пошуку числа, яке зустрічається найбільш часто, якщо таких чисел декілька то визначення найменьшого у масиві

int main() {

	setlocale(LC_ALL, "Ukrainian");
	srand(time(NULL));

	int* B;
	cout << "Введiть розмiрнiсть масива B[n]: " << endl;
	int n;
	cin >> n;
	B = generate_arr(n);
	cout << "Згенерований масив B[n]:" << endl;
	write_arr(B, n);
	int min_often = 0;
	min_often = find(B, n, min_often);
	cout << "Найменьше число з тих, якi зустрiчаються найбiльш часто: " << min_often;

	return 0;
}

int* generate_arr(int n) {
	int* B = new int[n];
	for (int i = 0; i < n; i++) {
		B[i] = (rand() % 20 - 0);
	}
	return B;
}

void write_arr(int* B, int n) {
	cout << "B[";
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << B[i];
		}
		if (i != 0) {
			cout << ", " << B[i];
		}
	}
	cout << "]";
	cout << endl;
}

int find(int* B, int n, int min_often) {
	int k = 0, max_k = 0, a;
	for (int i = 0; i < n; i++) {
		k = 0;
		for (int j = 0; j < n; j++) {
			a = B[j];
			if (a == B[i]) k++;
			if (k > max_k) {
				max_k = k;
				min_often = B[i];
			}
			if (k == max_k) {
				if (min_often > B[i]) min_often = B[i];
			}
		}
	}
	return min_often;
}