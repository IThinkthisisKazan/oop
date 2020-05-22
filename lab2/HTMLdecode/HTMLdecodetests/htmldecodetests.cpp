#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../STUDY/OOP_Malov/catch2/catch.hpp"
#include "../htmlDecode/htmldecode.h"

using namespace std;

SCENARIO("Empty line test")
{
	WHEN("input strig is empty")
	{
		string html = "";
		string emptyLine = "";
		THEN("Сomparison string is zero")
		{
			CHECK(Decode(html) == emptyLine);
		}
	}
}

SCENARIO("Testing decode string")
{
	WHEN("Decode string tests 1")
	{
		string html = "&&&qu&lt;ot&lt;;;;....&&&";
		string decryptedLine = "&&&qu\<ot<;;;....&&&";
		THEN("Comparison should be equal to each other")
		{
			CHECK(Decode(html) == decryptedLine);
		}

	}

	WHEN("Decode string tests 2")
	{
		string html = "256 &gt; 254 &amp; &apos;a&apos; &lt; &apos;b&apos;";
		string decryptedLine = "256 > 254 & \'a\' < \'b\'";

		THEN("Comparison should be equal to each other")
		{
			CHECK(Decode(html) == decryptedLine);
		}
	}

	WHEN("Decode string tests 3")
	{
		string html = "&quot;hello&quot;";
		string decryptedLine = "\"hello\"";
		THEN("Comparison should be equal to each other")
		{
			CHECK(Decode(html) == decryptedLine);
		}

	}

	WHEN("Decode string tests 4")
	{
		string html = "&lt;&lt;Hello&lt;&lt;&quot;";
		string decryptedLine = "<<Hello>>";
		THEN("Сomparison will not be equal")
		{
			CHECK(Decode(html) != decryptedLine);
		}

	}
}
