#include "HashTable.h"

#include <iostream>
using namespace std;

int main()
{
	// Test cases
	HashTable a(10);


	a.insert(89);
	a.insert(65);
	a.insert(38);
	a.insert(27);
	a.insert(79);
	a.insert(54);
	a.insert(32);
	a.insert(21);

	cout << a << endl;

	a.deleteNum(79);

	cout << a;

	HashTable b(a);

	HashTable c(45);

	a = c;

	//cout << a;

	//cout << b;

	cout << endl;
	system("Pause");
	return 0;
}