#include <stdio.h>
#include <malloc.h>
#include "DynamicMatrix.h"

int inc1(int level) {
    return 1;
};

int inc2(int level) {
    return 2;
};

int inc3(int level) {
    return 3;
};

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

int vector_size_lenght = sizeof(float);
int vector_lenght = 3; // Матрица 3 на 3
int matrix_lenght = 3;


//− map, where
//− Конкатенация
//
//void test1(void) {
//    const int array_length = 3;
//    int (**f)(int) = malloc(array_length * sizeof(int (*)(int)));
//    f[0] = &inc1;
//    f[1] = &inc2;
//    f[2] = &inc3;
//    for (int index = 0; index < array_length; index++)
//        printf("%i ", f[index](0));
//};
//
//void test2(void) {
//    mx = malloc(matrix_lenght * sizeof(Vector));
//    for (int i = 0; i < matrix_lenght; i++)
//        mx[i] = malloc(vector_lenght * sizeof(vector_size_lenght));
//    for (int i = 0; i < matrix_lenght; i++)
//        for (int j = 0; j < vector_lenght; ++j) {
//            mx[i][j] = 5.6;
//        };
//
//    for (int i = 0; i < matrix_lenght; i++) {
//        for (int j = 0; j < vector_lenght; j++) {
//            printf("%5.2f", mx[i][j]);
//        };
//        printf("\n");
//    };
//    printf("End");
//};
//
//DynamicArray* create_DynamicArray(size_t sd, size_t len)
//{
//    return nullptr;
//}


