/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */

#include<stdio.h>
#include<stdlib.h>


typedef struct Node  // 노드 구조체 정의 및 선언

{
	int key; 
	struct Node* llink;
	struct Node* rlink;

} listNode;

 

/* 함수 리스트 */
int initialize(listNode** h); // 연결리스트를 초기화 하는 함수
int freeList(listNode* h); // 연결리스트에서 동적으로 할당 된 메모리를 해제하는 함수
int insertLast(listNode* h, int key); // 연결리스트의 마지막에 노드를 추가하는 함수
int deleteLast(listNode* h); // 연결리스트의 마지막 노드를 삭제하는 함수
int insertFirst(listNode* h, int key); // 연결리스트의 첫번째에 노드를 추가하는 함수
int deleteFirst(listNode* h); // 연결리스트의 첫번째의 노드를 삭제하는 함수
int invertList(listNode* h); // 연결리스트의 노드들을 역순으로 재배치 하는 함수
int insertNode(listNode* h, int key); // 사용자에게 key값을 입력받고, 그 값보다 큰 값을 가진 노드 앞에 노드를 추가하는 함수
int deleteNode(listNode* h, int key); // 사용자에게 입력받은 key값을 가진 노드를 삭제하는 함수
void printList(listNode* h); // 연결리스트의 노드들을 출력하는 함수



int main()

{

	char command; // 명령어를 입력받을 변수 선언
	int key; // key값을 입력받을 변수 선언
	listNode* headnode = NULL; // headnode를 NULL로 초기화

		printf("\n");
		printf("             [------[2018038029]-----[신지혜]------]     \n"); // 학번과 이름 출력

	do {
		printf("----------------------------------------------------------------\n"); // 메뉴 출력
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = "); // 사용자에게 명령어를 입력받는다
		scanf(" %c", &command);

		switch (command) // 입력받은 명령어에 따라 조건문 실행 
		{

		case 'z': case 'Z': // 입력받은 명령어가 z 또는 Z이면, 
			initialize(&headnode); // 연결리스트를 초기화 하는 함수 호출
			break; 

		case 'p': case 'P': //  입력받은 명령어가 p 또는 P이면, 
			printList(headnode); // 연결리스트의 노드를 출력하는 함수 호출
			break;

		case 'i': case 'I':  // 입력받은 명령어가 i 또는 I이면,
			printf("Your Key = "); // 사용자에게 key값을 입력받는다
			scanf("%d", &key);
			insertNode(headnode, key); // 입력받은 key값 보다 큰 값을 가진 노드앞에 key값을 가진 노드를 새로 추가하는 함수 호출
			break; 

		case 'd': case 'D': // 입력받은 명령어가 d 또는 D이면,
			printf("Your Key = "); // 사용자에게 key값을 입력받는다
			scanf("%d", &key);
			deleteNode(headnode, key); // 입력받은 key값을 갖는 노드를 삭제하는 함수 호출
			break; 

		case 'n': case 'N': // 입력받은 명령어가 n 또는 N이면,
			printf("Your Key = "); // 사용자에게 key값을 입력받는다
			scanf("%d", &key);
			insertLast(headnode, key); // 리스트의 마지막에 노드를 추가하는 함수 호출
			break; 

		case 'e': case 'E': // 입력받은 명령어가 e 또는 E이면,
			deleteLast(headnode); // 리스트에서 마지막 노드를 삭제하는 함수 호출
			break; 

		case 'f': case 'F': // 입력받은 명령어가 f 또는 F이면,
			printf("Your Key = "); // 사용자에게 key값을 입력받는다
			scanf("%d", &key);
			insertFirst(headnode, key); // 리스트의 첫번째에 노드를 추가하는 함수 호출
			break;

		case 't': case 'T': // 입력받은 명령어가 t 또는 T이면,
			deleteFirst(headnode); // 리스트의 첫번째 노드를 삭제하는 함수 호출
			break;

		case 'r': case 'R': // 입력받은 명령어가 r 또는 R이면,
			invertList(headnode); // 연결리스트의 노드들을 역순으로 재배치하는 함수 호출
			break;

		case 'q': case 'Q': // 입력받은 명령어가 q 또는 Q이면,
			freeList(headnode); // 연결리스트의 동적으로 할당 된 메모리들을 해제하는 함수 호출
			break;

		default: // 위의 명령어 외에 다른 명령어를 입력하면, 
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // 해당 문구 출력
			break;
		}

	} while (command != 'q' && command != 'Q'); // q 또는 Q를 입력받기 전까지 반복문을 계속 실행한다

	return 1; // 종료

}

 

/* 연결리스트를 초기화하는 함수 */
int initialize(listNode** h) 

{
	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if (*h != NULL)
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h; // *h의 다음 노드가 *h가 되도록 한다
	(*h)->llink = *h; // *h의 이전 노드가 *h가 되도록 한다
	(*h)->key = -9999; // *h의 key값에 임의의 값을 대입
	return 1;

}

 

/* 메모리 해제 */
int freeList(listNode* h) 

{
	listNode* p;
	listNode* prev;
	prev = NULL; // prev를 NULL값으로 초기화한다
	p = h->rlink; // p에 h->rlink , 즉 p에 리스트의 첫번째 노드의 주소를 대입한다

	while (prev != NULL) // prev와 NULL이 다르다면 계속 반복

	{
		prev = p; // prev가 p를 따르도록 한다
		p = p->rlink; // p를 다음 노드로 이동시킨다
		free(prev); // prev가 가리키는 노드의 메모리를 해제한다
	}

	free(h); // headnode의 메모리를 해제한다.
	return 0; // 함수 종료

}


void printList(listNode* h) // 연결리스트의 노드들의 값, 주소를 출력하는 함수

{
	int i = 0;
	listNode* p;
	printf("\n---PRINT\n");

	if (h == NULL) // 만약 h가 NULL과 같다면, 즉 리스트에 아무 노드도 존재하지 않는다면

	{
		printf("Nothing to print....\n"); // 출력할 노드가 없다는 문구를 출력한다
		return;
	}

	p = h->rlink; // p가 리스트의 첫번째 노드를 가리키도록 한다

	while (p != NULL && p != h) // p가 NULL값과 다르고 p가 h와 다르다면 

	{
		printf("[ [%d]=%d ] ", i, p->key); // p가 가리키는 노드의 key값을 출력한다
		p = p->rlink; // p를 다음 노드로 이동시킨다
		i++; // i를 1씩 증가한다
	}

	printf("  items = %d\n", i); // 현재 연결리스트의 노드의 개수가 몇개인지 보여준다

	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink); // 헤드노드의 주소와 각각의 rlink와 llink가 가리키는 주소를 출력한다

	i = 0;
	p = h->rlink; // p가 연결리스트의 첫번째 노드를 가리키도록 한다

	while (p != NULL && p != h) // p가 NULL값과 다르고 p가 h와 다르다면 

	{
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink); // 연결리스트의 노드의 주소와 각각의 rlink와 llink가 가리키는 주소를 출력한다
		p = p->rlink; // p를 다음 노드로 이동시킨다
		i++; // i를 1씩 증가한다

	}

}

 
/* list에 key에 대한 노드하나를 연결리스트의 맨 마지막에 추가 */
int insertLast(listNode* h, int key) 

{

	listNode* newnode = (listNode*)malloc(sizeof(listNode)); // 새로추가할 노드의 메모리를 할당받는다
	listNode* search; // 현재 노드를 가리킬 포인터 변수 선언
	newnode->key = key; // newnode의 key필드에 사용자에게 입력받은 key값 대입
	search = h->rlink; // search가 리스트의 첫번째 노드를 가리키도록 한다

	newnode->rlink = h; // newnode의 rlink가 h를 가리키도록 한다 (newnode의 다음 노드가 h가 되도록 한다)
	newnode->llink = h->llink; // newnode의 llink가 현재 리스트에서의 마지막 노드를 가리키도록 한다
	h->llink->rlink = newnode; // 현재 리스트에서의 마지막 노드의 rlink가 newnode를 가리키도록 한다
	// (리스트에서의 마지막 노드의 다음노드가 newnode가 되도록 한다)
	h->llink = newnode; // h의 llink가 newnode를 가리키도록 한다 (헤드노드의 이전노드가 newnode가 되도록 한다)

	return 1; 

}

 
/* list의 마지막 노드 삭제 */
int deleteLast(listNode* h)

{
	if (h->rlink == h->llink) // 만약 h->rlink 의 값과 h->llink의 값이 같다면,(리스트에 노드가 존재하지 않는다면)
	{
		printf("삭제할 노드가 없습니다.\n"); // 삭제할 노드가 없다는 문구 출력
		return 0; // 종료
	}

	
	listNode* search; // 노드를 가리킬 포인터 변수 선언
	search = h->llink; // search가 리스트에서의 마지막 노드를 가리키도록 한다

	search->llink->rlink = h; // 현재 리스트에서의 마지막노드의 이전노드의 rlink가 h를 가리키도록 한다 
	h->llink = search->llink; // 헤드노드의 이전노드(리스트에서의 마지막 노드)가 현재 리스트에서 마지막 노드의 이전노드가 되도록 한다

	free(search); // search가 가리키고있는 노드를 해제한다
	return 1;

}

 

 
/* list 처음에 key에 대한 노드하나를 추가 */
int insertFirst(listNode* h, int key)

{
	listNode* newnode = (listNode*)malloc(sizeof(listNode)); // 새로추가할 노드의 메모리를 할당받는다
	newnode->key = key; // newnode의 key필드에 사용자에게 입력받은 key값을 대입한다

	newnode->llink = h; // newnode의 이전노드가 헤드노드가 되도록 한다
	newnode->rlink = h->rlink; // newnode의 다음노드가 현재 리스트의 첫번째 노드가 되도록 한다
	h->rlink->llink = newnode; // 현재 리스트의 첫번째 노드의 이전노드가 newnode가 되도록 한다
	h->rlink = newnode; // 리스트에서의 첫번째 노드가 newnode가 되도록 한다

	return 1;

}

/* list의 첫번째 노드 삭제 */
int deleteFirst(listNode* h) 

{
	if (h->rlink == h->llink) // h->rlink의 값과 h->llink의 값이 같다면(리스트에 노드가 존재하지 않는다면)
	{
		printf("삭제할 노드가 없습니다.\n"); // 삭제할 노드가 없다는 문구 출력
		return 0; // 함수 종료
	}

	listNode* search; // 노드를 가리킬 포인터 변수 선언
	search = h->rlink; // search가 리스트의 첫번째 노드를 가리키도록 한다

	search->rlink->llink = h; // 리스트의 첫번째 노드의 다음 노드의 llink가 h를 가리키도록 한다
	// ( 현재 리스트의 2번째 노드의 이전노드가 h가 되도록 한다 )
	h->rlink = search->rlink; // 헤드노드의 다음노드가 현재 리스트의 2번째 노드가 되도록 한다

	free(search); // search가 가리키는 노드(현재 리스트의 첫번째 노드)의 메모리를 해제한다
	return 1;

}

 
/*리스트의 링크를 역순으로 재 배치*/
int invertList(listNode* h) 

{
	if (h->rlink == h->llink) // h->rlink의 값과 h->llink의 값이 같다면(리스트에 노드가 존재하지 않는다면)
	{
		printf("역순으로 재배치 할 노드가 없습니다.\n"); // 역순으로 재배치할 노드가 없다는 문구 출력
		return 0; // 종료
	}

	listNode* search; // 노드를 가리킬 포인터 변수 선언
	listNode* middle; // search를 뒤따를 포인터 변수 선언
	listNode* tail; // middle을 뒤따를 포인터 변수 선언

	search = h->rlink; // search가 현재 리스트의 첫번째 노드를 가리키도록 한다
	tail = middle = h; // tail과 middle의 값을 h로 초기화한다

	h->llink = search; // 헤드노드의 이전노드가 현재 리스트의 첫번째 노드가 되도록 한다
	// ( 현재 리스트의 첫번째 노드가 마지막 노드가 되도록 한다)

 
	while (search != NULL && search != h) // search가 NULL과 다르고, search가 h와 다르면 계속 반복

	{
		tail = middle; // tail은 middle을 따르도록 한다
		middle = search; // middle은 search를 따르도록 한다
		search = search->rlink; // search는 search가 가리키는 노드의 다음 노드로 이동시킨다
		middle->llink = search; // middle의 이전노드가 search가 가리키는 노드가 되도록 한다
		middle->rlink = tail; // middle의 다음 노드가 tail이 가리키는 노드가 되도록 한다

	}

	// 현재 middle은 원래 리스트에서의 마지막 노드
	middle->rlink = tail; // middle의 다음 노드가 tail이 가리키는 노드가 되도록 한다
	middle->llink = h; // middle의 이전 노드가 헤드노드가 되도록 한다
	h->rlink = middle; // 헤드노드의 다음 노드(즉, 리스트의 첫번째 노드)가 middle(원래 리스트에서의 마지막 노드)이 되도록 한다

	return 0; // 함수 종료

}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(listNode* h, int key) 

{
	listNode* newnode = (listNode*)malloc(sizeof(listNode)); // // 새로추가할 노드의 메모리를 할당받는다
	listNode* search; // 입력받은 key보다 큰값이 나오는 노드를 가리킬 포인터 변수 선언
	newnode->key = key; // newnode의 key필드에 사용자에게 입력받은 key값을 대입한다
	search = h->rlink; // search가 가리키는 노드가 현재 리스트에서의 첫번째 노드가 되도록 한다

	if (h->rlink ==h->llink&&h->rlink==h&&h->llink==h) // h->rlink의 값과 h의 값과 h->llink의 값이 모두 같다면(리스트에 노드가 존재하지 않는다면)

	{
		h->rlink=newnode; // 헤드노드의 다음노드가 newnode가 되도록 한다
		h->llink = newnode; // 헤드노드의 이전노드가 newnode가 되도록 한다
		newnode->rlink = h; // newnode의 다음노드가 헤드노드가 되도록 한다
		newnode->llink = h; // newnode의 이전노드가 헤드노드가 되도록 한다
		return 0; // 함수 종료

	}

	while (search != NULL && search != h) // search가 NULL과 다르고 h와 다르다면 계속 반복
	{
		if (search->key > key) // 만약 search가 가리키는 노드의 key값이 사용자에게 받은 key값보다 크다면
		{
			if (search == h->rlink) // search가 리스트에서 첫번째 노드라면
			{
				newnode->rlink = search; // newnode의 다음 노드가 search가 가리키는 노드가 되도록 한다
				newnode->llink = h; // newnode의 이전 노드가 헤드노드가 되도록 한다
				h->rlink = newnode; // 헤드노드의 다음 노드가 newnode가 되도록 한다 
				search->llink = newnode; // search가 가리키는 노드의 이전노드가 newnode가 되도록 한다
				return 0; // 함수 종료
			}

			else  // search가 리스트 중간에 있는 노드라면
			{
				newnode->rlink = search; // newnode의 다음 노드가 search가 가리키는 노드가 되도록 한다
				newnode->llink = search->llink; // newnode의 이전 노드가 search의 이전노드가 되도록 한다
				search->llink->rlink = newnode; //  search의 이전노드의 다음 노드가 newnode가 되도록 한다
				search->llink = newnode; // search의 이전 노드가 newnode가 되도록 한다
				return 0; // 함수 종료
			}
		}
		search = search->rlink; // key보다 큰 값을 갖는 노드를 찾지 못했다면 search를 다음노드로 이동시킨다

	}

	insertLast(h, key); 
	// search가 가리키는 노드가 리스트에서의 마지막 노드임에도 불구하고 key보다 큰 값을 갖는 노드를 찾지 못했다면
	// 리스트의 마지막에 노드를 추가한다 (해당 함수 호출)

	return 0; // 함수 종료

}

 
/* list에서 key에 대한 노드 삭제 */
int deleteNode(listNode* h, int key) 
{
	if (h->rlink == h->llink) // h->rlink의 값과 h->llink의 값이 같다면(리스트에 노드가 존재하지 않는다면)
	{
		printf("삭제할 노드가 없습니다.\n"); // 삭제할 노드가 없다는 문구 출력
		return 0; // 함수 종료
	}

	
	listNode* search; // 노드를 가리킬 포인터 변수 선언
	search = h->rlink; // search가 가리키는 노드가 현재 리스트에서의 첫번째 노드가 되도록 한다

	while (search!=NULL&&search!=h) // search의 값이 NULL과 다르고 search의 값이 h와 다르면 계속 반복
	{
		if (search->key == key) // search의 key값과 입력받은 key값이 같다면
		{
			if (search == h->rlink) // search가 가리키는 노드가 리스트에서 첫번째 노드라면
			{
				search->rlink->llink = h; // search가 가리키는 노드의 다음 노드의 이전노드가 h가 되도록 한다
				h->rlink = search->rlink; // 헤드노드의 다음노드가 search가 가리키는 노드의 다음 노드가 되도록 한다
				// 즉, 현재 리스트의 두번째 노드가 첫번째 노드가 되도록 할 것임
				free(search); // search가 가리키는 노드의 메모리를 해제한다
				return 0; // 함수 종료

			}
			else if (search->rlink == h) // search가 가리키는 노드가 리스트에서 마지막 노드라면
			{
				search->llink->rlink = h; // search가 가리키는 노드의 이전노드의 다음 노드가 h가 되도록 한다
				h->llink = search->llink; // 헤드노드의 이전 노드가 search가 가리키는 노드의 이전노드가 되도록 한다
				free(search); // search가 가리키는 노드의 메모리를 해제한다
				// 즉, 현재 search가 가리키는 노드(리스트에서의 마지막 노드)를 삭제할것임
				return 0; // 함수 종료

			}
			else // search가 가리키는 노드가 리스트에서 중간에 있다면
			{

				search->llink->rlink = search->rlink; // search가 가리키는 노드의 이전노드의 다음 노드가 search가 가리키는 노드의 다음 노드가 되도록 한다
				search->rlink->llink = search->llink; // search가 가리키는 노드의 다음 노드의 이전 노드가 search가 가리키는 노드의 이전노드가 되도록 한다
				free(search); // search가 가리키는 노드의 메모리를 해제한다
				// 예를 들어, A -> search -> B가 있다면 A -> B 순서가 되도록 할 것임

				return 0; // 함수 종료
			}
		}

		search = search->rlink; // 만약 입력받은 key값을 갖는 노드가 없다면, search를 다음 노드로 이동시킨다
	}

	printf("해당 key=%d 값을 갖는 노드가 없습니다.\n",key); // 위에 해당하는 노드, key값을 가진 노드가 없다면 해당 노드가 없다는 문구 출력

	return 0; // 함수 종료

}
