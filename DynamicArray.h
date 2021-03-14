#define INTEGER_TYPE 0
#define FLOAT_TYPE 1
#define ADDERESS_OF_FUNCTION_TYPE 2

typedef struct{
	int type_of_value; //Тип содержимого 0 - целые числа, 1 - float, 2 - адрес функции и т.д. ... .
	size_t size_of_type; //Размер типа.
	size_t lenght; //Количество элементов в динамическом массиве.			
	void **idata; //Указатель на массив указателей на АТД.
	void (*map)(void *, void (*) (void*)); //Применяет переданную функцию к каждому элементу в массиве АТД.
	void (*where)(void *, int (*) (void*), void (*) (void*)); //Применяет вторую функцию при условии возвращения первой истины.
	void (*concat)(void *); //Склеивает массив переданный с исходным.
	void (*dump)(void *); //Печать массива в стандартный поток вывода (stdout).
} DynamicArray;

//Создаёт пустой динамический массив необходимо передать размер типа дынных, 
//количество элементов массива и функцию 
DynamicArray* create_DynamicArray(size_t size_of_type, size_t lenght, void (*sDump)(DynamicArray*));

//Отладка !!!
DynamicArray* create_DynamicArray2(size_t size_of_type, size_t lenght, void (*sDump)(DynamicArray*), void** userArray);

//Функции Dump для разных типов 
void intDump(DynamicArray* dynArr);

void floatDump(DynamicArray* dynArr);

void hexDump(DynamicArray* dynArr);

