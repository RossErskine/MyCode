#include "InputData.h"

namespace NN
{
	// =========================== member functions ============================= //
	

	// =========================== helper functions ============================= //
	void printPixels(InputData pixels)
	{
		// == print int pixels == //
		int count = 0;
		std::cout << "Label: " << pixels.getLabel() << '\n';
		for (int i=0;i != pixels.getDataSize(); i++)
		{
			char c = ':';
			count++;
			std::cout << pixels.getPixel(i) << '\b';
			if (count == 28)
			{
				std::cout << '\n';
				count = 0;
			}
		}
	}
	
	/*======================================================================
	* gets the datasets form a csv file and places them in  InputSets class
	*///====================================================================
	InputSet get_mnisk_data(std::string filename)
	{
		
		std::vector<std::string> s_pixels; // string pixels
		std::string line, pixel, temp;
		InputSet dataSet;

		// == get a line from file as string == //
		std::ifstream ist{ filename };
		if (!ist)throw"cannot open input file ", filename;
		std::cout << "Loading data....." << filename <<std::endl;
		while (!ist.eof())
		{
			s_pixels.clear();
			std::getline(ist, line);
			std::stringstream s(line);

			while (std::getline(s, pixel, ','))
			{
				s_pixels.push_back(pixel);
			}
			if (ist.eof())break;

			// == turns string pixels to int pixels == //
			InputData pixels;
			std::string s_label = s_pixels[0];
			for (int i = 1; i != s_pixels.size(); i++)
			{
				// stoi transforms ascii int to int then truncates to doouble //
				double td = transform_data(std::stoi(s_pixels[i]));		
				pixels.addData(td);
			}

			// == sorts problem with byte order mark(BOM) == //
			char ch = s_label[s_label.length() - 1]; // gets last ch in s_label
			int label = (int)(ch)-48;				// turns ascii ch into int.
			pixels.setLabel(label);

			// == print int pixels == //
			//printPixels(pixels);  // for testing and debugging

			dataSet.addDataSet(pixels);

			
		}
		std::cout << "Loading finished" << std::endl;
		ist.close();
		return dataSet;
	}

	// == transform_data turns grayscale numbers to between 0 & 1 == //
	double transform_data(int pixel)
	{
		return pixel * 0.99 / 255 + 0.01;
	}

	

}

