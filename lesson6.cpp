/*
1. Выделить в памяти динамический одномерный массив
типа int. Размер массива запросить у пользователя.
Инициализировать его числами степенями двойки: 1, 2, 4,
8, 16, 32, 64, 128 ... Вывести массив на экран. Не забыть
освободить память. =) Разбить программу на функции.

2. Динамически выделить матрицу 4х4 типа int.
Инициализировать ее псевдослучайными числами через
функцию rand. Вывести на экран. Разбейте вашу
программу на функции которые вызываются из main.

3. Написать программу, которая создаст два текстовых
файла (*.txt), примерно по 50-100 символов в каждом
(особого значения не имеет с каким именно содержимым).
Имена файлов запросить у пользователя.

4. * Написать функцию, «склеивающую» эти файлы в
третий текстовый файл (имя файлов спросить у
пользователя).

5. * Написать программу, которая проверяет присутствует
ли указанное пользователем при запуске программы слово
в указанном пользователем файле (для простоты
работаем только с латиницей). Используем функцию find
которая есть в строках std::string.
*/

#include <iostream>
#include <cmath> //подключаю для исспользования функции возведения в степень
#include <fstream> //для реализации файлового ввода вывода
#include <cstring> //для использования strcat()

//=======================================================================

void task1() 
{
	std::cout << "TASK1\n";

	int *arr1; //указатель на массив
	int n; // кол-во элементов массива

	std::cout << "Enter size of your array: ";
	std::cin >> n; // Ввести кол-во элементов массива

	arr1 = new int[n]; //Выделяем память под одномерный массив

	for (int i = 0; i < n; ++i)
	
	{
		arr1[i] = pow(2, i); //функция возведения в степень
		std::cout << arr1[i] << std::endl;
	}
	std::cout << std::endl;
	
	delete[] arr1;

	
}

//=======================================================================

void task2()
{
	std::cout << "TASK2\n";

	int **arr2; //указатель на массив указателей
	const int N = 4; //размер матрцы N x M
	const int M = 4;

	arr2 = new int *[N]; //Выделяем память под одномерный массив указателей
	for (int i = 0; i < N; ++i)
	{
		arr2[i] = new int[M];
	}

	arr2[N][M];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr2[i][j] = rand() % 100;
			std::cout << arr2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	for (int i = 0; i < N; ++i)
	{
		delete[] arr2[i];
	}

	delete[] arr2;

	std::cin.get(); // Ждем нажатия клавиши для задержки закрытия программы
}


//=======================================================================

int task3()
{
	std::cout << "TASK3\n";

	char fileName1[10], fileName2[10];
	
	std::cout << "Enter file name 1: " << std::endl;
	std::cin >> fileName1;
	
	std::cout << "Enter file name 2: " << std::endl;
	std::cin >> fileName2;

	std::strcat (fileName1, ".txt");
	std::ofstream file1(fileName1); //создаем 1 файл

	if (!file1) //проверяем, получилось ли открыть файл
	{
		std::cout << "I can't open the file for writing!\n";
		return 1;
	}

	file1 << "I am Professor Aronnax. My job is to study everything dead or alive under the sea. I see beautiful and ugly things down there. Bur there is one strange experience that stays in my mind like a nightmare.\n";
	
	file1.close(); //закрываем файл

	std::strcat (fileName2, ".txt");
	std::ofstream file2(fileName2); //создаем 2 файл

	if (!file2) 
	{
		std::cout << "I can't open the file for writing!\n";
		return 1;
	}

	file2 << "It was 1867. Some sailors said that they saw a dangerous giant monster living in the cold waters of the ocean. Some ships tried to find it and kill it, but they never returned.\n";
	
	file2.close();

	std::cin.get(); // Ждем нажатия клавиши для задержки закрытия программы

	std::cout << '\n';

	return 0;
}
	

//=======================================================================

int task4()
{
	std::cout << "TASK4\n";

	char fileName1[10], fileName2[10], fileName3[10];

	std::cout << "Enter file name 1: " << std::endl; //вводим названия файлов
	std::cin >> fileName1;
	
	std::cout << "Enter file name 2: " << std::endl;
	std::cin >> fileName2;

	std::cout << "Enter file name 3: " << std::endl;
	std::cin >> fileName3;


	char fil1[255] = "I am Professor Aronnax. My job is to study everything dead or alive under the sea. I see beautiful and ugly things down there. Bur there is one strange experience that stays in my mind like a nightmare.";

	char fil2[255] = "It was 1867. Some sailors said that they saw a dangerous giant monster living in the cold waters of the ocean. Some ships tried to find it and kill it, but they never returned.";


	std::strcat (fileName1, ".txt");
	std::ofstream file1(fileName1); //создаем 1 файл

	if (!file1) 					//проверяем, получилось ли открыть файл
	{
		std::cout << "I can't open the file for writing!\n";
		return 1;
	}

	file1 << fil1 << std::endl; //записываем текст в файл

	
	std::strcat (fileName2, ".txt");
	std::ofstream file2(fileName2); //создаем 2 файл

	if (!file2) 
	{
		std::cout << "I can't open the file for writing!\n";
		return 1;
	}

	file2 << fil2 << std::endl;

	
	std::strcat(fil1, fil2);


	std::strcat (fileName3, ".txt");
	std::ofstream file3(fileName3 /*, std::ios::app*/); //создаем 3 файл
	
	file3 << fil1 << std::endl;

	
	file1.close(); //закрываем файл
	file2.close();
	file3.close(); 
	
	std::cin.get(); // Ждем нажатия клавиши для задержки закрытия программы

	std::cout << '\n';

	return 0;	
}	
	
//=======================================================================
int task5()
{
	std::cout << "TASK5\n";
	std::string word;
	std::cout << "Enter word:";
	std::cin >> word;			// вводим слово, которое необходимо проверить

	std::ifstream myfile("QWERT.txt");  //открываем файл для чтения
	std::string s;
	

	if (myfile.is_open())
	{
		

		while (!myfile.eof()) // Пока не конец файла
		{
			getline(myfile, s); // Читаем из файла строку
			
			std::cout << s << std::endl; // Выводим на экран
		
			
			if (s.find(word) != std::string::npos)
			
				std::cout << "Yes, we found!";
			
			else
			
				std::cout << "No, we can not found...\n";				
		}

		
		myfile.close();
	}
	
	return 0;
}


//=======================================================================

int main(int argc, char const *argv[])
{
	task1();
	task2();
	task3();
	task4();
	task5();


	return 0;
}