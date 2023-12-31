## 오버플로우와 언더플로우

```
C 언어와 다른 프로그래밍 언어에서 "오버플로우"와 "언더플로우"는 주로 정수형 데이터 타입의 값이 해당 데이터 타입이 표현할 수 있는 범위를 넘어가는 상황을 가리키는 용어입니다.

오버플로우(Overflow):
오버플로우는 데이터 타입이 표현할 수 있는 최댓값을 초과하는 값을 저장하려고 할 때 발생합니다. 이렇게 하면 값이 해당 데이터 타입의 범위를 넘어가서 예상하지 못한 결과를 초래할 수 있습니다. 오버플로우가 발생하면 값을 다시 최솟값부터 시작하거나 예상치 못한 값으로 덮어쓸 수 있습니다.

예를 들어, 8비트 부호 있는 정수 데이터 타입인 char가 있다고 가정하면, 이 데이터 타입은 -128에서 127까지의 값을 표현할 수 있습니다. 만약 128을 저장하려고 하면 이것은 오버플로우로 간주되고 결과적으로 -128이 저장됩니다.

언더플로우(Underflow):
언더플로우는 데이터 타입이 표현할 수 있는 최솟값 미만의 값을 저장하려고 할 때 발생합니다. 마찬가지로 예상치 못한 결과를 초래할 수 있습니다. 언더플로우가 발생하면 값을 다시 최댓값부터 시작하거나 예상치 못한 값으로 덮어쓸 수 있습니다.

예를 들어, 위에서 언급한 8비트 부호 있는 정수 char를 다시 예로 들면, -129를 저장하려고 하면 이것은 언더플로우로 간주되고 결과적으로 127이 저장됩니다.

오버플로우와 언더플로우는 주로 산술 연산, 배열 인덱싱, 비트 연산 등에서 발생할 수 있으며, 프로그램에서 예상치 못한 결과를 초래하거나 보안 문제로 이어질 수 있으므로 주의해야 합니다. C 언어에서는 이러한 상황을 방지하기 위해 데이터 타입의 크기 및 범위를 고려하여 프로그래밍하는 것이 중요합니다.
```

```
#include <stdio.h>

int main()
{
	short over = 32768, under = -32769;

	printf(" 32768 => %8d\n", over);
	printf("-32769 => %8d\n", under);

	return 0;
}
```

이 코드에 대한 설명

```
이 코드는 C 언어를 사용하여 short 데이터 타입을 사용한 정수형 변수 over와 under를 선언하고 초기화한 후, 이 변수들의 값을 출력하는 간단한 프로그램입니다. 그러나 주의해야 할 중요한 점은 short 데이터 타입의 범위를 초과하는 값을 초기화하고 출력하고 있으므로 오버플로우와 언더플로우가 발생할 것입니다.

short는 보통 16비트 크기를 가지며, 부호 있는 정수를 나타냅니다. 범위는 대략 -32,768에서 32,767까지이므로 32,768은 범위를 초과한 값이며, -32,769도 범위를 초과한 값입니다.
```

실행결과

```
 32768 =>   -32768
-32769 =>    32767
```

## 정수형 int와 정수형 short의 차이점

위와 같은 예제로

```
#include <stdio.h>

int main()
{
	int over = 32768, under = -32769;

	printf(" 32768 => %8d\n", over);
	printf("-32769 => %8d\n", under);

	return 0;
}
```

이를 실행하였더니 변수명을 short로 했을떄와 다른 결과값이 나왔다

```
int 데이터 타입은 시스템에 따라 크기가 다를 수 있지만, 일반적으로 16비트, 32비트 또는 64비트 크기를 가집니다. 범위는 int 데이터 타입의 비트 수에 따라 달라지며, 가장 일반적인 경우로 32비트 int를 가정하면 대략 -2,147,483,648에서 2,147,483,647까지의 범위를 가집니다.
```

```
int 데이터 타입이 충분히 큰 범위를 가지고 있어서 32,768 및 -32,769와 같은 값들을 표현할 수 있음을 보여줍니다. 따라서 int 데이터 타입은 일반적으로 short보다 더 넓은 범위의 정수를 표현할 수 있습니다.
```

실행결과

```
 32768 =>    32768
-32769 =>   -32769
```

### 예제 4-12 만수르 용돈코드

```
#include <stdio.h>

int main()
{
	float money1 = 30000000000;
	double money2 = 30000000000;

	printf("float = %.1f\n", money1);
	printf("double = %.1lf\n", money2);
	printf("지수형 = %.1le\n", money2);

	return 0;
}
```
실행결과

```
float = 30000001024.0
double = 30000000000.0
지수형 = 3.0e+10
```

### 일 한 시간을 입력받고 총합을 계산하는 예제

```
#include <stdio.h>

int main()
{
	int hour_pay = 10850;
	double time = 0;
	double sum = 0;

	printf("일 한 시간을 입력하세요:", time);
	scanf_s("%lf", &time);

	sum = time * hour_pay;

	printf("시급 %d, %.1lf시간 일함\n", hour_pay, time);
	printf("총합 = %.1lf\n", sum);

	return 0;
}
```
실행결과
```
일 한 시간을 입력하세요:42.5
시급 10850, 42.5시간 일함
총합 = 461125.0
```

## 제어문자

```
\0 : NULL : 널 문자
\b : BS : 한 칸 왼쪽으로 이동
\t : HT : 수평 탭, 일정 간격으로 띄움
\n : LF : 한 줄을 끝내고 다음 줄로 이동
\r : CR : 줄의 맨 앞으로 이동
```

### 에제 4-16 제어문자 코드

```
#include <stdio.h>

int main()
{
	char mo = '\n';

	printf("L1 %d %d %c", 28, 10, mo);
	printf("L2 %d %d\n", 28, 10);
	printf("L3 %d \t%d\n", 28, 10);
	printf("L4 %d \b%d\n", 28, 10);
	printf("L5 %d \r%d\n", 28, 10);

	return 0;
}
```
실행결과
```
L1 28 10
L2 28 10
L3 28   10
L4 2810
10 28
```

의문점

왜 5번 쨰 줄의 L5는 출력이 안 되는것 인지?

```
지피티 왈

제공된 코드에서 "L5" 뒤에 \r을 사용하면서 출력 결과가 "10 28"로 나오는 것은 아마도 출력 디바이스나 터미널 설정에 따라 발생하는 동작입니다. \r은 커서를 현재 라인의 처음으로 이동시킨 후, 다음 문자를 출력합니다. 따라서 "L5"를 출력하고 커서를 처음으로 이동시킨 다음 " 10"이 출력되어 "10 28"으로 보일 수 있습니다.

커서를 이동시키는 동작은 출력 디바이스와 운영 체제에 따라 다를 수 있으며, 이러한 동작은 환경에 따라 결과가 달라질 수 있습니다. "10 28"이 출력되는 것은 특정 출력 환경에서의 결과이며, 이러한 결과를 예측하기 위해서는 터미널 및 출력 시스템의 동작을 고려해야 합니다.
```

### 특수문자 출력
```
\" : 화면에 큰따옴표(") 출력
\' : 화면에 작은따옴표(') 출력
\\ : 화면에 역슬래시(\) 출력
%% : 화면에 퍼센트(%) 출력
```

```
#include <stdio.h>

int main()
{
	printf(" \'A\' 문자 한 개\n");
	printf(" \"ABC\" 문자열\n");
	printf(" \\ 역슬래시\n");
	printf(" %% 퍼센트\n");

	return 0;
}
```

실행결과
```
 'A' 문자 한 개
 "ABC" 문자열
 \ 역슬래시
 % 퍼센트
```

## 상수

상수형 변수 선언할 떄는 변수 앞에 const를 붙임
```
#include <stdio.h>

int main()
{
	const double PI = 3.14;
	double height = 10.0, dia = 9.0;

	printf("라벨 높이 = %.2lf\n", height);
	printf("라벨 길이 = %.2lf\n", PI * dia);

	return 0;
}
```

### 매크로 macro

```
#difine 으로 선언
대문자를 사용
문장 끝에 세미콜론 붙이지 않음
```
지금은 상수 정의 에서만 사용하지만 다른 예시가 많으므로 시험 끝나고 더 자세히 공부 해야겠다

```
상수 정의: 상수 값을 정의하기 위해 매크로를 사용합니다. 예를 들어, #define 지시문을 사용하여 코드 내에서 사용할 상수를 정의합니다.
```
```
#include <stdio.h>
#define DIA 9  // 메모리에 들어가지 않은채로 상수가 됨

int main()
{
	const double PI = 3.14;  // 메모리에 들어간 채로 상수가 됨
	double height = 10.0;

	printf("라벨 높이 = %.2lf\n", height);
	printf("라벨 길이 = %.2lf\n", PI * DIA);

	return 0;
```
DIA를 사용하여 상수 9를 정의 함.

실행결과
```
라벨 높이 = 10.00
라벨 길이 = 28.26
```

### 리터럴
데이터를 의미

본래의 의미를 정확하게 표시해야 함

16진수와 8진수의 표기 및 서식문자
```
16진수 : 0x : %o
8진수  : 0  : %x(소문자), %X(대문자)
```

### 예제 4 - 20 진수 변환 코드

```
#include <stdio.h>

int main()
{
	int num1 = 0xB;
	int num2 = 016;

	printf("10진수 = %d\n", num1);
	printf(" 8진수 = %o\n\n", num1);
	printf("10진수 = %d\n", num2);
	printf("16진수 = %X\n", num2);

	return 0;
}
```
실행결과
```
10진수 = 11
 8진수 = 13

10진수 = 14
16진수 = E
```

```
이 코드는 C 프로그램으로, 16진수와 8진수로 표현된 정수를 10진수로 출력하는 예제입니다. 아래는 코드의 동작을 설명한 내용입니다:

1. `#include <stdio.h>`: 표준 입력과 출력 함수를 사용하기 위한 헤더 파일을 포함합니다.

2. `int num1 = 0xB;`: 16진수 리터럴 `0xB`를 사용하여 `num1`이라는 정수 변수를 선언하고 초기화합니다. `0xB`는 16진수로 11에 해당하며, 10진수로 11입니다.

3. `int num2 = 016;`: 8진수 리터럴 `016`을 사용하여 `num2`라는 정수 변수를 선언하고 초기화합니다. `016`은 8진수로 16에 해당하며, 10진수로 14입니다.

4. `printf("10진수 = %d\n", num1);`: `num1`의 값을 10진수로 출력합니다. `%d` 형식 지정자를 사용하여 변수 `num1`의 값을 출력합니다. 출력 결과로 "10진수 = 11"이 표시됩니다.

5. `printf(" 8진수 = %o\n\n", num1);`: `num1`의 값을 8진수로 출력합니다. `%o` 형식 지정자를 사용하여 변수 `num1`의 값을 8진수로 출력합니다. 출력 결과로 " 8진수 = 13"이 표시됩니다. `0xB`를 8진수로 표현하면 13입니다.

6. `printf("10진수 = %d\n", num2);`: `num2`의 값을 10진수로 출력합니다. `%d` 형식 지정자를 사용하여 변수 `num2`의 값을 출력합니다. 출력 결과로 "10진수 = 14"가 나타납니다.

7. `printf("16진수 = %X\n", num2);`: `num2`의 값을 16진수로 출력합니다. `%X` 형식 지정자를 사용하여 변수 `num2`의 값을 16진수 대문자로 출력합니다. 출력 결과로 "16진수 = E"가 표시됩니다. 8진수 016을 16진수로 표현하면 0xE입니다.

프로그램은 주어진 정수 값을 다른 진법으로 변환하고 출력하는 간단한 예제를 제공합니다.
```
### LAB2 세금을 포함한 주급 계산

```
#include <stdio.h>
#define TAX 0.045

int main()
{
	int hour_pay = 0;
	double time = 0;
	double sum = 0;

	printf("시급과 일한 시간을 입력하세요: ", hour_pay, time);
	scanf_s("%d, %lf", &hour_pay, &time);

	sum = hour_pay * time * TAX;

	printf("당신이 받을 주급은 %lf", &sum);

	return 0;
}
```
실행결과
```
시급과 일한 시간을 입력하세요: 10000, 42.5
당신이 받을 주급은 405875.000000
```

# 연산자

## LAB_1 생수 값 계산하기

```
#include <stdio.h>

int main()
{
	int person, bottle_for_person;

	printf("전체 인원을 입력하세요: ");
	scanf_s("%d", &person);

	printf("1인당 생수 개수를 입력하세요: ");
	scanf_s("%d", &bottle_for_person);

	int total_bottle = person * bottle_for_person;
	int pack_bottle = total_bottle / 15;
	int rest_bottle = total_bottle % 15;

	printf("15팩 구매비용 %d원\n", pack_bottle * 10000);
	printf("낱개 구매 비용 %d원\n", rest_bottle * 900);
	printf("전체 구매 비용 %d원\n", pack_bottle * 10000 + rest_bottle * 900);

	return 0;
}
```

책에서 제시하는 코드
```
#include <stdio.h>

int main()
{
	int person, amount, pack, bottle;

	printf("전체 인원을 입력하세요: ");
	scanf_s("%d", &person);

	printf("1인당 생수 개수를 입력하세요: ");
	scanf_s("%d", &amount);

	bottle = person * amount % 15;
	pack = (person * amount - bottle) / 15;

	printf("15팩 구매 비용 %d원\n", pack * 10000);
	printf("낱개 구매 비용 %d원\n", bottle * 900);
	printf("전체 구매 비용 %d원\n", pack * 10000 + bottle * 900);

	
	return 0;
}
```
실행결과
```
전체 인원을 입력하세요: 57
1인당 생수 개수를 입력하세요: 3
15팩 구매 비용 110000원
낱개 구매 비용 5400원
전체 구매 비용 115400원
```

### 예제 5 - 4 논리연산자 코드

```
#include <stdio.h>

int main()
{
	int num1, num2;

	printf("2개 숫자를 입력: ");
	scanf_s("%d, %d", &num1, &num2);

	printf("둘 다 0인가? %d\n", (num1 == 0) && (num2 == 0));
	printf("양수가 있는가? %d\n", (num1 >= 1) || (num2 >= 1));
	printf("참의 반대는 무엇인가? %d\n", !1);
	
	return 0;
}
```
실행결과
```
2개 숫자를 입력: 2, 0
둘 다 0인가? 0
양수가 있는가? 1
참의 반대는 무엇인가? 0
```
산술, 비교, 논리 연산자 순으로 우선순위가 정해짐

### 5.2 LAB 2 피자 값 계산하기

```
#include <stdio.h>

int main()
{
	int person, order;

	printf("전체 인원: ");
	scanf_s("%d", &person);

	order = person / 4;   // 소수점 이하는 버려짐
// 사람수가 4배수 이면 그대로 시킴
// 사람수가 4배수가 아니면 1판 더 시킴
	order = order + (person % 4 != 0);   // 소수점 이하 존재 -> 1판 추가
	printf("주문 피자 수: %d판\n", order);
	printf("피자 가격: %d원\n", order * 12000);

	return 0;
}
```
실행결과
```
전체 인원: 2
주문 피자 수: 1판
피자 가격: 12000원
```
```
#include <stdio.h>

int main()
{
	int person, order;

	printf("전체 인원: ");
	scanf_s("%d", &person);

	order = person / 4;   // 소수점 이하는 버려짐
	// 사람수가 4배수 이면 그대로 시킴
	// 사람수가 4배수가 아니면 1판 더 시킴
	if (person % 4 != 0)
		order = order + 1; // 소수점 이하 존재 -> 1판 추가
	printf("주문 피자 수: %d판\n", order);
	printf("피자 가격: %d원\n", order * 12000);

	return 0;
}
```

sizeof 자료형의 크기를 알려주는 연산자

### 형 변환

```
int a;
double b = 3.5;
a = b
```
실수 -> 정수 변환 시 소수점 이하 버림

a = 3이 들어감

명시적 형 변환
```
int a;
double b = 3.5;
a = (int)b;
```

```
암시적 형 변환은 자신의 의도와 상관없이 데이터가 소실될 수 있음
특정 의도가 있어서 형 변환을 하고자 할 때는 명시적 형 변환을 사용
자료형을 변환시키겠다고 표시해주는 것
```

### 예제 5 - 9 형변환 코드
```
#include <stdio.h>

int main()
{
	char cnum = 'a';  // a의 아스키 코드 값 97
	int inum;
	double fnum;

	inum = cnum;  // 문자가 정수로 변환되어 저장
	printf("int %d\n", inum);

	cnum = 2000;  // 문자 변수에 2000 대입
	              // 2000이라는 너무 큰 값을 할당하면 부호화된 문자로 처리됨
	printf("int %d\n", cnum);
	
	fnum = 3.7;  // fnum 초기화

	inum = fnum;  // 정수를 실수로 암시적 변환
	printf("int %d\n", inum);

	inum = (int)fnum;  // 정수를 실수로 명시적 변환
	printf("int %d\n", inum);

	return 0;
}
```
실행결과
```
int 97
int -48
int 3
int 3
```

### 5.3 LAB 3 T, F 출력하기
```
#include <stdio.h>

// T와 F 출력하기

int main()
{
	int num1, num2;

	printf("숫자 두개 입력: ");
	scanf_s("%d, %d", &num1, &num2);

	printf("두 수가 같은가? %c\n", (num1 == num2) * 14 + 70);
	printf("num1이 더 큰가? %c\n", (num1 > num2) * 14 + 70);
	printf("num2는 양수인가? %c\n", (num2 > 0) * 14 + 70);

	return 0;
}
```
실행결과
```
숫자 두개 입력: 4, 2
두 수가 같은가? F
num1이 더 큰가? T
num2는 양수인가? T
```
의문점 - () * 14 + 70 에서
14 + 70에 괄호를 안 붙이는 이유는...?
연산 순서떄문에

* 아스키 코드
* T는 84
* F는 70

## 비트 연산자

* & 연산자

두 개의 비트가 모두 1일 때 1을 반환하는 AND 연산을 진행함.
```
ex) 0 & 0 = > 0
    0 & 1 = > 0
    1 & 0 = > 0
    1 & 1 => 1
```
* | 연산자

두 개의 비트가 하나라도 1이면 1을 반환하는 OR 연산
```
ex) 0 | 0 = > 0
    0 | 1 = > 1
    1 | 0 = > 1
    1 | 1 => 1
```
* ^ 연산자

두 개의 비트가 서로 다른 경우에 1을 반환하는 XOR 연산
```
ex) 0 & 0 = > 0
    0 ^ 1 = > 1
    1 ^ 0 = > 1
    1 ^ 1 => 0
```

* ~ 연산자

비트를 0에서 1로, 1에서 0으로 반전시키는 NOT 연산. 보수연산이라고도 불림
```
~0 = > 1
~1 = > 0
```
~연산은 MSB도 반전되어 부호를 바꾸는 것에 주의해야함

* << 연산자

비트를 왼쪽으로 이동하는 shift연산
```
num1 << num2
num1의 비트열을 num2칸씩 왼쪽으로 이동시킨다는 의미를 지님
```
비트의 이동으로 인해서 생기는 오른쪽 빈 칸은 0으로 채워지고 왼쪽으로 밀려나는 비트들은 (4바이트를 넘어서는 비트들) 그냥 버려진다.

또한 비트의 열을 왼쪽으로 1칸씩 이동시킬때 마다 정수의 값은 두배가 됨

*  >> 연산자

비트를 오른쪽으로 이동하는 shift연산
```
num1 >> num2
num1이 양수라면 <<연산자와 같은 방식으로 작동된다
num2가 음수라면 결과는 사용하는 cpu에 따라 달라진다.
음의 값을 유지하기 위해서 1을 채우는 cpu도 있고, 음의값 유지에 상관하지 않고 0을 채우는 cpu도 있다
```

예시 코드
```
#include <stdio.h>
int main()
{
	int num1 = 15;   // 00000000 00000000 00000000 00001111
	int num2 = 20;   // 00000000 00000000 00000000 00010100

	int num3 = num1 & num2;
	printf("AND 연산결과: %d\n", num3);

	int num6 = num1 | num2;
	printf("OR 연산결과: %d\n", num6);

	int num7 = num1 ^ num2;
	printf("XOR 연산결과: %d\n", num7);

	int num4 = 15; // 00000000 00000000 00000000 00001111
	int num5 = ~num4;
	printf("NOT의 연산결과: %d\n", num5);

	int result1 = num1 << 1;
	int result2 = num1 << 2;
	int result3 = num1 << 3;

	printf("<< 연산자 결과\n");
	printf("1칸 이동 결과 : %d\n", result1);
	printf("2칸 이동 결과 : %d\n", result2);
	printf("3칸 이동 결과 : %d\n", result3);

	int num = -16;

	int result = num >> 2;

	printf(">> 연산자 2칸 이동 결과 : %d\n", num);

	return 0;
}
```
실행결과
```
AND 연산결과: 4
OR 연산결과: 31
XOR 연산결과: 27
NOT의 연산결과: -16
<< 연산자 결과
1칸 이동 결과 : 30
2칸 이동 결과 : 60
3칸 이동 결과 : 120
>> 연산자 2칸 이동 결과 : -16
```

## 연산자 우선순위

복잡한 연산자의 부작용
```
#include <stdio.h>
int main()
{
	int num1 = 0, num2 = 0, res;

	res = num1++ && num2++;
	printf("res = %d, num1 = %d, num2 = %d", res, num1, num2);

	return 0;
}
```
실행결과
```
res = 0, num1 = 1, num2 = 0
```
이것이 이렇게 나온 이유는
```
num1과 num2를 모두 0으로 초기화합니다.
res = num1++ && num2++; 라인에서 num1++를 먼저 평가합니다.
현재 num1의 값은 0입니다. 따라서 num1++는 0을 반환하고, num1은 1로 증가합니다.
그런 다음 num2++는 평가하지 않고, res에는 0이 할당됩니다. 왜냐하면 논리 AND 연산에서 둘 중 하나라도 거짓인 경우 결과는 거짓(0)이기 때문입니다.
printf 문에서 res, num1, 그리고 num2의 값들을 출력합니다.
따라서 이 코드는 res = 0, num1 = 1, num2 = 0을 출력합니다. 후위 증가 연산자는 현재 값을 사용한 후에 값을 증가시키므로, num2는 여전히 0이고, num1은 1로 증가한 것이 결과에 반영됩니다.
```
와 같다

코드를 수정하면
```
#include <stdio.h>
int main()
{
	int num1 = 0, num2 = 0, res;

	res = (num1++) && (num2++);
	printf("res = %d, num1 = %d, num2 = %d", res, num1, num2);

	return 0;
}
```
실행결과
```
res = 0, num1 = 1, num2 = 0
```
예상 결과로는
```
res = 1, num1 = 1, num2 = 1
```
이 나와야 맞는것 같은데
왜 실행결과가 그대로 나오는것 일까

# chapter 6 

## 6.1 제어문 

무작위 수를 만드는 함수 rand()
```
com = rand();  // rand() 함수가 무작위 수를 만들어 com에 대입

<stdlib.h> 파일에 포함되어 있는 함수이다.

#include <stdlib.h> 이라 선언

게임 만들때 꼭 필요한 함수 이다.

int com;

com = rand() % 10;  // 0에서부터 9까지 무작위 수 생성
com rand() % 10 +1;  // 1에서 부터 9까지 무작위 수 생성
```

### 예제 6-1
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int com;

	com = rand();
	printf("%d\n", com);

	com = rand() % 10;
	printf("%d\n", com);

	com = rand() % 10 + 1;
	printf("%d\n", com);

	return 0;
}
```
실행결과
```
41
7
5
```
## srand()함수

rand()는 매번 같은 수를 만들어 낸다

따라서 서로 다른 무작위 수를 만드려면 srand() 필요하다

rand() 사용전에 한 번만 사용하면 됨
```
include <time.h>

srand((unsigned)time(NULL));
여기서 unsigned는 형 변환을 도와주는 수식어임
```
### 예제 6 - 2
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int com;

	srand((unsigned)time(NULL));

	com = rand();
	printf("%d\n", com);

	com = rand() % 10;
	printf("%d\n", com);

	com = rand() % 10 + 1;
	printf("%d\n", com);

	return 0;
}
```
실행결과
```
20006
4
2
```
예제 6 - 1과 달리 코드 몇개만 추가 해줬더니 무작위수를 만들어 낸다.

## if~else

### 예제 6 - 4
```
#include <stdio.h>
int main()
{
	int birth, age;

	printf("이번달에 생일 입니까? yes = 1, no = 0: ");
	scanf_s("%d", &birth);

	printf("나이를 입력하세요: ");
	scanf_s("%d", &age);

	if ((birth == 1) && (age >= 19))
		printf("축하합니다 모히또 한 잔 당첨\n"); // 조건이 참(1)일 경우 실행

	return 0;
}
```
실행결과
```
이번달에 생일 입니까? yes = 1, no = 0: 1
나이를 입력하세요: 19
축하합니다 모히또 한 잔 당첨
```
```
if ((birth == 1) && (age >= 19))
이 코드를
if (birth == 1 && age >= 19)
이렇게 바꾸면 무슨일이 일어나는지 관찰해 보자
```
```
비교 연산자가 논리 연산자보다 먼저 연산되므로 동일한 결과가 출력이 될 것이다
그러나 이 경우에는 논리 연산자(&&)와 비교 연산자(==, >=)가 함께 사용되는 것으로, C 언어의 연산자 우선순위 규칙에 따라 괄호를 사용하지 않더라도 코드는 올바르게 작동된다
```

### 예제 6 - 7
```
#include <stdio.h>
int main()
{
	int time, meal_money, bounos_money = 0;
	int sum = 0;

	printf("일 한 시간을 입력하세요: ");
	scanf_s("%d", &time);

	meal_money = time / 4;

	if (time < 40)
	{
		sum = (time * 12800) + (meal_money * 9000);
		sum = sum + (sum * 0.02);

		printf("당신이 받을 금액은 %d", sum);
	}
	else
	{
		sum = (time * 12800) + (meal_money * 10000);
		sum = sum + (sum * 0.1);

		printf("당신이 받을 금액은 %d", sum);
	}

	return 0;
}
```
실행결과
```
일 한 시간을 입력하세요: 44
당신이 받을 금액은 740520
```

### LAB 2 가위바위보 게임
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int com, user;

	srand((unsigned)time(NULL));

	printf("가위 0 바위1 보2 선택: ");
	scanf_s("%d", &user);

	com = rand() % 3;

	printf("user = %d, com = %d", user, com);

	if (com == user)
		printf("비겼습니다\n");
	else if ((com == 0) && (user == 1) || (com == 1) && (user == 2) || (com == 2) && (user == 0))
		printf("사용자 승\n");
	else
		printf("컴퓨터 승\n");

	return 0;
}
```
실행결과
```
가위 0 바위1 보2 선택: 0
user = 0, com = 2사용자 승
```
```
가위 0 바위1 보2 선택: 2
user = 2, com = 2비겼습니다
```

만약 사용자가 2보다 큰 수를 입력했을때 강제로 종료 시키는 프로그램
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int com, user;

	srand((unsigned)time(NULL));

	printf("가위 0 바위1 보2 선택: ");
	scanf_s("%d", &user);

	if (user > 2)
	{
		printf("0~2 사이 숫자만 입력해야 합니다(해당하는 포지션 없음)");
		return 1;
	}

	com = rand() % 3;

	printf("user = %d, com = %d", user, com);

	if (com == user)
		printf("비겼습니다\n");
	else if ((com == 0) && (user == 1) || (com == 1) && (user == 2) || (com == 2) && (user == 0))
		printf("사용자 승\n");
	else
		printf("컴퓨터 승\n");

	return 0;
}
```
실행결과
```
가위 0 바위1 보2 선택: 3
0~2 사이 숫자만 입력해야 합니다(해당하는 포지션 없음)
```

사용자가 0, 1, 2 이외의 숫자를 입력했을 때 게임을 다시 시작하도록 만들기

```
무한 루프 구문인 while(1)을 사용하여 만들 수 있다

올바른 입력을 받았을때 루프를 종료하기 위해 break를 사용해야 한다

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int com, user;

    srand((unsigned)time(NULL));

    while (1) 
    {
        printf("가위 0 바위 1 보 2 선택: ");
        scanf_s("%d", &user);

        if (user < 0 || user > 2) 
        {
            printf("0~2 사이 숫자만 입력해야 합니다. 다시 입력하세요.\n");
        }
        else 
        {
            com = rand() % 3;
            printf("user = %d, com = %d\n", user, com);

            if (com == user)
                printf("비겼습니다\n");
            else if ((com == 0 && user == 1) || (com == 1 && user == 2) || (com == 2 && user == 0))
                printf("사용자 승\n");
            else
                printf("컴퓨터 승\n");

            break; // 올바른 입력을 받았으므로 루프를 종료합니다.
        }
    }

    return 0;
}

while(1) 루프를 사용하여 사용자의 입력이 해당 범위 내에 있는지 판단하고 올바른 입력을 받으면
루프를 종료하고 게임이 진행된다
```
실행결과
```
가위 0 바위 1 보 2 선택: 3
0~2 사이 숫자만 입력해야 합니다. 다시 입력하세요.
가위 0 바위 1 보 2 선택: 2
user = 2, com = 1
사용자 승
```
교수님 왈
```
 else if ((com == 0 && user == 1) || (com == 1 && user == 2) || (com == 2 && user == 0))
```
"사용자 승" 이 나오는 이 코드를 더 간단히 짜 보아라.. 규칙성을 발견해서
