# Study_C
* Update: 2026.08.31

## 1. Description
* C 언어 Self-study
* Book: 최호성의 C 프로그래밍
* Tool: Visual Studio 2022
---

## 2. Study Content
### Chapter 03
* double, float, long, int, sizeof

### Chapter 04
* getchar(void), putchar(int char), gets(*buffer), puts(*buffer) 
* %c, %s 
* %d, %f, %p
* %o, %x, %X, %e, %E
* 변수 선언 시 *name과 &name 차이
* printf("형식문자", 가변인자), scanf_s("형식문자", 메모리주소)

### Chapter 05
* 산술 연산자: +, -, *, /, %
* 형변환 연산자: (자료형) 피변환자
* 단순/복합 대입 연산자: =, +=, -=, >>=, |= 등등
* 비트 연산자: &, |, ^, ~, <<, >>
* Mask 연산: ex => 0xffff0000과 & 연산
* 단항 증감 연산자 
    * 전위 연산: ++a, --a
    * 후위 연산: a++, a--

### Chapter 06
* 관계 연산자: >, <, >=, <=, ==, !=
* 논리 연산자: &&, ||, !A
* &&, || 에서의 연산 생략
* sizeof 연산자: 차지 메모리를 byte 단위로 알림
* 조건식 ? A:B

### Chapter 07
* if
* switch/case/[default]: switch 식의 결과값은 정수(char, int, short)계열만 가능
    * case의 break;를 만날때까지, 또는 default의 ;을 만날때까지 순차적 실행
* goto 레이블;

### Chapter 08
* while, do/while
* for
* break, continue: 가장 가까운 반복문에 영향

### Chapter 09
* *(pointer)
* Pointer offset
* malloc(메모리 크기): stdlib.h에 정의
* memset(시작 메모리, 초기화 할 값, 초기화 할 만큼의 byte): stling.h에 정의
* memcpy(to 메모리 주소, from 메모리 주소, 복사할 만큼의 byte)
* memcmp(원본 메모리 주소, 비교할 메모리 주소, 비교할 만큼의 byte): 두 메모리의 값이 같으면 0, 원본이 크면 1, 작으면 -1을 반환
* char* psz_list[3] = { "Test", "String", "Data" }; printf("%c\n", **psz_list);
    * psz_list[3]으로 선언이 1중 포인터 선언과 같은 의미.
    * 따라서 printf로 **psz_list로 출력 시 psz_list[0]의 주소값 한 글자만 출력됨.
* %c는 대입되는 값을 아스키 코드로 변환해서 출력
* %s는 대입되는 값을 주소로 보고 그 주소에 있는 값을 \0이 나올때까지 아스키 코드로 변환하여 출력
* 함수나 배열의 이름은 모두 메모리 주소
* malloc(), calloc(), free(), realloc()
---