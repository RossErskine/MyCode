#include "Neural_Network.h"
#include <random>
#include <iostream>
#include <fstream>

namespace NN
{
	// ================================ member functions ================================ //
	// === constructors == //
	/*===============================================
	*	size_of = number of nodes in layer
	*	NL = next layer (hidden or output)
	*///=============================================
	Neuron::Neuron(int size_of_NL) : mInput(0) // start with empty neuron
	{
		// == randomly creates weights between 1 & -1 == //
		for (int i = 0; i != size_of_NL; i++){
			mWeights.push_back(randDouble(-1, 1));
		}
	}
	/*==================================================
	*	IL = input layer
	*	HL = Hidden layer
	*	OL = output layer
	*	size_of = number of nodes in layer
	*///================================================
	Network::Network(int size_of_IL, int size_of_HL, int size_of_OL)
		: mTotal_error(0), correct_answers(0)
	{
		// == input layer == //
		for (int i = 0; i != size_of_IL; i++){
			Neuron n(size_of_HL+1);
			mInput_layer.push_back(n);
		}
		Neuron input_bias(size_of_HL+1);	// input bias
		input_bias.setInput(1);
		mInput_layer.push_back(input_bias);

		// == hidden layers == //
		for (int i = 0; i != size_of_HL; i++){
			Neuron n(size_of_OL+1);
			mHidden_layer.push_back(n);
		}
		Neuron hidden_bias(size_of_OL);	// hiiden layers bias
		hidden_bias.setInput(1);
		mHidden_layer.push_back(hidden_bias);

		// == output layer == //
		for (int i = 0; i != size_of_OL; i++){
			Neuron n(0);		// no weights needed for output neuron 
			mOutput_layer.push_back(n);
		}

	
	}

	/*=======================================================================
	*	trainNetwork consists of first initial data added to in puts of 
	*	input layer, forward propogation sends the data to each layer, the
	*	total and local error is calculated, information is sent to csv file
	*	then finally ends with back popogation, needs to be in loop for 
	*	multiple sets	
	*///=====================================================================
	void Network::trainNetwork(std::vector<double> dataSet, int label)
	{
		setInputs(dataSet);
		// == forward propagate == //
		
		// input layer to hidden layer
		for (int i = 0; i != mHidden_layer.size(); i++) // -1 for bias
		{
			mHidden_layer[i].setInput(forward_prpogation(mInput_layer, i));  
		}
		
		
		// hidden layer to output layer
		for (int i = 0; i != mOutput_layer.size(); i++) // -1 for bias
		{
			mOutput_layer[i].setInput(softmax(mHidden_layer, i));
					
		}
		
		// compute error
		setTotal_error(compute_error(label));
		std::cout << "\nError: " << getTotal_error() << '\n';
		
		std::cout << "Output: \t Errors \n";
		for (int i = 0; i != mOutput_layer.size(); i++)
		{
			std::cout << mOutput_layer[i].getInput() << ":\t" << mLocalError[i] << '\n';
		}
		// == upload data to file == //
		NN_data(getTotal_error(), label);
		// compute gradient 
		back_propogation(label);

	}
	/*=================================================================
	*	test network is same as train except uses final guess and does 
	*	not upload to file or back propogation 
	*///===============================================================
	void Network::testNetwork(std::vector<double> dataSet, int label)
	{
		
		setInputs(dataSet);

		// input layer to hidden layer
		for (int i = 0; i != mHidden_layer.size() ; i++) // -1 for bias
		{
			mHidden_layer[i].setInput(forward_prpogation(mInput_layer, i));
		}

		// hidden layer to output layer
		for (int i = 0; i != mOutput_layer.size() ; i++) // -1 for bias
		{
			mOutput_layer[i].setInput(softmax(mHidden_layer, i));
				
		}
		
		setTotal_error(compute_final_error());
		std::cout << "\nError: " << getTotal_error() << '\n';
		// == has guess of label == //
		int guess = final_guess();
		std::cout << "Guess: " << guess << '\n';
		if (guess == label)correct_answers++;
		
		std::cout << "Output: \n";
		for (int i = 0; i != mOutput_layer.size(); i++)
		{
			std::cout << mOutput_layer[i].getInput() << '\n';
		}
	}

	/*========================================================================
	*	sets first data into network 
	*///======================================================================
	void Network::setInputs(std::vector<double> dataSet)
	{
		if (mInput_layer.size() - 1 != dataSet.size()) // -1 for bias
			throw "setInput: sets are not equal!";

		for (int i = 0; i != dataSet.size(); i++)
		{
			mInput_layer[i].setInput(dataSet[i]);
		}
	}


	/*======================================================================
	*	forward propogation uses summation and activation functions then sets 
	*	intput of next layer
	*///====================================================================
	double Network::forward_prpogation(std::vector<Neuron> layer1, int pos)
	{
		//summation
		double sum = summation_operator(layer1, pos);
		
		// activation
		double next_input = activation(sum);

		return next_input;
			
	}

	/*======================================================================
	*	 mean squared error 0.1 * sum (output - guess * 2)
	*///====================================================================
	double Network::compute_error(int label)
	{
		double totalError = 0;
		mLocalError.clear();
		for (int i = 0; i != mOutput_layer.size(); i++)
		{
			
			double local_error = ( is_target_output(label, i) - mOutput_layer[i].getInput())
				* (is_target_output(label, i) - mOutput_layer[i].getInput());
			
			
			totalError += local_error;
			mLocalError.push_back(local_error);
		}
		totalError *= 0.1;
		return totalError;

	}
	/*======================================================================
	*	 creates final errror from output of output layer then averaged 
	*///====================================================================
	double Network::compute_final_error()
	{
		double totalError = 0;
		mLocalError.clear();
		for (int i = 0; i != mOutput_layer.size(); i++)
		{
			double local_error = mOutput_layer[i].getInput();
				
			totalError += local_error;
			mLocalError.push_back(local_error);
		}
		totalError *= 0.1;
		return totalError;
	}

	/*======================================================================
	*	 final guess, number closest to one wins 
	*///====================================================================
	int Network::final_guess()
	{
		int guess = 0;
		double comp=0;
		for (int i = 0; i != mLocalError.size(); i++)
		{
			
			if (mLocalError[i] > comp)
			{
				comp = mLocalError[i];
				guess = i;
			}
		}
		return guess;
	}

	

	/*======================================================================
	*	 starts by updating hidden to ouput layer by calculating the 
	*	individual weight partial derivative using the chain rule, then the
		same is done updating weights on input to hidden layers weights
	*///====================================================================
	void Network::back_propogation(int label)
	{
		double learningConstant = 0.0001;
		double partial_derivative_output_layer = 0;
		double partial_derivative_hidden_layer = 0;
		double delta_z = 0;
		double delta_b = 0;
		
		
		double sumof_delta_z = 0;
		// == loops through hidden layer == //
		for (int i = 0; i != mHidden_layer.size(); i++)	
		{
			// == update weights in hiddenlayer == //
			for (int j = 0; j != mOutput_layer.size(); j++)
			{
				delta_z = (mOutput_layer[j].getInput() - is_target_output(label, j))
					* (is_target_output(label, j) -  mOutput_layer[j].getInput());

				partial_derivative_output_layer = delta_z
					* (mHidden_layer[i].getInput() * mHidden_layer[i].getWeights()[j]);

				mHidden_layer[i].setWeight(
					(mHidden_layer[i].getWeights()[j] - learningConstant * partial_derivative_output_layer), j);

				// ===== avg sum of delta z ====== //
				sumof_delta_z += delta_z * mHidden_layer[i].getWeights()[j];
			}
		}
		sumof_delta_z /= mHidden_layer[0].getWeightSize();
		// ==  loops through inputlayer Neurons == // 
		for (int i = 0; i != mInput_layer.size(); i++)
		{
				
			// == update weights in inputlayer == //
			for (int j = 0; j != mHidden_layer.size(); j++)
			{
				delta_b = sumof_delta_z * mInput_layer[i].getWeights()[j]
					* (is_target_output(label, j) - mHidden_layer[j].getInput());
					
				partial_derivative_hidden_layer = delta_b
					* (mInput_layer[i].getInput() * mInput_layer[i].getWeights()[j]);

					
				mInput_layer[i].setWeight(
					(mInput_layer[i].getWeights()[j] - learningConstant * partial_derivative_hidden_layer), j);
					
			}
		}
		
	}

	

	

	// =================================== helper function ============================ //
	/* =========================== randint =========================================//
	*   "random number engine  is a function that generates uniformly distributed
	*	sequence of integer values."
	*	"Distribution is a function that generates a sequence of values according
	*	to a mathematical formaula given a sequence of value from an engine."
	*	Stroustrup (2014: p914)
	*///===========================================================================//
	double randDouble(double min, double max)// generates random number
	{
		static std::default_random_engine ran;
		return std::uniform_real_distribution<>{min, max}(ran);
	}

	int randInt(int min, int max)// generates random number
	{
		static std::default_random_engine ran;
		return std::uniform_int_distribution<>{min, max}(ran);
	}
	
	
	/*======================================================================
	*	 uploads error and label to csv file 
	*///====================================================================
	void NN_data(double total_error, int label)
	{
		const std::string NN_data_file = "NN_data_file_x10.csv";
		std::ofstream ost{ NN_data_file, std::ios_base::app };
		if (!ost) throw " cannot open file ", NN_data_file;

		ost << total_error << ',' << label << std::endl;

		ost.close();
	}

	/*======================================================================
	*	 Summation operator the sum of all inputs multiplied by weights that
	*	corespond to the next layers input 
	*///====================================================================
	double summation_operator(std::vector<Neuron> layer, int neuron_pos)
	{
		double sum = 0;
		for (int i = 0; i != layer.size(); i++)
		{
			sum += layer[i].getInput() * layer[i].getWeights()[neuron_pos];
		}

		return sum;

	}

	/*======================================================================
	*	 Activation function squashes the number and 
	*	signifies how much a neuron has fired 
	*///====================================================================
	double activation(double sum)
	{
		return 1.0 / (1.0 + exp(-sum));
	}

	double relu(double sum)
	{
		if (sum >= 0)return 0;
		else return 1;
	}

	double softmax(std::vector<Neuron> layer, int neuron_pos)
	{
		double m = 0, sum = 0, con = 0;

		// gets maximum input
		for (int i = 0; i != layer.size(); i++){
			if (layer[i].getInput() > m)m = layer[i].getInput();
		}

		// sums inputs
		for (int i = 0; i != layer.size(); i++){
			sum += exp(layer[i].getInput() - m);
		}

		con = m + log(sum);
	
		return exp(layer[neuron_pos].getInput() - con);
		
		
	}


	/*======================================================================
	*	 represents the target out put if the label is the same as the iteration
	*	it will send back one. example label 4 (0,0,0,0,1,0,0,0,0,0)
	*///====================================================================
	bool is_target_output(int label, int i)
	{
		return label == i;
	}
}

