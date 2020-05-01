 /* single linked list

 *

 *  Data Structures

 *  Department of Computer Science

 *  at Chungbuk National University

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node // 구조체 함수 정의
{
	int key; // 원소를 저장할 값 
	struct Node* link; // 자신과 동일한 구조체를 가르키는 포인터 

} listNode;

 
typedef struct Head

{
	struct Node* first; // 처음 노드를 가리키는 포인터

}headNode;

 

/* 함수 리스트 */

headNode* initialize(headNode* h); // 리스트를 초기화해주는 함수
int freeList(headNode* h); // 리스트의 메모리들을 해제하는 함수
int insertFirst(headNode* h, int key); // 노드를 리스트의 첫번째에 추가하는 함수
int insertNode(headNode* h, int key); // 노드를 삽입하는 함수
int insertLast(headNode* h, int key); // 노드를 리스트의 마지막에 추가하는 함수
int deleteFirst(headNode* h); // 첫번째 노드를 삭제하는 함수
int deleteNode(headNode* h, int key); // 특정 노드를 삭제하는 함수
int deleteLast(headNode* h); // 리스트의 마지막 노드를 삭제하는 함수
int invertList(headNode* h); // 리스트의 링크를 역순으로 재배치 하는 함수
void printList(headNode* h); // 노드를 출력하는 함수 


int main()

{

	char command; // 입력받을 명령어 변수 선언
	int key; // 입력할 key값 변수 선언
	headNode* headnode = NULL; // 헤드노드가 아무것도 가리키지 않는다.(노드가 아직 없다)


		printf("\n");
		printf("            [--------- [신지혜] [2018038029] ---------]\n"); // 이름과 학번 출력

	do {
		// 명령어를 입력받는 문구 출력//
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); // 사용자에게 명령어를 입력받는다


		switch (command) { // 입력받은 명령어에 따라 조건문을 실행한다

		case 'z': case 'Z': // 사용자가 z 또는 Z를 입력하면
			headnode = initialize(headnode); // 연결 리스트를 초기화하는 함수 호출
			break; // 조건문 탈출

		case 'p': case 'P': // 사용자가 p 또는 P를 입력하면
			printList(headnode); // 연결리스트를 출력하는 함수 호출
			break; // 조건문 탈출

		case 'i': case 'I': // 사용자가 i또는 I를 입력하면
			printf("Your Key = "); // key값을 입력받는 문구 출력
			scanf("%d", &key); // key값을 입력받는다
			insertNode(headnode, key); // 입력받은 key값을 갖는 노드를 연결 리스트에 삽입한다
			break; // 조건문 탈출

		case 'd': case 'D': // 사용자가 d 또는 D를 입력하면
			printf("Your Key = "); // key값을 입력받는 문구 출력
			scanf("%d", &key); // key값을 입력받는다
			deleteNode(headnode, key); // 입력받은 key값을 갖는 노드를 연결리스트에서 삭제한다
			break; // 조건문 탈출

		case 'n': case 'N': // 사용자가 n 또는 N을 입력하면
			printf("Your Key = "); // key값을 입력받는 문구 출력
			scanf("%d", &key); // key값을 입력받는다
			insertLast(headnode, key); // 입력받은 key값을 갖는 노드를 연결리스트 마지막에 추가한다
			break; // 조건문 탈출

		case 'e': case 'E': // 사용자가 e 또는 E를 입력하면
			deleteLast(headnode); // 연결리스트의 마지막 노드를 삭제한다
			break; // 조건문 탈출

		case 'f': case 'F': // 사용자가 f 또는 F를 입력하면
			printf("Your Key = "); // key값을 입력받는 문구 출력
			scanf("%d", &key); // key값을 입력받는다
			insertFirst(headnode, key); // 입력받은 key값을 갖는 노드를 연결리스트 맨 앞에 추가한다
			break; // 조건문 탈출

		case 't': case 'T': // 사용자가ㅏ t 또는 T를 입력하면
			deleteFirst(headnode); // 첫번째 노드를 연결리스트에서 삭제한다
			break; // 조건문 탈출

		case 'r': case 'R': // 사용자가 r 또는 R을 입력하면
			invertList(headnode); // 리스트를 역으로 만든다
			break; // 조건문 탈출

		case 'q': case 'Q': // 사용자가 q 또는 Q를 입력하면
			freeList(headnode); // freeList 함수 호출
			break; // 조건문 탈출

		default: // 그외의 값을 입력하면 
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // 이 문구를 출력한다
			break; // 조건문 탈출

		}


	} while (command != 'q' && command != 'Q'); // 사용자에게 종료명령어를 입력받을때까지 반복한다

	return 1;

}

 

headNode* initialize(headNode* h) 

{
	if (h != NULL)  // head노드가 NULL이 아니면면
		freeList(h); // 할당된 메모리를 모두 해제한다

 
	/* headNode에 대한 메모리를 할당하여 리턴 */

	headNode* temp = (headNode*)malloc(sizeof(headNode)); // head노드에 대한 메모리를 동적으로 할당받는다
	temp->first = NULL; // temp->first 가 가리키는 것이 없게 NULL값을 대입한다

	return temp; // temp의 주소값 리턴

}

 
int freeList(headNode* h) 

{
	/* h와 연결된 listNode 메모리 해제

	* headNode도 해제되어야 함.

	*/

	listNode* p = h->first; // 헤드노드의 주소값을 포인터 p에 대입한다
	listNode* prev = NULL; // 포인터 prev를 NULL로 초기화 한다
	while (p != NULL) { // p가 NULL과 같지 않다면 계속 반복

		prev = p; // prev도 p가 가리키는 값을 가리키도록 한다
		p = p->link; // p link의 주소값을 p에 대입한다(다음 노드로 이동)
		free(prev); // prev가 가리키는 노드를 해제한다

	}

	free(h); // 헤드노드 메모리를 해제한다
	return 0;

}

 //list 처음에 key에 대한 노드하나를 추가

int insertFirst(headNode* h, int key)  // 노드를 연결리스트의 첫번째에 추가하는 함수
{
	listNode* node = (listNode*)malloc(sizeof(listNode)); // 포인터 node에 메모리를 할당 받는다
	
	node->key = key; // node의 key에 key값을 대입한다
	node->link = h->first; // 헤드 노드가 가리키고 있는 리스트의 주소를 node->link에 대입
	// 추가하려는 node의 링크가 현재 헤드노드가 가리키고 있는 리스트를 가리키도록 한다

	h->first = node; // 헤드 노드에 노드의 주소값을 대입한다(헤드노드가 node를 가리키도록 한다)
	return 0;

}

int insertNode(headNode* h, int key)  // 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입하는 함수 

{

	listNode* node = (listNode*)malloc(sizeof(listNode)); // 포인터 node에 메모리를 할당 받는다
	listNode* prev; // 이전 노드를 가리킬 포인터 prev 선언
	listNode* search; // 현재 노드를 가리킬 포인터 search 선언

	search = h->first; // search노드도 헤드 노드가 가리키는 곳을 가리키도록 한다
	node->key = key; // node->key값에 key를 대입한다
	prev = NULL; // prev는 아직 이전 노드가 없으므로 NULL값으로 초기화한다


	while (search!=NULL) // serach가 NULL과 같지 않다면 계속 반복한다

	{
		if (node->key > search->key) // 만약 현재 가리키고 있는 노드의 키보다 입력하려는 노드의 키가 더 크다면
		{
			prev = search; // prev도 search가 가리키는 곳을 가리키도록 한다
			search = search->link; // search가 가리키고 있는 다음 노드를 search에 대입한다
			//(즉, search를 다음노드로 이동)
		}

		else // 그렇지 않다면
			break; // 반복문 탈출
	}

	if (prev == NULL) // 만약 prev의 값이 NULL이라면, 

	{
		insertFirst(h, key); // 연결리스트의 노드는 1개밖에 존재하지 않는 것이므로 insertFirst 함수를 호출하여
		// 연결리스트의 맨 앞에 노드를 추가한다
	}

	else // prev도 값을 갖고 있다면
	{
		node->link = search; // 삽입하려는 node의 링크가 search 노드를 가리키도록 한다
		prev->link = node; // search노드 이전의 노드, 즉 prev 노드의 link가 삽입하려는 node를 가리키도록 한다
		// 결과적으로 prev , search에서 prev,  node, search 이 순서가 된다

	}

	return 0;

}

int insertLast(headNode* h, int key) //list에 key에 대한 노드하나를 마지막에 추가하는 함수

{
	listNode* search; // 현재 노드를 가리키는 포인터 선언
	listNode* node = (listNode*)malloc(sizeof(listNode)); // 메모리를 할당받는다
	node->key = key; // 삽입하려는 node의 key에 입력받는 key값을 대입한다
	search = h->first; // search도 헤드노드가 가리키는 노드, 즉 첫번째 노드를 가리키도록 한다

	while (search != NULL) // serach값이 NULL과 다르다면 계속 반복

	{
		search = search->link; // search 노드가 가리키는 다음 노드의 주소를 search에 대입(search를 다음 노드로 이동)

		if(search->link==NULL) // 만약 search의 link가 NULL이면 (serach노드가 마지막 노드이면)
			break; // 반복문을 탈출한다

	}
		search->link = node; // search의 링크가 새로 삽입할 node를 가리키도록 한다
		node->link = NULL; // 새로 삽입할 node의 link에 NULL값을 대입한다(이 새로 삽입할 노드가 마지막 노드라는 뜻)

	return 0;
}

int deleteFirst(headNode* h) //list의 첫번째 노드 삭제하는 함수

{
	listNode* temp; // 노드를 가리킬 포인터 변수 선언
	temp = h->first; // 헤드노드가 가리키는 노드를 temp도 가리키도록 한다(temp가 첫번째 노드를 가리키도록 한다)
	h->first=h->first->link; // 첫번째 노드가 가리키는 다음 노드의 주소를 헤드노드에 대입한다
	// 헤드노드가 가리키는 값이 첫번째 노드에서 두번째 노드로 이동하는것과 동일
	free(temp); // temp가 가리키는 노드를 해제한다 (첫번째 노드 해제)

	return 0;

}


int deleteNode(headNode* h, int key)  //list에서 key에 대한 노드를 삭제하는 함수
{
	listNode* search; // 찾고자하는 노드를 가리킬 포인터 search 변수 선언
	listNode* prev; // 이전 노드를 가리킬 포인터 prev 변수 선언

	search = h->first; // 헤드노드가 가리키는 노드를 search도 가리키도록 한다
	// 즉, search가 리스트에서 첫번째 노드를 가리키도록 한다
	prev = NULL; // prev의 값을 NULL로 초기화

while (search != NULL) // search가 NULL값과 다르다면 계속 반복
{
		if(search->key==key) // key값을 가진 노드를 search가 가리키고 있다면
		{
				prev->link = search->link; // search가 가리키고 있는 노드의 다음노드의 주소를 prev->link에 대입
				// 즉, prev의 노드가 search 다음 노드를 가리키도록 한다
				free(search); // search 노드를 해제한다
				return 0;
			
		}

		else //key값 가진 노드를 못 찾았다면
		{
			prev = search; // search가 가리키는 노드를 prev도 가리키도록 한다
			search = search->link; // search를 다음 노드로 이동시킨다

		}															
}
// 위에 해당하는 key가 존재하지 않다면		
printf("해당하는 key = %d가 존재하지 않습니다.\n",key); // 찾는 key가 없다는 문구 출력
	
}


int deleteLast(headNode* h) // 연결리스트의 마지막 노드를 삭제하는 함수

{
	listNode* search; // 현재 노드를 가리키는 포인터 search 변수 선언
	listNode* prev=NULL; // 이전 노드를 가리키는 포인터 prev 변수 선언

	search = h->first; // 헤드노드가 가리키는 노드를 search도 가리키도록 한다
	// 즉, search도 첫번째 노드를 가리키도록 한다 (search의 값에는 첫번째 노드의 주소가 있음)
	
	while (search!= NULL) // search가 NULL과 다르면 계속 반복한다

	{
			prev = search; // prev도 search가 가리키는 노드를 가리키도록 한다
			search = search->link; // search노드가 가리키는 다음 노드의 주소를 search에 대입
			// 즉, search노드가 다음 노드를 가리키도록 한다

			if(search->link==NULL) // 만약 search의 노드가 리스트에서 마지막 노드이면
				break; // 반복문 탈출

	}

	prev->link = NULL; // search노드 이전의 노드 , 즉 prev의 노드의 link값에 NULL을 대입한다.
	// 즉, prev의 노드가 리스트에서 마지막 노드임을 뜻한다.
	free(search); // search의 노드 메모리 해제
	
	return 0;

}

int invertList(headNode* h)  // 리스트의 링크를 역순으로 재 배치하는 함수

{

	listNode* lead; // 현재 노드를 가리킬 포인터 lead 변수 선언
	listNode* middle; // 노드를 가리킬 포인터 middle 변수 선언
	listNode* tail; // 노드를 가리킬 포인터 tail 변수 선언

	lead = h->first; // 헤드노드가 가리키고 있는 노드를 lead도 가리키도록 한다
	// 즉, lead가 첫번째 노드를 가리키도록 한다. 
	middle = NULL; //middle의 값을 NULL로 초기화
	tail=NULL; //tail의 값을 NULL로 초기화

	while (lead != NULL) // lead 노드값이  NULL과 다르다면 계속 반복

	{

		tail = middle; // middle이 가리키는 노드를 tail도 가리키도록 한다
		middle = lead; // lead가 가리키는 노드를 middle도 가리키도록 한다
		// 즉 tail이 middle을 뒤 따르도록 하고, middle은 lead를 뒤 따르도록 한다
		lead = lead->link; //lead를 다음 노드로 이동시킨다
		middle->link = tail; // mildle의 link가 tail의 노드를 가리키도록 한다
	}

	h->first = middle; // 헤드노드가 middle이 가리키는 노드를 가리키도록 한다
	// 즉, 헤드노드에 middle이 가리키는 노드의 주소를 대입한다

	return 0;

}


void printList(headNode* h)  // 리스트를 출력하는 함수 

{
	int i = 0; // 변수 i를 0으로 초기화
	listNode* p;

	printf("\n---PRINT\n"); 

	if (h == NULL) // 만약 h에 아무런값도 들어있지 않다면
	{

		printf("Nothing to print....\n"); // 출력할 것이 없다는 문구 출력
		return;

	}

	p = h->first; // p에 헤드노드가 가리키는 노드의 주소를 대입 (즉, p가 첫번째 노드를 가리키도록 한다)

	while (p != NULL) { // p의 값이 NULL과 다르다면 계속 반복

		printf("[ [%d]=%d ] ", i, p->key); // 노드의 번호와 p가 가리키는 노드의 key값 출력
		p = p->link; // p노드를 다음 노드로 이동한다
		i++; // i를 1씩 증가

	}

	printf("  items = %d\n", i); // 노드의 총 개수가 몇개인지 출력한다

}