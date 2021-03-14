#include <stdio.h>
#include <malloc.h>
#include "DynamicArray.h"
#include <string.h>

// В программе, в зависимости от варианта, требуется реализовать одну из следующих структур данных: вектор,
// квадратная матрица, прямоугольная матрица, список (или один из производных от них).
// Для реализации необходимо использовать концепцию динамических массивов.
// Структура данных должна поддерживать работу с элементами различных типов (вообще говоря, произвольных,
// если они удовлетворяют некоторым условиям, которые зависят от специфики задачи).
// Основные алгоритмы необходимо покрыть (модульными) тестами.
// Реализацию следует оснастить пользовательским интерфейсом (консольным) для проверки корректности реализации.

//Динамический массив

//− Вещественные числа
//− Функции

//void (*map)(void (*) (void*)); //применяет переданную функцию к каждому элементу в массиве атд.
//void (*where)(int (*) (void*), void (*) (void*)); //применяет вторую функцию при условии возвращения первой истины.
//void (*concat)(dynamicarray*); //склеивает массив переданный с исходным.
//void (*dump)(void); //печать массива в стандартный поток вывода (stdout).

void someMap(DynamicArray *dynArr, void (*function) (void*))
{
    for (int i = 0; i < dynArr->lenght; i++)
    {
        function(dynArr->idata[i]);
    }
}

void someWere(DynamicArray* dynArr, int (*conditionFunction) (void*),void (*function) (void*))
{

    for (int i = 0; i < dynArr->lenght; i++)
    {
        //С проверкой выполнения условия функции пробегаем по элементам 
        //массива и выполняем опрерацию только при его выполнении.
        if(conditionFunction(dynArr->idata[i])) 
            function(dynArr->idata[i]);
    }
}
// TODO:Не забыть добавить проверку совместимости двух массивов.
void someConcat(DynamicArray* dynArr1, DynamicArray* dynArr2)
{
    DynamicArray* result = NULL;
    result = malloc(sizeof(DynamicArray)); //Выделение памяти.
    
    result->size_of_type = dynArr1->size_of_type;
    result->lenght = dynArr1->lenght + dynArr2->lenght;
    result->idata = malloc(sizeof(void*) * result->lenght);
    //Копируем указатели из первого массива в новый.
    for (int i = 0; i < dynArr1->lenght; i++)
    {
        result->idata[i] = dynArr1->idata[i];
    }
    //Копируем указатели из второго массива в новый.
    for (int i = 0; i < dynArr2->lenght; i++)
    {
        result->idata[dynArr1->lenght + i] = dynArr2->idata[i];
    }
    free(dynArr1);
    free(dynArr2);
    dynArr1 = result;
}

void intDump(DynamicArray* dynArr)
{
    for (int i = 0; i < dynArr->lenght; i++)
    {
        printf("a[%d] = %d/n", i, *(int *) (dynArr->idata[i]));
    }
}

void floatDump(DynamicArray* dynArr)
{
    for (int i = 0; i < dynArr->lenght; i++)
    {
        printf("a[%d] = %f/n", i, *(float *) (dynArr->idata[i]));
    }
}

void hexDump(DynamicArray* dynArr)
{
    for (int i = 0; i < dynArr->lenght; i++)
    {
        printf("Адрес расположения функции a[%d]: %x/n", i, (void *) dynArr->idata[i]);
    }
}

DynamicArray* create_DynamicArray(size_t size_of_type, size_t lenght, void (*sDump)(DynamicArray*))
{
    DynamicArray* result = NULL;
    result = malloc(sizeof(DynamicArray)); //Выделение памяти.
    result->size_of_type = size_of_type;
    result->lenght = lenght;
    result->idata = malloc(sizeof(void *) * lenght);
    //Соёздаём пустой динамический массив.
    for (int i = 0; i < lenght; i++)
    {
        result->idata[i] = malloc(size_of_type); //Выделяем память под отдельный элемент.
    }
    result->map = &someMap;
    result->where = &someWere;
    result->concat = &someConcat;
    return result;
}

//void **ptrTeArr = 
DynamicArray* create_DynamicArray2(size_t size_of_type, size_t lenght, void (*sDump)(DynamicArray*), void **userArray)
{
    DynamicArray* result = NULL;
    result = malloc(sizeof(DynamicArray)); //Выделение памяти.
    result->size_of_type = size_of_type;
    result->lenght = lenght;
    result->idata = malloc(sizeof(void*) * lenght);
    //Соёздаём пустой динамический массив.
    for (int i = 0; i < lenght; i++)
    {
        result->idata[i] = malloc(size_of_type); //Выделяем память под отдельный элемент.
        //*result->idata[i] = (void)userArray[i];
        //Копируем блок памяти из userArray[i] в result->idata[i] с помощью memcpy
        memcpy(result->idata[i], &(userArray[i]), size_of_type);
    }
    result->map = &someMap;
    result->where = &someWere;
    result->concat = &someConcat;
    return result;
}

