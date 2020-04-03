#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != 3)
	{
		cout << "incorrect input \n" << "need: compare.exe <file1> <file2> \n";
		system("pause");
		return 1;
	}

	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	if (!file1.is_open())
	{
		cout << "open error \n" << argv[1] << " for read\n";
		system("pause");
		return 1;
	}

	if (!file2.is_open())
	{
		cout << "open error \n" << argv[2] << " for read \n";
		system("pause");
		return 1;
	}

	if (file1 && file2)
	{
		int x, y;
		x = y = 0;
		char ch1, ch2;
		bool result = true;
		while (file1.get(ch1) && file2.get(ch2))
		{

			if (ch1 == '\n')
			{
				x++;
			}

			if (ch1 != ch2)
			{
				result = false;
				cout << "Files are different. Line number is " << ++x << endl;
				return 1;
			}
		}
		if (result)
		{
			cout << "Files are equal \n" << endl;
			return 0;
		}

	}
	file1.close();
	file2.close();
	return 0;

}