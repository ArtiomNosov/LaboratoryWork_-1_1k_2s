//includes
#include <stdio.h>
#include "DynamicArray.h"
#include "UI.h"

		/*Тестируем map в DynamicArray.*/

//Dump функции для проверки работы map.
void funcIncTen(int* pValue)
{
	*pValue += 10;
}

void dumpCharValue(char* pValue)
{
	printf("%c\n", *pValue);
}

void dumpFloatValue(float* pValue)
{
	printf("%f\n", *pValue);
}

//Функция условия
int conditionFunction(int *pValue)
{
	return *pValue % 2;
}

//Пяток функций для массива функций
void functionElemOne(char *pStr)
{
	printf("Сработала функция \"functionElemOne\" - %s\n", pStr);
}

void functionElemTwo(char* pStr)
{
	printf("Сработала функция \"functionElemTwo\" - %s\n", pStr);
}

void functionElemThree(char* pStr)
{
	printf("Сработала функция \"functionElemThree\" - %s\n", pStr);
}

void functionElemFour(char* pStr)
{
	printf("Сработала функция \"functionElemFour\" - %s\n", pStr);
}

void functionElemFive(char* pStr)
{
	printf("Сработала функция \"functionElemFive\" - %s\n", pStr);
}


//Функции изменяющие массив 

void testMapInDynamicArrayInt(void)
{
	int result = 0;
	int testArrayInt[10] = { 84, 842, 238, 2399, 12, 434, 13, 434, 34, 0 };
	/*int ss1 = UserMenu("This is menu 1", mm1);
	int ss2 = UserMenu("This is menu 2", mm2);*/
	DynamicArray* myLovedArray1 = create_DynamicArray(INTEGER_TYPE, sizeof(int), 10);
	//Тестирование инициализации DynamicArray из массива типа int.
	
	for (int i = 0; i < 10; i++)
	{
		*(int*)(myLovedArray1->idata[i]) = testArrayInt[i];
		//printf("%x\n", testArray + i);
	}
	printf("Array before processing.\n");
	myLovedArray1->dump(myLovedArray1);
	myLovedArray1->map(myLovedArray1, &funcIncTen);
	printf("Массив после processing.\n");
	myLovedArray1->dump(myLovedArray1);
	//Вызываем dump
	//Проверяет с помощью сверки с значениями массива после отработки на них map с funcIncTen
	for (int i = 0; i < 10; i++)
	{
		if (*(int*)(myLovedArray1->idata[i]) != (testArrayInt[i] + 10))
		{
			result = -1;
			break;
		}
		//printf("%x\n", testArray + i);
	}

	/*Тестирование where*/
	printf("Array before use where.\n");
	myLovedArray1->dump(myLovedArray1);
	myLovedArray1->where(myLovedArray1, &conditionFunction, funcIncTen);
	printf("Массив после использования where.\n");
	myLovedArray1->dump(myLovedArray1);
	
	for (int i = 0; i < 10; i++)
	{
		if (*(int*)(myLovedArray1->idata[i]) != (testArrayInt[i] + 10) && (*(int*)(myLovedArray1->idata[i]) % 2))
		{
			result = -1;
			break;
		}
		//printf("%x\n", testArray + i);
	}
	/*Тестирование concat*/
	DynamicArray* myArray2 = create_DynamicArrayFromArray(INTEGER_TYPE, sizeof(int), 5, testArrayInt);
	printf("Array before use concat.\n");
	myLovedArray1->dump(myLovedArray1);
	myLovedArray1->concat(&myLovedArray1, myArray2);
	printf("Массив после использования concat.\n");
	myLovedArray1->dump(myLovedArray1);
	for (int i = 0; i < 15; i++)
	{
		printf("%i %d", i % 10, testArrayInt[i % 10]);
		if (   *(int*)(myLovedArray1->idata[i]) != testArrayInt[i % 10]   )
		{
			result = -1;
			break;
		}
		//printf("%x\n", testArray + i);
	}
	if (result == 0)
	{
		printf("Успешное прохождение теста \"testMapInDynamicArrayInt\"\n");
	}
	else
	{
		printf("Тест \"testMapInDynamicArrayInt\" не пройден\n");
	}

	dynamicArray_delete(myLovedArray1);
}

void testMapInDynamicArrayChar(void)
{
	int result = -1;

	if (result = 0)
	{
		printf("Успешное прохождение теста \"testMapInDynamicArrayChar\"\n");
	}
	else
	{
		printf("Тест \"testMapInDynamicArrayChar\" не пройден\n");
	}
}

void testMapInDynamicArrayFloat(void)
{
	int result = -1;
	float testArrayFloat1[4] = { 8.35434, 2.3434, 3.14, 99.00056 };
	float testArrayFloat2[4] = { 0, 0, 0, 0 };
	DynamicArray* myLovedArray = create_DynamicArrayFromArray(sizeof(float), 4, &dumpFloatValue, testArrayFloat1);
	myLovedArray->map(myLovedArray, &dumpFloatValue);
	
	//for(int i = 0;)
	if (result = 0)
	{
		printf("Успешное прохождение теста \"testMapInDynamicArrayFloat\"\n");
	}
	else
	{
		printf("Тест \"testMapInDynamicArrayFloat\" не пройден\n");
	}
	dynamicArray_delete(myLovedArray);
}
		/*Тестирование типа элемент указатель на функцию*/
//передаём указатель на указатель на функцию
	//соответственно необходимы две звёздочки
void funcCallFunction(void (**pValue)(char*))
{
	
	(*pValue)("Test elemets of function.\n");
}

void testMapInDynamicArrayFunction(void)
{
	int result = 0;

	const int array_length = 5;
	void (**testArrayFunction)(char *) = malloc(array_length * sizeof(void (*)(char *)));
	testArrayFunction[0] = &functionElemOne;
	testArrayFunction[1] = &functionElemTwo,
	testArrayFunction[2] = &functionElemThree,
	testArrayFunction[3] = &functionElemFour,
	testArrayFunction[4] = &functionElemFive;
	
	DynamicArray* dynArr = create_DynamicArrayFromArray(ADDERESS_OF_FUNCTION_TYPE, sizeof(void (*)(char*)), array_length, testArrayFunction);
	//Печатаем адреса функций
	dynArr->dump(dynArr);
	dynArr->map(dynArr, &funcCallFunction);
}

		
