#include <iostream>
#include<iomanip>

namespace TASK5 
{

	void initARRAY(float *array, int size) 
	{
		for (int i = 0; i < size; ++i)
		{
			array[i] = (rand() % 101 - 50)/10.0;			
		}
	}


	void printARRAY(float *array, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			std::cout << array[i] << std::setw(5);
		}
		std::cout << '\n';
	}


	void countELEMENTS(float *array, int size)
	{
		int countNegatuve = 0;
		int countPositive = 0;

		for (int i = 0; i < size; ++i)
		{
			if (array[i] < 0 )
				countNegatuve++;
			else 
				if (array[i] >= 0)
					countPositive++;
		}
		std::cout << "quantity negative elements - " << countNegatuve << '\n';
		std::cout << "quantity positive elements - " << countPositive << '\n';
	}

}