#include <stdio.h>
#include <conio.h>

#ifdef _WIN32
void clrscr()
{
    system("CLS");
};
#else
    #define clrscr() printf("\e[1;1H\e[2J")
#endif
#include "UI.h"


// Пользовательское меню
// 0 всегда выход
// Вход заголовох
// список элементов вывода

int UserMenu(char* title, menu mmenu)
{
    char ch;
    do {
        clrscr();
        printf("%s\n", title);
        for (int i = 0; i < mmenu.len; i++)
            printf(" %d) %s\n", i + 1, mmenu.shoice[i]);
        printf("Make your choice (0 - Exit):");
        ch = _getch();
    } while ((ch < '0') || (ch > ((char)'0' + mmenu.len)));
    printf("%c\n", ch );
    return (int) ch-'0';
};


