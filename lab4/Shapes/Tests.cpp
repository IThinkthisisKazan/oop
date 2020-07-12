#define CATCH_CONFIG_MAIN
#include "../ShapesTests/catch2/catch.hpp"
#include "../Shapes/ShapesProcessor.h"
#include <math.h>
 
using namespace std;
TEST_CASE("Read line segment")
{
	ShapesProcessor processor;
	istringstream input("lineSegment 2 0 2 100 ff0000");
	processor.ReadShapes(input);
	string expectedString = "\nShape: line\nStart:  point (2.00, 0.00)\nEnd: point (2.00, 100.00)\nArea: 0.00\nPerimetr: 100.00\nOutline color: ff0000";
	REQUIRE(processor.GetShapes()[0]->ToString() == expectedString);
	cout << "Test Read line \n";
}

TEST_CASE("Read triangle")
{
	ShapesProcessor processor;
	istringstream input("triangle 0 -10 0 10 0 0 ff00ff ff002");
	processor.ReadShapes(input);
	string expectedString = "\nShape: triangle\nVertex1: point (0.00, -10.00)\nVertex2: point (0.00, 10.00)\nVertex3: point (0.00, 0.00)\nArea: 0.00\nPerimetr: 40.00\nOutline color: ff00ff\nFill color: ff002";
	REQUIRE(processor.GetShapes()[0]->ToString() == expectedString);
	cout << "Test Read triangle \n";
}

TEST_CASE("Read rectangle")
{
	ShapesProcessor processor;
	istringstream input("rectangle 0 -10 10 10 0 0");
	processor.ReadShapes(input);
	string expectedString = "\nShape: rectangle\nLeft top: point (0.00, -10.00)\nWidth: 10.00\nHeight: 10.00\nArea: 100.00\nPerimetr: 40.00\nOutline color: 000000\nFill color: 0";
	REQUIRE(processor.GetShapes()[0]->ToString() == expectedString);
	cout << "Test Read rectangle \n";
}

TEST_CASE("Read circle")
{
	ShapesProcessor processor;
	istringstream input("circle 0 0 10 ff00ff ffffff");
	processor.ReadShapes(input);
	string expectedString = "\nShape: circle\nCenter: point (0.00, 0.00)\nRadius: 10.00\nArea: 314.00\nPerimetr: 62.80\nOutline color: ff00ff\nFill color: ffffff";
	REQUIRE(processor.GetShapes()[0]->ToString() == expectedString);
	cout << "Test Read circle \n";
}

TEST_CASE("Read point")
{
	string s("Read point");
	CPoint p1{ 2, 2.5 };
	REQUIRE(p1.x == 2);
	REQUIRE(p1.x == 2);
	REQUIRE(p1 == p1);
	std::string expectedString = "point (2.00, 2.50)";
	REQUIRE(p1.ToString() == expectedString);
	cout << "Test Read point \n";
}

TEST_CASE("FindFigureWithBiggestArea")
{
	ShapesProcessor figures;
	stringstream in;
	in << "line 10.3 20.15 30.7 40.4 ff00aa\n"
		<< "rectangle 10.3 20.15 30.7 40.4 ff0000 00ffaa\n"
		<< "triangle 10.3 20.15 30.7 40.4 10.3 40.4 ff0000 00ffaa\n"
		<< "circle 10.3 20.15 10 ff0000 00ffaa\n";
	for (int i = 0; i < 4; i++)
	{
		figures.ReadShapes(in);
	}
	string expected = "\nShape: rectangle\nLeft top: point (10.30, 20.15)\nWidth: 30.70\nHeight: 40.40\nArea: 1240.28\nPerimetr: 142.20\nOutline color: ff0000\nFill color: ffaa";
	REQUIRE(figures.FindLargestAreaShape()->ToString() == expected);
	cout << "Test Find Max area\n";
}
TEST_CASE("FindFigureWithSmallestPerimeter")
{
	ShapesProcessor figures;
	stringstream in;
	in << "line 10.3 20.15 30.7 40.4 ff00aa\n"
		<< "rectangle 10.3 20.15 30.7 40.4 ff0000 00ffaa\n"
		<< "triangle 10.3 20.15 30.7 40.4 10.3 40.4 ff0000 00ffaa\n"
		<< "circle 10.3 20.15 10 ff0000 00ffaa\n";
	for (int i = 0; i < 4; i++)
	{
		figures.ReadShapes(in);
	}

	string expected = "\nShape: circle\nCenter: point (10.30, 20.15)\nRadius: 10.00\nArea: 314.00\nPerimetr: 62.80\nOutline color: ff0000\nFill color: ffaa";
	REQUIRE(figures.FindSmallestPerimeterShape()->ToString() == expected);
	cout << "Test Find Min perimetr\n";
}