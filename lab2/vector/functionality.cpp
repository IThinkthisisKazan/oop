#include "vector.h"


void Readvector(istream& input, vector<double>& vect)
{
	int num;
	cout << "Enter number whith space, enter 'q' to start: \n";
	while (cin >> num)		
		vect.push_back(num);
	cout << "This is your sequence: " << endl;
	for (int i = 0; i < vect.size(); i++)  
		cout << vect[i] << ' ';
}

double FindMaxElement(vector<double>& vect)
{
	cout << "\nFindMaxElement is started " << endl;
	if (!vect.empty())
	{
		double maxdiv ;
		float maxElement = *max_element(vect.begin(), vect.end());
		for (size_t i = 0; i < vect.size(); i++)
		{
			if (maxElement != 0)
			{
				maxdiv = maxElement / 2;
			}
			
		}
		cout << maxdiv;
		return maxdiv;
	}
}


void splitvector(vector<double>& vect, double maxdiv)
{
	cout << "\nsplitvector is started" << endl;
	for (unsigned int i = 0; i < vect.size(); ++i) {
		vect[i] /= maxdiv;
		cout << vect[i] << " ";
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



