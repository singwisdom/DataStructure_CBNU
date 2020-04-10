#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5]; // 배열 list 선언, 인덱스 총 5개
    int *plist[5]; // 포인터 배열 plist 선언, 인덱스 총 5개

    list[0]=10; // list 0번 인덱스에 값 10 저장
    list[1]=11; // list 1번 인덱스에 값 11 저장 

    plist[0]=(int *)malloc(sizeof(int)); //plist 0번 인덱스에 힙 영역에서 할당받은 메모리 주소 저장 

    printf("---------[신지혜]-----[2018038029]--------\n\n");
    printf("list[0] \t = %d\n",list[0]); // list 0번 인덱스의 값 출력 = 10
    printf("address of list \t= %p\n",list); // list의 주소 출력 
    printf("address of list[0] \t= %p\n",&list[0]); // list 0번 인덱스의 주소 출력 =(list의 주소와 동일)
    printf("address of list + 0 \t= %p\n",list+0); // list+0의 주소 출력 (=list[0]의 주소와 동일)
    printf("address of list + 1 \t= %p\n",list+1); // list+1의 주소 출력 (=list[1]의 주소와 동일)
    printf("address of list + 2 \t= %p\n",list+2); // list+2의 주소 출력 (=list[2]의 주소와 동일)
    printf("address of list + 3 \t= %p\n",list+3); // list+3의 주소 출력 (=list[3]의 주소와 동일)
    printf("address of list + 4 \t= %p\n",list+4); // list+4의 주소 출력 (=list[4]의 주소와 동일) 
    printf("address of list[4] \t= %p\n",&list[4]); // list[4]의 주소 출력 (=list+4의 주소와 동일)

    // list 의 인덱스 번호를 키워가며 해당 주소를 출력하면, 주소 값이 4바이트씩 커지는 것을 알 수 있다.
    // (= 배열이 int 형식이기 때문)

    free(plist[0]); // 힙 영역에서 할당받은 메모리 해제
}