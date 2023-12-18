## 배열 활용

#### 소나기 코드
```c
#include <stdio.h>
#include <stdlib.h>

#define WTH 119  //화면의 가로 폭
#define HGT 26  // 화면의 세로 높이

int main()
{
	int rain[WTH], k, jul, met;

	for (met = 0; met < WTH; met++)
		rain[met] = rand() % HGT - HGT;  //음수를 만들어 화면에서 숨김

	for (k = 0; k < 200; k++)
	{
		system("cls");
		for (met = 0; met < WTH; met++)
		{
			if (rain[met] < HGT)  //바닥이 아니면 한 줄 내려감
				rain[met]++;
			else
				rain[met] = -1;  //바닥이면 -1 부터 다시 시작
		}
		for (jul = 0; jul < HGT; jul++)
		{
			for (met = 0; met < WTH; met++)
			{
				if (rain[met] == jul)
					printf("|");
				else
					printf(" ");
			}
			printf("\n");
		}  //jul 반복 끝
			
	}  //k 반복 끝
	return 0;
}
```
