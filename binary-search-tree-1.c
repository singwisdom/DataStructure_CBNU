/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int key;
	struct node* left;
	struct node* right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */
void freeBST_2(Node* ptr); // 동적할당을 해제하는 서브함수
Node* searchparent(Node* head, int key); // 찾고자 하는 노드의 부모노드를 탐색하는 함수

 

int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	printf("\n          [---------[2018038029]--------[신지혜]--------]\n"); // 학번과 이름 출력

	do {
		printf("\n\n");
		printf("----------------------------------------------------------------\n"); // 명령어 메뉴 출력
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) 
        {
		case 'z': case 'Z': // 명령어에 Z를 입력하면 트리를 초기화 하는 함수 호출
			initializeBST(&head);
			break;

		case 'q': case 'Q': // 명령어에 Q를 입력하면 할당된 노드의 메모리를 해제하는 함수 호출
			freeBST(head);
			break;

		case 'n': case 'N': // 명령어에 N를 입력하면 노드를 추가하는 함수 호출
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;

		case 'd': case 'D': // 명령어에 D를 입력하면 단말노드를 삭제하는 함수 호출
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;

		case 'f': case 'F': // 명령어에 F를 입력하면 반복문을 이용하여 KEY값을 갖는 노드를 탐색하는 함수 호출
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if (ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 's': case 'S': // 명령어에 S를 입력하면 재귀함수를 이용하여 KEY값을 갖는 노드를 탐색하는 함수 호출
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if (ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I': // 명령어에 I를 입력하면 중위 운행을 하는 함수 호출
			inorderTraversal(head->left);
			break;

		case 'p': case 'P': // 명령어에 P를 입력하면 전위 운행을 하는 함수 호출
			preorderTraversal(head->left);
			break;

		case 't': case 'T': // 명령어에 T를 입력하면 후위 운행을 하는 함수 호출
			postorderTraversal(head->left);
			break;

		default: // 그 외에 다른 명령어를 입력하면 해당 문구 출력
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q'); // Q를 입력받을때까지 반복문을 반복한다

	return 1;

}

int initializeBST(Node** h) // 트리를 초기화 하는 함수
{
	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if (*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	return 1;

}


void inorderTraversal(Node* ptr) // 중위 운행을 하면서 노드의 KEY값을 출력하는 함수 (왼쪽->부모->오른쪽)
{
	if (ptr) // ptr이 참이면 해당 조건문 실행 
	{

		inorderTraversal(ptr->left); // 부모노드의 왼쪽 자식노드를  탐색한다
		printf("%d ", ptr->key); // 부모노드의 key값을 출력한다
		inorderTraversal(ptr->right); // 부모노드의 오른쪽 자식노드를 탐색한다
	}

}

void preorderTraversal(Node* ptr) // 전위 운행을 하면서 노드의 KEY값을 출력하는 함수 (부모->왼쪽->오른쪽)
{

	if (ptr) // ptr이 참이면 해당 조건문 실행
	{
		printf("%d ", ptr->key); // 부모노드의 key값을 출력한다
		preorderTraversal(ptr->left); // 부모노드의 왼쪽 자식노드를 탐색한다
		preorderTraversal(ptr->right); // 부모노드의 오른쪽 자식노드를 탐색한다
	}

}

void postorderTraversal(Node* ptr) // 후위 운행을 하면서 노드의 KEY값을 출력하는 함수 (왼쪽->오른쪽->부모)
{
	if (ptr) // ptr이 참이면 해당 조건문 실행
	{
		postorderTraversal(ptr->left); // 부모노드의 왼쪽 자식노드를 탐색한다
		postorderTraversal(ptr->right); // 부모노드의 오른쪽 자식노드를 탐색한다
		printf("%d ", ptr->key); // 부모노드의 key값을 출력한다
	}

}

 
// 새로 추가할 노드의 key가 부모노드의 key값보다 작다면 왼쪽에, 크다면 오른쪽에 삽입하는 방식 //
int insert(Node* head, int key) // 트리에 노드를 추가하는 함수

{
	Node* search; // 새로 추가할 노드의 부모노드를 가리키는 포인터
	search = head->left; // search에 트리의 첫번째 노드의 주소를 대입한다
	Node* newnode=(Node*)malloc(sizeof(Node)); // 트리에 노드를 추가하기 위해 newnode를 새로 선언하고 동적으로 메모리 할당

	newnode->key = key; // newnode의 key필드에 사용자가 입력한 key값을 대입한다

	if (head->left == NULL) // 만약 트리에 노드가 하나도 존재하지 않는다면
	{
		head->left = newnode; // 새롭게 추가할 노드를 트리의 첫번째 노드로 지정한다
		newnode->left = NULL; // newnode의 left에 NULL값 대입
		newnode->right = NULL; // newnode의 right에 NULL값 대입
		return 0; // 종료
	}

	while (search != NULL) // search가 NULL과 다르다면 계속 반복
	{
		if (search->key > newnode->key) // 만약 search의 key가 새로 추가할 노드의 key값보다 크다면
		{
			if (search->left == NULL) // 만약 search의 왼쪽 자식노드가 존재하지 않는다면
			{
				search->left = newnode; // search의 왼쪽 자식노드를 newnode가 되도록 한다
				newnode->left = NULL; // newnode의 left에 NULL값 대입
				newnode->right = NULL; // newnode의 right에 NULL값 대입
				return 0; // 종료
			}
			else search = search->left; // 만약 왼쪽 자식노드가 있다면, 그 자식의 왼쪽 자식노드로 이동

		}
		else if (search->key < newnode->key) // 만약 search의 key가 새로 추가할 노드의 key값 보다 작다면
		{
			if (search->right == NULL) // 만약 search의 오른쪽 자식노드가 존재하지 않는다면 
			{
				search->right = newnode; // search의 오른쪽 자식노드를 newnode가 되도록 한다
				newnode->left = NULL; // newnode의 left에 NULL값 대입
				newnode->right = NULL; // newnode의 right에 NULL값 대입
				return 0; // 종료
			}

			else search = search->right; // 만약 search의 오른쪽 자식노드가 있다면, 그 자식의 오른쪽 자식노드로 이동
		}

	}

}

 
int deleteLeafNode(Node* head, int key) // 단말노드를 삭제하는 함수
{
	Node* search; // 단말노드를 가리킬 포인터
	Node* parent; // 단말노드의 부모노드를 가리킬 포인터
	search = head->left; // search가 트리의 첫번째 노드를 가리키도록 한다
	parent = head->left; // parent가 트리의 첫번째 노드를 가리키도록 한다

	parent = searchparent(head, key); // searchparent함수를 호출한 후, 반환값을 parent에 대입
	search = searchRecursive(search, key); // 찾고자 하는 노드를 탐색하는 함수를 호출한 후, 반환값을 search에 대입


	if (head->left == NULL) // 만약 트리에 노드가 존재하지 않는다면 안내문구 출력
	{
		printf("트리에 삭제할 노드가 존재하지 않습니다.\n"); 
		return 0; // 종료
	}

	if (search != NULL) // 만약 search가 NULL과 다르다면 반복문 실행
	{
		if (parent->left == search) // 만약 parent의 왼쪽 자식노드가 search가 가리키는 노드라면
		{
			if (search->left == NULL && search->right == NULL) // search가 단말노드가 맞다면
			{
				free(search); // search가 가리키는 노드의 메모리를 해제한다
				parent->left = NULL; // search의 부모노드인 parent의 노드의 left에 NULL값 대입
			}

			else // search가 단말노드가 아니라면 해당 문구 출력
				printf("단말노드가 아닙니다.\n");

			return 0; // 종료

		}

		else if (parent->right == search) // 만약 parent의 오른쪽 자식노드가 search가 가리키는 노드라면
		{
			if (search->left == NULL && search->right == NULL) // search가 단말노드가 맞다면
			{
				free(search); // search가 가리키는 노드의 메모리를 해제한다
				parent->right = NULL; // search의 부모노드인 parent의 노드의 right에 NULL값 대입
			}

			else // search가 단말노드가 아니라면 해당 문구 출력
				printf("단말노드가 아닙니다.\n");

			return 0; // 종료
		}

	}

	else printf("해당 key=%d 값을 갖는 노드가 없습니다. \n", key); // 호출한 함수에서의 리턴값이 NULL이라면 노드가 없다는 문구 출력

}

	
Node* searchRecursive(Node* ptr, int key) // key값을 가진 노드를 탐색하는 함수 (재귀함수)
{
	if (!ptr) // ptr이 거짓이면
		return NULL; // NULL값 반환

	if (ptr->key == key) // 만약 ptr이 가리키는 노드의 key값과 입력받은 key값이 같다면
		return ptr; // ptr의 주소 리턴

	if (ptr->key > key) // 만약 ptr이 가리키는 노드의 key값이 입력받은 key값보다 크다면
	{
		return searchRecursive(ptr->left, key); // 왼쪽 자식노드를 탐색하는 함수 호출 및 반환
	}

	return searchRecursive(ptr->right, key); // ptr이 가리키는 노드의 key값이 입력받은 key값보다 작다면
	// 오른쪽 자식노드를 탐색하는 함수 호출 및 반환

}

 
Node* searchIterative(Node* head, int key) // key값을 가진 노드를 탐색하는 함수
{

	Node* search; // key값을 가진 노드를 가리킬 포인터
	search = head->left; // search에 head->left의 주소를 대입한다

	while (search) // search가 참이면 계속 반복
	{
		if (search->key == key) // search가 가리키는 노드의 key값과 입력받은 key값이 같다면
		{
			return search; // search가 가리키는 노드의 주소 반환
		}

		else if (search->key > key) // search가 가리키는 노드의 key값이 입력받은 key값보다 크다면
		{
			search = search->left; // search를 왼쪽 자식 노드로 이동
		}

		else if (search->key < key) // search가 가리키는 노드의 key값이 입력받은 key값보다 작다면
		{
			search = search->right; // search를 오른쪽 자식 노드로 이동
		}

	}

	return NULL; // key값을 가진 노드가 없다면 NULL 반환
}


Node* searchparent(Node* head, int key) // key값을 가진 노드의 부모노드를 반환하는 함수
{
	Node* search; // key값을 가진 노드를 가리킬 포인터
	search = head->left; // head->left의 주소를 search에 대입
	Node* prev; // search가 가리키는 노드의 부모노드를 가리킬 포인터
	prev = head; // head의 주소를 prev에 대입

	
	while (search) // search가 참이면 계속 반복
	{
		if (search->key == key) // search가 가리키는 노드의 key값과 입력받은 key값이 같다면
		{
			return prev; // 부모노드를 가리키는 prev의 주소 리턴
		}

		else if (search->key > key) // search가 가리키는 노드의 key값이 입력받은 key값보다 크다면
		{   
		    prev = search; // search가 가리키는 노드를 prev도 가리키게 한다
			search = search->left; // search를 왼쪽 자식노드로 이동한다
		}

		else if (search->key < key) // search가 가리키는 노드의 key값이 입력받은 key값보다 작다면
		{
			prev = search; // search가 가리키는 노드를 prev도 가리키게 한다
			search = search->right; // search를 오른쪽 자식노드로 이동한다
		}

	}

	return NULL; // key값을 가진 노드가 없다면 NULL 반환

}

 
int freeBST(Node* head) // 트리의 모든 노드의 메모리를 해제하는 함수
{
	freeBST_2(head->left); // 재귀함수를 이용하여서 메모리를 해제하는 함수 호출
	return 0; // 종료

}

 
void freeBST_2(Node* ptr) // 트리의 모든 노드의 메모리를 해제하는 함수 (재귀 함수 이용)
// 후위 운행의 알고리즘과 똑같다 //
{

	if (ptr) // ptr이 참이라면 조건문실행
	{
		freeBST_2(ptr->left); // ptr의 왼쪽 자식 노드를 인자값으로 대입하고 free함수 호출 (왼쪽 자식노드로 이동)
		freeBST_2(ptr->right); // ptr의 오른쪽 자식 노드 인자값으로 대입하고 free함수 호출 (오른쪽 자식노드로 이동)
		free(ptr); // ptr이 가리키는 노드의 메모리 해제

	}
}
