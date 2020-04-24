/*
 * circularQ.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4 // MAX_QUEUE_SIZE의 값을 4로 정의

typedef char element; // 자료형 char을 element로 정의(별명과 비슷한 개념)
typedef struct { // 구조체 QueueType 선언
	element queue[MAX_QUEUE_SIZE]; // char형 배열 queue 선언
	int front, rear; // int형 변수 front, rear 선언
}QueueType;


QueueType *createQueue(); // 원형큐를 만드는 함수 정의
int isEmpty(QueueType *cQ); // 원형큐가 비었는지 검사하는 함수
int isFull(QueueType *cQ); // 원형큐가 다 찼는지 검사하는 함수
void enQueue(QueueType *cQ, element item); // 큐에 원소를 삽입하는 함수
void deQueue(QueueType *cQ, element* item); // 큐의 원소를 삭제하는 함수
void printQ(QueueType *cQ); // 큐의 원소들을 출력하는 함수
void debugQ(QueueType *cQ); // 큐의 상태를 보여주는 함수

element getElement(); // 사용자에게 원소를 입력받는 함수


int main(void)
{
	QueueType *cQ = createQueue(); // 원형큐를 생성하는 함수 호출
	element data; // char형 변수 data 선언

	char command; // char형 변수 command 선언

	printf("\n--------------[신지혜]---------[2018038029]----------\n"); // 이름과 학번 출력
	do{
		printf("\n-----------------------------------------------------\n"); // 원형큐 메뉴 출력
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = "); // 사용자에게 명령을 입력받는 메세지 출력
		scanf(" %c", &command); // 사용자에게 명령을 입력받음

		switch(command) { // 입력받은 명령어에 따라 수행이 달라지는 조건문
		case 'i': case 'I': // i 혹은 I를 입력받으면
			data = getElement(); // 원소를 입력받는 함수를 호출하여 변수 data에 저장
			enQueue(cQ, data); // 원형큐에 변수 data 값을 저장한다.
			break; // 조건문 탈출
		case 'd': case 'D': // d 혹은 D를 입력받으면
			deQueue(cQ,&data); // 원형큐에서 원소를 삭제하는 함수 호출
			break; // 조건문 탈출
		case 'p': case 'P': // p 혹은 P를 입력받으면
			printQ(cQ); // 원형큐 배열의 원소들을 출력하는 함수 호출
			break; //  조건문 탈출
		case 'b': case 'B': // b 혹은 B를 입력받으면
			debugQ(cQ); // 현재 원형큐의 상태를 보여주는(배열의 인덱스 값들, front,rear의 위치) 함수 호출
			break; // 조건문 탈출
		case 'q': case 'Q': // q 혹은 Q를 입력받으면 (종료)
			break; // 조건문 탈출
		default: // 그 외의 값들을 입력받으면 
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // 해당 문구 출력
			break; // 조건문 탈출
		}

	}while(command != 'q' && command != 'Q'); // q나 Q의 값을 입력받기 전까지 계속 반복문 실행


	return 1;
}


QueueType *createQueue() // 원형큐를 생성하는 함수
{
	QueueType *cQ; // 포인터 cQ를 선언한다
	cQ = (QueueType *)malloc(sizeof(QueueType)); //  QueueType 사이즈 만큼의 메모리 크기를 동적할당 받는다
	cQ->front = 0; // front값을 0으로 초기화
	cQ->rear = 0; // rear 값을 0으로 초기화
	return cQ; // cQ를 반환값으로 리턴
}

element getElement() // 사용자에게 원소를 입력받는 함수 
{
	element item; // char형 변수 item 선언
	printf("Input element = "); // 원소를 입력하라는 문구 출력
	scanf(" %c", &item); // 원소를 입력받는다
	return item; // 입력받은 원소값을 리턴
}


/* complete the function */
int isEmpty(QueueType *cQ) // 원형큐가 비었는지 검사하는 함수
{ 
	if(cQ->front==cQ->rear) // 원형큐의 front값과 rear값이 같다면(=원형큐가 비어있음)
	return 1; // 1을 반환한다

	else return 0; // 그렇지 않다면 0을 반환한다
}

/* complete the function */
int isFull(QueueType *cQ) // 원형큐가 꽉 찼는지 검사하는 함수
{
  if(cQ->front==((cQ->rear+1)%MAX_QUEUE_SIZE)) // 원형큐의 front값과 (rear+1)%4의 값이 같다면(원형큐가 가득 참)
  return 1; // 1을 반환한다

  else return 0; // 그렇지 않다면 0을 반환한다
}


/* complete the function */
void enQueue(QueueType *cQ, element item) // 원형큐에 원소를 삽입하는 함수
{
	if(isFull(cQ)==1) // isFull 함수의 결과값이 1이면 (원형큐가 가득 찼다면)
	printf("큐가 꽉 찼습니다."); // 가득찼다는 문구 출력
	else // 가득 안 찼다면
	{
		cQ->rear=((cQ->rear+1)%MAX_QUEUE_SIZE); // rear값을 (rear+1)%4로 바꾼다
		cQ->queue[cQ->rear]=item; // rear값에 해당하는 인덱스에 입력받은 원소를 대입한다
	}
	
}

/* complete the function */
void deQueue(QueueType *cQ, element *item) // 원형큐에 원소를 빼내는 함수
{
    if(isEmpty(cQ)==1) //isEmpty 함수의 결과값이 1이면 (원형큐가 이미 비어있다면)
	printf("큐가 이미 비어있습니다."); // 큐가 비어있다는 문구 출력
	else // 큐가 비어있지 않다면
	{
		*item=cQ->queue[cQ->front]; // front가 위치한 배열의 인덱스 값을 item 포인터에 역참조한다
		cQ->front=((cQ->front+1)%MAX_QUEUE_SIZE); // front의 값을 (front+1)%4로 바꾼다
		
	}
	
}


void printQ(QueueType *cQ) // 원형큐 배열의 원소들을 출력하는 함수
{
	int i, first, last; // 변수 선언

	first = (cQ->front + 1)%MAX_QUEUE_SIZE; // 1번째 값 의 위치 = (front+1)%4의 위치
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE; // 마지막 값의 위치 = (rear+1)%4의 위치

	printf("Circular Queue : ["); // 원형큐 배열의 원소들을 출력하는 문구

	i = first; // first의 값을 i값에 대입
	while(i != last) // i와 last의 값이 같지 않다면 계속 반복
	{
		printf("%3c", cQ->queue[i]); // 원형큐의 원소를 출력한다.
		i = (i+1)%MAX_QUEUE_SIZE; // i값을 (i+1)%4로 바꾼다

	}
	printf(" ]\n"); // 반복문 끝나면 해당 문구 출력
}


void debugQ(QueueType *cQ) // 현재 원형큐의 진행상황을 출력 하는 함수
{

	printf("\n---DEBUG\n"); // 해당 문구 출력
	for(int i = 0; i < MAX_QUEUE_SIZE; i++) // i는 0부터 3까지 1씩 증가하며 반복문을 반복한다
	{
		if(i == cQ->front) // i값이 원형큐의 front값과 같다면
		{ 
			printf("  [%d] = front\n", i); // front값은 i라고 출력한다
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]); // front값과 같지 않다면, 큐의 i번째 인덱스 값을 출력

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); // 원형큐의 front값과 rear값 출력
}


