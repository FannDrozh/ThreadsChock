#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <time.h>
long int ttime;
DWORD p = -1;
DWORD timer = 0;
DWORD timer1 = 0;
DWORD timer2 = 0;
DWORD timess = 0;
DWORD timess1 = 0;
DWORD timess2 = 0;
void Watch(long int t) 
{
	int hour = 0, min = 0, sec = t;
	while(1)
	{
		while (sec > 60)
		{
			sec = sec - 60;
			min ++;
		}
		while (min > 60)
		{
			min = min - 60;
			hour++;
		}
		while(hour > 24)
		{
			hour = hour - 24;
			if (hour < 24)
			{
				hour = hour + 3;
			}
		}
		Sleep(1000);
		sec++;
		if (sec > 59)
		{
			sec = 0;
			min++;
		}
		if (min > 59)
		{
			min = 0;
			hour++;
		}
		if (hour > 23)
		{
			hour = 0;
		}
		system("cls");
		printf("%d:%d:%d\n", hour, min, sec);
	}
}

int Timer(long int t)
{
	int hour = 0, min = 0, sec = t;
	while (1)
	{
		while (sec > 60)
		{
			sec = sec - 60;
			min++;
		}
		while (min > 60)
		{
			min = min - 60;
			hour++;
		}
		while (hour > 24)
		{
			hour = hour - 24;
			if (hour < 24)
			{
				hour = hour + 3;
			}
		}
		Sleep(1000);
		sec--;
		if (hour == 0 && min == 0 && sec == 0)
		{
			printf_s("������ �������!");
			break;
		}
		if (sec == 0)
		{
			min--;
			sec = 59;
			if (min == 0)
			{
				hour--;
				min = 59;
			}
		}
		system("cls");
		printf("%d:%d:%d\n", hour, min, sec);
	}
}

int main()
{
	system("chcp 1251>nul");
	int exit = 1;
	while (exit == 1)
	{
		printf("*** ���� ***\n\n");
		printf("1 - �����\n2 - ��������� �������\n3 - ����������\n4 - ������\n5 - �����\n");
		int menu;
		HANDLE hTread[4];
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:
			system("cls");
			printf("�����\n");
			SuspendThread(hTread[0]);
			ttime = time(NULL);
			hTread[0] = CreateThread(NULL, 0, Watch, ttime, NULL, NULL);
			break;
		case 2:
			system("cls");
			printf("��������� �������\n");
			printf_s("�: ");
			scanf_s("%d", &timess);
			printf_s("���: ");
			scanf_s("%d", &timess1);
			printf_s("���: ");
			scanf_s("%d", &timess2);
			if (timess > 24 || timess < 0 || timess1>60 || timess1 < 0 || timess2>60 || timess2 < 0)
			{
				printf_s("�������� ������\n");
			}
			else
			{
				while (timess != 0 || timess1 != 0)
				{
					if (timess != 0)
					{
						timess = timess - 1;
						timess1 = timess1 + 60;
					}
					if (timess1 != 0)
					{
						timess1 = timess1 - 1;
						timess2 = timess2 + 60;
					}
				}
			}
			hTread[1] = CreateThread(NULL, 0, Watch, timess2, NULL, NULL);
			break;
		case 3:
			system("cls");
			printf("����������\n");
			hTread[2] = CreateThread(NULL, 0, Watch, 0, NULL, NULL);
			break;
		case 4:
			system("cls");
			printf("������\n");
			printf_s("�: ");
			scanf_s("%d", &timer);
			printf_s("���: ");
			scanf_s("%d", &timer1);
			printf_s("���: ");
			scanf_s("%d", &timer2);
			if (timer > 24 || timer < 0 || timer1>60 || timer1 < 0 || timer2>60 || timer2 < 0)
			{
				printf_s("�������� ������\n");
			}
			else
			{
				while (timer != 0 || timer1 != 0)
				{
					if (timer != 0)
					{
						timer = timer - 1;
						timer1 = timer1 + 60;
					}
					if (timer1 != 0)
					{
						timer1 = timer1 - 1;
						timer2 = timer2 + 60;
					}
				}
				hTread[3] = CreateThread(NULL, 0, Timer, timer2, NULL, NULL);
			}
			break;
		case 5:
			system("cls");
			for (size_t i = 0; i < 4; i++)
			{
				SuspendThread(hTread[i]);
				system("cls");
				printf_s("���������� ��������������!\n");
			}
			break;
		default:
			printf("����� ������� ���!");
			break;
		}
		printf("������ �����?");
		scanf_s("%d", &exit);
	}
	return 0;
}