/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */

#include<stdio.h>
#include<stdlib.h>


typedef struct Node  // 구조체 함수 정의

{
	int key; // key 값이 들어갈 필드
	struct Node* llink; // 현재 노드의 이전노드 주소를 가리키는 포인터
	struct Node* rlink; // 현재 노드의 다음노드 주소를 가리키는 포인터

} listNode;


typedef struct Head // 헤드노드

{
	struct Node* first; // 리스트의 첫번째 노드를 가리키는 포인터

}headNode;

/* 함수 리스트 */


/* note: initialize는 이중포인터를 매개변수로 받음
		singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h); // 초기화 하는 함수

 
/* note: freeList는 싱글포인터를 매개변수로 받음
		- initialize와 왜 다른지 이해 할것
		- 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h); // 메모리 해제하는 함수

int insertNode(headNode* h, int key); // 새로운 노드를 할당받아 입력받은 key보다 큰 값 앞에 삽입하는 함수
int insertLast(headNode* h, int key); // 리스트의 마지막에 노드를 삽입하는 함수
int insertFirst(headNode* h, int key); // 리스트의 첫번째에 노드를 삽입하는 함수
int deleteNode(headNode* h, int key); // 주어진 key값이 들어있는 노드를 찾아 삭제하는 함수
int deleteLast(headNode* h); // 리스트의 마지막 노드를 삭제하는 함수
int deleteFirst(headNode* h); // 리스트의 첫번째 노드를 삭제하는 함수
int invertList(headNode* h); // 리스트를 역순으로 재배치 하는 함수
void printList(headNode* h); // 현재 리스트의 원소들을 출력하는 함수


int main()

{
	char command; // 명령어를 입력받을 변수 선언
	int key; // key값 변수 선언
	headNode* headnode = NULL; // 헤드노드 선언 및 NULL로 초기화

	printf("----------------[2018038029]-----------[신지혜]-----------------\n\n"); // 이름과 학번 출력
	do {

		printf("----------------------------------------------------------------\n"); // 메뉴 출력
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = "); // 명령어를 입력받을 문구 출력
		scanf(" %c", &command); // 사용자로부터 명령어를 입력받는다

		switch (command) {
		case 'z': case 'Z': // 입력된 명렁어가 z 또는 Z이면,
			initialize(&headnode); // 초기화하는 함수를 호출한다
			break; // 조건문 탈출

		case 'p': case 'P': // 입력된 명렁어가 p 또는 P이면,
			printList(headnode); // 리스트를 출력하는 함수를 호출한다
			break; // 조건문 탈출

		case 'i': case 'I': //입력된 명렁어가 i 또는 I이면,
			printf("Your Key = "); // key값을 입력하라는 문구 출력
			scanf("%d", &key); // key값을 사용자로부터 입력받는다
			insertNode(headnode, key); // 노드를 삽입하는 함수 호출
			break;// 조건문 탈출

		case 'd': case 'D': // 입력된 명렁어가 d 또는 D이면,
			printf("Your Key = "); // key값을 입력하라는 문구 출력
			scanf("%d", &key); // key값을 사용자로부터 입력받는다
			deleteNode(headnode, key); // 노드를 삭제하는 함수 호출
			break;// 조건문 탈출

		case 'n': case 'N': // 입력된 명렁어가 n 또는 N이면,
			printf("Your Key = "); // key값을 입력하라는 문구 출력
			scanf("%d", &key); // key값을 사용자로부터 입력받는다
			insertLast(headnode, key); // 리스트의 첫번째에 노드를 삽입하는 함수 호출
			break;// 조건문 탈출

		case 'e': case 'E': // 입력된 명렁어가 e 또는 E이면,
			deleteLast(headnode); // 리스트의 마지막노드를 삭제하는 함수 호출
			break;// 조건문 탈출

		case 'f': case 'F': // 입력된 명렁어가 f 또는 F이면,
			printf("Your Key = "); // key값을 입력하라는 문구 출력
			scanf("%d", &key); // key값을 사용자로부터 입력받는다
			insertFirst(headnode, key); // 리스트의 첫번째에 해당 노드를 삽입하는 함수 호출
			break;// 조건문 탈출

		case 't': case 'T': // 입력된 명렁어가 t 또는 T이면,
			deleteFirst(headnode); // 리스트의 첫번째 노드를 삭제하는 함수 호출
			break;// 조건문 탈출

		case 'r': case 'R': // 입력된 명렁어가 r 또는 R이면,
			invertList(headnode); // 리스트를 역순으로 재배치 하는 함수 호출
			break;// 조건문 탈출

		case 'q': case 'Q': // 입력된 명렁어가 q 또는 Q이면,
			freeList(headnode); // 리스트의 메모리를 해제하는 함수 호출
			break;// 조건문 탈출

		default: // 위의 명령어 외에 다른 값들을 입력하면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // 해당 안내 문구 출력
			break;// 조건문 탈출
		}
	} while (command != 'q' && command != 'Q'); // 사용자가 q 또는 Q를 입력하면 반복문 종료

	return 1;
}


//initialize(&headnode);
int initialize(headNode** h) // h와 연결된 리스트 노드들의 메모리 해제하는 함수

{
	if (*h != NULL) // h가 가리키는 곳의 값이 NULL과 다르다면,
		freeList(*h); // h가 가리키는 곳의 메모리를 해제한다

	headNode* temp = (headNode*)malloc(sizeof(headNode)); // 헤드노드의 대한 메모리를 동적으로 할당 받는다
	temp->first = NULL; // temp->first가 가리키는 것이 없게 NULL값 대입 (헤드노드가 아무것도 가리키지 않도록)
	*h = temp; // h가 가리키고 있는 주소의 값에 temp 대입
	return 1;
}

 
int freeList(headNode* h) // 메모리를 해제하는 함수 
{

	listNode* p; // 현재 노드를 가리킬 포인터 선언
	listNode* prev; // 이전 노드를 가리킬 포인터 선언
	p = h->first; // p가 헤드노드가 가리키는 노드를 가리키도록 한다
	// 즉, p가 리스트의 첫번재 노드를 가리키도록 한다
	prev = NULL; // prev를 NULL값으로 초기화

	while (p != NULL) // p와 NULL이 다르면 계속 반복

	{
		prev = p; // prev도 p가 가리키는 노드를 가리키도록 한다
		p = p->rlink; // p가 현재노드의 다음노드를 가리키도록 이동시킨다
		free(prev); // prev가 가리키는 노드의 메모리를 해제한다
	}

	free(h); // 헤드노드의 메모리 또한 해제한다
	return 0; // 종료

}


void printList(headNode* h) // 리스트를 출력하는 함수 

{
	int i = 0; // 노드의 개수를 세는 변수 선언
	listNode* p; // 리스트 노드 포인터 선언
	printf("\n---PRINT\n");

	if (h == NULL) // 만약 헤드노드에 아무런 값이 들어있지 않다면

	{
		printf("Nothing to print....\n"); // 출력할 것이 없다는 문구 출력
		return;

	}
	p = h->first; // p에 첫번째 노드의 주소값을 대입한다

	while (p != NULL) // p과 NULL이 다르면 계속 반복

	{
		printf("[ [%d]=%d ] ", i, p->key); // 리스트의 번호와 노드의 key값을 출력한다
		p = p->rlink; // p가 가리키고 있는 노드를 다음 노드로 이동시킨다
		i++; // i값 1씩 증가
	}
	printf("  items = %d\n", i); // 총 노드의 개수가 몇개인지 출력한다

}


int insertLast(headNode* h, int key) // list에 key에 대한 노드하나를 추가 

{

	listNode* newnode = (listNode*)malloc(sizeof(listNode)); // 새로운 노드를 삽입할 수 있도록 메모리를 할당받는다
	newnode->key = key; // 새롭게 할당받은 노드에 key값을 집어넣는다
	listNode* search = h->first; // 현재 노드를 가리킬 포인터 search 선언, 헤드노드가 가리키고 있는 노드의 주소를 search에 대입한다
	// 즉 , 리스트의 첫번째 노드의 주소를 search에 대입

	if (h->first == NULL) // 만약 첫번째 노드가 없다면(= 아직 아무것도 없다면)
	{
		h->first = newnode; // 리스트의 첫번째 노드를 newnode로 지정한다
	}

	while (search!= NULL) // search와 NULL 값이 다르면 반복

	{
		search = search->rlink; // search가 가리키고 있는 노드의 다음 노드로 search를 이동시킨다. 
		if (search->rlink == NULL) // 만약 search가 리스트에서 마지막 노드라면
			break; // 반복문 탈출

	}
	search->rlink = newnode; // search가 가리키고있는 노드의 다음노드가 newnode가 되도록 한다
	newnode->llink = search; // newnode의 이전노드가 search가 가리키고 있는 노드가 되도록 한다
	newnode->rlink = NULL; // 마지막 노드의 rlink에 NULL값 대입
	return 0; // 종료

}


int deleteLast(headNode* h) /* list의 마지막 노드 삭제 */

{
	listNode* search; // 현재 노드를 가리킬 포인터 선언
	search = h->first; // search 포인터가 리스트의 첫번째 노드를 가리키도록 한다.
	while (search!= NULL) // 원래 while(serach->rlink==NULL)
	{

		search = search->rlink; // search를 다음 노드로 이동시킨다
		if (search->rlink == NULL) // 만약 search가 리스트에서 마지막 노드라면
			break; // 반복문 탈출
	}

	search->llink->rlink = NULL; // search가 가리키는 노드의 이전 노드의 rlink에 NULL값을 집어 넣는다
	// 즉, search의 이전노드가 리스트에서 마지막 노드라는 뜻
	free(search); // search가 가리키는 노드를 해제한다

	return 0; // 종료 

}

 
int insertFirst(headNode* h, int key)  /* list 처음에 key에 대한 노드하나를 추가 */

{
	listNode* newnode = (listNode*)malloc(sizeof(listNode)); // 새로운 노드를 삽입할 수 있도록 메모리를 할당받는다
	newnode->key = key; // newnode의 key에 입력받은 key값을 대입한다
	newnode->rlink = h->first; // newnode의 다음 노드가 현재 리스트의 첫번째 노드가 되도록한다
	// 즉, newnode를 리스트 맨 앞에 삽입한다

	h->first->llink = newnode; // 현재 리스트의 첫번째 노드, 즉 헤드노드가 가리키고 있는 노드의 llink에 newnode의 주소를 대입한다
	h->first = newnode; // 헤드노드가 newnode를 가리키도록 한다. 즉, 리스트의 첫번째 노드가 newnode가 되도록 한다

	return 0; // 종료

}

 
int deleteFirst(headNode* h)  /* list의 첫번째 노드 삭제 */

{
	listNode* search; // 현재 노드를 가리킬 포인터 선언
	search = h->first; // search가 헤드노드가 가리키는 노드를 가리키도록 한다
	// 즉, search가 리스트의 첫번째 노드를 가리키도록 한다

	h->first = search->rlink; // 헤드노드가 search의 다음 노드를 가리키도록 한다
	h->first->llink = NULL; // 헤드노드가 가리키는 노드의 llink 에 NULL값을 대입한다
	free(search); // search가 가리키는 노드를 해제한다

	return 0; // 종료

}


int invertList(headNode* h) /* 리스트의 링크를 역순으로 재 배치 */

{
	listNode* lead; // 반복문에서 첫번째로 이동시킬 포인터 변수 선언
	listNode* middle; // lead 뒤를 따르게 할 middle 포인터 변수 선언
	listNode* tail; // middle뒤를 따르게 할 tail 포인터 변수 선언
	lead = h->first; // lead가 리스트의 첫번째 노드를 가리키도록 한다
	tail = NULL; // tail값을 NULL로 초기화
	middle = NULL; // middle값을 NULL로 초기화

	if (h->first->rlink == NULL) // 만약 리스트에 노드가 1개밖에 없다면

	{
		h->first->llink = NULL; // 첫번째 노드의 llink에 NULL값 대입
	}

	while (lead->rlink!=NULL) // lead의 rlink값이 NULL과 다르다면 반복
		// 즉, lead가 리스트에서의 마지막 노드를 가리키고 있다면 반복하지 않는다
	{

		tail = middle; // tail은 middle의 뒤를 따르게 한다
		middle = lead; // middle은 lead의 뒤를 따르게 한다
		lead = lead->rlink; // lead를 lead가 가리키는 노드의 다음 노드로 이동한다(lead를 다음 노드로 이동)

		middle->llink = lead; // middle이 가리키는 노드의 llink가 lead를 가리키게 한다(middle의 이전노드가 lead노드가 되도록)
		middle->rlink = tail; // middle이 가리키는 노드의 rlink가 tail을 가리키게 한다(middle의 다음노드가 tail노드가 되도록)

	}

	// 현재 lead는 리스트에서의 마지막 노드를 가리킨다(역으로 재배치 하기 전 기준)
	lead->rlink = middle; // lead가 가리키는 노드의 rlink가 middle을 가리키게 한다 
	lead->llink = NULL; // lead가 가리키는 노드의 llink에 NULL값을 대입한다
	h->first = lead; // 헤더노드가 lead가 가리키는 노드를 가리키도록 한다
	// 즉, 리스트의 마지막 노드가 리스트의 첫번째 노드가 되도록 한다
	return 0; // 종료

}

 

 

/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) 

{
	listNode* newnode = (listNode*)malloc(sizeof(listNode)); // 새로운 노드를 삽입할 수 있도록 메모리를 할당받는다
	listNode* search; // 현재 노드를 가리키는 포인터 선언
	newnode->key = key; // newnode의 key에 key값을 대입한다
	search = h->first; // 헤드노드가 가리키는 노드를 search도 가리키도록 한다 
	// 즉, search가 리스트의 첫번째 노드를 가리키도록 한다

 
	if (h->first == NULL) // 만약 아직 리스트에 노드가 하나도 없다면

	{
		h->first = newnode; // 헤드노드가 newnode를 가리키도록 한다
		newnode->rlink = NULL; // newnode의 rlink에 NULL값 대입
		newnode->llink = NULL; // newnode의 llink에 NULL값 대입
		return 0; // 종료

	}

	while (search->rlink != NULL) //search의 rlink의 값과 NULL이 다르면 반복

	{
		if (search->key > key) // 만약 search가 가리키는 노드의 key값이 사용자에게 입력받은 key값보다 크다면
		{
			if (search == h->first) // search가 가리키는 노드가 리스트에서 첫번째 노드라면
			{
				h->first = newnode; // 헤드노드가 newnode를 가리키도록 한다 (newnode가 리스트에서의 첫번재 노드가 되도록)
				newnode->rlink = search; // newnode의 다음 노드가 search가 가리키는 노드가 되도록 한다
				newnode->llink = NULL; // newnode의 llink에 NULL값 대입
				return 0; // 종료

			}
			else // 중간에 삽입해야 할 경우라면

			{
				newnode->rlink = search; // newnode의 다음 노드가 search가 가리키는 노드가 되도록 한다
				newnode->llink = search->llink; // newnode의 이전노드가 search가 가리키는 노드의 이전노드가 되도록 한다
				search->llink->rlink = newnode; // search가 가리키는 노드의 이전노드의 다음 노드가 newnode가 되도록 한다
				search->llink = newnode; // search의 이전노드가 newnode가 되도록 한다
				return 0; // 종료

			}

		}
		search = search->rlink; // search를 다음 노드로 이동시킨다

	}

	// newnode가 리스트의 마지막 노드가 되도록 하는 경우 
	//( 입력받은 key값보다 큰 값을 갖는 노드가 없는 경우)
 
	newnode->rlink = NULL; // newnode의 rlink에 NULL값 대입
	newnode->llink = search; // newnode의 이전노드가 search가 가리키는 노드가 되도록 한다
	search->rlink = newnode; // search가 가리키는 노드의 다음 노느가 newnode가 되도록 한다
	return 0; // 종료


}

int deleteNode(headNode* h, int key) /* list에서 key에 대한 노드 삭제 */

{
	listNode* search; // 현재 노드를 가리킬 포인터 선언
	search = h->first; // search가 리스트의 첫번째 노드를 가리키도록 한다

	while (search != NULL) // search의 값과 NULL값이 다르다면 반복

	{
		if (search->key == key) // search가 가리키는 노드의 key값과 입력받은 key값이 같은 경우
		{
			if (search==h->first) // search가 가리키는 노드가 리스트에서의 첫번째 노드라면
			{

				h->first = search->rlink; // 헤드노드가 search가 가리키는 노드의 다음 노드를 가리키도록 한다
				h->first->llink = NULL; // 헤드노드가 가리키는 노드의 llink에 NULL값 대입
				free(search); // search가 가리키는 노드를 해제한다
				return 0; // 종료

			}
			else if (search->rlink == NULL) // 만약 search가 가리키는 노드가 리스트의 마지막 노드라면
			{

				search->llink->rlink = NULL; // search가 가리키는 노드의 이전 노드의 rlink에 NULL 값 대입
				// search의 이전노드가 리스트에서 마지막이 되도록 한다
				free(search); // search가 가리키는 노드 메모리 해제
				return 0; // 함수 종료

			}
			else // 삭제하려는 노드가 리스트 중간에 있다면 
			{
				search->llink->rlink = search->rlink; // search의 이전노드의 rlink가 search의 다음 노드를 가리키도록 한다
				search->rlink->llink = search->llink; // search의 다음노드의 llink가 search의 이전 노드를 가리키도록 한다
				free(search); // search가 가리키는 노드 메모리 해제
				return 0; // 종료

			}
		}

		search = search->rlink; // search가 가리키는 노드의 key값과 입력받은 key값이 다른 경우,
		// search를 다음 노드로 이동시킨다
	}

	printf("해당 key = %d값을 갖는 노드가 없습니다.\n\n", key); // 만약 위에 해당하는 사항이 없다면(리스트에 입력받은 key값을 갖는 노드가 없다면)
	// 해당 key값을 갖는 노드가 없다는 문구 출력
	return 1;

}