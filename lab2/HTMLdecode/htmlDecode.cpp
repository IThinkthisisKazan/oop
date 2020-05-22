#include "htmlDecode.h"

using namespace std;

int main()
{
	string line;
	cout << "Please input HTML-code for decoding: \n";
	while (getline(cin, line))
	{
		line = Decode(line);
		cout <<"Your HTML-decode text : \n" << line << endl;
	}

	return 0;
}