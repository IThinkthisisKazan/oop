#include "vector.h"

using namespace std;

int main()
{
	vector<double> input;
	Readvector(cin, input);
	if (input.size() != 0) {
		double maxElement = FindMaxElement(input);
		PrintSortedVector(input);
	}
	else {
		cout << "Error! Vector is empty" << endl;
		return 0;
	}
	return 0;

}