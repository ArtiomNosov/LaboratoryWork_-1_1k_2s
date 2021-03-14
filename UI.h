typedef struct {
    int len;
    char *shoice[10];
} menu;

//Функция возвращающая выбор пользователя.
int UserMenu(char* title, menu mmenu);

//Ждёт нажатия enter. Выделяет память для ввода строки и освобождает её.
void waitingUserPressEnter(void);

//Возвращает указатель на строку введённую пользователем с клавиатуры с выделением памяти.
//char* get_str();