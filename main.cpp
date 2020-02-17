#include <iostream>
#include "header/Lista.h"
using namespace std;

int main()
{
	Lista<int> miLista;
	miLista.push_front(10);
	miLista.push_front(20);
	miLista.push_back(200);
	miLista.push_back(300);
	miLista.push_front(50);
	miLista.push_front(60);
	miLista.push_back(300);
	miLista.push_back(500);
	miLista.print();
	cout << "Num: " << miLista.size() << endl;

	cout << endl;

	miLista.pop_back();
	miLista.pop_front();
	miLista.print();	
	cout << "Num: " << miLista.size() << endl;

	cout << endl;	

	// system("color 0a");
	
	return 0;
}