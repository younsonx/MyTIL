## 라이브러리 함수
함수를 사용하는것: 함수를 호출한다  
함수로 전달되는 변수를 매개변수라고 함  
라이브러리의 장점은 함수의 재사용!!  
## 사용자 정의 함수
사용자 정의 함수의 장점은 모듈화  
- 함수를 재 사용함으로써 작업이 단순해짐
- main 함수의 코드가 간결해지고 구조 쉽게 파악 가능

코드의 유지보수가 쉬워짐

형식  
반환 자료형 / 함수 이름(입력) / {몸체}
```c
void fry(int A)
{
  printf("%d~~~~~~", A);
}
```

주의 사항: 사용자 함수를 사용하기 전에 먼저 함수를 정의해야 한다.

#### 사운드미터 제작
```c
#include <stdio.h>
#include <stdlib.h>

void num(int num)
{
	printf("%d", num);
}

int main()
{
	int k, jul, met;

	for (k = 0; k <= 100; k++)
	{
		system("cls");
		for (jul = 1; jul <= 8; jul++)
		{
			for (met = 0; met <= rand() % 80; met++)
			{
				printf("ㅁ ");
			}
			num(jul);
			printf("\n");
			printf("----------------------------------------------------");
			printf("\n");
		}
			
	}
	return 0;
}
```
#### 사용자 정의 함수를 사용한 사운드미터
```c
#include <stdio.h>
#include <stdlib.h>

void sound_meter(int num)
{
	int k, jul, met;

	for (k = 0; k <= 100; k++)
	{
		system("cls");
		for (jul = 1; jul <= num; jul++)
		{
			for (met = 0; met <= rand() % 80; met++)
				printf("ㅁ");
			printf("\n");
		}
			
	}
}

int main()
{
	sound_meter(8);
	sound_meter(16);
	sound_meter(24);
	return 0;
}
```

## 함수의 종류와 특징

참조에 의한 호출  
두 수 바꾸기 코드
```c
#include <stdio.h>

void swap(int one, int two)
{
	int temp;

	temp = one;
	one = two;
	two = temp;
}

int main()
{
	int first = 7, second = 10;
	swap(&first, &second);
	printf("f=%d, c=%d", first, second);

	return 0;
}
```
값이 바꿔지지 않는다..  
swap()함수의 매개 변수를 일반 형태인 값에 의한 호출로 정의를 했기 때문에 바뀌지 않고  
main 함수 에서 &를 사용하여 호출하였는데 호출을 받는 쪽의 매개변수는 일반 변수이다.  

#### 행운의 수 코드
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int today_luck(int num)
{
	int k, luck = 60, lkey;

	srand((unsigned)time(NULL));
	for (k = 1; k <= 20; k++)
	{
		lkey = rand() % 20 + 1;
		if (lkey != num)
		{
			luck -= 1;
			printf("행운 수 %2d  %2d만점 사라짐 %4d만점\n", lkey, k, luck);
		}
		else
			break;
		system("timeout 2 > NULL");
	}
	return luck;
}

int main()
{
	int point, key;

	printf("60만점부터 시작 1~20 선택: ");
	scanf("%d", &key);
	
	point = today_luck(key);
	printf("\n오늘은 %d만점!\n", point);
	return 0;
}
```
