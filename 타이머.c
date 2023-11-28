#include <stdio.h>
#include <windows.h>

int main() {
    int countdown = 10; // 카운트다운을 10으로 초기화

    printf("10초 타이머를 시작합니다.\n");

    printf("시작 하려면 enter 입력\n");

    if (getchar() )
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

    return 0;
}
