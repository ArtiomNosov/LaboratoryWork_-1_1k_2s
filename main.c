//Системные includes
#include <locale.h>
#include <stdio.h>

//Мои includes )
#include "DynamicArray.h"
#include "UI.h"


menu MainMenu = { 4, "Тестирование массива целых чисел", "Тестирование массива типа char","Тестирование массива типа float", "Тестирование работы с функциями" };




int main() {
	char* locale = setlocale(LC_ALL, "");
	int userChoice = 0;
	do {
		userChoice = UserMenu("Выберите предмет тестирования", MainMenu);
		switch (userChoice)
		{
		case 1:
			printf("Тест_1\n");
			testMapInDynamicArrayInt();
			waitingUserPressEnter();
			break;
		case 2:
			printf("Тест_2\n");
			testMapInDynamicArrayChar();
			waitingUserPressEnter();
			break;
		case 3:
			printf("Тест_3\n");
			testMapInDynamicArrayFloat();
			waitingUserPressEnter();
			break;
		case 4:
			printf("Тест_4\n");
			testMapInDynamicArrayFunction();
			waitingUserPressEnter();
			break;
		default:
			break;
		}
	} while (userChoice != 0);
};
