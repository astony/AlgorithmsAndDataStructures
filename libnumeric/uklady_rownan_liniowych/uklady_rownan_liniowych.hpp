#ifndef UKLADY_ROWNAN_HPP
#define UKLADY_ROWNAN_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int gauss(double **macierz, double *b, int rozm)
{
	double m;
	double a;
	for(int k = 0; k < rozm; ++k)
		for(int i = k + 1; i < rozm; ++i)
		{
			m = macierz[i][k] / macierz[k][k];
			for(int j = 0; j < rozm; ++j)
				macierz[i][j] = macierz[i][j] - m * macierz[k][j];
			b[i] = b[i] - m*b[k];
		}
	for(int k = rozm - 1; k >= 0; --k)
		for(int i = k - 1; i >= 0; --i)
		{
			m = macierz[i][k] / macierz[k][k];
			for(int j = 0; j < rozm; ++j)
				macierz[i][j] = macierz[i][j] - m * macierz[k][j];
			b[i] = b[i] - m*b[k];
		}

	for(int i = 0; i < rozm; ++i)
		for(int j = 0; j < rozm; ++j)
			cout << macierz[i][j] << " ";
		cout << endl;

	for(int i = 0; i < rozm; ++i)
		cout << "x[" << i << "] = " << b[i] / macierz[i][i] << endl;
}

void jacobi(double **A, double* b, int rozm)
{
    double* N = new double[rozm];
    // Calculate N = D^-1
    for (int i=0; i < rozm; i++)
        N[i] = 1/A[i][i];

    double** M = new double*[rozm];
    for(int i=0; i < rozm; ++i)
        M[i] = new double[rozm];
    // Calculate M = -D^-1 (L + U)
    for (int i=0; i < rozm; i++)
        for (int j=0; j < rozm; j++)
            if (i == j)
                M[i][j] = 0;
            else
                M[i][j] = - (A[i][j] * N[i]);

    double* x1 = new double[rozm];
    for(int i = 0; i < rozm; ++i)
        x1[i] = 0;
    int iter = 10;
    for (int k=0; k < iter; k++) {
        for (int i=0; i < rozm; i++) {
            x1[i] = N[i]*b[i];
            for (int j=0; j < rozm; j++)
                x1[i] += M[i][j]*x1[j];
        }
    }
}

void menu_uklady()
{
	system("clear");
	char a;
	cout << "MENU UK�ADY R�WNA�" << endl;
	cout << "1 - metoda Gaussa" << endl;
	cout << "2 - metoda Jacobi" << endl;
	cout << "Tw�j wyb�r: ";
	cin >> a;

	ifstream plik;
	plik.open("macierz.txt");
	int rozm;
	plik >> rozm;

	double** macierz = new double *[rozm];
	for(int i = 0; i < rozm; i++)
		macierz[i] = new double[rozm];

	for(int i = 0; i < rozm; i++)
		for (int j = 0; j < rozm; j++)
			plik >> macierz[i][j];
	plik.close();

	double* b = new double[rozm];
	for(int i = 0; i < rozm; ++i)
		plik >> b[i];

	switch(a)
	{
	case '1':
		gauss(macierz, b, rozm);
		break;
    case '2':
        jacobi(macierz, b, rozm);
        break;
	default:
		menu_uklady();
		break;
	}
}

#endif
