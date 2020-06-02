#pragma once
#include <string>

class TVSet
{
public:
	void TurnOff();
	void TurnOn();
	bool SelectChannel(int channel);
	int GetChannel() const;
	bool IsTurnedOn() const;
	void SelectPreviousChannel();
	bool IsAllowRange(int channel);

private:
	bool m_isEnabled = false;
	int m_channel = 1;
	static const int m_minChannel = 1;
	static const int m_maxChannel = 99;
};