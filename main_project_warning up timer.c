#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <ctype.h>

#define w 119

char key;

void volley_ball();
void basket_ball();
void running();
void weight();
void Exit_pro();

void HRmax();

// 시간에 따른 타이머 함수들
void timer_10s();
void timer_20s();
void timer_30s();
void timer_60s();

// 조깅에서 걷기 타이머 설정하기
void timer_warking();

int num;

int main()
{
	printf("오늘 할 운동은?\n");
	printf("      1. 배구         \n");
	printf("      2. 농구         \n");
	printf("      3. 런닝         \n");
	printf(" 4. 웨이트 트레이닝   \n");

	scanf("%d", &num);

	system("cls");

	if (num == 1)
	{
		// volley_ball();
	}
	else if (num == 2)
	{
		// basket_ball();
	}
	else if (num == 3)
	{
		running();
	}
	else if (num == 4)
	{
		// weight();
	}
	else if (num == 5)
	{
		// Exit_pro();
	}

	return 0;
}

void timer_10s()
{
	int countdown = 10; // 카운트다운을 10으로 초기화

	printf("10초 타이머를 시작합니다.\n");

	printf("시작 하려면 enter 입력\n");

	if (getchar())
	{
		system("cls");
	}

	while (countdown > 0) {
		printf("%d초 남았습니다.\n", countdown);
		Sleep(1000); // 1초 대기

		countdown--; // 카운트다운을 감소시킴

		system("cls");
	}

	printf("타이머가 종료되었습니다!\n");

}

void timer_20s()
{
	int countdown = 20; // 카운트다운을 10으로 초기화

	printf("10초 타이머를 시작합니다.\n");

	printf("시작 하려면 enter 입력\n");

	if (getchar())
	{
		system("cls");
	}

	while (countdown > 0) {
		printf("%d초 남았습니다.\n", countdown);
		Sleep(1000); // 1초 대기

		countdown--; // 카운트다운을 감소시킴

		system("cls");
	}

	printf("타이머가 종료되었습니다!\n");
}

void timer_30s()
{
	int countdown = 30; // 카운트다운을 10으로 초기화

	printf("30초 타이머를 시작합니다.\n");

	printf("시작 하려면 enter 입력\n");

	if (getchar())
	{
		system("cls");
	}

	while (countdown > 0) {
		printf("%d초 남았습니다.\n", countdown);
		Sleep(1000); // 1초 대기

		countdown--; // 카운트다운을 감소시킴

		system("cls");
	}

	printf("타이머가 종료되었습니다!\n");
}

void timer_60()
{
	int countdown = 60; // 카운트다운을 10으로 초기화

	printf("60초 타이머를 시작합니다.\n");

	printf("시작 하려면 enter 입력\n");

	if (getchar())
	{
		system("cls");
	}

	while (countdown > 0) {
		printf("%d초 남았습니다.\n", countdown);
		Sleep(1000); // 1초 대기

		countdown--; // 카운트다운을 감소시킴

		system("cls");
	}

	printf("타이머가 종료되었습니다!\n");
}

void timer_warking()
{
	key = _getch();

	char key = 'W';

	tolower(key) == 'w';

	if (key == w)
	{
		timer_10s();
	}

}

void running()
{
	system("cls");

	printf("런닝 루틴 시작하겠습니다.\n");
	printf("아무키나 눌러서 진행\n");
	_getch();

	system("cls");

	HRmax();

	int c;
	while ((c = getchar()) != '\n' && c != EOF); // 개행 문자까지 버퍼 비우기

	system("cls");

	printf("가벼운 조깅 실시(운동장 한 바퀴 권장)\n 조깅이 끝났으면 Enter누르기\n");


	getchar();


	system("cls");

	printf("30m 왕복 달리기 실시\n");
	timer_30s();

	system("cls");

	printf("50m 왕복 달리기 실시\n");
	timer_30s();

	system("cls");

	printf("중간 정도의 속력으로 운동장 3바퀴 돌기\n     1바퀴 뛰고 10초 걷기를 유지하세요\n");
	printf("걷기 타이머를 시작하려면 'w'입력\n");

	timer_warking();

}

void HRmax()
{
	int age;
	int hrmax;
	int a;
	printf("나이를 입력하세요: ");
	scanf("%d", &age);

	int c;
	while ((c = getchar()) != '\n' && c != EOF); // 개행 문자까지 버퍼 비우기


	hrmax = 220 - age;

	printf("당신의 최대 심박수는 %d\n 최대 심박수를 넘어가지 않게 주의 하세요!!\n", hrmax);
	printf("최대 심박수 보다 심박수가 높아진다면 종료키를 입력\n");

}
