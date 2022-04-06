﻿#include <iostream>
#include <Windows.h> //для того чтоб компилятор понимал русский язык строки

using namespace std;

int StrLen(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);

void remove_symbol(char str[], char symbol);

bool is_integer(char str[]);
bool is_bin(char str[]);
bool is_hex(char str[]);

void main()
{
	setlocale(LC_ALL, ".1251");

	/*char str[] = { 'H','e','l','l','o','!',0 };
	  char str[] = "Hello!";
	  cout << str << endl;

	  cout << (int)'A' << endl;
	  cout << (int)'a' << endl;
	*/

	SetConsoleCP(1251); //  чтоб вывести русский язык
	//SetConsoleOutputCP(1251); // не работает

	const int n = 256;
	char str[n]="1011";

	//cout << "Введите строку: "; 
	//cin >> str;
	//cin.getline(str, n); // чтоб ввести строку с пробелами

	cout << str << endl;
	cout << "Длина введенной строки: " << StrLen(str) << endl;
	to_upper(str);
	cout << "Строка преобразована в верхний регистр: " << str << endl;
	to_lower(str);
	cout << "Строка преобразована в нижний регистр: " << str << endl;
	shrink(str);
	cout << "Удаление из строки лишних пробелов: " << str << endl;
	is_palindrome(str);
	cout << "Палиндром: " <<is_palindrome(str)<< endl;
	cout << " 1 - палиндром, если 0 - не палиндром" << endl;
	
	cout << "Строка " << str << (is_integer(str) ? " " : " не ") << "является целым числом!" << endl;
	cout << "Строка "<< str<< (is_bin(str) ? " " : " не ") << "является двоичным числом!"<< endl;
	cout << "Строка "<< str<< (is_hex(str) ? " " : " не ") << "является шестнадцатеричным числом!"<< endl;

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

void to_upper(char str[])
{
	for (int i = 0;str[i];i++)
	{   // если элемент строки str[i] - маленькая буква 
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'a' && str[i] <= 'я')
			str[i] -= 32; // Преобразуем в большую букву
	}
}

void to_lower(char str[])
{
	for (int i = 0;str[i];i++)
	{   // если элемент строки str[i] - большая 
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
			str[i] += 32; // Преобразуем в маленькую
	}
}

void shrink (char str[])
{
	for (int i = 0;i < str[i];i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ') // if - выполнится один раз, чтоб цикл выполнялся до n кол-ва раз
			                                       // пока строка не сдвинется на нужное кол-во нам пробелов, необходимо использовать while
		{
			for (int j = i;str[j];j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void remove_symbol(char str[], char symbol) // удаление любого символа из строки
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{ 
				str[j] = str[j + 1];
			}
		}
	}
}

bool is_palindrome(char str[])
{
	char* buffer = new char[StrLen(str) + 1]{};
	for (int i = 0;str[i];i++)
		buffer[i] = str[i];
	remove_symbol(buffer, ' ');
	int n = StrLen(buffer);
	to_upper(buffer); // если в строке есть хотя бы одна заглавная буква, то чтоб функция считала ее полиндромом, используем to_upper(str)
	for (int i = 0; i < n / 2;i++)
	{
		if (buffer[i] != buffer[n - 1 - i]) // n-1 последний элемент массива, далее отнимаем i - это мы выходим на предпоследний элемент, потом
									        // пред-предпоследний и.т.д.
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_integer(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return false;
		if (str[i] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}

bool is_bin(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			return false;
		if (str[i] == ' ' && str[i - 1] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}

bool is_hex(char str[])
{
	for (int i = str[0] == '0' && (str[1] == 'x' || str[1] == 'X') ? 2 : 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'f')
			)
			return false;
	}
	return true;
}
