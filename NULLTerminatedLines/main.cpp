#include <iostream>
#include <Windows.h> // для того чтоб компилятор понимал русский язык строки

using namespace std;

int StrLen(char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");

	//char str[] = { 'H','e','l','l','o','!',0 };
	//char str[] = "Hello!";
	//cout << str << endl;

	SetConsoleCP(1251); //  чтоб вывести русский язык
	const int n = 20;
	char str[n];
	cout << "Введите строку: "; 
	//cin >> str;
	cin.getline(str, n); // чтоб ввести строку с пробелами
	cout << str << endl;
	cout << "Длина введенной строки: " << StrLen(str) << endl;
}

int StrLen(char str[])
{
	int i = 0;
	for (;str[i];i++);
	return i;
}

// bool
// true - все что не 0
// false - 0