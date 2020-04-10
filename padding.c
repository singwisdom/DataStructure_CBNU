#include <stdio.h>

struct student { // 구조체 student 정의
    char lastName[13];
    int studentId;
    short grade;
};

int main()
{
    struct student pst; // 구조체 student 변수 pst선언

    printf("-----[신지혜]---[2018038029]-----\n\n");
    printf("size of student = %ld\n",sizeof(struct student)); // sizeof 연산자 함수를 이용한 구조체 크기 출력
    // char 13byte + int 4byte + short 2byte  = 19byte 이지만, 남는 공간을 채우면(패딩) 총 24byte가 된다.
    printf("size of int = %ld\n",sizeof(int)); // int형의 크기 출력 = 4
    printf("size of short = %ld\n",sizeof(short)); // short형의 크기 출력 = 2

    return 0;
}