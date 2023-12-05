#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <ctype.h>

#define w 119
#define r 114
#define y 121
#define n 110

char key;

void volley_ball();
void basket_ball();
void running();
//void weight();
void Exit_pro();

void HRmax();

// 타이머
void timer(int countdown);

// 조깅에서 걷기 타이머 설정하기
void timer_warking();
void timer_warking2();

void clearScreen();

int num;

int main()
{
	while (110)
	{
		printf("오늘 할 운동은?\n");
		printf("      1. 배구         \n");
		printf("      2. 농구         \n");
		printf("      3. 런닝         \n");
		printf(" 4. 웨이트 트레이닝   \n");
		printf("      5. 종료         \n");

		scanf("%d", &num);

		system("cls");

		if (num == 1)
		{
			volley_ball();
		}
		else if (num == 2)
		{
			basket_ball();
		}
		else if (num == 3)
		{
			running();
		}
		else if (num == 4)
		{
			//weight();
		}
		else if (num == 5)
		{
			Exit_pro();
		}
	}

	return 0;
}

void clearScreen() {
	COORD topLeft = { 0, 0 }; // 화면 좌측 상단의 좌표 (0, 0)
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen); // 현재 화면 버퍼 정보 가져오기
	FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written); // 화면을 공백으로 채우기
	SetConsoleCursorPosition(console, topLeft); // 커서를 좌측 상단으로 이동
}

void timer(int countdown)
{

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

void timer_warking()
{
	char key = _getch();
	key = tolower(key);

	int goal_run = 3;
	int warkingCounter = 0;

	printf("목표 바퀴: %d\n", goal_run);
	printf("완료 바퀴: %d\n", warkingCounter);
	printf("걷기 타이머를 시작하려면 w 입력\n");

	while (warkingCounter < goal_run)
	{
		key = _getch();
		if (key == 119)
		{
			warkingCounter++;

			system("cls");

			printf("목표 바퀴: %d\n", goal_run);
			printf("완료 바퀴: %d\n", warkingCounter);

			int countdown = 10;

			printf("10초 타이머 시작!\n");

			printf("호흡을 내뱉으며 걷기\n");
			printf("시작하려면 w 입력\n");

			key = _getch();
			key = 119;

			system("cls");

			while (countdown > 0) {
				printf("%d초 남았습니다.\n", countdown);
				Sleep(1000); // 1초 대기

				countdown--; // 카운트다운을 감소시킴

				system("cls");

			}
		}
	}

	printf("목표 바퀴 달성!\n\n");
	printf("60초간 휴식!\n\n");
	timer(60);

}

void timer_warking2()
{
	char key = _getch();
	key = tolower(key);

	int goal_run = 3;
	int warkingCounter = 0;

	printf("목표 바퀴: %d\n", goal_run);
	printf("완료 바퀴: %d\n", warkingCounter);
	printf("걷기 타이머를 시작하려면 w 입력\n");

	while (warkingCounter < goal_run)
	{
		key = _getch();
		if (key == 119)
		{
			warkingCounter++;

			system("cls");

			printf("목표 바퀴: %d\n", goal_run);
			printf("완료 바퀴: %d\n", warkingCounter);

			int countdown = 30;

			printf("30초 타이머 시작!\n");

			printf("호흡을 내뱉으며 걷기\n");
			printf("시작하려면 w 입력\n");

			key = _getch();
			key = 119;

			system("cls");

			while (countdown > 0) {
				printf("%d초 남았습니다.\n", countdown);
				Sleep(1000); // 1초 대기

				countdown--; // 카운트다운을 감소시킴

				system("cls");

			}
		}
	}

	printf("목표 바퀴 달성!\n\n");
	printf("60초간 휴식!\n\n");
	timer(60);

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

	do
	{
		printf("가벼운 조깅 실시(운동장 한 바퀴 권장)\n 조깅이 끝났으면 Enter누르기\n");


		getchar();


		system("cls");

		printf("30m 왕복 달리기 실시\n");
		/*timer(10);

		system("cls");

		printf("50m 왕복 달리기 실시\n");
		timer(30);*/

		system("cls");

		printf("중간 정도의 속력으로 운동장 3바퀴 돌기\n     1바퀴 뛰고 10초 걷기를 유지하세요\n\n");

		timer_warking();

		printf("최고 속력으로 운동장 3바퀴 돌기\n	1바퀴 뛰고 30초 걷기를 유지하세요\n\n");

		timer_warking2();

		printf("마무리 운동~~~\n\n");
		printf("가벼운 조깅 실시(운동장 한 바퀴 권장)\n");
		printf("조깅이 끝났으면 esc누르기\n");
		printf("더 하고싶으면 'r'누르기\n");
	} while (key);
	{
		char key = _getch();
		key = tolower(key);

		if (key == 114)
		{
			system("cls");
			printf("런닝 다시 시작합니다!\n");
			running();
		}
		else if (key == 27)
		{
			exit(0);
		}
	}while (key != 27);

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

void volley_ball()
{
	printf("어깨, 하체, 허리 스트레칭 시작하겠습니다\n");
	printf("아무 키나 눌러서 진행\n");
	_getch();

	int c;
	while ((c = getchar()) != '\n' && c != EOF); // 개행 문자까지 버퍼 비우기

	system("cls");

	do
	{
		printf("어깨 스트레칭 시작!\n\n");
		printf("1. 한 팔을 안쪽으로 보내고 다른쪽 팔로 팔을 당겨주세요\n");
		printf("2. 다른쪽도 똑같이 실시 합니다.\n\n");
		timer(30);

		system("cls");

		printf("1. 한 쪽 손을 뒤로 넘기고 다른 손으로 팔꿈치를 잡고 뒤쪽으로 당겨주세요\n");
		printf("2. 다른쪽도 똑같이 실시 합니다.\n\n");
		timer(30);

		system("cls");

		printf("하체 스트레칭 시작!\n");
		printf("무릎 굽혔다 펴기 실시\n\n");
		timer(20);

		system("cls");

		printf("1. 무릎 시계방향으로 돌리기\n");
		printf("2. 무릎 반시계방향으로 돌리기\n\n");
		timer(20);

		system("cls");

		printf("런지 실시\n\n");
		timer(10);

		system("cls");

		printf("1. 앞쪽 허벅지 근육 스트레칭\n");
		printf("2. 허벅지 안쪽 근육 스트레칭\n");
		printf("3. 종아리 근육 스트레칭\n\n");

		printf("각 20초씩 실시 하세요\n\n");

		timer(60);

		system("cls");

		printf("허리 스트레칭 시작하겠습니다.\n\n");
		printf("1. 기립근 스트레칭 시작\n	코브라 자세를 실시 하세요\n\n");
		timer(10);

		system("cls");

		printf("1. 허리를 좌우 흔들어가며 외복사근 스트레칭 시작\n\n");
		timer(20);

		printf("스트레칭 끝났습니다.\n\n");
		printf("기초 동작 실시하고 본 게임을 즐기세요!\n");

		printf("스트레칭을 한번 더 실시하고 싶다면'r' 클릭\n");
		printf("종료하려면 esc 입력\n");
	} while (key);
	{
		char key = _getch();
		key = tolower(key);

		if (key == 114)
		{
			system("cls");
			printf("스트레칭을 다시 시작합니다!\n");
			volley_ball();
		}
		else if (key == 27)
		{
			exit(0);
		}

	}

}

void basket_ball()
{
	printf("1. (하체근육) 종아리, 허벅지 근육을 제대로 풀기\n");
	printf("2. (상체근육) 코어, 대흉근, 어깨를 제대로 풀기\n");
	printf("아무 키나 눌러서 진행\n");
	_getch();

	int c;
	while ((c = getchar()) != '\n' && c != EOF); // 개행 문자까지 버퍼 비우기

	system("cls");

	do
	{
		printf(" 히체 스트레칭 시작!\n\n");
		printf("1. 의자에 앉아 다리를 들었다 폈다 반복\n");
		printf("2. 다른쪽도 똑같이 실시 합니다.\n\n");
		timer(20);

		system("cls");

		printf("1. 뒷 꿈치 들었다 폈다 반복\n\n");
		timer(20);

		system("cls");

		printf("한쪽 손을 이용해 다리를 뒤로 들어올려 대퇴근육 늘려주기\n");
		printf("양쪽 15초씩 실시\n\n");
		timer(30);

		system("cls");

		printf("1. 스쿼트 20초간 실시\n\n");
		timer(20);

		system("cls");

		printf("상체 스트레칭 시작!\n\n");

		system("cls");

		printf("1. 등배운동 실시\n\n");
		timer(20);

		system("cls");

		printf("1. 버피테스트 20초간 실시n\n");
		timer(10);

		system("cls");

		printf("1. 허리를 좌우 흔들어가며 외복사근 스트레칭 시작\n\n");
		timer(20);

		printf("스트레칭 끝났습니다.\n\n");
		printf("기초 동작 실시하고 본 게임을 즐기세요!\n");

		printf("스트레칭을 한번 더 실시하고 싶다면'r' 클릭\n");
		printf("종료하려면 esc 입력\n");
	} while (key);
	{
		char key = _getch();
		key = tolower(key);

		if (key == 114)
		{
			system("cls");
			printf("스트레칭을 다시 시작합니다!\n");
			volley_ball();
		}
		else if (key == 27)
		{
			exit(0);
		}

	}

}

void Exit_pro()
{
	printf("정말로 프로그램을 종료 하시겠습니까?\n");
	printf("           예: y 아니오: n          \n");

	char key = _getch();
	key = tolower(key);

	switch (key)
	{
	case 121:
		exit(0);
		break;

	case 110:
		system("cls");
		printf("다시 시작합니다.\n\n");
		break;
	}
}
