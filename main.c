#include <stdio.h>
#include "DynamicMatrix.h"
#include "UI.h"

menu mm1 = { 3, "Test", "âûôâôûâôû","Test3" };
menu mm2 = { 4, "Vâûâûôô", "ôûâûôâ","Test3" ,"fdfsdfsdfsd" };


int main() {
	int ss1 = UserMenu("This is menu 1", mm1);
	int ss2 = UserMenu("This is menu 2", mm2);

};
