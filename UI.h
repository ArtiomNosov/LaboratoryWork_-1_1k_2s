typedef struct {
    int len;
    char *shoice[10];
} menu;

//������� ������������ ����� ������������.
int UserMenu(char* title, menu mmenu);

//��� ������� enter. �������� ������ ��� ����� ������ � ����������� �.
void waitingUserPressEnter(void);

//���������� ��������� �� ������ �������� ������������� � ���������� � ���������� ������.
//char* get_str();