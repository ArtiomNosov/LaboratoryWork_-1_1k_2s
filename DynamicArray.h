#define INTEGER_TYPE 0
#define FLOAT_TYPE 1
#define ADDERESS_OF_FUNCTION_TYPE 2

typedef struct{
	int type_of_value; //��� ����������� 0 - ����� �����, 1 - float, 2 - ����� ������� � �.�. ... .
	size_t size_of_type; //������ ����.
	size_t lenght; //���������� ��������� � ������������ �������.			
	void **idata; //��������� �� ������ ���������� �� ���.
	void (*map)(void *, void (*) (void*)); //��������� ���������� ������� � ������� �������� � ������� ���.
	void (*where)(void *, int (*) (void*), void (*) (void*)); //��������� ������ ������� ��� ������� ����������� ������ ������.
	void (*concat)(void *); //��������� ������ ���������� � ��������.
	void (*dump)(void *); //������ ������� � ����������� ����� ������ (stdout).
} DynamicArray;

//������ ������ ������������ ������ ���������� �������� ������ ���� ������, 
//���������� ��������� ������� � ������� 
DynamicArray* create_DynamicArray(size_t size_of_type, size_t lenght, void (*sDump)(DynamicArray*));

//������� !!!
DynamicArray* create_DynamicArray2(size_t size_of_type, size_t lenght, void (*sDump)(DynamicArray*), void** userArray);

//������� Dump ��� ������ ����� 
void intDump(DynamicArray* dynArr);

void floatDump(DynamicArray* dynArr);

void hexDump(DynamicArray* dynArr);

