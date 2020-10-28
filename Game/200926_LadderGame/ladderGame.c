#include<stdio.h>
#include<time.h>
#include<windows.h>

// ª¢ªßªÀª¯ª¸
// insert number(1~NUM)
// Goal number
// MAP[vertical][horizon] vertical = 20, horizon = 6

#define NUM 6 // «é«¤«óªÎ?(?ÌÚÊ¦)
#define VERTI 20 // á÷òÁàÊªÎíşªµ
#define HORI (NUM*4) //â©øÁàÊªÎíşªµ

void mapVerical(int MAP[VERTI][HORI]); //MAP??ªËá÷òÁªÎàÊìıÕô
void mapHorizon(int MAP[VERTI][HORI]); //MAP??ªËâ©øÁªÎàÊìıÕô
void printMap(int MAP[VERTI][HORI]); //MAPõóÕô
void color(int colorNum); //ªÏª·ª´ªÎßä?ÌÚ
void ladder(int MAP[VERTI][HORI], int num); //ª¢ªßªÀª¯ª¸?ú¼

int main() {

	int num;
	int MAP[VERTI][HORI];

	printf("Insert number(1~%d) : ", NUM);
	scanf_s("%d", &num);
	system("cls"); //?ØüôøÑ¢ûù
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
				MAP[i][j] = 5; //á÷òÁàÊ¡æASCII«³?«É'I'ìıÕô
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
		for (int i = 0;i < 5;i++) //â©øÁàÊªÎ??ÌÚÊ¦
		{
			int vertical = rand() % 19; // á÷òÁõîªÎ1~19Êà«é«ó«À«àªÇâ©øÁàÊìıÕô¡¡
			int line = j * 4; //á÷òÁàÊ0ªËâ©øÁàÊªòÙÚª¤ª¿ªé¡¢ó­á÷òÁàÊ1ªËâ©øÁàÊªòÙÚª¯
			for (int overlapCheck = 0;overlapCheck < VERTI;overlapCheck++) //×öªÎá÷òÁàÊªËâ©øÁàÊª¬áóÜÖªµªìªÊª¤ªèª¦ªËàâïÒ
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
			MAP[vertical][line] = 25; //á÷òÁàÊ¡æASCII«³?«É'¤¿'ìıÕô
			for (int count = line + 1;count < j * 4 + 4;count++)
			{
				MAP[vertical][count] = 6;//á÷òÁàÊ¡æASCII«³?«É'-'ìıÕô
			}
			line += 4;
			MAP[vertical][line] = 23; //á÷òÁàÊ¡æASCII«³?«É'¤Ã'ìıÕô
		}
	}
}

void printMap(int MAP[VERTI][HORI]) //á÷òÁàÊ¡¢â©øÁàÊõóÕô
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

void color(int colorNum) //õóÕôªÎßäàâïÒ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void gotoxy(int x, int y) //Cusorì¹ÔÑ??¡¢«¢«Ë«á?«·«ç«ó
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void ladder(int MAP[VERTI][HORI], int num) //Animation××éÄª·¡¢îåª¤àÊªÇøúãÆ
{
	int y = 4 * (num - 1);
	color(4); //õóÕôßäîåªÇ?ÌÚ
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
	color(15); //õóÕôßäÛÜªÇ?ÌÚ
	gotoxy(0, 26);
	printf("number %d !!\n\n", y / 4 + 1);
	system("pause");
}