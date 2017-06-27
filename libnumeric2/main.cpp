#include <iostream>

#include "aproksymacja/aproksymacja.hpp"
#include "calkowanie/calkowanie.hpp"
#include "interpolacja/interpolacja.hpp"
#include "miejsca_zerowe/miejsca_zerowe.hpp"
#include "uklady_rownan_liniowych/uklady_rownan_liniowych.hpp"
#include "rownania_rozniczkowe/rownania_rozniczkowe.hpp"

using namespace std;

void menu_click()
{
    cout << "Nacisnij klawisz aby powrocic do menu ..";
	cin.ignore().get();
}

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
	cout << "6 - rownania rozniczkowe" << endl;
	cout << "7 - wyjscie z programu" << endl;
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
        menu_aproksymacja();
		break;
    case '6':
        menu_rownania_rozniczkowe();
        break;
	case '7':
		exit(0);
	}
}

int main()
{
	main_menu();
	return 0;
}
