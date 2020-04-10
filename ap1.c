#include <stdio.h>
#include <stdlib.h>
void main()
{
    int list[5]; // 배열 list 선언 
    int *plist[5]={NULL,}; //  포인터 배열 plist 선언 및 null값으로 초기화
    plist[0]=(int *)malloc(sizeof(int)); // plist의 인덱스 0번에 힙 영역에서 동적 메모리를 할당 받은 주소 저장

    list[0]=1; // list 배열의 인덱스 0번에 1 저장
    list[1]=100; // list 배열의 인덱스 1번에 100 저장

    *plist[0]=200; // plist 0번이 가리키고 있는 주소의 값에 200을 저장

    printf("--------[신지혜]------[2018038029]-------\n\n");

    printf("value of list[0] = %d\n",list[0]); // list 인덱스 0번에 저장 되어있는 값 출력 = 1
    printf("address of list[0]       =%p\n",&list[0]); // list 인덱스 0번의 주소 출력
    printf("value of list            =%p\n",list); // list 배열의 값 출력 (배열의 이름 = 인덱스 0번의 주소와 동일)
    printf("address of list (&list)  =%p\n",&list); // list 배열의 주소 출력 

    printf("----------------------------------------\n\n");
    printf("value of list[1]   = %d\n",list[1]); // list 인덱스 1번에 저장 되어있는 값 출력 = 100
    printf("address of list[1] = %p\n",&list[1]); // list 인덱스 1번의 주소 출력
    printf("value of *(list+1) = %d\n",*(list+1)); // list 인덱스 1번에 저장 되어있는 값 출력(=list[1]) = 100
    printf("address of list+1  = %p\n",list+1); // list+1의 주소 출력 (= &list[1])

    printf("----------------------------------------\n\n");
    printf("value of *plist[0]  = %d\n",*plist[0]); // plist 인덱스 0번에 저장 되어있는 값 출력 = 200
    printf("&plist[0]           = %p\n",&plist[0]); // plist 인덱스 0번의 주소 출력
    printf("&plist              = %p\n",&plist); // plist 배열의 주소 출력 = (0번째의 주소와 동일)
    printf("plist               = %p\n",plist); // plist의 값 출력 (= 배열의 주소와 동일) , 배열 이름 = 배열 주소
    printf("plist[0]            = %p\n",plist[0]); // plist 인덱스 0번에 저장 되어있는 값 출력 (=메모리 주소 출력)
    printf("plist[1]            = %p\n",plist[1]); // plist 인덱스 1번에 저장 되어있는 값 출력 (=null)
    printf("plist[2]            = %p\n",plist[2]); // plist 인덱스 2번에 저장 되어있는 값 출력 (=null)
    printf("plist[3]            = %p\n",plist[3]); // plist 인덱스 3번에 저장 되어있는 값 출력 (=null)
    printf("plist[4]            = %p\n",plist[4]); // plist 인덱스 4번에 저장 되어있는 값 출력 (=null)

    free(plist[0]); // 동적으로 받은 메모리 해제
   

}