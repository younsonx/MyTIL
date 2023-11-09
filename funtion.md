# funtion
C 언어에서 사용자 정의 함수는 프로그래머가 직접 정의하여 필요한 작업을 수행하는 코드 블록입니다. 이러한 함수를 정의하면 프로그램의 가독성을 높이고 코드의 재사용성을 향상시킬 수 있습니다. 사용자 정의 함수를 만들려면 다음과 같은 단계를 따릅니다.

1. 함수의 정의:
   사용자 정의 함수를 정의하기 위해 다음과 같은 기본 구문을 사용합니다.
   
   ```c
   반환_자료형 함수_이름(매개변수_목록) {
       // 함수의 내용
   }
   ```
   
   - `반환_자료형`: 함수가 어떤 종류의 값을 반환할 것인지 지정하는 부분입니다. 반환값이 없는 경우 `void`를 사용합니다.
   - `함수_이름`: 함수의 고유한 이름을 정의합니다. 이 이름은 함수를 호출할 때 사용됩니다.
   - `매개변수_목록`: 함수가 필요로 하는 입력 값들을 지정합니다. 필요 없는 경우 비워둘 수 있습니다.

2. 함수의 내용:
   함수의 내용은 중괄호 `{}` 안에 작성됩니다. 이 곳에서 함수가 수행해야 할 작업을 구현합니다.

예를 들어, 두 정수를 더하는 사용자 정의 함수를 만들어 보겠습니다.

```c
#include <stdio.h>

// 함수의 정의
int add(int a, int b) {
    int result = a + b;
    return result; // 결과값 반환
}

int main() {
    int x = 5;
    int y = 7;
    int sum = add(x, y); // 함수 호출
    printf("합계: %d\n", sum);

    return 0;
}
```

위의 코드에서 `add` 함수는 두 정수를 더하고 그 결과를 반환합니다. `main` 함수에서 `add` 함수를 호출하고 그 결과를 출력합니다.

사용자 정의 함수를 작성하면 코드를 모듈화하고 유지보수를 용이하게 할 수 있으며, 비슷한 작업을 여러 번 수행하는 데 유용합니다.

## 사용자 정의 함수를 사용하기 전에 먼저 함수를 정의해야 한다

사용자 정의 함수를 사용하기 전에 함수를 정의해야 하는 것은 함수가 어떻게 동작할지를 미리 프로그램에 알려주는 단계입니다. 
함수 정의는 함수의 이름, 반환 형식 및 매개 변수 목록을 포함하여 함수의 구조를 정의하는 것을 의미합니다. 이것은 C 언어에서 필요한 사전 작업입니다.

함수 정의를 통해 프로그램은 컴파일러에게 함수가 무엇을 수행해야 하는지에 대한 정보를 제공합니다. 이로써 함수를 호출하는 부분에서 함수의 이름과 인수를 사용할 수 있게 됩니다.

다음은 C 언어에서 함수 정의의 예제입니다:

```c
int add(int a, int b) {
    int result = a + b;
    return result;
}
```

위의 코드에서 `add` 함수는 두 개의 정수를 인수로 받아서 더하고, 그 합을 반환하는 함수입니다. 
이 함수의 정의를 먼저 프로그램에 포함해야 합니다. 그러면 프로그램의 다른 부분에서 `add` 함수를 호출할 수 있습니다.

함수 정의를 선행하는 것은 프로그램의 가독성을 높이고 코드를 모듈화하며, 함수를 호출하는 부분에서 함수의 이름을 사용해 원하는 작업을 수행할 수 있도록 합니다. 함수를 정의하지 않고 사용하면 컴파일러는 함수가 어떻게 작동하는지 알 수 없으므로 컴파일 오류가 발생할 것입니다.

## 함수가 다른 함수를 부르는 경우

함수가 다른 함수를 호출하는 것은 프로그램에서 일반적인 구조 중 하나입니다. 이것은 함수를 모듈화하고 코드를 더 효율적으로 구성하며 재사용성을 향상시키는 데 도움이 됩니다. C 언어 및 다른 프로그래밍 언어에서 함수 간의 호출은 다음과 같이 이루어집니다.

1. 함수 정의: 먼저 함수를 정의합니다. 함수 정의는 함수의 이름, 반환 자료형, 매개변수 목록 및 함수의 내용을 포함합니다. 예를 들어:

   ```c
   int add(int a, int b) {
       return a + b;
   }
   ```

   이 함수는 두 정수를 더하고 결과를 반환합니다.

2. 함수 호출: 함수가 다른 함수를 호출하는 경우, 함수 이름과 필요한 인수를 사용하여 호출됩니다.
3. 예를 들어, 다음은 `add` 함수를 호출하는 코드입니다.

   ```c
   int result = add(5, 7);
   ```

   이 호출은 `add` 함수를 호출하고, 인수로 5와 7을 전달하여 결과를 계산하고 `result` 변수에 저장합니다.

4. 함수 반환: 호출된 함수가 작업을 완료하면, 그 결과가 호출한 함수로 반환됩니다. 이것은 함수 호출 위치에서 해당 결과를 사용하거나 다른 작업에 활용할 수 있게 합니다.

아래는 함수 간 호출의 예제 코드입니다. 여기서 `add` 함수가 `multiply` 함수를 호출하여 두 수의 곱을 계산한 다음, 그 결과를 반환합니다.

```c
#include <stdio.h>

int multiply(int x, int y) {
    return x * y;
}

int add(int a, int b) {
    int result = multiply(a, b); // multiply 함수 호출
    return result;
}

int main() {
    int x = 5;
    int y = 7;
    int sum = add(x, y); // add 함수 호출
    printf("합계: %d\n", sum);

    return 0;
}
```

이 코드에서 `add` 함수는 `multiply` 함수를 호출하여 곱셈 작업을 수행하고, 그 결과를 반환합니다. 
함수 호출을 통해 다른 함수들 간에 작업을 조합하고 조직할 수 있으며, 코드의 가독성과 유지보수성을 향상시키는 데 도움이 됩니다.