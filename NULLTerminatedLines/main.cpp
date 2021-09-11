#include <iostream>
#include <Windows.h> // ��� ���� ���� ���������� ������� ������� ���� ������

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

	SetConsoleCP(1251); //  ���� ������� ������� ����
	//SetConsoleOutputCP(1251); // �� ��������

	const int n = 256;
	char str[n]="1011";

	//cout << "������� ������: "; 
	//cin >> str;
	//cin.getline(str, n); // ���� ������ ������ � ���������

	cout << str << endl;
	cout << "����� ��������� ������: " << StrLen(str) << endl;
	to_upper(str);
	cout << "������ ������������� � ������� �������: " << str << endl;
	to_lower(str);
	cout << "������ ������������� � ������ �������: " << str << endl;
	shrink(str);
	cout << "�������� �� ������ ������ ��������: " << str << endl;
	is_palindrome(str);
	cout << "���������: " <<is_palindrome(str)<< endl;
	cout << " 1 - ���������, ���� 0 - �� ���������" << endl;
	
	cout << "������ " << str << (is_integer(str) ? " " : " �� ") << "�������� ����� ������!" << endl;
	cout << "������ "<< str<< (is_bin(str) ? " " : " �� ") << "�������� �������� ������!"<< endl;
	cout << "������ "<< str<< (is_hex(str) ? " " : " �� ") << "�������� ����������������� ������!"<< endl;

}

int StrLen(char str[])
{
	int i = 0;
	for (;str[i];i++);
	return i;
}

// bool
// true - ��� ��� �� 0
// false - 0

void to_upper(char str[])
{
	for (int i = 0;str[i];i++)
	{   // ���� ������� ������ str[i] - ��������� ����� 
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'a' && str[i] <= '�')
			str[i] -= 32; // ����������� � ������� �����
	}
}

void to_lower(char str[])
{
	for (int i = 0;str[i];i++)
	{   // ���� ������� ������ str[i] - ������� 
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '�' && str[i] <= '�')
			str[i] += 32; // ����������� � ���������
	}
}

void shrink (char str[])
{
	for (int i = 0;i < str[i];i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ') // if - ���������� ���� ���, ���� ���� ���������� �� n ���-�� ���
			                                       // ���� ������ �� ��������� �� ������ ���-�� ��� ��������, ���������� ������������ while
		{
			for (int j = i;str[j];j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void remove_symbol(char str[], char symbol) // �������� ������ ������� �� ������
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
	to_upper(buffer); // ���� � ������ ���� ���� �� ���� ��������� �����, �� ���� ������� ������� �� �����������, ���������� to_upper(str)
	for (int i = 0; i < n / 2;i++)
	{
		if (buffer[i] != buffer[n - 1 - i]) // n-1 ��������� ������� �������, ����� �������� i - ��� �� ������� �� ������������� �������, �����
									        // ����-������������� �.�.�.
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
