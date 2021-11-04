#include <iostream>
#include <locale.h>


#define PI 3.14159265       // число PI

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");     // підключення української мови

    cout << "Введіть змінні a, b, c, d" <<endl;
    float a, b, c, d;       // оглошеня змінних
    cin >> a >> b >> c >> d;        // введення змінних
    float e, f;     // оглошеня змінних
    c = PI * c / 180;       // перекласти в радіани
    e = abs(b * b - a * a) * sin(c);        // обчислення знаменника
    if (d < 0) cout << "Від'ємне значення у логарифму" << endl;        // перевірка логарифму
    else if (e == 0) cout << "Ділення на 0";        // перевірка знаменника
         else {
            f = (log(d) / e);       // обчислення функції
            cout << "Значення функції дорівнює " << f << endl;      // виведення функції
         }
    
    return 0;
}