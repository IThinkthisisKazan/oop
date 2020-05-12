#include "vector.h"


void Readvector(istream& input, vector<double>& vect)
{
	int num;
	cout << "Enter number whith space, enter 'q' to start: \n";
	while (cin >> num)		
		vect.push_back(num);
	cout << "This is your sequence: " << endl;
	for (int i = 0; i < vect.size(); i++)     // нужна поддержка стандарта C++11
		cout << vect[i] << ' ';


}

double FindMinAndMaxElement(vector<double>& vect)
{
	cout << "\nFindMinAndMaxElement is started " << endl;
	if (!vect.empty())
	{
		double minmax = 100000000;
		float maxElement = *max_element(vect.begin(), vect.end());
		for (size_t i = 0; i < vect.size(); i++)
		{
			if (maxElement != 0)
			{
				minmax = maxElement / 2;
			}
			else
			{
				minmax = INFINITY;
			}
		}
		cout << minmax;
		return minmax;
	}
}


void MultiplyNumberForMinMax(vector<double>& vect, double minmax)
{
	cout << "\nMultiplyVectorByNumber is started \n" << endl;
	for (unsigned int i = 0; i < vect.size(); ++i) {
		vect[i] *= minmax;
		cout << vect[i];
	}
}


void PrintSortedVector(vector<double>& vect, ostream& output)
{
	cout << "\nPrintSortedVector is started " << endl;
	sort(vect.begin(), vect.end());
	for (unsigned int i = 0; i < vect.size(); ++i) {
		if (i != vect.size() - 1) {
			output << setprecision(3) << vect[i] << " ";
		}
		else {
			output << setprecision(3) << vect[i];
		}
	}
}



