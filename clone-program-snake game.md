* 화면 설계서
![KakaoTalk_20231120_232121322](https://github.com/younsonx/MyTIL/assets/144593956/0b5c0d5c-76f3-4e05-87df-398a2eed0d96)
![KakaoTalk_20231120_232121322_01](https://github.com/younsonx/MyTIL/assets/144593956/a2be76bb-be3c-4926-a02e-29f330971947)
![KakaoTalk_20231120_232121322_02](https://github.com/younsonx/MyTIL/assets/144593956/5d41a1c8-0245-42ce-9098-c10899734464)
![KakaoTalk_20231120_232121322_03](https://github.com/younsonx/MyTIL/assets/144593956/eb183106-acd9-476e-9ddc-9b445f91bda1)

우선 오류가 두가지 발생하였는데  
1. Instead, use the ISO C and C++ conformant name:  관련 오류와
2. This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.  
오류가 발생하였다
```
이것은 C++ 프로그래밍 언어에서 발생하는 오류 메시지입니다.
이 오류는 'kbhit' 함수에 대한 경고로, 해당 함수가 POSIX(Portable Operating System Interface) 표준의 이름이 아니라고 알려주며, 대신 ISO C 및 C++ 표준에 따른 이름인 '_kbhit'를 사용하라고 권고하고 있습니다.
```
이와 같은 경고를 무시하기 위해 
```cpp
#pragma warning(disable: 4996)
// 코드 작성
```
```
C++ 컴파일러에서 경고를 무시하도록 지시하는 방법이 있습니다. 일반적으로는 경고를 무시하기 위해 특정 경고를 끄는 컴파일러 지시문 또는 프리프로세서 디렉티브를 사용할 수 있습니다.

경고를 무시하기 위해선 #pragma warning 디렉티브를 사용할 수 있습니다. 다음은 Visual Studio 컴파일러에서 해당 경고를 무시하는 방법입니다.
```
또한
```cpp
#define _CRT_SECURE_NO_WARNINGS
```
를 선언하여 두가지 경고를 무시하였다.  
또한 처음보는 헤더파일이 등장하여 이에대한 공부 해야겠다.  
```cpp
아래는 주어진 코드에서 사용된 헤더 파일들에 대한 간단한 설명입니다.

1. **`<conio.h>`**: "Console Input and Output"의 약자로, 콘솔 기반의 입출력을 위한 함수들을 포함하고 있습니다. `getch()`나 `clrscr()`와 같은 함수들이 주로 사용됩니다.
하지만, `<conio.h>`는 표준 C 또는 C++의 공식 표준 헤더 파일이 아니므로, 특정 컴파일러에서만 지원되거나 특정 운영 체제에서만 사용 가능할 수 있습니다.

2. **`<time.h>`**: 시간과 관련된 함수들을 정의하는 표준 C 라이브러리 헤더 파일입니다. `time()` 함수와 같은 시간과 관련된 함수들을 제공합니다. 현재 시간을 얻거나 시간을 조작하는 데 사용됩니다.

3. **`<ctype.h>`**: 문자 처리 함수들을 포함하는 표준 C 라이브러리 헤더 파일입니다. 주로 문자가 알파벳인지, 숫자인지, 대문자인지, 소문자인지 등을 판별하는 함수들이 있습니다.

4. **`<windows.h>`**: Microsoft Windows 운영 체제에서 시스템 함수와 데이터 구조를 포함하는 헤더 파일입니다. 윈도우 API 함수들을 사용하여 윈도우 프로그래밍을 할 때 필요한 여러 함수와 상수들을 제공합니다.

5. **`<process.h>`**: 프로세스와 관련된 함수들을 정의하는 표준 C 라이브러리 헤더 파일입니다. 프로세스 생성, 종료, 제어 등과 관련된 함수들을 제공합니다.

헤더 파일은 프로그램에서 특정 기능이나 라이브러리를 사용하기 위한 함수들을 정의하고 선언하는 역할을 합니다. 각 헤더 파일에는 관련된 함수들이나 상수들이 정의되어 있으며, 프로그램에서 이러한 기능들을 사용하기 위해서는 해당 헤더 파일을 포함시켜야 합니다.
```
1. conio.h  
[google] https://marinelifeirony.tistory.com/49

2. time.h  
[google] https://modoocode.com/108  
[google] https://scvtwo.tistory.com/186#google_vignette

3. ctype.h  
[google] https://marinelifeirony.tistory.com/48

4. process.h  
[google] https://ko.wikipedia.org/wiki/Process.h

* 논리구조  
 메인 함수
1. 게임 화면과 게임 설명을 보여주는 첫 화면 출력 
2. 화면을 삭제한 뒤 로딩하는 화면 출력 
3. 게임보드 출력하는 함수 호출 
4. 기본적인 지렁이 생성 
5. 게임 화면 내에 먹이를 생성하기 
6. 먹이를 처리하는 함수를 통해 먹이를 먹었을경우(뱀의 머리와 먹이의 위치와 같을때)뱀의 길이를 1만큼 증가시키고, 새로운 먹이를 생성한다. 초기먹이 생성: food.x==0은 아직 초기 먹이가 생성되지 않은것을 나타냄 먹이 좌표를 랜덤하게 설정하여 초기 먹이를 생성
7. 목숨과 뱀의 머리를 생성 
8. 뱀의 이동, 먹이생성, 게임종료, 키 입력 처리하는 함수 호출하여 뱀 게임 진행
