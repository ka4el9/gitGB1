#include <iostream>

// 1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main. 

void printArray(double *arr, int size) // прототип функции
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << std::endl;
}

//2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.


void changeArray(int *ar, int size1)
{
	for (int i = 0; i < size1; i++)
	{
		if (ar[i] == 1)
			ar[i] = 0;
	
		else
			ar[i] = 1;

			std::cout << ar[i] << std::endl;
	}
} 

// 3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.

void filingArray(int *a, int size2)
{	
	for (int i = 1; i <= size2; i++)
	{
		a[i] = a[0] + 3*(i - 1);
		std::cout << a[i] << std::endl;
	}
}

// 4. * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.

void offsetArray(int *array, int size3, int n)
{
	for (int i = 0; i < size3; i++)
	{
		array[i] = array[i + n];	
		std::cout << array[i] << std::endl;		
	}
		//не разобрался как сделать сдвиг циклически
}


// 5. ** Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.

void balanceArray(int *k, int size4)
{
	for (int i = 0; i < size4; i++)
	{
		k[i];
	}
		
	if ((k[0] == k[1] + k[2] + k[3] + k[4]) || 
		(k[0] + k[1] == k[2] + k[3] + k[4]) ||
		(k[0] + k[1] + k[2] == k[3] + k[4]) ||
		(k[0] + k[1] + k[2] + k[3] == k[4]))
	
		std::cout << "TRUE\n";
		
	else
		std::cout << "FALSE\n";	
}


int main(int argc, char const *argv[])
{

//1.-----------------------------------------------------------
	const int P = 10;
	double A[P] = {1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99, 10.10};
	printArray(A, 5);
	std::cout << '\n';
	printArray(A, 10);
	std::cout << '\n';

//2.-----------------------------------------------------------
	const int U = 10;
	int B[U] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
		
		for (int i = 0; i < U; i++)
		{
			std::cout << B[i] << std::endl;
		}
	std::cout << " " << std::endl;
	
	changeArray(B, 10);
	std::cout << '\n';

//3.------------------------------------------------------------
	const int T = 8;
	int C[T];
	C[0] = 1;
	
	filingArray(C, 8);
	std::cout << '\n';

//4.------------------------------------------------------------
	int l = 6;
	int D[l]= {4, 6, 12, -33, 21, 7};
	offsetArray(D, 6, 2);
	std::cout << '\n';

//5.------------------------------------------------------------
	int E[5] = {1, 1, 1, 2, 1};
	balanceArray(E, 5);

	int F[5] = {2, 1, 1, 2, 1};
	balanceArray(F, 5);

	int G[5] = {10, 1, 2, 3, 4};
	balanceArray(G, 5);

	return 0;
}


