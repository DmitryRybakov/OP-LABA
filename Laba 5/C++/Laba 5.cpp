#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	int n;
	cout << "Введiть довiльне натуральне число n ";
	cin >> n;// Ввод n
	int a, b, c;// Начальные данные
	c = 1;
	a = 1;
	b = 1;
	cout << "Всi пiфагоровi трiйки натуральних чисел, кожне з яких не перевищує введенного числа n:" << endl;
	for (c = 1; c <= n; c++)
	{
		if (c * c == a * a + b * b) cout << a << "," << b << "," << c << "; ";
		for (a = 1; a <= n; a++)
		{
			if (c * c == a * a + b * b) cout << a << "," << b << "," << c << "; ";
			for (b = a; b <= n; b++)// начальное значение а для исключения повторяющихся выводов
			{
				if (c * c == a * a + b * b) cout << a << "," << b << "," << c << "; ";
			}
		}
	}

	cout << endl;
	return 0;
}