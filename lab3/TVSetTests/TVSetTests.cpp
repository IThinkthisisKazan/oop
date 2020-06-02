#define CATCH_CONFIG_MAIN
#include "../TVSet/TVSet.h"
#include "../../../catch2/catch.hpp"

using namespace std;

TEST_CASE("TV should be turned off and channel is 0")
{
	TVSet tv;
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("channel at turned off tv equals 0")
{
	TVSet tv;
	tv.TurnOff();
	REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("select chanel")
{
	TVSet tv;
	tv.TurnOn();
	tv.SelectChannel(5);
	REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("tv turn on at previous channel")
{
	TVSet tv;
	tv.TurnOn();
	tv.SelectChannel(5);
	tv.TurnOff();
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("select chanel on turned off tv")
{
	TVSet tv;
	tv.TurnOff();
	tv.SelectChannel(5);
	REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("select not available chanel")
{
	TVSet tv;
	tv.TurnOn();
	tv.SelectChannel(1);
	tv.SelectChannel(10);
	tv.SelectChannel(12);
	tv.SelectPreviousChannel();
	REQUIRE(tv.GetChannel() == 10);
}