#include "vector.h"

using namespace std;

int main()
{
	vector<double> inVector;
	Readvector(cin, inVector);
	if (inVector.size() != 0) {
		double maxElement = FindMaxElement(inVector);
		splitvector(inVector, maxElement);
		PrintSortedVector(inVector, cout);
	}
	else {
		cout << "Error! Vector is empty" << endl;
		return 0;
	}
	return 0;

}