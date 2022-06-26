#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

class list
{
	ofstream
		file_out;

	ifstream
		file;

	streampos
		begin,
		end;
	string
		line;

public:
	int
		int_ = 0;
	double
		double_ = 0;
	char
		char_{};
	string
		string_;

	void out() const;

	void out_txt();

	void out_bin();

	void copy_txt_to_bin();

	streampos size_binary();

	void read_txt();

	void read_bin();
};

inline void list::out() const
{
	cout << endl << "INT" << setw(20) << int_
		<< endl << "DOUBLE" << setw(20) << setprecision(10) << double_
		<< endl << "CHAR" << setw(20) << char_
		<< endl << "STRING" << setw(20) << string_ << endl;
}

inline void list::out_txt()
{
	file_out.open("in.txt");

	file_out
		<< int_ << endl
		<< setprecision(10)
		<< double_ << endl
		<< char_ << endl
		<< string_;

	file_out.close();
}

inline void list::out_bin()
{
	file_out.open("data.bin", fstream::binary);
	file_out
		<< int_ << endl
		<< setprecision(10) << double_ << endl
		<< char_ << endl
		<< string_;
	file_out.close();
}

inline void list::copy_txt_to_bin()
{
	file.open("in.txt", fstream::binary);
	file_out.open("data_copy.bin", std::fstream::trunc | fstream::binary);
	file_out << file.rdbuf();
	file.close();
	file_out.close();
}

inline streampos list::size_binary()
{
	file.open("data.bin", ios::binary);
	begin = file.tellg();
	file.seekg(0, ios::end);
	end = file.tellg();
	file.close();

	return end - begin;
}

inline void list::read_txt()
{
	cout << endl << "\nЧтение из текстового файла:\n";
	file.open("in.txt");
	while(getline(file, line))
	{
		cout << line << endl;
	}
	file.close();
}

inline void list::read_bin()
{
	cout << endl << "\nЧтение из бинарного файла:\n";
	file.open("data.bin", ios::binary);
	while(getline(file, line))
	{
		cout << line << endl;
	}
	file.close();
}
