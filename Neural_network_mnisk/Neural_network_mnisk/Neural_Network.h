#include <vector>

namespace NN
{
	/*=====================================================================
	*	Neuron class consists of one input with attached vector of weights, 
	*	size depends on the size of next layer
	*///===================================================================
	class Neuron
	{
	public:
		// == constructor == //
		Neuron(int size_of_NL); // NL = next layer

		// == non-modifying operations == //
		double getInput() const { return mInput; }
		int getWeightSize() const { return mWeights.size(); }
		std::vector<double> getWeights() const { return mWeights; }

		// == modifying operations == //
		void setInput(double input) { mInput = input; }
		void setWeight(double weight, int i) { mWeights[i] = weight; }

	private:
		double mInput;
		std::vector<double> mWeights;
	};

	/*=====================================================================
	* Network class is a collection of layer Neuron's. 
	* the consructor is able to create the size network such as (3,2,1)
	* and random size weights added to that input. Data to inputs are added at the 
	* start of train or test network.
	*	
	*	IL = input layer
	*	HL = Hidden layer
	*	OL = output layer
	*	size_of = number of nodes in layer
	*///==================================================================
	
	class Network
	{
	public:
		// == constructor == //
		Network(int size_of_IL, int size_of_HL, int size_of_OL);

		// == non-modifying operations == //
		double getTotal_error() const { return mTotal_error; }
		std::vector<Neuron> getInput_Layer() const { return mInput_layer; }
		std::vector<Neuron> getHidden_Layer() const { return mHidden_layer; }
		std::vector<Neuron> getOutput_Layer() const { return mOutput_layer; }
		int getCorrect_answers() const { return correct_answers; }

		// == modifying operations == //
		void setTotal_error(double total_error) { mTotal_error = total_error; }
		void trainNetwork(std::vector<double> dataSet, int label);
		void testNetwork(std::vector<double> dataSet, int label);
		double forward_prpogation(std::vector<Neuron> layer1, int pos);
		void setInputs(std::vector<double> dataSet);
		void back_propogation(int label);

		double compute_error(int label);
		double compute_final_error();
		int final_guess();
		
		
	private:
		std::vector<Neuron> mInput_layer;
		std::vector<Neuron> mHidden_layer;
		std::vector<Neuron> mOutput_layer;
		
		std::vector<double> mLocalError;
		double mTotal_error;
		int correct_answers;
	};

	// === helper functions === //
	double randDouble(double min, double max);// generates random number
	int randInt(int min, int max);// generates random number
	double summation_operator(std::vector<Neuron> layer, int neuron_pos);
	double activation(double sum);
	double relu(double sum);
	double softmax(std::vector<Neuron> Layer, int neuron_pos);
	bool is_target_output(int label, int i);
	void NN_data(double total_error, int label);


	
	
}
