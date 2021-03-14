//includes
#include <stdio.h>
#include "DynamicArray.h"
#include "UI.h"

		/*��������� map � DynamicArray.*/

//Dump ������� ��� �������� ������ map.
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

//������� �������
int conditionFunction(int *pValue)
{
	return *pValue % 2;
}

//����� ������� ��� ������� �������
void functionElemOne(char *pStr)
{
	printf("��������� ������� \"functionElemOne\" - %s\n", pStr);
}

void functionElemTwo(char* pStr)
{
	printf("��������� ������� \"functionElemTwo\" - %s\n", pStr);
}

void functionElemThree(char* pStr)
{
	printf("��������� ������� \"functionElemThree\" - %s\n", pStr);
}

void functionElemFour(char* pStr)
{
	printf("��������� ������� \"functionElemFour\" - %s\n", pStr);
}

void functionElemFive(char* pStr)
{
	printf("��������� ������� \"functionElemFive\" - %s\n", pStr);
}


//������� ���������� ������ 

void testMapInDynamicArrayInt(void)
{
	int result = 0;
	int testArrayInt[10] = { 84, 842, 238, 2399, 12, 434, 13, 434, 34, 0 };
	/*int ss1 = UserMenu("This is menu 1", mm1);
	int ss2 = UserMenu("This is menu 2", mm2);*/
	DynamicArray* myLovedArray1 = create_DynamicArray(INTEGER_TYPE, sizeof(int), 10);
	//������������ ������������� DynamicArray �� ������� ���� int.
	
	for (int i = 0; i < 10; i++)
	{
		*(int*)(myLovedArray1->idata[i]) = testArrayInt[i];
		//printf("%x\n", testArray + i);
	}
	printf("Array before processing.\n");
	myLovedArray1->dump(myLovedArray1);
	myLovedArray1->map(myLovedArray1, &funcIncTen);
	printf("������ ����� processing.\n");
	myLovedArray1->dump(myLovedArray1);
	//�������� dump
	//��������� � ������� ������ � ���������� ������� ����� ��������� �� ��� map � funcIncTen
	for (int i = 0; i < 10; i++)
	{
		if (*(int*)(myLovedArray1->idata[i]) != (testArrayInt[i] + 10))
		{
			result = -1;
			break;
		}
		//printf("%x\n", testArray + i);
	}

	/*������������ where*/
	printf("Array before use where.\n");
	myLovedArray1->dump(myLovedArray1);
	myLovedArray1->where(myLovedArray1, &conditionFunction, funcIncTen);
	printf("������ ����� ������������� where.\n");
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
	/*������������ concat*/
	DynamicArray* myArray2 = create_DynamicArrayFromArray(INTEGER_TYPE, sizeof(int), 5, testArrayInt);
	printf("Array before use concat.\n");
	myLovedArray1->dump(myLovedArray1);
	myLovedArray1->concat(&myLovedArray1, myArray2);
	printf("������ ����� ������������� concat.\n");
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
		printf("�������� ����������� ����� \"testMapInDynamicArrayInt\"\n");
	}
	else
	{
		printf("���� \"testMapInDynamicArrayInt\" �� �������\n");
	}

	dynamicArray_delete(myLovedArray1);
}

void testMapInDynamicArrayChar(void)
{
	int result = -1;

	if (result = 0)
	{
		printf("�������� ����������� ����� \"testMapInDynamicArrayChar\"\n");
	}
	else
	{
		printf("���� \"testMapInDynamicArrayChar\" �� �������\n");
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
		printf("�������� ����������� ����� \"testMapInDynamicArrayFloat\"\n");
	}
	else
	{
		printf("���� \"testMapInDynamicArrayFloat\" �� �������\n");
	}
	dynamicArray_delete(myLovedArray);
}
		/*������������ ���� ������� ��������� �� �������*/
//������� ��������� �� ��������� �� �������
	//�������������� ���������� ��� ��������
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
	//�������� ������ �������
	dynArr->dump(dynArr);
	dynArr->map(dynArr, &funcCallFunction);
}

		
