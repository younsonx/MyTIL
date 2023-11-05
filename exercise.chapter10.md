# 1. 
```c
#include <stdio.h>
#define SIZE 7

int main()
{
	int arr[SIZE];
	int i;
	int num;
	int sum = 0;

	for (i = 0; i < SIZE; i++)
	{
		printf("값을 입력하시오: ");
		scanf_s("%d", &arr[i]);
		sum += arr[i];
	}

	printf("합은 %d\n", sum);
	printf("평균은 %d\n", sum / SIZE);

	return 0;
}
```
```
값을 입력하시오: 1
값을 입력하시오: 2
값을 입력하시오: 3
값을 입력하시오: 4
값을 입력하시오: 5
값을 입력하시오: 6
값을 입력하시오: 8
합은 29
평균은 4
```

#2.
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int main()
{
	int arr[SIZE];
	int max;
	int min;
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < SIZE; i++) {
		arr[i] = rand() % 20 + 1;
	}

	min = arr[0];
	max = arr[0];

	for (i = 1; i < SIZE; i++) {
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	printf("최대값: %d\n", max);
	printf("최소값: %d\n", min);

	return 0;
}
```
```
최대값: 20
최소값: 1
```

# 3.
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main()
{
	int arr[SIZE];
	int i;
	int num;
	int count = 0;

	srand((unsigned)time(NULL));

	for (i = 0; i < SIZE; i++) {
		arr[i] = rand() % 100 + 1;
	}

	printf("(1~100)사이의 수를 입력하세요: ");
	scanf_s("%d", &num);

	for (i = 0; i < SIZE; i++) {
		if (arr[i] > num)
			count++;
	}

	printf("%d보다 큰 수 %d개", num, count);

	return 0;
}
```
```
(1~100)사이의 수를 입력하세요: 80
80보다 큰 수 4개
```

# 4. 정렬 with 버블정렬알고리즘
```c
#include <stdio.h>
#define SIZE 5

void bubbleSort(int arr[], int size) {
    int i, j;
    int temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int i;
    int num[SIZE];

    for (i = 0; i < SIZE; i++) {
        printf("숫자 입력: ");
        scanf_s("%d", &num[i]);
    }

    bubbleSort(num, SIZE);

    for (i = 0; i < SIZE; i++) {
        printf("%d\n", num[i]);
    }

    return 0;
}
```
```
숫자 입력: 5
숫자 입력: 10
숫자 입력: 3
숫자 입력: 8
숫자 입력: 1
10
8
5
3
1
```
# 5.
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void bubbleSort(int arr[], int size) {
    int i, j;
    int temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int i;
    int num[SIZE];
    int choice;

    srand((unsigned)time(NULL));

    for (i = 0; i < SIZE; i++) {
        num[i] = rand() % 21;
    }

    printf("정렬 방식 (1: 오름차순, 2: 내림차순)");
    scanf_s("%d", &choice);

    if (choice == 2)
        bubbleSort(num, SIZE);
    else if (choice == 1) {
        bubbleSort(num, SIZE);
        for (i = 0; i < SIZE / 2; i++) {
            int temp = num[i];
            num[i] = num[SIZE - i - 1];
            num[SIZE - i - 1] = temp;
        }
    }
    else {
        printf("잘못된 선택\n");
        return 1;
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d\n", num[i]);
    }
    
    return 0;
}
```
```
정렬 방식 (1: 오름차순, 2: 내림차순)1
0
1
4
7
8
11
14
16
18
19
```
