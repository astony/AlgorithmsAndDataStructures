#ifndef CALKOWANIE_HPP
#define CALKOWANIE_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void main_menu();
void menu_click();

double horner(double* wsp, int size, int x)
{
	double value = wsp[0];
	for(int i = 1; i <= size; ++i)
		value = value*x + wsp[i];
	return value;
}

double f(double val)
{
    int rozm = 4;
    double* matrix = new double[rozm];
    matrix[0] = 4;
    matrix[1] = 5;
    matrix[2] = 0;
    matrix[3] = 1;
	return horner(matrix, rozm, val);
}

double lewe_prostokaty(double a, double b, int N)
{
	double S, H = (b - a) / N, rm = 0;
	for(int i = 0; i < N; ++i)
		rm += f(a + i * H);
	S = H*rm;
	return S;
}

double prawe_prostokaty(double a, double b, int N)
{
	double S, H = (b - a) / N, rm = f(b);
	for(int i = N - 1 ; i > 1 ; --i)
		rm += f(b - i * H);
	S = H * rm;
	return S;
}

double srodkowe_prostokaty(double a, double b, int N)
{
	double S, H = (b - a) / N, rm = 0;
	for (int i = 0; i < N ; i++)
		rm += f(((a + i*H) + (a + (i+1)*H))/2);
	S = H*rm;
	return S;
}

double trapezy(double a, double b, int N)
{
	double S, H = (b - a) / N;
	double rm = 1/2 * f(a) + 1/2 * f(b);
	for (int i = 1; i < N ; i++)
		rm += f(a + i * H);
	S = H*rm;
	return S;
}

double simpson(double a, double b, int N)
{
	double H, S, rm, rx;
	H = (b - a) / N;
	rm = f(a) + f(b);
	rx = 0;
	for (int i = 1; i < N; i = 1+2)
	{
		rx += f(a + i*H);
	}
	rm = rm + 4 *rx;
	rx = 0;
	for(int i = 2; i < N; i = i + 2)
	{
		rx += f(a + i*H);
	}
	S = (1/3) * H *(rx + rm);
	return S;

}

void menu_calkowanie()
{
	system("clear");
	char znak;
	cout << "MENU CA£KOWANIE" << endl;
	cout << "1 - calkowanie metod¹ prostok¹tów lewych" << endl;
	cout << "2 - calkowanie metod¹ prostok¹tów œrodkowych" << endl;
	cout << "3 - calkowanie metod¹ prostok¹tów prawych" << endl;
	cout << "4 - calkowanie metod¹ trapezów" << endl;
	cout << "5 - calkowanie metod¹ simpsonów" << endl;
	cout << "6 - powrot do menu glownego" << endl;
	cout << "Twój wybór: ";
	cin >> znak;
	double a, b;
    double n=5;
	switch(znak)
	{
	case '1':
        cout << "Podaj poczatek przedzialu: ";
        cin >> a;
        cout << "Podaj koniec przedzialu: ";
        cin >> b;
		lewe_prostokaty(a, b, n);
		menu_click();
		menu_calkowanie();
		break;
	case '2':
        cout << "Podaj poczatek przedzialu: ";
        cin >> a;
        cout << "Podaj koniec przedzialu: ";
        cin >> b;
		srodkowe_prostokaty(a, b, n);
		menu_click();
		menu_calkowanie();
		break;
	case '3':
        cout << "Podaj poczatek przedzialu: ";
        cin >> a;
        cout << "Podaj koniec przedzialu: ";
        cin >> b;
		prawe_prostokaty(a, b, n);
		menu_click();
		menu_calkowanie();
		break;
	case '4':
        cout << "Podaj poczatek przedzialu: ";
        cin >> a;
        cout << "Podaj koniec przedzialu: ";
        cin >> b;
		trapezy(a, b, n);
		menu_click();
		menu_calkowanie();
		break;
	case '5':
        cout << "Podaj poczatek przedzialu: ";
        cin >> a;
        cout << "Podaj koniec przedzialu: ";
        cin >> b;
		simpson(a, b, n);
		menu_click();
		menu_calkowanie();
		break;
    case '6':
        main_menu();
        break;
	default:
		menu_calkowanie();
		break;
	}
}

#endif // CALKOWANIE_HPP
