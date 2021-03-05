#include "Points.h"
#include <string>

using namespace _Points;


void drill()
{
	
	Points original_points;	// drill 1 and 2
	std::string mydata = "mydata.text";

	std::cout << "Enter '7' pairs of points: (x, y): " << std::endl;
	
	for (Point p; std::cin >> p;)
	{
		original_points.addToPoints(p);
		if (original_points.pointsSize() >= 7)break;
	}
	printPoints(original_points);	// drill 3
	output_to_file(original_points, mydata);	// drill 4

	Points processed_points = input_from_file(mydata);	// drill 5

	printPoints(original_points);	// drill 6
	printPoints(processed_points);

	if (original_points != processed_points)	// drill 7
	{
		std::cout << "Something went wrong!" << std::endl;
	}
	else
	{
		std::cout << "Whoop!" << std::endl;
	}
}

void runDrills()
{
	drill();
}
