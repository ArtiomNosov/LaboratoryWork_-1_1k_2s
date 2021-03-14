#define INTEGER_TYPE 0
#define FLOAT_TYPE 1
#define CHAR_TYPE 2
#define ADDERESS_OF_FUNCTION_TYPE 3


typedef struct{
	int type_of_value; //Тип содержимого 0 - целые числа, 1 - float, 2 - адрес функции и т.д. ... .
	size_t size_of_type; //Размер типа.
	size_t lenght; //Количество элементов в динамическом массиве.			
	void **idata; //Указатель на массив указателей на АТД.
	void (*map)(void *, void (*) (void*)); //Применяет переданную функцию к каждому элементу в массиве АТД.
	void (*where)(void *, int (*) (void*), void (*) (void*)); //Применяет вторую функцию при условии возвращения первой истины.
	void (*concat)(void *, void *); //Склеивает массив переданный с исходным.
	void (*dump)(void *); //Печать массива в стандартный поток вывода (stdout).
} DynamicArray;

//Создаёт пустой динамический массив необходимо передать тип данных, размер типа данных, 
//количество элементов массива и userArray
DynamicArray* create_DynamicArray(int type_of_value, size_t size_of_type, size_t lenght);

//Создаёт динамический массив и присваивает его элементам значения из userArray значения необходимо передать тип данных, размер типа данных, 
//количество элементов массива и userArray
DynamicArray* create_DynamicArrayFromArray(int type_of_value, size_t size_of_type, size_t lenght, void* userArray);

//Функции Dump для разных типов 
void intDump(DynamicArray* dynArr);

void floatDump(DynamicArray* dynArr);

void hexDump(DynamicArray* dynArr);

//Удаляет DynamicArray.
void dynamicArray_delete(DynamicArray* dynArr);

