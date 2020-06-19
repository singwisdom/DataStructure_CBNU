/*
 ============================================================================
 Name        : Term_Project.c
 ============================================================================
 */

#include <stdio.h>

#include <stdlib.h>



#define MAX_VERTEX 20



typedef struct Vertex // 정점 구조체

{

   int num; // 정점의 번호

   struct Vertex* link; // 연결리스트를 연결할 링크

}Vertex;



typedef struct VertexHead // 헤드노드

{

   struct Vertex* head; // 정점을 가리킬 포인터

}VertexHead;



typedef struct Graph

{

   VertexHead* vlist; // 헤드노드를 가리킬 포인터

}Graph;



Graph* createGraph(Graph* G); // 그래프를 만들어서 초기화시키는 함수

int destoryGraph(Graph* G); // 그래프에 있는 모든 메모리를 해제하는 함수

int insertVertex(Graph* G, int num); // 정점을 삽입하는 함수

int deleteVertex(Graph* G, int num); // 정점을 제거하는 함수

int insertEdge(Graph* G, int u, int v); // 간선을 추가하는 함수

int deleteEdge(Graph* G, int u, int v); // 간선을 제거하는 함수

//void depthFS();

//void breadthFS();

int printGraph(Graph* G); // 그래프의 정점 및 간선을 출력하는 함수



int vflag[MAX_VERTEX] = { 0 }; // 정점이 만들어졌는지 여부를 판단하는 배열



int main()

{

   char command; // 명령어를 입력받을 변수

   int u, v, num; //  간선 및 정점 변수

   Graph* Graph = NULL; // 그래프 포인터 변수





   do {



      printf("----------------------------------------------------------------\n"); // 메뉴 출력

      printf("                     무방향 그래프                        \n");

      printf("----------------------------------------------------------------\n");

      printf(" createGraph   = z           Print         = p \n");

      printf(" Insert Vertex = i           Delete Vertex = d \n");

      printf(" Insert Edge   = n           Delete Edge   = e \n");

      printf(" depthFS       = f           breadthFS     = b \n");

      printf(" destoryGraph  = t           Quit          = q \n");

      printf("----------------------------------------------------------------\n");



      printf("Command = "); // 명령어를 입력받을 문구 출력
      fflush(stdout);
      scanf(" %c", &command); // 사용자로부터 명령어를 입력받는다



      switch (command)

      {

      case 'z': case 'Z': // 입력된 명령어가 z 또는 Z이면,

         Graph = createGraph(Graph); // 그래프를 새로 만든다

         break; // 조건문 탈출



      case 'p': case 'P': // 입력된 명령어가 p 또는 P이면,

         printGraph(Graph); // 그래프의 정점과 간선들을 출력한다

         break; // 조건문 탈출



      case 'i': case 'I': //입력된 명령어가 i 또는 I이면,

         printf("생성 할 Vertex Number = ");
         fflush(stdout);

         scanf("%d", &num); // key값을 사용자로부터 입력받는다

         insertVertex(Graph, num); // 정점을 그래프에 삽입한다

         break;// 조건문 탈출



      case 'd': case 'D': // 입력된 명령어가 d 또는 D이면,

         printf("삭제 할 Vertex Number = ");
         fflush(stdout);

         scanf("%d", &num);

         deleteVertex(Graph, num); // 정점을 그래프에서 삭제한다

         break;// 조건문 탈출



      case 'n': case 'N': // 입력된 명령어가 n 또는 N이면,

         printf("Input Edge u,v = "); // 문구 출력
         fflush(stdout);

         scanf("%d %d", &u, &v); // 사용자에게 간선을 입력받는다

         insertEdge(Graph, u, v); // 입력받은 간선을 그래프에 추가한다

         break;// 조건문 탈출



      case 'e': case 'E': // 입력된 명령어가 e 또는 E이면,

         printf("Delete Edge u,v = "); // 문구 출력
         fflush(stdout);

         scanf("%d %d", &u, &v); //  사용자에게 간선을 입력받는다

         deleteEdge(Graph, u, v); // 입력받은 간선을 그래프에서 삭제한다

         break;// 조건문 탈출



      //case 'f': case 'F': // 입력된 명령어가 f 또는 F이면,

         //printf("Your Key = ");

         //scanf("%d", &key);

         //depthFS();

         //break;// 조건문 탈출



      //case 'b': case 'B': // // 입력된 명령어가 b 또는 B이면,

         //breadthFS();

         //break;// 조건문 탈출



      case 't': case 'T': // 입력된 명령어가 t 또는 T이면,

         destoryGraph(Graph); // 그래프에 할당된 메모리를 해제한다

         break;// 조건문 탈출



      case 'q': case 'Q': // 입력된 명령어가 q 또는 Q이면,

         destoryGraph(Graph); // 그래프에 할당된 모든 메모리를 해제한 후 프로그램 종료

         break;// 조건문 탈출



      default: // 위의 명령어 외에 다른 값들을 입력하면

         printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // 해당 안내 문구 출력

         break;// 조건문 탈출

      }

   } while (command != 'q' && command != 'Q'); // 사용자가 q 또는 Q를 입력하면 반복문 종료



   return 1;

}



Graph* createGraph(Graph* G) // 그래프를 새로 생성하는 함수

{

   Graph* g = (VertexHead*)malloc(sizeof(VertexHead) * MAX_VERTEX);// 그래프 포인터 변수에 vertexhead 크기만큼의 배열을 할당받는다



   for (int i = 0; i < MAX_VERTEX; i++)

   {

      g[i].vlist = NULL; // 인덱스 0번부터 19번까지의 vlist 값을 NULL로 초기화한다

      vflag[i] = 0; // vflag의 해당 인덱스에도 0값을 대입한다

   }



   return g; // 포인터 g 리턴

}



int destoryGraph(Graph* G) // 그래프에 할당된 메모리를 해제하는 함수

{

   VertexHead* p = NULL; // 헤드노드를 가리킬 포인터

   Vertex* temp = NULL;

   Vertex* prev = NULL;



   for (int i = 0; i < MAX_VERTEX; i++)

   {

      if (vflag[i] == 1) // 만약 i값을 가진 정점이 생성되어있다면

      {

         p = G[i].vlist; // G[i].vlist의 주소를 p에 대입한다

         temp = p->head; // temp가 p의 헤드노드를 가리키도록 한다



         while (temp != NULL) // temp가 NULL과 다르다면 반복문 실행

         {

            prev = temp; // prev가 temp의 뒤를 따르도록 한다

            temp = temp->link; // temp는 temp의 다음노드로 이동시킨다

            free(prev); // prev가 가리키는 노드의 메모리를 해제한다

         }

         free(p); // p가 가리키는 노드의 메모리를 해제한다

      }

   }

   free(G); // G가 가리키는 노드의 메모리를 해제한다(배열)





   return 0; // 함수 종료

}



int insertVertex(Graph* G, int num) // 그래프에 정점을 삽입하는 함수

{

   VertexHead* head = (VertexHead*)malloc(sizeof(VertexHead)); // 헤드노드를 가리킬 포인터 변수

   head->head = NULL; // head노드의 값을 NULL로 초기화한다



   if (vflag[num] == 1) // 만약 사용자에게 입력받은 NUM을 가진 정점이 존재한다면,

      printf("이미 해당 Vertex가 존재합니다.\n"); // 이미 존재한다는 문구 출력



   else // 입력받은 NUM을 가진 정점이 그래프에 없다면

   {

      G[num].vlist = head; // G[num]배열에 메모리를 할당받은 헤드노드의 주소를 대입한다

      vflag[num] = 1; // vflag[num]값을 1로 설정 (정점이 생겼다는 뜻)

   }



   return 0; // 종료

}



int deleteVertex(Graph* G, int num) // 정점을 삭제하는 함수

{

   VertexHead* p = NULL; // 헤드노드 포인터를 NULL로 초기화

   Vertex* temp = NULL; // 정점을 가리킬 포인터 변수

   Vertex* prev = NULL; // temp이전의 노드를 가리킬 포인터 변수



   p = G[num].vlist; // G[num].vlist의 주소를 p에 대입한다

   temp = p->head; // temp에 p->head의 주소를 대입하여 초기화

   prev = p->head; // prev에 p->head의 주소를 대입하여 초기화



   if (vflag[num]==0) // 만약 정점 num이 존재하지 않는다면

   {

      printf("이미 Vertex가 존재하지 않습니다.\n"); // 이미 존재하지 않는다는 문구 출력

      return 0;

   }



   else // 정점 num이 존재한다면

   {

      while (temp != NULL) // temp가 NULL과 다르다면 반복문 실행

      {

         prev = temp; // prev가 temp의 뒤를 따르도록 한다

         temp = temp->link; // temp가 temp다음 노드를 가리키도록 한다

         free(prev); // prev가 가리키는 노드의 메모리를 해제한다

      }



      for (int i = 0; i < MAX_VERTEX; i++) // 각 배열 0번부터 19번까지에서 num의 vertex 삭제

      {

         if (vflag[i] == 1) // 정점이 만들어져있는지 확인, 만들어져 있는 정점에서만 찾는다

         {

            p = G[i].vlist; // G[i].vlist의 주소를 p에 대입한다

            temp = p->head; // p->head의 주소를 temp에 대입하여 초기화

            prev = p->head; // p->head의 주소를 prev에 대입하여 초기화



            while (temp != NULL) // 만약 temp가 NULL과 다르다면 계속 반복

            {

               if (temp->num == num) // temp가 가리키는 노드의 num이 입력받은 num과 같다면

               {

                  if (temp == p->head) // 만약 temp가 p->head와 같다면

                  {

                     p->head = temp->link;// 헤드노드가 가리키는 주소를 temp다음 노드로 변경한다

                  }

                  else // 만약 temp가 p->head와 다르다면 (간선이 몇개 존재한다면)

                  {

                     prev->link = temp->link; // temp이전 노드가 temp 다음 노드를 가리키도록 한다

                  }

                  free(temp); // temp가 가리키는 노드의 메모리를 해제한다



               }

               else // temp가 가리키는 노드의 num이 입력받은 num과 다르다면

               {

                  prev = temp; // prev가 temp를 뒤따르도록 한다

                  temp = temp->link; // temp를 그 다음 노드로 이동시킨다

               }

            }



         }

         free(p); // p가 가리키는 노드의 메모리를 해제한다

         vflag[num] = 0; // 정점 num이 없다는 의미로 0을 대입

      }

   }

   return 0; // 함수 종료

}



int insertEdge(Graph* G, int u, int v) // 간선을 생성하는 함수

{

   Vertex* vertex = (Vertex*)malloc(sizeof(Vertex)); // 연결리스트에 연결할 vertex 변수

   Vertex* temp = NULL; // 정점을 가리킬 포인터 ㅂ녀수

   Vertex* prev = NULL; // 정점을 가리킬 포인터 변수





   if (vflag[u] == 1 && vflag[v] == 1) // 만약 u와 v의 정점이 둘 다 존재한다면

   {

      temp = G[u].vlist->head; // G[u]배열의 헤드노드의 주소를 temp에 대입한다

      prev = G[u].vlist->head; // G[u]배열의 헤드노드의 주소를 prev에 대입한다

      vertex->num = v; // vertex가 가리키는 노드의 num값에 v를 대입한다



      if (temp == NULL) // 만약 아무런 간선이 생성되어있지 않다면

      {

         G[u].vlist->head = vertex; // G[u]배열의 헤드노드에 vertex의 주소 대입

         vertex->link = NULL; // vertex노드가 연결리스트에서 마지막이 되도록 한다

      }



      else if (temp != NULL) // 만약 간선이 생성 되어있다면

      {

         while (temp != NULL) // temp가 NULL과 다르면 계속 반복

         {

            if ((temp->num) > v) // 만약 temp가 가리키는 노드의 num값이 입력받은 v보다 크다면

            {

               if (temp == G[u].vlist->head) // 만약 temp가 연결리스트에서 첫번째 원소라면

               {

                  G[u].vlist->head = vertex; // G[u]배열 헤드노드의 연결리스트에서 첫번째 원소를 vertex로 정한다

                  vertex->link = G[u].vlist->head->link; // vertex의 다음 노드는 G[u]배열 헤드노드가 가리키던 노드를 가리키도록 한다

               }

               else

               {

                  vertex->link = temp; // vertex의 다음노드가 temp를 가리키도록 한다

                  prev->link = vertex; // temp이전의 노드의 다음이 vertex가 되도록 한다

                  break; // 반복문 탈출

               }



            } // 만약 temp가 가리키는 노드의 num값이 입력받은 v보다 크다면

            prev = temp; //  temp를 prev가 뒤따르도록 한다

            temp = temp->link; // temp를 temp다음 노드로 이동시킨다

         }

      }



      temp = G[v].vlist->head; // G[v]배열의 헤드노드의 주소를 temp에 대입한다

      prev = G[v].vlist->head; // G[u]배열의 헤드노드의 주소를 prev에 대입한다

      vertex->num = u; // vertex가 가리키는 노드의 num값에 u를 대입한다



      if (temp == NULL) // 만약 아무런 간선이 생성되어있지 않다면

      {

         G[v].vlist->head = vertex; // G[v]배열의 헤드노드에 vertex의 주소 대입

         vertex->link = NULL; // vertex노드가 연결리스트에서 마지막이 되도록 한다

      }



      else if (temp != NULL) // 만약 간선이 생성 되어있다면

      {

         while (temp != NULL)  // temp가 NULL과 다르면 계속 반복

         {

            if ((temp->num) > u) // 만약 temp가 가리키는 노드의 num값이 입력받은 u보다 크다면

            {

               if (temp == G[v].vlist->head) // 만약 temp가 연결리스트에서 첫번째 원소라면

               {

                  G[v].vlist->head = vertex; // G[u]배열 헤드노드의 연결리스트에서 첫번째 원소를 vertex로 정한다

                  vertex->link = G[v].vlist->head->link;// vertex의 다음 노드는 G[v]배열 헤드노드가 가리키던 노드를 가리키도록 한다

               }

               else

               {

                  vertex->link = temp; // vertex의 다음노드가 temp를 가리키도록 한다

                  prev->link = vertex; // temp이전의 노드의 다음이 vertex가 되도록 한다

                  break; // 반복문 탈출

               }



            }

            prev = temp; // prev가 temp를 뒤따르도록 한다

            temp = temp->link; // temp를 temp 다음 원소로 이동시킨다

         }

      }



   }

   else

      printf("해당 정점이 생성되지 않았습니다. vertex를 먼저 생성해 주십시오.\n"); // vflag[u],vflag[v]의 값이 1이 아니라면 정점을 먼저 생성하라는 문구 출력



   return 0; // 함수 종료

}



int deleteEdge(Graph* G, int u, int v) // 간선을 삭제하는 함수

{

   Vertex* temp = NULL;

   Vertex* prev = NULL;



   if (vflag[u] == 1 && vflag[v] == 1) // 만약 u와 v의 값을 가진 정점이 존재한다면

   {

      temp = G[u].vlist->head; // G[u].vlist->head값을 temp에 대입한다 (헤드노드의 주소)

      prev = G[u].vlist->head; // G[u].vlist->head값을 prev에 대입한다 (헤드노드의 주소)



      while (temp != NULL) // temp가 NULL값과 다르다면 반복문 실행

      {

         if (temp->num == v) // temp가 가리키는 노드의 num값과 v값이 같다면(삭제할 간선)

         {

            if (temp == G[u].vlist->head) // temp가 연결리스트의 첫번째일때

            {

               free(temp); // temp가 가리키는 노드의 메모리를 해제한다

               G[u].vlist = NULL; // G[u].vlist를 NULL로 초기화

               vflag[u] = 0; // 정점 U는 생성되지 않았다(삭제되었다)라는 것을 표기하기 위해 배열에 0 대입



            }

            else if (temp->link == NULL) // temp가 연결리스트의 마지막일때

            {

               free(temp); // temp가 가리키는 노드의 메모리를 해제한다

               prev->link = NULL; // temp이전의 노드, 즉 prev가 연결리스트에서 마지막 노드가 되도록 한다

               vflag[u] = 0; // 정점 U는 생성되지 않았다(삭제되었다)라는 것을 표기하기 위해 배열에 0 대입



            }

            else // temp가 리스트의 중간일때

            {

               prev->link = temp->link; // temp이전 노드의 다음 노드가 temp의 다음노드가 되도록 한다

               //  prev temp temp다음  ->  prev temp다음  (temp는삭제)



               free(temp);// temp가 가리키는 노드의 메모리를 해제한다

               vflag[u] = 0;// 정점 U는 생성되지 않았다(삭제되었다)라는 것을 표기하기 위해 배열에 0 대입



            }

         }

         else // temp가 가리키는 노드의 num값과 v값이 다르다면

         {

            prev = temp; // prev는 temp를 뒤따르도록 한다

            temp = temp->link; // temp는 temp가 가리키는 다음 노드로 이동시킨다

         }

      }



      //temp = NULL; prev = NULL;



      temp = G[v].vlist->head; // G[v].vlist->head값을 temp에 대입한다 (헤드노드의 주소)

      prev = G[v].vlist->head; // G[v].vlist->head값을 prev에 대입한다 (헤드노드의 주소)



      while (temp != NULL) // temp가 NULL값과 다르다면 반복문 실행

      {

         if (temp->num == u) // temp가 가리키는 노드의 num값과 u값이 같다면(삭제할 간선)

         {

            if (temp == G[v].vlist->head) // temp가 연결리스트의 첫번째일때

            {

               free(temp); // temp가 가리키는 노드의 메모리를 해제한다

               G[v].vlist = NULL; // G[v].vlist를 NULL로 초기화

               vflag[v] = 0; // 정점 v는 생성되지 않았다(삭제되었다)라는 것을 표기하기 위해 배열에 0 대입

            }

            else if (temp->link == NULL) // temp가 연결리스트의 마지막일때

            {

               free(temp); // temp가 가리키는 노드의 메모리를 해제한다

               prev->link = NULL; // temp이전의 노드, 즉 prev가 연결리스트에서 마지막 노드가 되도록 한다

               vflag[v] = 0; // 정점 v는 생성되지 않았다(삭제되었다)라는 것을 표기하기 위해 배열에 0 대입

            }

            else // temp가 리스트의 중간일때

            {

               prev->link = temp->link;// temp이전 노드의 다음 노드가 temp의 다음노드가 되도록 한다

               //  prev temp temp다음  ->  prev temp다음  (temp는삭제)



               free(temp); // temp가 가리키는 노드의 메모리를 해제한다

               vflag[v] = 0; // 정점 v는 생성되지 않았다(삭제되었다)라는 것을 표기하기 위해 배열에 0 대입

            }

         }

         else // temp가 가리키는 노드의 num값과 u값이 다르다면

         {

            prev = temp; // prev는 temp를 뒤따르도록 한다

            temp = temp->link;  // temp는 temp가 가리키는 다음 노드로 이동시킨다

         }

      }



   }

   else // 만약 u와 v의 값을 가진 정점이 존재하지 않는다면

      printf("해당 정점이 생성되지 않았습니다. vertex를 먼저 생성해 주십시오.\n"); // 정점을 먼저 생성하라는 문구 출력



   return 0; // 함수 종료



}



int printGraph(Graph* G) // 그래프의 정점 및 간선을 출력하는 함수

{

   //VertexHead* p = NULL; // 헤드노드를 가리킬 포인터 변수

   Vertex* temp; // 정점을 가리킬 포인터 변수



   for (int i = 0; i < MAX_VERTEX; i++) // 0부터 19까지 계속 반복

   {

      if (vflag[i] == 1) // 만약 i값을 가진 정점이 존재한다면

      {

         //p = G[i].vlist; // 배열 G[i].vlist의 주소를 p에 대입한다

         temp = G[i].vlist->head; // 헤드노드의 주소를 temp에 대입한다

         printf("\n\t정점 %d의 인접 리스트", i); // 정점이 존재하는 인접리스트의 글자만 출력



         while (temp != NULL) // temp가 NULL과 다르다면 계속 반복한다

         {

            printf(" -> [%d]", temp->num); // temp->num 값을 출력한다

            temp = temp->link; // temp를 다음 연결리스트로 이동

         }

      }

   }

   printf("\n"); // 줄바꿈 문자 출력

   return 0; // 함수 종료

}
