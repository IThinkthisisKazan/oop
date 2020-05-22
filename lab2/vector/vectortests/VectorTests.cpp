#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../ConsoleApplication2/vector.h"

using namespace std;

TEST_CASE("Empty vector")
{
	vector<double> vect;
	FindMaxElement(vect);
	CHECK(vect.empty());
}

TEST_CASE("Single element in vector")
{
	vector<double> vectTest = { 6 };
	vector<double> vectRes = { 2 };
	FindMaxElement(vectTest);
	CHECK(vectTest == vectRes);
}

TEST_CASE("Check vector")
{
	vector<double> vectTest = { 12, 4, 21 };
	vector<double> vectRes = { 1.143, 0.381, 2 };
	FindMaxElement(vectTest);
	CHECK(vectTest == vectRes);
}

TEST_CASE("Sort vect")
{
	vector<double> vectTest = { 8,7,6,5,4,3,2,1 };
	vector<double> vectRes = { 1,2,3,4,5,6,7,8 };
	PrintSortedVector(vectTest);
	CHECK(vectTest == vectRes);
}

TEST_CASE("Divide by zero")
{
	vector<double> vectTest = { 2, 1, 0 };
	vector<double> vectRes = { 2.0, 1.0, INFINITY };
	FindMaxElement(vectTest);
	CHECK(vectTest == vectRes);
}
