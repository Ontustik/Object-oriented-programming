#include "list.h"

int main()
{
	setlocale(LC_ALL, "RU");
	list list;

	char flag = 'y';
	int key = 0;
	while(flag == 'y')
	{
		system("cls");  // NOLINT(concurrency-mt-unsafe)
		cout
			<< endl
			<< "[1] - Запись в файл" << endl
			<< "[2] - Чтение с файла" << endl
			<< ">> ";
			
		cin >> key;
		switch(key)
		{
			case 1:
			{
				cout << "int\t";
				cin >> list.int_;

				cout << "\ndouble\t";
				cin >> list.double_;

				cout << "\nchar\t";
				cin >> list.char_;

				cout << "\nstring\t";
				cin >> list.string_;

				list.out();
				list.out_txt();
				list.out_bin();
				break;
			}
			case 2:
			{
				list.read_txt();
				list.read_bin();
				cout << "\nSize is " << list.size_binary() << " bytes." << endl;

				list.copy_txt_to_bin();

				break;
			}
			default:
				break;
		}
		cout << "Продолжить? [y/n] ";
		cin >> flag;
	}
}
