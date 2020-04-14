#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>

class Array
{
private:

	float array_size, average, deviation;
	std::vector<float> Arr;

public:

	Array(float size) 																				// конструктор с параметром
	{
		array_size = size;
	}

	float made_array()  																			// метод создания массива
	{
		srand(time(NULL));
		for (int i = 0; i < array_size; i++)
		{
			Arr.push_back(rand() % 1000);
		}
		return 0;
	}

	float print_array() 		// метод вывода массива
	{
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << "Source array: " << std::endl;
		for (std::vector<float>::iterator i = Arr.begin(); i != Arr.end(); i++)
		{
			std::cout << *i << "\t";
		}
		return 0;
	}

	float finding_average()   // метод нахождения среднего арифм.
	{
		float s = 0, sum = 0;
		for (std::vector<float>::iterator i = Arr.begin(); i != Arr.end(); i++)
		{
			sum += *i;
			s++;
		}
		average = sum / array_size;
		std::cout << std::endl << "Average: " << average;
		return 0;
	}

	int number_of_elements()  // колич. элементов, меньше среднего
	{
		int s = 0;
		for (std::vector<float>::iterator i = Arr.begin(); i != Arr.end(); i++)
		{
			if (*i < average)
			{
				s++;
			}
		}
		std::cout << std::endl << "Number of elements that less than average: " << s;
		return 0;
	}

	float finding_deviation()  		// нахождение отклонения 														
	{
		float min = 1000;
		for (std::vector<float>::iterator i = Arr.begin(); i != Arr.end(); i++)
		{
			if (*i < min)
			{
				min = *i;
			}
		}
		if (min != 0)
		{
			deviation = fabs((average - min) / min); 										// формула нахождения отклонения
			std::cout << std::endl << "Deviation: " << deviation << "%";
		}
		else
		{
			std::cout << std::endl << "Error";
		}
		return 0;
	}

	~Array()			// деструктор
	{
		std::cout << std::endl << std::endl << "-------Program execution completed--------";
	}
};

int main()
{
	float N;
	while (1)
	{
		std::cout << "Enter size of array" << std::endl;
		std::cin >> N;
		if (N < 33 && N > 0)
		{
			break;
		}
		else
		{
			std::cout << "Error, try again" << std::endl;
		}
	}

	Array A(N);
	system("cls");
	A.made_array();
	A.print_array();
	A.finding_average();
	A.number_of_elements();
	A.finding_deviation();

	return 0;
}