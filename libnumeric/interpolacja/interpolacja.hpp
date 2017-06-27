#ifndef INTERPOLACJA_HPP
#define INTERPOLACJA_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

struct XFX
{
	double x, fx;
};

void main_menu();
void read_save_lagrange();

void menu_interpolacja()
{
	system("clear");
	char a;
	cout << "MENU INTERPOLACJA" << endl;
	cout << "1 - interpolacja Lagrange'a" << endl;
	cout << "2 - powrot do menu glownego" << endl;
	cin >> a;
	switch(a)
	{
	case '1':
		read_save_lagrange();
		break;
	case '2':
		main_menu();
		break;
	default:
		main_menu();
		break;
	}
}

double lagrange_interpolation(XFX *tablica, int size, double value)
{
	double sum = 0.0;
	for(int i=0; i<size; ++i)
	{
		double f1 = 1.0;
		double f2 = 1.0;
		for(int j=0; j<size; ++j)
		{
			if(i != j)
			{
				f1 *= value - tablica[j].x;
				f2 *= tablica[i].x - tablica[j].x;
			}
		}
		sum += tablica[i].fx * f1/f2;
	}
	return sum;
}

void read_save_lagrange()
{
	fstream plik("dane.txt");
	string size;
	getline(plik, size);
	int size_i = atoi(size.c_str());
	XFX *tablica = new XFX[size_i];
	string tmp;
	for(int i=1; i<=size_i; ++i)
	{
		getline(plik,tmp);
		stringstream strumien(tmp);
		string x,y;
		strumien >> x;
		strumien >> y;
		tablica[i-1].x = atof(x.c_str());
		tablica[i-1].fx = atof(y.c_str());
	}
	string size2;
	getline(plik, size2);
	double *values = new double[atoi(size2.c_str())];
	string tmp2;
	for(int i=1; i<=atoi(size2.c_str()); ++i)
	{
		getline(plik,tmp2);
		stringstream strumien(tmp2);
		string a;
		strumien >> a;
		values[i-1] = atof(a.c_str());
	}
	for(int i=0; i<size_i; ++i)
		cout << tablica[i].x << tablica[i].fx << endl;
	plik.close();
	fstream plik2;
	plik2.open("wynik.txt");
	plik2 << lagrange_interpolation(tablica, size_i, values[0]) << endl;
	plik2.close();
	cout << "Nacisnij klawisz aby powrocic do menu interpolacji...";
	cin.ignore().get();
	menu_interpolacja();
}

#endif
