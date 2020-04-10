#include <stdio.h>
#include <stdlib.h>

void main()
{
    int **x; // 더블포인터 변수 x 선언

    printf("-----[신지혜]-----[2018038029]------\n\n");

    printf("sizeof(x) = %lu\n",sizeof(x)); // x의 값 출력 = 8 (주소를 저장하기 때문)
    printf("sizeof(x) = %lu\n",sizeof(*x)); // *x의 값 출력 = 8 (주소를 저장하기 때문)
    printf("sizeof(x) = %lu\n",sizeof(**x)); // **x의 값 출력 = 4 (int형 값이기 때문)
    // 64bit에서 주소를 저장하는 포인터의 크기는 8바이트가 된다. 
}