# cahpter 4 연습문제

72번
```
300억이 출력되도록 코딩

매우 큰 정수 값 이므로 long long int 를 선언한다.

#include <stdio.h>
int main()
{
  long long int money = 30000000000;

  printf("chunsur = %lld\n", money);

  return 0;
}
```
73번
```
0.123456789 모두 출력되도록 코딩

큰 실숫값을 받아들일 수 있는 long double 사용
정밀도로 인해 모두 출력이 안 될수 있으므로 유의!

#include <stdio.h>

int main()
{
	long double fnum = 0.123456789L;

	printf("long double = %.9Lf\n", fnum);  // 소수점 9번째 자리 까지 출력될 수 있도록 서식문자를 수정하기!

	return 0;
}
```
76번
```
scanf 문제로서 &를 유의하는 문제
```
79번
```
#include <stdio.h>

int main()
{
	const double PAL;

	PAL = 24.56;

	printf("PAL = %.2lf\n", PAL);

	return 0;
}

수정하기
#include <stdio.h>

int main()
{
	const double PAL = 24.56;

	printf("PAL = %.2lf\n", PAL);

	return 0;
}

E0137	식이 수정할 수 있는 lvalue여야 합니다.	

이미 상수형 변수 PAL을 설정 했으므로
PAL = 24.56으로 초기화가 되지 않고
PAL에는 아무 수도 들어가지 않은 상태가 되어 실행할 수 없게 된다
```
