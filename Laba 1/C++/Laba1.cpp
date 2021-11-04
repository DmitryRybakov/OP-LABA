#include <iostream>		// для операторов cout
#include <cmath>		// для функций  acos

#define PI 3.14159265		// число пи

using namespace std;

int main() {
	float a, b, c, x1, y1, x2, y2, x3, y3, ka, kb, kc;		//  оглошеня змінних

	cout << "enter coordinates x1 and y1" << endl;
	cin >> x1 >> y1;		// ввід змінних
	cout << "enter coordinates x2 and y2" << endl;
	cin >> x2 >> y2;		// ввід змінних
	cout << "enter coordinates x3 and y3" << endl;
	cin >> x3 >> y3;		// ввід змінних
	a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));		// визначення відстані між двома заданими точками
	b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));		// визначення відстані між двома заданими точками
	c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));		// визначення відстані між двома заданими точками

	cout << "AB = " << a << endl << "BC = " << b << endl << "AC = " << c << endl;		// вивід довжин сторін

	ka = acos((c * c + b * b - a * a) / (2 * b * c));		// знаходження кутів у радіанах
	kb = acos((a * a + c * c - b * b) / (2 * a * c));		// знаходження кутів у радіанах
	kc = acos((a * a + b * b - c * c) / (2 * a * b));		// знаходження кутів у радіанах
	ka = (ka * 180) / PI;		// переведення в градусну міру
	kb = (kb * 180) / PI;		// переведення в градусну міру
	kc = (kc * 180) / PI;		// переведення в градусну міру

	cout << "A = " << ka << endl << "B = " << kb << endl << "C = " << kc << endl;		// вивід величин кутів

	return 0;
}
