#include <iostream>
#include <locale.h>

using namespace std;

int SUM(int sum, int a);

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	cout << "Введiть тiльки перше довiльне натуральне n-значне число: ";
	int k;
	cin >> k;
	int sum, max = 0, a, x = 0;
	while (k != 0) {
		sum = 0;
		a = k;
		sum = SUM(sum, a);
		if (max < sum) {
			max = sum;
			x = k;
		}
		cout << "Число сума цифр якого є найбільшою - " << x << " Сума цифр цього числа дорівнює " << max << endl;
		cout << "Введiть наступне довiльне натуральне n-значне число, або введiть 0 для завершення программи: ";
		cin >> k;
	}
	return 0;
}

int SUM(int sum, int a) {
	for (sum; a != 0; sum) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

