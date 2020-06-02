#include "CommandHandler.h"

using namespace std;

void HandleTvCommands(std::istream& input, std::ostream& output, TVSet& tv)
{
	string command;
	while (!input.eof())
	{
		input >> command;
		if (command == "TurnOn" || command == "turnon")
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
		else if (command == "TurnOff" || command == "turnoff")
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
		else if (command == "SelectChannel" || command == "selectchannel")
		{
			int channel;
			if (input >> channel)
			{
				if (!tv.IsTurnedOn())
				{
					output << "Error. TV is turned off\n";
					continue;
				}
				else if (!tv.IsAllowRange(channel))
				{
					output << "Error. Channel is out of allow range\n";
					continue;
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
		else if (command == "Info" || command == "info")
		{
			output << "TV is turned " << (tv.IsTurnedOn() ? "on" : "off") << endl;
			output << "Current channel " << tv.GetChannel() << endl;
		}
		else if (command == "SelectPreviousChannel" || command == "selectpreviouschannel")
		{
			tv.SelectPreviousChannel();
		}
		else
		{
			output << "Undefined command '" << command << "'" << endl;
		}
	}
}