// lesson7

/*
1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp,
mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
для инициализации массива (типа float), печати его на экран и
подсчета количества отрицательных и положительных
элементов. Вызывайте эти 3-и функции из main для работы с
массивом.

2. Описать макрокоманду (через директиву define),
проверяющую, входит ли переданное ей число (введенное с
клавиатуры) в диапазон от нуля (включительно) до переданного
ей второго аргумента (исключительно) и возвращает true или
false, вывести на экран «true» или «false».

3. Задайте массив типа int. Пусть его размер задается через
директиву препроцессора #define. Инициализируйте его через
ввод с клавиатуры. Напишите для него свою функцию
сортировки (например Пузырьком). Реализуйте перестановку
элементов как макрокоманду SwapINT(a, b). Вызывайте ее из
цикла сортировки.

4. * Объявить структуру Сотрудник с различными полями.
Сделайте для нее побайтовое выравнивание с помощью
директивы pragma pack. Выделите динамически переменную
этого типа. Инициализируйте ее. Выведите ее на экран и ее
размер с помощью sizeof. Сохраните эту структуру в текстовый
файл.

5. * Сделайте задание 1 добавив свой неймспейс во втором
модуле (первое задание тогда можно не делать)
*/

#include <iostream>
#include <fstream> 
#include<iomanip>
#include <string>
#include "mylib.h"

//task 2
#define FUNCTION_BOOL(i, n) ((i >= 0 && i <= n) ? 1 : 0) 


//task 3
#define ARRAY_SIZE 5 
#define SWAPINT(a, b) (std::swap(a, b))



//task 4

struct Employee1
{
	std::string names;
	std::string position;
	unsigned short age;
	int telephone;	
};

#pragma pack(push, 1)
struct Employee2
{
	std::string names;
	std::string position;
	unsigned short age;
	int telephone;	
};

#pragma pack(pop)





int main(int argc, char const *argv[])
{	

//task 1
	std::cout << "task 1" << '\n';
	
	int size = 10;
	float array[size] = {};

//task 5 and task 1	
	TASK5::initARRAY(array, size);
	
	TASK5::printARRAY(array, size);
	
	TASK5::countELEMENTS(array, size);


//task 2
	std::cout << "task 2" << '\n';

	int i;
	int n = 100;

	std::cout << "Enter a number: ";
	std::cin >> i;

	std::cout << FUNCTION_BOOL(i, n) << '\n';



//task 3
	std::cout << "task 3" << '\n';

	int arr[ARRAY_SIZE];


	//Fill the array with values
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		std::cout << "Enter an array element " << i + 1 << " : ";
		std::cin >> arr[i];
	}
	
	//Output the original array
	std::cout << "Output the original array: ";

	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		std::cout << arr[i] << std::setw(3);
	}
	std::cout << '\n';

	//Let's sort the array
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		bool flag = true;

			for (int j = 0; j < ARRAY_SIZE - (i + 1); ++j)
			{
				if (arr[j] > arr[j + 1])
				{
					flag = false;
					
					SWAPINT(arr[j], arr[j + 1]);
				}
			}
		if (flag)
		{
			break;
		}
	}

	//Output a sorted array
	std::cout << "Output the sorted array: ";

	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		std::cout << arr[i] << std::setw(3);
	}
	std::cout << '\n';



//task 4
	
	std::cout << "task 4" << '\n';
	
	//Alignment results before and after
	std::cout << sizeof(Employee1) << " " << sizeof(Employee2) << '\n';

	//Memory allocation for the structure
	Employee1 *emp = new Employee1;

	emp->names = "John McClane";
	emp->position = "engineer";
	emp->age = 33;
	emp->telephone = 35648;

	//Output structure
	std::cout << (*emp).names << '\n';
	std::cout << (*emp).position << '\n';
	std::cout << (*emp).age << '\n';
	std::cout << (*emp).telephone << '\n';
	
	std::cout << sizeof(Employee1) << '\n';

	delete emp;


	//Save the structure
	Employee1 var;
	var.names = "John McClane";
	var.position = "engineer";
	var.age = 33;
	var.telephone = 35648;
	
	std::ofstream structFile("struct.txt");
	
	if (!structFile) //we check whether it was possible to open the file
		{
			std::cout << "I can't open the file for writing!\n";
			return 1;
		}
	structFile << var.names << " " << var.position << " " 
				<< var.age << " " << var.telephone << '\n';

	structFile.close();

	return 0;
}