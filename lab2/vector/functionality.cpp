#include "vector.h"


void Readvector(istream& input, vector<double>& vect)
{
	double num;
	cout << "Enter number whith space, enter 'q' to start: \n";
	while (input >> num) 
	{
		vect.push_back(num);
	}
	cout << "This is your sequence: " << endl;
	for (int i = 0; i < vect.size(); i++)  
		cout << vect[i] << ' ';
}


double FindMaxElement(vector<double>& vect)
{
	cout << "\nFindMaxElement is started " << endl;

	if (!vect.empty())
	{

		double maxdiv = 9999999.0;
		double maxElement = *max_element(vect.begin(), vect.end());
		for (size_t i = 0; i < vect.size(); i++)
		{
			if (maxElement != 0)
			{
				maxdiv = maxElement / 2;
			}		
		}
		cout << maxdiv << endl;
		cout << "Split vector:" << endl;
		for (unsigned int i = 0; i < vect.size(); ++i) {
			vect[i] = round((vect[i] / maxdiv)*1000)/1000;
			cout << vect[i] << " ";

			if (vect[i] == 0)
			{
				vect[i] = INFINITY;
			}
		}

		return maxdiv;
	}
}


/*
void splitvector(vector<double>& vect, double maxdiv)
{
	cout << "\nsplitvector is started" << endl;
	for (unsigned int i = 0; i < vect.size(); ++i) {
		vect[i] /= maxdiv;
		cout << vect[i] << " ";
	}
}
*/

void PrintSortedVector(vector<double>& vect)
{
	cout << "\nPrintSortedVector is started " << endl;
	sort(vect.begin(), vect.end());
	for (unsigned int i = 0; i < vect.size(); ++i) {
		if (i != vect.size() - 1) {
			cout << setprecision(3) << vect[i] << " ";
		}
		else {
			cout << setprecision(3) << vect[i];
		}
	}
}



