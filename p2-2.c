#include <stdio.h>
void print1(int *ptr, int rows); // pirnt1 함수 선언 

int main()
{
    int one[]={0,1,2,3,4}; // 배열의 인덱스가 총 5개인 one 선언 및 초기화
    
    printf("------[신지혜]------[2018038029]------\n\n");
    printf("one      = %p\n",one); // 배열 one의 값 출력 (= 배열 one의 주소 출력)
    printf("&one     = %p\n",&one); // 배열 one의 주소 출력
    printf("&one[0]  = %p\n",&one[0]); // 배열 one 인덱스 0번의 주소 출력 (= 배열 one의 주소 출력)

    print1(&one[0],5); // print1 함수 호출
    // 포인터 ptr이 배열 one의 주소를 가리킨다, rows=5에 대응.

    return 0;
}
// 
void print1(int *ptr,int rows) // print1 함수 정의 
{
    int i; // int형 변수 i 선언 
    printf("address  \t Contents\n"); // address Contents 라는 화면 출력
    for(i=0;i<rows;i++) // i=0 부터 i<rows까지 i는 1씩 증가 (여기서 rows는 5)
    {
        printf("%p \t %5d\n",ptr+i,*(ptr+i)); 
        // ptr+i 의 주소(=ptr[i]의 주소) 및 ptr+i의 주소에 있는 값 출력 (ptr[i]에 저장 되어있는 값 출력)
        // 함수를 호출하게 되면 one[i]의 주소와 one[i]에 값을 출력하게 된다.
    printf("\n"); // 줄바꿈 문자 출력
    }
}