#include <stdio.h>
#include <malloc.h>
#include "DynamicArray.h"
#include <string.h>

/// В программе, в зависимости от варианта, требуется реализовать одну из следующих структур данных: вектор,
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

void someMap(DynamicArray* dynArr, void (*function) (void*))
{
    for (int i = 0; i < dynArr->lenght; i++)
    {
        function(dynArr->idata[i]);
    }
}

void someWhere(DynamicArray* dynArr, int (*conditionFunction) (void*),void (*function) (void*))
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
void someConcat(DynamicArray** dynArr1, DynamicArray* dynArr2)
{
    if ((*dynArr1)->type_of_value != dynArr2->type_of_value)
    {
        printf("Ошибка в функции someConcat разные типы элементов для конкатинации\n");
        return;
    }
    DynamicArray* result = create_DynamicArray((*dynArr1)->type_of_value, (*dynArr1)->size_of_type, (*dynArr1)->lenght + dynArr2->lenght);
    
    //Копируем указатели из первого массива в новый.
    for (int i = 0; i < (*dynArr1)->lenght; i++)
    {
        memcpy(result->idata[i], (*dynArr1)->idata[i], result->size_of_type);
    }
    //Копируем указатели из второго массива в новый.
    for (int i = 0; i < dynArr2->lenght; i++)
    {
        memcpy(result->idata[(*dynArr1)->lenght + i], dynArr2->idata[i], result->size_of_type);
    }
    dynamicArray_delete((*dynArr1));
    dynamicArray_delete(dynArr2);
    *dynArr1 = result;
}

void someDump(DynamicArray* dynArr)
{
    switch (dynArr->type_of_value)
    {
        case INTEGER_TYPE:
            for (int i = 0; i < dynArr->lenght; i++)
            {
                printf("a[%d] = %d\n", i, *(int*)(dynArr->idata[i]));
            }
            break;
        case FLOAT_TYPE:
            for (int i = 0; i < dynArr->lenght; i++)
            {
                printf("a[%d] = %f\n", i, *(float*)(dynArr->idata[i]));
            }
            break;
        case ADDERESS_OF_FUNCTION_TYPE:
            for (int i = 0; i < dynArr->lenght; i++)
            {
                printf("Adress of function a[%d]: %x\n", i, (void*)dynArr->idata[i]);
            }
            break;
        case CHAR_TYPE:
            for (int i = 0; i < dynArr->lenght; i++)
            {
                printf("a[%d] = %c\n", i, *(char*)(dynArr->idata[i]));
            }
            break;
        default:
            printf("Указанный тип данных не поддерживается функцией \"someDump\"\n");
    }
    
}


DynamicArray* create_DynamicArray(int type_of_value, size_t size_of_type, size_t lenght)
{
    DynamicArray* result = NULL;
    result = malloc(sizeof(DynamicArray)); //Выделение памяти.
    result->type_of_value = type_of_value;
    result->size_of_type = size_of_type;
    result->lenght = lenght;
    result->idata = malloc(sizeof(void *) * lenght);
    //Соёздаём пустой динамический массив.
    for (int i = 0; i < lenght; i++)
    {
        result->idata[i] = malloc(size_of_type); //Выделяем память под отдельный элемент.
    }
    result->map = &someMap;
    result->where = &someWhere;
    result->concat = &someConcat;
    result->dump = &someDump;
    return result;
}

DynamicArray* create_DynamicArrayFromArray(int type_of_value, size_t size_of_type, size_t lenght, void *userArray)
{
    DynamicArray* result = create_DynamicArray(type_of_value, size_of_type, lenght);
    //Соёздаём пустой динамический массив.
    for (int i = 0; i < lenght; i++)
    {
        memcpy(result->idata[i], (void *)((char *)userArray + i * size_of_type), size_of_type);
    }
    return result;
}

void dynamicArray_delete(DynamicArray* dynArr)
{
    for (int i = 0; i < dynArr->lenght; i++)
    {
        free(dynArr->idata[i]); //Освобождаем память, выделенную под каждый элемент.
    }
    free(dynArr->idata); //Освободи память, выделенную под массив указателей.
    free(dynArr);
}

