#include <stdio.h>  //. prinf(), scanf(), sprintf(), _getch(), _getche(), gets(), puts() , stdlen()
#include <stdlib.h>  //. _countof(), malloc(), free()
#include <string.h>  //. memset()
// #include <conio.h>  //. _getch(), _getche()에 대한 선언 포함. 현재는 stdio.h에도 포함되어 있음.

void main(void)
{
	//. p.335
	char* psz_data = "1234";
	char sz_buffer[16] = { 0 };

	printf("Input password: ");

	gets(sz_buffer);

	if (memcmp(psz_data, sz_buffer, 4) == 0) {
		puts("Success!");
	}
	else {
		puts("Failure!");
	}
		
	// memcmp()의 첫번째 인작값이 크면 양수(+1), 두번째 인자 값이 크면 음수(-1), 같으면 0
	printf("%d\n", memcmp(psz_data, sz_buffer, 4));




	//. p.333
/*	char* psz_data = "TEST STRING~";
	int n_data = 0;

	memcpy(&n_data, psz_data, 3);

	printf("%s", (char*)&n_data)*/;
	/* n_data는 int형으로 4바이트 크기. 4바이트를 복사하면 메모리가['T', 'E', 'S', 'T']로 꽉 차게 됨.
	처음에 int n_data = 0; 으로 만들어두었던 0x00(널 문자)이 'T'로 덮어씌워져 사라짐.
	%s 포맷은 메모리를 순서대로 읽으면서 널 문자(0x00)를 만나야만 출력을 멈춤.
	n_data의 4바이트(TEST)를 모두 출력한 후에도 출력을 멈추지 않고,
	n_data 변수 공간을 넘어선 그다음 메모리 주소에 있는 값들까지 문자로 해석해서 화면에 출력.
	그러다 우연히 0x00을 만나면 그제서야 출력을 멈춤. */


	//. +a 글자 크기 늘어날 수록 재할당
	//char* psz_data = NULL;
	//int capacity = 1; // 처음에 임의로 잡은 방의 크기 (1칸)
	//int length = 0;    // 실제 입력된 글자 수
	//char ch;

	//// 1. 우선 처음에는 1칸만 먼저 빌려 공간을 만들어둠
	//psz_data = (char*)malloc(sizeof(char) * capacity);

	//if (psz_data == NULL) {
	//	printf("메모리 할당 실패!\n");
	//	return 1;
	//}

	//printf("문자열을 입력하세요 (엔터를 치면 입력이 끝납니다):\n");

	//// 2. 한 글자씩(getchar) 실시간으로 읽어오기
	//while ((ch = getchar()) != '\n' && ch != EOF) {

	//	// 3. 만약 입력받은 글자 수가 방 크기(capacity)보다 커지려고 하면?
	//	if (length >= capacity - 1) {
	//		capacity *= 2; // 방 크기를 2배로 늘리겠다고 계획함 (10 -> 20 -> 40...)

	//		// realloc으로 기존 메모리 데이터는 그대로 유지하면서 크기만 확장!
	//		char* p_temp = (char*)realloc(psz_data, sizeof(char) * capacity);

	//		if (p_temp == NULL) {
	//			printf("메모리 재할당 실패!\n");
	//			free(psz_data); // 실패했더라도 기존 메모리는 지워줘야 해
	//			return 1;
	//		}
	//		psz_data = p_temp; // 안전하게 늘어난 새 주소로 업데이트
	//	}

	//	psz_data[length++] = ch; // 늘어난 공간에 글자를 차곡차곡 넣음
	//}

	//// 4. C언어 문자열의 끝을 알리는 '마침표' 역할의 널 문자(\0)를 꼭 넣어줘야 해
	//psz_data[length] = '\0';

	//// 5. 결과 출력
	//printf("\n[입력된 문자열 출력]\n");
	//puts(psz_data);

	//// 6. 다 썼으면 빌렸던 메모리 반납!
	//free(psz_data);

	//return 0;


	//. p.320
	//char* psz_data = NULL;
	//int n_input = 0;

	//printf("Input length: ");
	//scanf_s("%d", &n_input);
	//psz_data = (char*)malloc(sizeof(char) * n_input);

	////fflush(stdin);    //. 입력 버퍼를 비울 때 역할 안됨. 대신 아래와 같이 while문을 이용해서 입력 버퍼 비움.
	//while (getchar() != '\n'); 
	//gets(psz_data);
	//puts(psz_data);

	//free(psz_data);


	//. p.311
	//int n_data = 10;

	//void* psz_string = "Test string!";
	//void* pfn_main = main;
	//void* pn_number = &n_data;

	//printf("%s\n", psz_string);
	//printf("%c\n", psz_string);  //. psz_string에는 문자 2가 입력된 주소가 값으로 들어가 있음.주소를 % c 아스키 문자로 해석하려니 예상 못하는 문자라 나옴.
	//printf("%c\n\n", *(char*)psz_string);  //. void형으로 선언된 포인터 변수를 형변환하여 출력하면 예상한 값 출력

	////printf("%d\n", *pn_number);  //. *pn_number는 void형이므로 여기의 주소의 값을 int로 해석하지 않음. 컴파일 오류 발생.
	//printf("%d\n\n", *(int*)pn_number);

	////printf("%c\n", *(psz_string + 1);  //. void형이므로 psz_string을 얼마만큼의 자료형 크기만큼 옵셋 해야 할지 모름. 컴파일 오류 발생.
	//printf("%c\n", *((char*)psz_string + 1));  //. %c는 값을 아스키 코드로 변환하여 출력.
	//printf("%s\n\n", (char*)psz_string + 1);  //. %s는 값을 주소로 보고 해당 주소에 있는 값을 \0이 나올 때까지 출력.
	////printf("%s\n\n", *(char*)psz_string + 1);  //. 바로 전 줄의 주석 처리 내용에 의해 *를 붙이면 char 사이즈 1만큼 옵셋 된 주소에 있는 값을 %s에 의해 다시 주소로 본다. 정상 작동 안하게 됨.


	//. p.310
	//char* psz_data = "1234 67890!";

	//printf("%s\n", psz_data);
	//printf("%s\n", psz_data++);
	//printf("%s\n", psz_data);

	//printf("%c\n", psz_data);  //. 앞에서 psz_data++에 의해 psz_data에는 문자 2가 입력된 주소가 값으로 들어가 있음. 주소를 %c 아스키 문자로 해석하려니 예상 못하는 문자라 나옴.
	//printf("%c\n", *psz_data);
	//printf("%c\n", *psz_data++);
	//printf("%c\n", *--psz_data);

	//printf("%c\n", (*psz_data) + 3);
	//printf("%c\n", *psz_data + 3); //. +연산보다 *(간접지정) 연산이 우선순위가 더 높기 때문에 괄호는 효과 없지만, 가독성을 위해 하는 편이 좋음.


	//. p.306
	//char* psz_list[3] = { "Test", "String", "Data" };
	//char** ppsz_list = psz_list;

	//char sz_buffer[32] = { "TestString" };
	//char* psz_buffer = sz_buffer;

	//printf("%c\n", **psz_list);  //. 배열 선언 자체가 1중 포인터로 선언과 의미 같음. 따라서 2중 포인터로 값을 출력 가능.
	//printf("%c\n", *psz_list);  //. psz_list[0]에 값으로 들어 있는 주소 자체를 %c인 아스키 코드로 해석해서 이상한 글자 나옴.
	//printf("%c\n", *psz_list[1]);
	//printf("%c\n", *psz_buffer);

	//printf("%s\n", psz_list[0]);
	//printf("%s\n", *(ppsz_list + 1));



	//. +a
	//char* psz_data = "Test...!!!";

	////printf("s: %s", *psz_data);
	//printf("c: %c\n", *psz_data);
	//printf("c: %c\n\n", *(psz_data+2));


	//. p.298
	//int* pn_data = NULL;
	//pn_data = (int*)malloc(sizeof(int) * 4);
	//memset(pn_data, 0, sizeof(int) * 4);

	//*(pn_data) = 10;
	//*(pn_data + 1) = 20;

	//printf("pn_data: %d\n", *(pn_data));
	//printf("pn_data + 1: %d\n\n", *(pn_data + 1));

	//free(pn_data);  //. malloc()로 동적으로 받은 메모리 반환

	//. p.295
	//char szName[16] = { 0 };
	//char* pszName = szName;

	//sprintf_s(pszName, sizeof(szName), "%s", "Centaucyan");
	//puts(szName);


	//. p.294
	//char* psz_data = "Test string!";

	//printf("%zu\n", sizeof(psz_data));
	//printf("%zu\n", sizeof(*psz_data));
	//printf("\n");
	//printf("%zu\n", sizeof(psz_data + 1));  //. *psz_data는 char로 선언되어 있으므로 주소 번지 1 증가. 64비트 시스템에서는 64비트로 주소 저장.
	//printf("%zu\n", sizeof(*psz_data + 1));  //. *psz_data는 char로 선언되어 있으므로 1바이트 이지만 뒤에 int 연산으로 인해 int로 승격된다.
	//printf("%zu\n", sizeof(*(psz_data + 1)));
	//printf("\n");
	//printf("%c\n", (*psz_data + 1));  //. *psz_data는 'T'이며 이것의 아스키코드 값은 84. 여기에 1을 더해 85인 아스키코드 값은 'U'이다.

	//. p.285
	//int n_data = 10;
	//int* pn_data = &n_data;

	//printf("n_data value: %d, pn_data point_value: %d\n", n_data, *pn_data);
	//printf("n_data addr: %p, pn_data value: %p\n\n", &n_data, pn_data);

	//*pn_data = 60;
	//printf("=== After change *pn_data ===\n");
	//printf("n_data value: %d, pn_data point_value: %d\n\n", n_data, *pn_data);

	//n_data = 100;
	//printf("=== After change n_data ===\n");
	//printf("n_data value: %d, pn_data point_value: %d\n\n", n_data, *pn_data);
}