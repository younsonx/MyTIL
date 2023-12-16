```c
#define NULL ((void *)0)
```
NULL은 일반적으로 "아무것도 가리키지 않는 포인터"를 나타내는데 사용됩니다.  
여기서 ((void *)0)은 주로 0에 해당하는 포인터를 나타냅니다. 대부분의 경우, NULL은 정수 0과 동일하게 동작하지만, 포인터를 나타내기 위해 사용할 때 보다 명시적입니다.

포인터 변수에 초기 값을 대입하지 않으면 쓰레기 값이 들어가므로 0번 주소 값인 NULL로 초기 값 저장.

포인터 p가 가리키는 변수가 data라면 *p는 변수 data를 의미
```c
#include <stdio.h>
int main()
{
	int data = 100;
	int* p = &data;

	printf("%d\n", *p);

	*p = 200;

	printf("%d", *p);

	return 0;
}
```
```c
*p = 200
```
으로 변수 data의 저장 값을 200으로 수정 가능  
변수 data로 가능한 작업은 *p로도 가능

*p로 data 변수 저장 장소 l-value와 참조 값인 r-value로 참조 가능

포인터 *p를 사용하여 변수 data의 값을 가져올 때,  
*p가 l-value(값을 저장할 수 있는 위치)와 r-value(참조할 값을 나타내는 값)로 모두 작용할 수 있다는 것을 의미합니다.  
*p는 data 변수의 값을 읽을 때 r-value로 사용되고, *p를 통해 data 변수의 값을 변경할 수도 있으므로 l-value로도 작용할 수 있습니다.

### LAB 포인터를 이용하여 두 수의 값을 교환하는 프로그램
```c
#include <stdio.h>
int main()
{
	int x = 100, y = 200;
	int dummy;

	int* px = &x, * py = &y;
	int* pd = &dummy;

	printf("교환 하기 전 %d %d\n", *px, *py);

	*pd = *px;
	*px = *py;
	*py = *pd;

	printf("교환 후      %d %d\n", *px, *py);
	
	return 0;
}
```
```c
교환 하기 전 100 200
교환 후      200 100
```

### 이중 포인터를 이용한 변수의 참조
```c
#include <stdio.h>
int main()
{
	int i = 100;
	int* pi = &i;
	int** dpi = &pi;

	printf("%p %p %p\n", &i, pi, *dpi); // 주소값 출력

	*pi = i + 30; // i 값 130 으로 저장 
	printf("%d %d %d\n", i, *pi, **dpi); // 주소값에 해당하는 메모리값 출력 

	**dpi = *pi + 30; // i값 160으로 저장
	printf("%d %d %d\n", i, *pi, **dpi);
	
	return 0;
}
```
```c
000000B80B1CF4E4 000000B80B1CF4E4 000000B80B1CF4E4
130 130 130
160 160 160
```

### 간접 연산자와 증감연산자 활용
```c
#include <stdio.h>
int main()
{
	int arr[] = { 10, 20 };
	int* p = arr;

	int b = NULL;

	printf("%d\n", *p);

	b = *p++;
	printf("%d\n", b);

	b = *++p;
	printf("%d\n", b);

	b = (*p)++;
	printf("%d\n", b);

	b = ++ * p;
	printf("%d\n", b);
	
	return 0;
}
```
```c
10
10
-858993460
-858993460
-858993458
```

제시된 코드는 포인터 연산 및 값 증감에 따라 예상치 못한 결과를 내고 있습니다. 이를 해결하려면 코드의 의도를 명확히 이해하고 표현식을 수정해야 합니다.

위의 코드에서 예상치 못한 결과를 피하기 위해 표현식을 재구성하거나 변수 사용 방식을 변경해야 할 수 있습니다. 포인터 증감 연산자와 후위/전위 증감 연산자를 조심스럽게 사용하여 코드를 수정해보세요.

제시된 코드에서 값이 예상과 다르게 출력되는 이유는 포인터와 값을 조작하는 방식에 있습니다. 몇 가지 수정을 통해 결과를 예상한 대로 나오도록 코드를 변경해보겠습니다.

예제 답 참조조

### 포인터 상수
종류 크게 두가지로 구분
```c
(const)(자료형) 포인터 변수
```
```c
(자료형)* (const) 변수
```

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
	*pd = e; // pd = &e 오류 발생
	printf("%f\n", *pd);

	return 0;
}
```
```c
10 20
7.800000 2.700000
```

### 배열에서 포인터를 사용해 원소와 주소값의 참조

배열 원소 접근 방법  
score 이라는 배열이 존재할때  
```c
score[i]

*(score+i)
```
주소값 ( 첫 주소 + 배열 원소 크기*i)

주소값 접근방법
```c
&score[i]

score + i
```

#### 예제
```c
#include <stdio.h>
int main()
{
	int score[] = { 10, 20, 30 };
	printf("%p %p\n", score, (score + 1));
	printf("%d %d\n\n", *score, *(score + 1));

	int a[] = { 5, 10, 15 };
	int* p = a;

	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));
	printf("%d %d %d\n", p[0], p[1], p[2]);

	printf("%d ", *p++);
	printf("%d\n\n", *p);

	p = &a[2];

	printf("%d ", *p--);
	printf("%d\n\n", (*p)--);

	printf("%d %d %d\n", *(p - 1), *p, *(p + 1));
	
	return 0;
}
```
```c
00000068D88FFA68 00000068D88FFA6C
10 20

5 10 15
5 10 15
5 10

15 10

5 9 15
```
p = &a[2]; 와 *p = a[2]가 동일한 코드인 줄 알았음  
p가 배열의 주소값을 가져온다고 생각하여 포인터 변수p가 메모리 값을 가져오는것과 별반 다를게 없다고 생각했는데  

첫 번째 코드에서는 포인터 p가 증가하거나 감소할 때 실제로 배열의 요소에 접근하여 값을 변경하지 않고, 단지 포인터가 가리키는 주소를 변경합니다.

하지만 두 번째 코드에서는 *p = a[2];와 같이 포인터 p가 가리키는 메모리 위치에 값을 변경하는 연산을 수행하고 있습니다.

라고 함

두 번째 코드에서는 포인터 p를 통해 배열의 요소에 값을 할당하고 변경하는 작업이 수행되는거임. 그래서 
```c
+		a	0x00000091ad95fa18 {5, 15, 15}	int[3]
+		p	0x00000091ad95fa1c {15}	int *
```
배열의 값이 5 15 15로 초기화 되어버림
