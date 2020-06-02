#include "TVSet.h"


void TVSet::TurnOff()
{
	m_isEnabled = false;
}

void TVSet::TurnOn()
{
	m_isEnabled = true;
}

bool TVSet::IsAllowRange(int channel)
{
	return m_minChannel <= channel && channel <= m_maxChannel;
}

bool TVSet::SelectChannel(int channel)
{
	if (!m_isEnabled)
	{
		return false;
	}
	if (IsAllowRange(channel))
	{
		m_previousChannel = m_channel;
		m_channel = channel;
		return true;
	}
	return false;
}

int TVSet::GetChannel() const
{
	if (m_isEnabled)
	{
		return m_channel;
	}
	return 0;
}

bool TVSet::IsTurnedOn() const
{
	return m_isEnabled;
}

void TVSet::SelectPreviousChannel()
{
	if (!m_isEnabled || m_previousChannel == 0)
	{
		return;
	}
	std::swap(m_channel, m_previousChannel);
}