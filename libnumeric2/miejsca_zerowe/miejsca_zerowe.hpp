#ifndef MIEJSCA_ZEROWE_HPP_INCLUDED
#define MIEJSCA_ZEROWE_HPP_INCLUDED

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void main_menu();
void menu_click();

double wielomian(double a)
{
	double x = -0.2, y = -0.7, z = 1;
	return x*pow(a,3) + y*a + 1;
}

void bisekcja(double a, double b)
{
	double x1, f1, f2, epsilon = pow(10, -8);
	long int it = 0;
	do
	{
		it++;
		f1 = wielomian(a);
		f2 = wielomian(b);
		x1 = (a + b)/2;
		if (f1 * wielomian(x1) < 0)
			b = x1;
		else
			a = x1;

	}while(fabs(wielomian(x1)) > epsilon);
	cout << "Liczba iteracji algorytmu bisekcji: " << it << endl;
	cout << "Miejsce zerowe: " << x1 << endl;
}

void sieczne(double a, double b)
{
	double x1, f1, f2, epsilon = pow(10, -8);
	long int it = 0;
	do
	{
		it++;
		f1 = wielomian(a);
		f2 = wielomian(b);
		x1 = a - f1*((b-a)/(f2-f1));
		if (f1 * wielomian(x1) < 0)
			b = x1;
		else
			a = x1;

	}while(fabs(wielomian(x1)) > epsilon);
	cout << "Liczba iteracji algorytmu siecznych: " << it << endl;
	cout << "Miejsce zerowe: " << x1 << endl;
}

void menu_zerowe()
{
	system("clear");
	char a;
	cout << "MENU MIEJSCE ZEROWE" << endl;
	cout << "1 - miejsce zerowe metoda bisekcji" << endl;
	cout << "2 - miejsce zerowe metoda siecznych" << endl;
	cout << "3 - powrot do menu glownego" << endl;
	cout << "Twój wybór: ";
	cin >> a;
	switch(a)
	{
	case '1':
		bisekcja(-5,5);
		menu_click();
		menu_zerowe();
		break;
	case '2':
		sieczne(-5,5);
		menu_click();
		menu_zerowe();
		break;
    case '3':
        main_menu();
        break;
	default:
		menu_zerowe();
		break;
	}
}

#endif // MIEJSCA_ZEROWE_HPP_INCLUDED
