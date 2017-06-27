#ifndef APROKSYMACJA_HPP_INCLUDED
#define APROKSYMACJA_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void main_menu();
void menu_click();

typedef struct
{
	double a0, a1;
} F;

typedef struct
{
	double x, f;
} XF;

F least_squares(const XF *xf, unsigned int n)
{
	double sum_x = 0.0;
	double sum_f = 0.0;
	double sum_xf = 0.0;
	double sum_x2 = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum_x += xf[i].x;
		sum_f += xf[i].f;
		sum_xf += xf[i].x * xf[i].f;
		sum_x2 += xf[i].x * xf[i].x;
	}
	F f;
	f.a0 = (sum_x2 * sum_f - sum_x * sum_xf) / (n * sum_x2 - sum_x * sum_x);
	f.a1 = (n * sum_xf - sum_x * sum_f) / (n * sum_x2 - sum_x * sum_x);
	return f;
}

void sredniokwadratowa()
{
        int n, r;
        double *x, *y,*p,**a,*b;

        fstream plik;
        plik.open("C:\\Users\\PC\\Desktop\\informatyka\\IV SEM\\Metody numeryczne\\aproksymacja\\Debug\\wezly.txt");

        if (plik.good())
        {
                plik >> n;
                plik >> r;
                x = new double[r];
                y = new double[r];
                p = new double[r];
                b = new double[n];
                a = new double*[n];
                for (int i = 0; i < n; i++)     a[i] = new double[n];
                for (int i = 0; i < n; i++) b[i] = 0;
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < n; j++)
                        {
                                a[i][j] = 0;
                        }
                }

                for (int i = 0; i < r; i++)
                {
                        plik >> x[i];
                        plik >> y[i];
                        plik >> p[i];
                }


                        for (int i = 0; i < n; i++)
                        {
                                for (int j = 0; j < r; j++)
                                {
                                        b[i] += p[j] * y[j] * pow(x[j], i);
                                }
                        }

                        int m=0;
                        for (int i = 0; i < n; i++)
                        {
                                for (int j = n-1; j >= 0; j--,m++)
                                {
                                        for (int k = 0; k < r; k++) a[i][j] += p[k] * pow(x[k], i+m);
                                }
                                m = 0;
                        }

                        for (int i = 0; i < n; i++)
                        {
                                for (int j = 0; j < n; j++)
                                {
                                        cout << a[i][j] << " ";
                                }
                                cout << b[i] << endl;
                        }

                        //gauss(a, b, n);


                delete[] b;
                delete[] x;
                delete[] y;
                delete[] p;
                for (int i = 0; i < n; i++)
                {
                        delete[] a[i];
                }
                delete[] a;

                plik.close();

        }
        else cout << "Brak dostepu do pliku z danymi!" << endl;
}

void menu_aproksymacja()
{
	system("clear");
	char znak;
	cout << "MENU APROKSYMACJA" << endl;
	cout << "1 - metda œredniokwadratow¹" << endl;
	cout << "2 - powrot do menu glownego" << endl;
	cout << "Twój wybór: ";
	cin >> znak;
	switch(znak)
	{
	case '1':
		sredniokwadratowa();
		menu_click();
		menu_aproksymacja();
		break;
    case '2':
        main_menu();
        break;
	default:
		menu_aproksymacja();
		break;
	}
}

#endif // APROKSYMACJA_HPP_INCLUDED
