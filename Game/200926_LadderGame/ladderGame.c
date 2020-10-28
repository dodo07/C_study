#include<stdio.h>
#include<time.h>
#include<windows.h>

// ���ߪ�����
// insert number(1~NUM)
// Goal number
// MAP[vertical][horizon] vertical = 20, horizon = 6

#define NUM 6 // �髤���?(?��ʦ)
#define VERTI 20 // �����ʪ�����
#define HORI (NUM*4) //����ʪ�����

void mapVerical(int MAP[VERTI][HORI]); //MAP??��������������
void mapHorizon(int MAP[VERTI][HORI]); //MAP??�������������
void printMap(int MAP[VERTI][HORI]); //MAP����
void color(int colorNum); //�Ϫ�������?��
void ladder(int MAP[VERTI][HORI], int num); //���ߪ�����?��

int main() {

	int num;
	int MAP[VERTI][HORI];

	printf("Insert number(1~%d) : ", NUM);
	scanf_s("%d", &num);
	system("cls"); //?����Ѣ��
	mapVerical(MAP);
	mapHorizon(MAP);
	printMap(MAP);
	ladder(MAP, num);
	return 0;
}

void mapVerical(int MAP[VERTI][HORI])
{
	for (int i = 0;i < VERTI;i++)
		for (int j = 0;j < HORI;j++)
		{
			if (j % 4 == 0)
			{
				MAP[i][j] = 5; //�����ʡ�ASCII��?��'I'����
			}
			else
			{
				MAP[i][j] = 0;
			}
		}
}

void mapHorizon(int MAP[VERTI][HORI])
{
	srand((int)time(NULL));
	for (int j = 0;j < NUM - 1;j++)
	{
		for (int i = 0;i < 5;i++) //����ʪ�??��ʦ
		{
			int vertical = rand() % 19; // �������1~19�������������������
			int line = j * 4; //������0������ʪ��ڪ����顢�������1������ʪ��ڪ�
			for (int overlapCheck = 0;overlapCheck < VERTI;overlapCheck++) //���������ʪ�����ʪ����֪���ʪ��誦������
			{
				if (MAP[overlapCheck][line] == 23)
				{
					if (overlapCheck == vertical)
					{
						vertical = rand() % 19;
						overlapCheck = 0;
					}
				}
			}
			MAP[vertical][line] = 25; //�����ʡ�ASCII��?��'��'����
			for (int count = line + 1;count < j * 4 + 4;count++)
			{
				MAP[vertical][count] = 6;//�����ʡ�ASCII��?��'-'����
			}
			line += 4;
			MAP[vertical][line] = 23; //�����ʡ�ASCII��?��'��'����
		}
	}
}

void printMap(int MAP[VERTI][HORI]) //�����ʡ����������
{
	for (int i = 1;i < NUM + 1;i++)
	{
		printf("%d   ", i);
	}
	printf("\n");
	for (int i = 0;i < VERTI;i++)
	{
		for (int j = 0;j < HORI;j++)
		{
			printf("%c", MAP[i][j]);
		}
		printf("\n");
	}
	for (int i = 1;i < NUM + 1;i++)
	{
		printf("%d   ", i);
	}
}

void color(int colorNum) //������������
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void gotoxy(int x, int y) //Cusor���??�����˫�?�����
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void ladder(int MAP[VERTI][HORI], int num) //Animation���Ī����媤�ʪ�����
{
	int y = 4 * (num - 1);
	color(4); //���������?��
	for (int x = 0;x < VERTI;x++)
	{
		switch (MAP[x][y])
		{
		case 5:
			Sleep(200);
			gotoxy(y, x + 1);
			printf("%c", MAP[x][y]);
			break;
		case 23:
			for (int i = 0;i < 5;i++)
			{
				Sleep(200);
				gotoxy(y, x + 1);
				printf("%c", MAP[x][y]);
				y--;
				if (i == 4)
				{
					y++;
				}
			}
			break;
		case 25:
			for (int i = 0;i < 5;i++)
			{
				Sleep(200);
				gotoxy(y, x + 1);
				printf("%c", MAP[x][y]);
				y++;
				if (i == 4)
				{
					y--;
				}
			}
			break;
		default:
			break;
		}
	}
	color(15); //�������ܪ�?��
	gotoxy(0, 26);
	printf("number %d !!\n\n", y / 4 + 1);
	system("pause");
}