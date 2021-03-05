#include "Algorithms.h"


using namespace MyAlgorithm_lib;

int main()
{
	std::vector<int> test{ 5,7,45,21,76,98,5,4,87,12,23,54 };
	Sort sort;
	sort.heapSort(test);

	for (int i : test)
	{
		std::cout << i << '\t';
	}
}