#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 45
#define NUM 6

int input_num[NUM] = { 0, };
int lotto_num[NUM + 1] = { 0, };
int lotto_bonus = 0;
void lotto_num_caculation();
void lotto_num_input();
void lotto_num_input_Auto();
void lotto_num_check(int* count, int* count_bonus);

main()
{
	while (1)
	{
		srand(time(NULL));

		int bonus_num = 0;
		int Manual = 1;
		int Auto = 2;
		int select_num = 0;
		int count = 0;
		int count_bonus = 0;

		printf("Manual : %d, Auto : %d\n", Manual, Auto);
		scanf_s("%d", &select_num);

		if (select_num == 1)
		{
			lotto_num_input();
		}

		else if (select_num == 2)
		{
			lotto_num_input_Auto();
		}

		else
		{
			printf("Your number is wrong\nPlease input correct number(Manual : %d, Auto : %d\n)", Manual, Auto);
		}
		lotto_num_caculation();
		printf("======Your number is======\n");
		for (int i = 0;i < NUM;i++)
		{
			printf("%d  ", input_num[i]);
		}
		printf("\n");
		printf("======lotto number is======\n");
		for (int i = 0;i < NUM;i++)
		{
			printf("%d  ", lotto_num[i]);
		}
		printf("+ %d(bonus number)\n", lotto_num[6]);

		lotto_num_check(&count, &count_bonus);
	}

	return 0;
}

void lotto_num_caculation()
{
	int tem = 0;
	for (int i = 0;i < NUM + 1;i++)
	{
		lotto_num[i] = rand() % MAX + 1;
		for (int j = 0;j < i;j++)
		{
			if (lotto_num[i] == lotto_num[j])
			{
				i--;
				break;
			}
		}
	}

	for (int i = 0;i < NUM - 1;i++)
	{
		for (int j = 0;j < NUM - 1 - i;j++)
		{
			if (lotto_num[j] > lotto_num[j + 1])
			{
				tem = lotto_num[j];
				lotto_num[j] = lotto_num[j + 1];
				lotto_num[j + 1] = tem;
			}
		}
	}

}

void lotto_num_input()
{
	for (int i = 0;i < NUM;i++)
	{
		printf("input your number(1~%d)\n", MAX);
		printf("%d input number is  : ", i + 1);
		scanf_s("%d", &input_num[i]);
		if (input_num[i] > MAX || input_num[i] < 0)
		{
			printf("Your input number is wrong\n");
			printf("Please input correct number(1~%d)\n", MAX);
			i--;
		}
	}
}

void lotto_num_input_Auto()
{
	int tem = 0;

	for (int i = 0;i < NUM;i++)
	{
		input_num[i] = rand() % MAX + 1;
		for (int j = 0;j < i;j++)
		{
			if (input_num[i] == input_num[j])
			{
				i--;
				break;
			}
		}
	}

	for (int i = 0;i < NUM - 1;i++)
	{
		for (int j = 0;j < NUM - 1 - i;j++)
		{
			if (input_num[j] > input_num[j + 1])
			{
				tem = input_num[j];
				input_num[j] = input_num[j + 1];
				input_num[j + 1] = tem;
			}
		}
	}

}

void lotto_num_check(int* count, int* count_bonus)
{
	for (int i = 0;i < NUM;i++)
	{
		for (int j = 0;j < NUM;j++)
		{
			if (input_num[i] == lotto_num[j])
			{
				(*count)++;
			}

			else if (input_num[i] == lotto_num[6])
			{
				*count_bonus = 1;
			}
		}
	}

	if (*count + *count_bonus == 3)
	{
		printf("5th\n");
	}
	else if (*count + *count_bonus == 4)
	{
		printf("4th\n");
	}
	else if (*count + *count_bonus == 5)
	{
		printf("3th\n");
	}
	else if (*count == 5 && *count_bonus == 1)
	{
		printf("2th\n");
	}

	else if (count == 6)
	{
		printf("1th\n");
	}

	else if (*count + *count_bonus < 3)
	{
		printf("fail count : %d bonus : %d\n", *count, *count_bonus);
	}
	else
	{
		printf("Error\n");
	}

}
