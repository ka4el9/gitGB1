#include <iostream>

int main(int argc, char const *argv[])
{
	
//1. Создать и инициализировать переменные пройденных типов данных

	short s = 7;
	short int si = 13;
	int i = 5;
	double d = 5.5;
	float f = 5.5f;
	char c = 'a';
	long long l = 563;
	bool b = false;
	enum cars {audi, bmw, pontiac, toyota, mercedes};
	int array[13];

//2. Создать перечисление с возможными вариантами символов для игры в крестики-нолики

	enum symbolsKrestikiNoliki {player1 = 'X', players2 = '0', empty = '.'};

//3. Создать массив, способный содержать значения такого перечисления и инициализировать его

	symbolsKrestikiNoliki field[3][3] = {};
	field[0][0] = player1;
	field[0][1] = players2;
	field[0][2] = empty;


	

//4. * Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами

struct Field
{
	char namePlayers[2];	// имя игроков
	int gameType;		// тип игры: против компьютера, против игрока
	int winGames;		// счет игры
	char characterTypeSelections; // выбрать символ для игры Х или 0
};




//5.1 * Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении


struct DataTime
{
	uint Day : 5; // 2^5=32, 32>31
	uint Month : 4; //2^4 = 16, 16>12 и так далее ко всем значениям
	uint Year : 11;
	uint Week : 6;
} dd;

	std::cout << (dd.Day = 16) << '\n';
	std::cout << (dd.Month = 12) << '\n';
	std::cout << (dd.Year = 2021) << '\n';
	std::cout << (dd.Week = 50) << '\n';


// 5.2 . ** Создать структуру (struct MyVariant) объединяющую: union MyData (int,float, char) и 3-и битовых поля (флага) указывающими какого типа значение в данный момент содержится в объединении (isInt, isFloat, isChar). Продемонстрировать пример использования в коде этой структуры

struct myVariant
{
	union myData 
	{
		float isFloat; 
		int isInt : 1; 
		char isChar : 2;

	} dataNow;

} variantNow;


std::cout << (variantNow.dataNow.isFloat = 2) << '\n';
std::cout << (variantNow.dataNow.isInt = 1) << '\n';
std::cout << (variantNow.dataNow.isChar = 0) << '\n';


	return 0;
}

