#include "ShapesProcessor.h"

using namespace std;

int main(int argc, char* argv[])
{
	ShapesProcessor processor;
	cout << "For create shape use this commands:\n\n"
		<< "lineSegment <start point> <end point> <outline color>\n"
		<< "triangle <vertex1> <vertex2> <vertex3> <outline color> <fill color>\n"
		<< "rectangle <left top vertex> <width> <height> <outline color> <fill color>\n"
		<< "circle <center> <radius> <outline color> <fill color>\n\n";

	try
	{
		processor.ReadShapes(cin);
		shared_ptr<IShape> largestAreaShape = processor.FindLargestAreaShape();
		if (largestAreaShape != nullptr)
		{
			cout << "Max area: " << largestAreaShape->ToString() << endl;
		}
		shared_ptr<IShape> smallestPerimeterShape = processor.FindSmallestPerimeterShape();
		if (largestAreaShape != nullptr)
		{
			cout << "\nMin perimetr: " << smallestPerimeterShape->ToString() << endl;
		}
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}