#include<iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{

	if (argc != 2)
	{
		setlocale(LC_ALL, "Russian");
		cout << "incorrect input \n" << "need: dec2bin.exe < числов в десятичной системе > \n";
		return 1;
	}

	int t = 0, d = 1;
	string test = argv[1];
	int num = stoi(test);

	while (num)
	{
		t += (num % 2) * d;
		num = num / 2;
		d = d * 10; // razryad
	}
	cout << t;
	cout << endl;
	return 0;
}

