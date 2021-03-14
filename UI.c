#include <stdio.h>
#include <locale.h>
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
//
void waitingUserPressEnter(void)
{
    char* locale = setlocale(LC_ALL, "");
    printf("PRESS EBTER MY FRIEND!\n");
    do {} while (_getch() != 13);
}

//char* get_str()
//{
//    char buf[81] = { 0 };
//    char* res = null;
//    int len = 0;
//    int n = 0;
//
//    do {
//
//        n = scanf("%80[^\n]", buf);
//
//        if (n < 0)
//        {
//            if (!res)
//            {
//                return null;
//            }
//        }
//        else if (n > 0) {
//
//            int chunk_len = strlen(buf);
//            int str_len = len + chunk_len;
//            res = realloc(res, str_len + 1); //experiment
//            memcpy(res + len, buf, chunk_len);
//            len = str_len;
//        }
//        else {
//            scanf("%*c");
//        }
//    } while (n > 0);
//
//
//    if (len > 0)
//    {
//        res[len] = '\0'; //experiment
//        res[len+1] = '\0';
//    }
//    else {
//        res = calloc(1, sizeof(char));
//        *res = '\0';
//    }
//
//    return res;
//}


