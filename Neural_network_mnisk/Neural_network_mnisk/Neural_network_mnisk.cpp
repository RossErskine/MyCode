#include "Neural_Network.h"
#include "InputData.h"
#include <time.h>
#include <Windows.h>

using namespace NN;
bool end = false;


	/*======================================================================
	*	 stops program early by press ng esc if data has converged 
	*///====================================================================
void waitToQuit(int time)
{
	clock_t endWait;
	bool noInput = true;
	endWait = clock() + time;
	while (clock() <= endWait && noInput)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			end = true;
			noInput = false;
		}
	}
}

void runMnist_NN()
{
	const std::string mnist_training_data = "train.csv";
	InputSet trainSet = get_mnisk_data(mnist_training_data);
	
	Network test_NN(784, 30, 10);// network slayer sizes 
	
	std::cout << "Training data....." << std::endl;
	std::cout << "training data size: " << trainSet.getSetSize() << std::endl;


	while (!end)
	{	
		
		for (int i = 0; i != 10000; i++)
		{
			std::cout << "\nEpoch:" << i << ": label:" << trainSet.getDataSet()[i].getLabel() << '\n';
			test_NN.trainNetwork(trainSet.getDataSet()[i].getPixels(), trainSet.getDataSet()[i].getLabel());

			waitToQuit(20);
			if (end)break;
		}
	
	
		end = true;
	}


	std::cout << "Training finished" << std::endl;
	std::cout << "Validating data....." << std::endl;
	for (int i = 40001; i != 40101; i++) // 100 validation of dataset
	{
		std::cout << "\nEpoch:" << i << ": label:" << trainSet.getDataSet()[i].getLabel() << '\n';
		test_NN.testNetwork(trainSet.getDataSet()[i].getPixels(), trainSet.getDataSet()[i].getLabel());
		std::cout << "correct answers:" << test_NN.getCorrect_answers() << std::endl;
	}
	std::cout << "Validating finished" << std::endl;
	
}

void runTestSet()
{
	
	const std::string mnist_mini_training_data = "mnist_mini.csv";
	InputSet trainSet = get_mnisk_data(mnist_mini_training_data);
	

	Network test_NN(784, 15, 10);// network slayer sizes 

	std::cout << "Training data....." << std::endl;
	std::cout << "training data size: " << trainSet.getSetSize() << std::endl;


	while (!end)
	{
		for (int j = 0; j != 20; j++) {
			for (int i = 0; i != trainSet.getSetSize(); i++){
				std::cout << "\ndEpoch:" << i << ": label:" << trainSet.getDataSet()[i].getLabel() << '\n';
				test_NN.trainNetwork(trainSet.getDataSet()[i].getPixels(), trainSet.getDataSet()[i].getLabel());

				waitToQuit(20);
				if (end)break;
			}
		}
		end = true;
	}


	std::cout << "Training finished" << std::endl;
	std::cout << "Validating data....." << std::endl;
	for (int i = 0; i != trainSet.getSetSize(); i++) // 1000 validation of dataset
	{
		std::cout << "\nEpoch:" << i << ": label:" << trainSet.getDataSet()[i].getLabel() << '\n';
		test_NN.testNetwork(trainSet.getDataSet()[i].getPixels(), trainSet.getDataSet()[i].getLabel());
		std::cout << "correct answers:" << test_NN.getCorrect_answers() << std::endl;
	}
	std::cout << "Validating finished" << std::endl;
}


int main()
{
	std::cout.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);// exceptions on file use 
	try
	{
		runMnist_NN();
		//runTestSet();
		return 0;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;

	}
	catch (const std::ios_base::failure& ex)
	{
		std::cerr << "Caught exception: " << ex.what()
			<< ", error code = " << ex.code() << std::endl;
	}
	
}




