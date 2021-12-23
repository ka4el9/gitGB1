#include <iostream>
#include <cmath>
#include <iomanip> // for using setw()


int main(int argc, char const *argv[])
{
	// 1. Написать программу, проверяющую что сумма двух чисел лежит в пределах от 10 до 20 (включительно), если да – вывести true, в противном случае – false;

	int a, b;

	std::cout << "Enter number a and number b:";
	std::cin >> a >> b;
	
	if ((a+b)>=10 && (a+b)<=20) 
		std::cout << "True" << '\n';
	else 
		std::cout << "False" << '\n';


	// 2. Написать программу, выводящую на экран “истину”, если две целочисленные константы, объявленные в её начале либо равны десяти сами по себе, либо их сумма равна десяти.

	int q, w;
	
	std::cout << "Enter q:";
	std::cin >> q;

	std::cout << "Enter w:";
	std::cin >> w;

	if (q==10 && w==10)
		std::cout << "True\n";
 			
 	else if ((q+w) == 10)
		std::cout << "True\n";

	else
		std::cout << "False\n";


	// 3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. Например: "Your numbers: 1 3 5 7 9 11 13 ...". Для решения используйте любой С++ цикл

	std::cout << "Variant 1 loop for: \n";
	
	for (int i = 0; i <= 50 ; i++)
	{
		if (i % 2 != 0)
		std::cout << "Your numbers:" <<i << '\n';
	}
		
	std::cout << "Variant 2 loop while: \n";

	int h = 0;
	while (h <= 50) 
	{
		if (h % 2 != 0)
			std::cout << "Your numbers:" << h << '\n';
		h++;
	}


	// 4. Написать программу, проверяющую, является ли некоторое число - натуральным простым. Простое число - это число, которое делится без остатка только на единицу и себя само.

	int c;

	std::cout << "Enter number c:";
	std::cin >> c;
	
	if (c < 2)
		std::cout << "Error! Enter number >=2.\n";
	
	if ((c == 2) || (c == 3) )
		std::cout << c << " - natural number.\n";

	// одно из свойств простого числа при делении КВАДРАТА числа по модулю на 24 дает остаток 1

	if ((c*c) % 24 == 1) 

		std::cout << c << " - natural number.\n";

	else
		std::cout << c << " - not natural number. \n";
	
	
	// 4.1 Написать программу, которая заполняет диагональные элементы квадратной матрицы единицами. Размеры матрицы нужно задать константными числами, матрицу нужно инициализировать нулями.

	int n;
	int A[n][n];	

	std::cout << "Enter lines and columns n:";
	std::cin >> n;
	
	for (int i = 0; i < n; ++i) //i - определяет номер строки
	
		{ 
			for (int j = 0; j < n; ++j) //j - определяет номер столбца
		
				{					
					if (i == j)
					
					{
						A[i][j] = 1;	
					}
					
					else 
						A[i][j] = 0;

					std::cout << std::setw(3) << A[i][j];
				}

			std::cout << '\n';
		}
	

	// 5. Написать программу, которая определяет является ли год високосным. Каждый 4-й год является високосным, кроме каждого 100-го, при этом каждый 400-й – високосный. Для проверки работы вывести результаты работы программы в консоль

	int year;

	std::cout << "Enter Year:";
	std::cin >> year;

	if (year % 4 == 0)
		
		{ if (year % 100 == 0)

				{ if (year % 400 == 0)
					std::cout << year << " - leap year\n";

					else 
						std::cout << year << " - not leap year\n";
				}

			else 
				std::cout << year << " - leap year\n";
		}

	else
		std::cout << year << " - not leap year\n";	


	return 0;

}