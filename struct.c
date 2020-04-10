#include <stdio.h>

struct student1{ // 구조체 student1 정의
    char lastName; 
    int studentId;
    char grade;
};

typedef struct { // typedef를 이용한 구조체 student2 정의
    char lastName;
    int studentId;
    char grade;
} student2;

int main()
{
    struct student1 st1 = {'A',100,'A'}; // 구조체 변수 st1선언 후 각각의 변수에 값 저장

    printf("-----[신지혜]-----[2018038029]-----\n");
    printf("st1.lastName = %c\n",st1.lastName); // st1.lastName에 저장 되어있는 값 출력 = A
    printf("st1.studentId = %d\n",st1.studentId); // st1.studentId에 저장 되어있는 값 출력 = 100
    printf("st1.grade = %c\n",st1.grade); // st1.grade에 저장 되어있는 값 출력 = A

    student2 st2 = {'B',200,'B'}; // 구조체 변수 st2 선언 후 각각의 변수에 값 저장

    printf("\nst2.lastName = %c\n",st2.lastName); // st2.lastName에 저장 되어있는 값 출력 = B
    printf("st2.studentId = %d\n",st2.studentId); // st2.studentId에 저장 되어있는 값 출력 = 200
    printf("st2.grade = %c\n",st2.grade); // st2.grade에 저장 되어있는 값 출력 = B

    student2 st3; // 구조체 student2의 변수 st3 선언
    st3=st2; // st2를 변수 st3에 대입한다. (구조체 st2에 저장되어있는 값들을 st3에 대입)

    printf("\nst3.lastName = %c\n",st3.lastName); // st3.lastName에 저장 되어있는 값 출력 = B
    printf("st3.studentId = %d\n",st3.studentId); // st3.studentId에 저장 되어있는 값 출력 = 200
    printf("st3.grade = %c\n",st3.grade); // st3.grade에 저장 되어있는 값 출력 = B

    /* equality test */
    /*if(st3==st2) 
    printf("equal\n");
    else  
    printf("not equal\n");
    */
    return 0;

}