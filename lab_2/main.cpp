#include "list.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");  // NOLINT(concurrency-mt-unsafe)

	list list1;
	list list2;
	cout
		<< "x = " << list2.x
		<< endl << "y = " << list2.y
		<< endl << "z = " << list2.z;

	list2.out();

	char flag = 'y';
	while(flag == 'y')
	{
		cout << "x = ";
		cin >> list1.x;

		cout << "\ny = ";
		cin >> list1.y;

		cout << "\nz = ";
		cin >> list1.z;

		list1.out();

		cout << "Продолжить? [y/n]\n>> ";
		cin >> flag;
		system("cls");  // NOLINT(concurrency-mt-unsafe)
	}
}
