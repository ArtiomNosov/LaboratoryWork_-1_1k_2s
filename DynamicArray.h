#define INTEGER_TYPE 0
#define FLOAT_TYPE 1
#define CHAR_TYPE 2
#define ADDERESS_OF_FUNCTION_TYPE 3


typedef struct{
	int type_of_value; //��� ����������� 0 - ����� �����, 1 - float, 2 - ����� ������� � �.�. ... .
	size_t size_of_type; //������ ����.
	size_t lenght; //���������� ��������� � ������������ �������.			
	void **idata; //��������� �� ������ ���������� �� ���.
	void (*map)(void *, void (*) (void*)); //��������� ���������� ������� � ������� �������� � ������� ���.
	void (*where)(void *, int (*) (void*), void (*) (void*)); //��������� ������ ������� ��� ������� ����������� ������ ������.
	void (*concat)(void *, void *); //��������� ������ ���������� � ��������.
	void (*dump)(void *); //������ ������� � ����������� ����� ������ (stdout).
} DynamicArray;

//������ ������ ������������ ������ ���������� �������� ��� ������, ������ ���� ������, 
//���������� ��������� ������� � userArray
DynamicArray* create_DynamicArray(int type_of_value, size_t size_of_type, size_t lenght);

//������ ������������ ������ � ����������� ��� ��������� �������� �� userArray �������� ���������� �������� ��� ������, ������ ���� ������, 
//���������� ��������� ������� � userArray
DynamicArray* create_DynamicArrayFromArray(int type_of_value, size_t size_of_type, size_t lenght, void* userArray);

//������� Dump ��� ������ ����� 
void intDump(DynamicArray* dynArr);

void floatDump(DynamicArray* dynArr);

void hexDump(DynamicArray* dynArr);

//������� DynamicArray.
void dynamicArray_delete(DynamicArray* dynArr);

