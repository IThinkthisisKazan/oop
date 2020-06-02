#include <iostream>
#include "../TVSet/TVSet.h"

using namespace std;

void TurnOn(TVSet& tv, ostream& output)
{
	if (!tv.IsTurnedOn())
	{
		tv.TurnOn();
		output << "TV is turned on\n";
	}
	else
	{
		output << "TV is already on\n";
	}
}

void TurnOff(TVSet& tv, ostream& output)
{
	if (tv.IsTurnedOn())
	{
		tv.TurnOff();
		output << "TV is turned off\n";
	}
	else
	{
		output << "TV is already off\n";
	}
}

void SelectChannel(TVSet& tv, istream& input, ostream& output)
{
	int channel;
	if (input >> channel)
	{
		if (!tv.IsTurnedOn())
		{
			output << "Error. TV is turned off\n";
			return;
		}
		else if (!tv.IsAllowRange(channel))
		{
			output << "Error. Channel is out of allow range\n";
			return;
		}
		tv.SelectChannel(channel);
		output << "Selected channel " << channel << "\n";
	}
	else
	{
		output << "Error. Input error\n";
		input.clear();
	}
}

void PrintInfo(TVSet& tv, ostream& output)
{
	output << "TV is turned " << (tv.IsTurnedOn() ? "on" : "off") << endl;
	output << "Current channel " << tv.GetChannel() << endl;
}

void TVController(istream& input, ostream& output)
{
	TVSet tv;
	string command;
	while (cin >> command)
	{
		if (command == "TurnOn" || command == "turnon")
		{
			TurnOn(tv, output);
		}
		else if (command == "TurnOff" || command == "turnoff")
		{
			TurnOff(tv, output);
		}
		else if (command == "SelectChannel" || command == "selectchannel")
		{
			SelectChannel(tv, input, output);
		}
		else if (command == "Info" || command == "info")
		{
			PrintInfo(tv, output);
		}
		else
		{
			output << "Error!! \nUnknown command, use: TurnOn, TurnOff, SelectChannel <channel number>, Info\n";
		}
	}
}

int main(int argc, char* argv[])
{
	cout << "Program TVSet is started" << endl;
	TVController(cin, cout);
}