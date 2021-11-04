#include <iostream>
#include <locale.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "Ukrainian");

    cout << "Введiть довiльне натуральне число" << endl;
    int n;
	cin >> n;
    int sum = 0, a;
    a = n;
	for (sum; a != 0; sum) {
        sum += a % 10;
        a /= 10;
        //cout << sum << " ";
	}
    cout << "Сумма цифр введенного натурального числа дорiвнює " << sum << endl;

	return 0;
}

