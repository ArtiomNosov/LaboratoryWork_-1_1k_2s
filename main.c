//��������� includes
#include <locale.h>
#include <stdio.h>

//��� includes )
#include "DynamicArray.h"
#include "UI.h"


menu MainMenu = { 4, "������������ ������� ����� �����", "������������ ������� ���� char","������������ ������� ���� float", "������������ ������ � ���������" };




int main() {
	char* locale = setlocale(LC_ALL, "");
	int userChoice = 0;
	do {
		userChoice = UserMenu("�������� ������� ������������", MainMenu);
		switch (userChoice)
		{
		case 1:
			printf("����_1\n");
			testMapInDynamicArrayInt();
			waitingUserPressEnter();
			break;
		case 2:
			printf("����_2\n");
			testMapInDynamicArrayChar();
			waitingUserPressEnter();
			break;
		case 3:
			printf("����_3\n");
			testMapInDynamicArrayFloat();
			waitingUserPressEnter();
			break;
		case 4:
			printf("����_4\n");
			testMapInDynamicArrayFunction();
			waitingUserPressEnter();
			break;
		default:
			break;
		}
	} while (userChoice != 0);
};
