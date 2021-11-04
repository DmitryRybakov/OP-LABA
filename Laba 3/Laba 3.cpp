#include <iostream>
#include <locale.h>

using namespace std;


int main() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "Введiть довiльне дiйсне число a>0 ";
    float a;        // Обьявление переменной
    cin >> a;       // Ввод необходимой переменной
    float xn0, b;       // Обьявление переменных
    if (a <= 1) {
        b = 2 * a;
        if (b < 0.95) xn0 = b;
        else xn0 = 0.95;
    }
    else if (1 < a && a < 25) xn0 = a / 5;
         else xn0 = a / 25;         // Условия для нахождения
    float xn1, xn2, xfn, q, n;      // Обьявление переменных
    q = pow(10, -6);        // Присваивание необходимого значения
    //n = 0;
    do {
        //n++;
        //cout << n << endl;
        //cout << " " << xn0;
        xn1 = (4.0 / 5.0) * xn0 + a / (5 * pow(xn0, 4));
        //cout << " " << xn1;
        xn2 = (4.0 / 5.0) * xn1 + a / (5 * pow(xn1, 4));
        //cout << " " << xn2;
        xfn = (5.0 / 4.0) * a * abs(xn2 - xn1);
        //cout << " " << xfn << endl;
        xn0 = xn1;
        xn1 = xn2;      
    } while (xfn > q);      // Цикл с постусловием
    float r;        // Обьявление переменной
    r = a - pow(xfn, 5);        // Вычисление разницы
    cout << "Перший член Xn = " << xfn << endl << "Рiзниця a - Xn^5 = " << r << endl;       // Вывод необходимых переменных
    return 0;
}