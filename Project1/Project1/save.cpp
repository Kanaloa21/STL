#include "save.h"
#include <iostream>
#include <filesystem>
#include <fstream>
// google coding convention
using namespace std;

void save(string_view file_name)
{
	using namespace filesystem;
	// ������� �����ϴ��� ȭ�鿡 ����Ѵ�. - File Name & Size
	cout << "����: " << file_name << ", ũ�� " << file_size(file_name) << endl;
	ofstream out("2021 1�б� STL ȭ56 ��56 ��������.txt", ios::app);			// app googling
	ifstream in(file_name);													// read file open
	out << endl << endl;													// write enter
	time_t t = time(nullptr);												// time_t googling
	out.imbue(locale("korean"));											// imbue googling
	out << "//----------------------------------------------------" << endl;
	out << "// ����ð� : " << put_time(localtime(&t), "%c, %A") << endl;		// localtime googling
	out << "//" << endl;
	int c;																	// file�� ���� �˱����� int, not char
	while ((c = in.get()) != EOF)
		out.put(c);
	// RAII ���
	// in.close();	x, out, in�� stack�� ����
	// out.close(); x, c++�� �ڵ����� ����
}
