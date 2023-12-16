# 1
```c
#include <stdio.h>

int main()
{
	char c = '@';
	char* pc = &c;

	int m = 100;
	int* pm = &m;

	double x = 5.83;
	double* px = &x;

	printf("변수명  주소값             저장값\n");
	printf("----------------------------------\n");
	printf("%3s %12p %9c\n", "c", pc, c);
	printf("%3s %12p %9d\n", "m", pm, m);
	printf("%3s %12p %9f\n", "x", px, x);

	return 0;
}
```
```
변수명  주소값             저장값
----------------------------------
  c 0000000FD1B6F4A4         @
  m 0000000FD1B6F4E4       100
  x 0000000FD1B6F528  5.830000
```

# 2

포인터 변수에 지정할 특별한 초기 값이 없는 경우  
0번 주소 값인 NULL로 초기 값을 저장

피피티 참고

```c
#include <stdio.h>

int main()
{
	int data = 10;
	int* p1 = NULL, * p2 = &data;

	printf("%d\n", data);
	printf("%p %p\n", p1, p2);

	return 0;
}
```
```
10
0000000000000000 000000A1084FF9D4
```

# 3
```c
#include <stdio.h>

int main()
{
	int i = 100;
	char c = 'A';

	int* pi = &i;
	int* pc = &c;
	printf("간접참조 출력: %d %c\n", *pi, *pc);

	*pi = 200;
	*pc = 'B';
	printf("직접참조 출력: %d %c\n", i, c);

	return 0;
}
```
```
간접참조 출력: 100 A
직접참조 출력: 200 B
```
Run-Time Check Failure #2 - Stack around the variable 'c' was corrupted. 발생  

```
C 또는 C++과 같은 언어에서 발생하는 메모리 오버플로우(overflow)나 배열 범위를 벗어난 접근 등으로 인해 스택 메모리가 손상되었을 때 발생하는 오류입니다.

이 오류는 주로 배열이나 버퍼에 할당된 메모리를 초과하여 읽거나 쓸 때 발생합니다. 배열 범위를 벗어나거나 메모리를 잘못된 방식으로 조작하면 프로그램이 예기치 않게 스택 메모리를 손상시킬 수 있습니다.

이 오류를 해결하기 위해서는 다음과 같은 접근 방법을 고려할 수 있습니다:

코드 검토: 손상된 변수나 배열에 대한 접근을 찾아내고, 범위를 벗어나는 메모리 접근을 수정합니다.
배열 범위 확인: 배열을 사용할 때, 배열의 크기를 벗어나는 인덱스에 접근하지 않도록 주의합니다. 올바른 인덱스를 사용하여 배열에 접근합니다.
메모리 관리: 동적으로 할당된 메모리를 사용할 때 메모리 누수나 할당된 메모리를 벗어나는 접근을 방지하기 위해 메모리를 올바르게 해제하고, 할당된 메모리를 초과하여 접근하지 않도록 합니다.
이러한 수정 사항을 통해 프로그램에서 발생하는 오류를 해결할 수 있습니다. 하지만 오류의 원인은 코드나 해당하는 상황에 따라 다르므로 오류를 식별하고 수정하기 위해서는 해당 코드를 자세히 분석해야 합니다.
```
[google]https://habitus92.tistory.com/13

# 4
두 값을 교환하기  
모두 포인터 변수를 사용하기

```c
#include <stdio.h>

int main()
{
	int x = 500, y = 700, dummy;
	printf("%d %d\n", x, y);

	int* px = &x, * py = &y, * pd = &dummy;

	*pd = *px;
	*px = *py;         
	*py = *pd;

	printf("%d %d\n", x, y);

	return 0;
}
```
```
500 700
700 500
```

# 5
```c
#include <stdio.h>

int main()
{
	int value = 0x44434241;
	printf("저장 값: %#x(16진수) %d(10진수)\n\n", value, value);

	int* pi = &value;
	char* pc = (char*)&value;

	printf("변수명   저장값      주소값\n");
	printf("---------------------------\n");
	printf(" value  %#x   %llu\n\n", value, (uintptr_t)pi);

	printf("간접참조 코드 문자   주소값\n");
	printf("---------------------------\n");

	for (int i = 0; i <= 3; i++)
	{
		char ch = *(pc + i);
		printf(" *(pc+%d) %#x %3c %llu\n", i, ch, ch, (uintptr_t)(pc + i));
	}

	return 0;
}
```
```
저장 값: 0x44434241(16진수) 1145258561(10진수)

변수명   저장값      주소값
---------------------------
 value  0x44434241   567224431828

간접참조 코드 문자   주소값
---------------------------
 *(pc+0) 0x41   A 567224431828
 *(pc+1) 0x42   B 567224431829
 *(pc+2) 0x43   C 567224431830
 *(pc+3) 0x44   D 567224431831
```

# 6
```c
#include <stdio.h>

int main()
{
	int i = 10, j = 20;
	const int* p = &i;
	printf("%d ", *p);
	p = &j; // *p = 20; 오류 발생
	printf("%d\n", *p);

	double d = 7.8, e = 2.7;
	double* const pd = &d;
	printf("%f ", *pd);
	*pd = 4.4; // pd = &e; 오류 발생
	printf("%f\n", *pd);


	return 0;
}
```
```
10 20
7.800000 4.400000
```
