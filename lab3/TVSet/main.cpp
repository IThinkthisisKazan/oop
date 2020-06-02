#include <iostream>
#include "TVSet.h"
#include "CommandHandler.h"

using namespace std;

int main()
{
	cout << "TVSet is started" << endl;
	TVSet tv;
	HandleTvCommands(cin, cout, tv);
}