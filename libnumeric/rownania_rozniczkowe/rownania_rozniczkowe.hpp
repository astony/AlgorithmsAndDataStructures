#ifndef ROWNANIA_ROZNICZKOWE_HPP
#define ROWNANIA_ROZNICZKOWE_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

double y_poch(double x, double y)
{
	return 1+sqrt(y-x+3);
}

double rozw(double x, double y)
{
	return x + (x+4)*(x+4)/4 -3;
}

void wypisz(double *x, double *y, int n)
{
	for(int i = 0; i <= n; ++i)
	{
		cout << setw(5) << "x[" << i << "]= " << setprecision(4) << x[i];
		cout << ", ";
		cout << setw(5) << "y[" << i << "]= " << setprecision(4) << y[i] << endl;
	}
}

void metoda_eulera(double (*f)(double t, double x), double x0, double y0, double a, double b, int n)
{
	if (n < 1)
		return;
	double h=(b-a)/n;
	double *x = new double[n];
	double *y = new double[n];
	x[0] = x0;
	y[0] = y0;
	for(int i = 1; i <= n; ++i)
	{
		y[i] = y[i-1] + h*f(x[i-1], y[i-1]);
		x[i] = x[i-1] + h;
	}
	wypisz(x, y, n);
}

void metoda_henna(double (*f)(double t, double x), double x0, double y0, double a, double b, int n)
{
	if (n < 1)
		return;
	double h=(b-a)/n;
	double *x = new double[n];
	double *y = new double[n];
	x[0] = x0;
	y[0] = y0;
	for(int i = 1; i <= n; ++i)
	{
		y[i] = y[i-1] + h/2*( f( x[i-1], y[i-1] ) + f( x[i-1]+h, y[i-1]+h*f(x[i-1], y[i-1]) ) );
		x[i] = x[i-1] + h;
	}
	wypisz(x, y, n);
}

void metoda_zmodyfikowana_eulera(double (*f)(double t, double x), double x0, double y0, double a, double b, int n)
{
	if (n < 1)
		return;
	double h=(b-a)/n;
	double *x = new double[n];
	double *y = new double[n];
	x[0] = x0;
	y[0] = y0;
	for(int i = 1; i <= n; ++i)
	{
		y[i] = y[i-1] + h*f(x[i-1]+1/2*h, y[i-1]+1/2*h*f(x[i-1], y[i-1]));
		x[i] = x[i-1] + h;
	}
	wypisz(x, y, n);
}

void rk4(double (*f)(double t, double x), double x0, double y0, double a, double b, unsigned int n)
{
	if (n < 1)
		return;
	double h=(b-a)/n;
	double *x = new double[n];
	double *y = new double[n];
	x[0] = x0;
	y[0] = y0;
	for (int i = 1; i <= n ; ++i)
	{
		double k1 = f(x[i-1] + h, y[i-1] + h);
		double k2 = f(x[i-1] + h/2, y[i - 1] + h/2 * k1);
		double k3 = f(x[i-1] + h/2, y[i - 1] + h/2 * k2);
		double k4 = f(x[i-1] + h, y[i - 1] + h * k3);
		y[i] = y[i - 1] + 1.0 / 6.0 * h*(k1 + 2 * k2 + 2 * k3 + k4);
		x[i] = x[i-1] + h;
	}
	wypisz(x, y, n);
}

void rk3(double (*f)(double t, double x), double x0, double y0, double a, double b, unsigned int n)
{
	if (n < 1)
		return;
	double h=(b-a)/n;
	double *x = new double[n];
	double *y = new double[n];
	x[0] = x0;
	y[0] = y0;
	for (int i = 1; i <= n ; ++i)
	{
		double k1 = f(x[i-1], y[i-1]);
		double k2 = f(x[i-1] + h/2, y[i - 1] + h/2 * k1);
		double k3 = f(x[i-1] + h, y[i - 1] - k1 *h + h * 2* k2);
		y[i] = y[i - 1] + 1.0 / 6.0 * h*(k1 + 4*k2 + k3);
		x[i] = x[i-1] + h;
	}
	wypisz(x, y, n);
}

void menu_rownania_rozniczkowe()
{
	system("clear");
	char a;
	cout << "MENU CA£KOWANIE" << endl;
	cout << "1 - metoda Eulera" << endl;
	cout << "2 - metoda Henna" << endl;
	cout << "3 - zmodyfikowana metoda Eulera" << endl;
	cout << "4 - metoda Runego-Kutty 4 rzedu" << endl;
	cout << "5 - metoda Runego-Kutty 3 rzedu" << endl;
	cout << "Twój wybór: ";
	cin >> a;
	switch(a)
	{
	case '1':
		metoda_eulera(y_poch, 0, 1, 0, 1, 10);
		break;
	case '2':
		metoda_henna(y_poch, 0, 1, 0, 1, 10);
		break;
	case '3':
		metoda_zmodyfikowana_eulera(y_poch, 0, 1, 0, 1, 10);
		break;
	case '4':
		rk4(y_poch, 0, 1, 0, 1, 10);
		break;
	case '5':
		rk3(y_poch, 0, 1, 0, 1, 10);
		break;
	default:
		menu_rownania_rozniczkowe();
		break;
	}
}

#endif //ROWNANIA_ROZNICZKOWE_HPP
