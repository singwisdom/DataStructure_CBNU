#include <stdio.h>
#define MAX_SIZE 100 // MAX_SIZE의 값을 100으로 선언
float sum(float list[],int); // 함수 sum 선언
float input[MAX_SIZE],answer; // float형 배열 input, 변수 answer 선언
int i; // int형 타입 변수 i선언

void main(void)
{
    printf("--------[신지혜]-----[2018038029]-------\n\n");
    
    for(i=0;i<MAX_SIZE;i++) // i=0부터 i<100까지 i가 1씩 증가하는 반복문 
        {input[i]=i;} // 배열 input 인덱스 i번째에 값 i를 저장한다. 
    
    printf("address of input = %p\n",input); // 배열 input의 주소 출력
   
    answer=sum(input,MAX_SIZE); // sum 함수를 호출해서 answer값에 저장한다. 
    // input, 즉 배열의 이름은 배열의 주소이다. 따라서 배열의 주소가 sum 함수의 list에 복사된다.
    printf("The sum is : %f\n",answer); // answer의 값 출력 
}

float sum(float list[],int n) // 함수 sum 정의 
{
    printf("value of list = %p\n",list); // 배열 list의 값 출력 =(list의 주소와 동일)
    printf("address of list = %p\n\n",&list); // 배열 list의 주소 출력
    
    int i; // int 형 변수 i 선언
    float tempsum=0; // float형 변수 tempsum 선언
    for(i=0;i<n;i++) 
    // i는 0부터 i<n까지 i가 1씩 증가하는 반복문 (위에서 n이 MAX_SIZE를 받으므로 i<100까지)
        tempsum+=list[i]; // tempsum = tempsum + list[i] (= tempsum의 값과 list 인덱스 i번째 값을 더함)

    return tempsum; // tempsum의 값을 리턴해준다. 
}