#include <iostream>

#include "miejsca_zerowe/miejsca_zerowe.hpp"
#include "calkowanie/calkowanie.hpp"
#include "interpolacja/interpolacja.hpp"
#include "rownania_rozniczkowe/rownania_rozniczkowe.hpp"
#include "uklady_rownan_liniowych/uklady_rownan_liniowych.hpp"

using namespace std;

void main_menu()
{
	system("clear");
	char a;
	cout << "MENU GLOWNE" << endl;
	cout << "1 - miejsce zerowe" << endl;
	cout << "2 - interpolacja" << endl;
	cout << "3 - calkowanie" << endl;
	cout << "4 - uklady rownan" << endl;
	cout << "5 - aproksymacja" << endl;
	cout << "6 - wyjscie z programu" << endl;
	cin >> a;
	switch(a)
	{
	case '1':
		menu_zerowe();
		break;
	case '2':
		menu_interpolacja();
		break;
	case '3':
        menu_calkowanie();
		break;
	case '4':
        menu_uklady();
		break;
	case '5':
        //menu_aproksymacja();
		break;
	case '6':
		exit(0);
	}
}

int main()
{
	main_menu();
	return 0;
}
