#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace NN
{
	/*==================================================================
	* InputData is a single data set in a vector with attached label
	*///================================================================
	class InputData
	{
	public:
		// == constructor ==  //
		InputData(): mLabel(0){}

		// == non-modifying operations == //
		int getDataSize()const { return mPixels.size(); }
		double getPixel(int i) const { return mPixels[i]; }
		std::vector<double> getPixels() const { return mPixels; }
		int getLabel() const { return mLabel; }

		// == modifying operations == //
		void addData(double pixel) { mPixels.push_back(pixel); }
		void setData(std::vector<double> data) { mPixels = data; }
		void setLabel(int label) { mLabel = label; }

	private:
		std::vector<double> mPixels;
		int mLabel;
	};

	/*==================================================================
	* InputSets is a vector of InputData or collection of datasets
	*///================================================================
	class InputSet
	{
	public:
		// == constructor == //
		InputSet(){}

		// == non-modifying operations == //
		int getSetSize()const { return mDataSet.size(); }
		std::vector<InputData> getDataSet() const { return mDataSet; }
		
		// == modifying operations == //
		void addDataSet(InputData inputData) { mDataSet.push_back(inputData); }
		
	private:
		std::vector<InputData> mDataSet;
		
	};


	// == helper functions == //
	void printPixels(std::vector<int> pixels);
	InputSet get_mnisk_data(std::string filename);
	double transform_data(int pixel);
	
}
