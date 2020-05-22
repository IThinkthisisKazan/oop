#include "htmlDecode.h"

using namespace std;

const unordered_map <string, string> codeLibrary =
{
	{"&quot;", "\""},
	{"&apos;", "'"},
	{"&lt;", "<"},
	{"&gt;", ">"},
	{"&amp;", "&"}
};



string Decode(string const& html)
{
	string decodingLine = html;
	size_t codeIndex;


	for (auto it = codeLibrary.begin(); it != codeLibrary.end(); ++it)
	{
		string valueCode = it->first;
		string decryptedValue = it->second;
		size_t sizeCode = valueCode.length();

		while ((codeIndex = decodingLine.find(valueCode)) != string::npos)
		{
			decodingLine.erase(codeIndex, sizeCode);
			decodingLine.insert(codeIndex, decryptedValue);
		}
	}
	return decodingLine;
}