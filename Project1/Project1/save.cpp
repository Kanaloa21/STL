#include "save.h"
#include <iostream>
#include <filesystem>
#include <fstream>
// google coding convention
using namespace std;

void save(string_view file_name)
{
	using namespace filesystem;
	// 어떤파일을 저장하는지 화면에 출력한다. - File Name & Size
	cout << "저장: " << file_name << ", 크기 " << file_size(file_name) << endl;
	ofstream out("2021 1학기 STL 화56 목56 강의저장.txt", ios::app);			// app googling
	ifstream in(file_name);													// read file open
	out << endl << endl;													// write enter
	time_t t = time(nullptr);												// time_t googling
	out.imbue(locale("korean"));											// imbue googling
	out << "//----------------------------------------------------" << endl;
	out << "// 저장시간 : " << put_time(localtime(&t), "%c, %A") << endl;		// localtime googling
	out << "//" << endl;
	int c;																	// file의 끝을 알기위해 int, not char
	while ((c = in.get()) != EOF)
		out.put(c);
	// RAII 기능
	// in.close();	x, out, in은 stack에 저장
	// out.close(); x, c++은 자동으로 해제
}
