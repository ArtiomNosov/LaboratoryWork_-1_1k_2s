#include <stdio.h>
#include "DynamicArray.h"
#include "UI.h"

//menu mm1 = { 3, "Test", "âûôâôûâôû","Test3" };
//menu mm2 = { 4, "Vâûâûô", "ôûgdgfgfûôâ","Test3" ,"fdfsdfsdfsd" };

void dumpValue(char* pValue)
{
	printf("%c\n", *pValue);
}


int main() {
	int testArray[10] = { 84, 842, 238, 2399, 12, 434, 13, 434, 34, 0 };
	/*int ss1 = UserMenu("This is menu 1", mm1);
	int ss2 = UserMenu("This is menu 2", mm2);*/
	DynamicArray* myLovedArray = create_DynamicArray(sizeof(int), 10, &intDump);
	for (int i = 0; i < 10; i++)
	{
		*(char *)(myLovedArray->idata[i]) = i + '0';
	}
	myLovedArray->map(myLovedArray, &dumpValue);

};
