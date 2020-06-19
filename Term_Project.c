/*
 ============================================================================
 Name        : Term_Project.c
 ============================================================================
 */

#include <stdio.h>

#include <stdlib.h>



#define MAX_VERTEX 20



typedef struct Vertex // ���� ����ü

{

   int num; // ������ ��ȣ

   struct Vertex* link; // ���Ḯ��Ʈ�� ������ ��ũ

}Vertex;



typedef struct VertexHead // �����

{

   struct Vertex* head; // ������ ����ų ������

}VertexHead;



typedef struct Graph

{

   VertexHead* vlist; // ����带 ����ų ������

}Graph;



Graph* createGraph(Graph* G); // �׷����� ���� �ʱ�ȭ��Ű�� �Լ�

int destoryGraph(Graph* G); // �׷����� �ִ� ��� �޸𸮸� �����ϴ� �Լ�

int insertVertex(Graph* G, int num); // ������ �����ϴ� �Լ�

int deleteVertex(Graph* G, int num); // ������ �����ϴ� �Լ�

int insertEdge(Graph* G, int u, int v); // ������ �߰��ϴ� �Լ�

int deleteEdge(Graph* G, int u, int v); // ������ �����ϴ� �Լ�

//void depthFS();

//void breadthFS();

int printGraph(Graph* G); // �׷����� ���� �� ������ ����ϴ� �Լ�



int vflag[MAX_VERTEX] = { 0 }; // ������ ����������� ���θ� �Ǵ��ϴ� �迭



int main()

{

   char command; // ��ɾ �Է¹��� ����

   int u, v, num; //  ���� �� ���� ����

   Graph* Graph = NULL; // �׷��� ������ ����





   do {



      printf("----------------------------------------------------------------\n"); // �޴� ���

      printf("                     ������ �׷���                        \n");

      printf("----------------------------------------------------------------\n");

      printf(" createGraph   = z           Print         = p \n");

      printf(" Insert Vertex = i           Delete Vertex = d \n");

      printf(" Insert Edge   = n           Delete Edge   = e \n");

      printf(" depthFS       = f           breadthFS     = b \n");

      printf(" destoryGraph  = t           Quit          = q \n");

      printf("----------------------------------------------------------------\n");



      printf("Command = "); // ��ɾ �Է¹��� ���� ���
      fflush(stdout);
      scanf(" %c", &command); // ����ڷκ��� ��ɾ �Է¹޴´�



      switch (command)

      {

      case 'z': case 'Z': // �Էµ� ��ɾ z �Ǵ� Z�̸�,

         Graph = createGraph(Graph); // �׷����� ���� �����

         break; // ���ǹ� Ż��



      case 'p': case 'P': // �Էµ� ��ɾ p �Ǵ� P�̸�,

         printGraph(Graph); // �׷����� ������ �������� ����Ѵ�

         break; // ���ǹ� Ż��



      case 'i': case 'I': //�Էµ� ��ɾ i �Ǵ� I�̸�,

         printf("���� �� Vertex Number = ");
         fflush(stdout);

         scanf("%d", &num); // key���� ����ڷκ��� �Է¹޴´�

         insertVertex(Graph, num); // ������ �׷����� �����Ѵ�

         break;// ���ǹ� Ż��



      case 'd': case 'D': // �Էµ� ��ɾ d �Ǵ� D�̸�,

         printf("���� �� Vertex Number = ");
         fflush(stdout);

         scanf("%d", &num);

         deleteVertex(Graph, num); // ������ �׷������� �����Ѵ�

         break;// ���ǹ� Ż��



      case 'n': case 'N': // �Էµ� ��ɾ n �Ǵ� N�̸�,

         printf("Input Edge u,v = "); // ���� ���
         fflush(stdout);

         scanf("%d %d", &u, &v); // ����ڿ��� ������ �Է¹޴´�

         insertEdge(Graph, u, v); // �Է¹��� ������ �׷����� �߰��Ѵ�

         break;// ���ǹ� Ż��



      case 'e': case 'E': // �Էµ� ��ɾ e �Ǵ� E�̸�,

         printf("Delete Edge u,v = "); // ���� ���
         fflush(stdout);

         scanf("%d %d", &u, &v); //  ����ڿ��� ������ �Է¹޴´�

         deleteEdge(Graph, u, v); // �Է¹��� ������ �׷������� �����Ѵ�

         break;// ���ǹ� Ż��



      //case 'f': case 'F': // �Էµ� ��ɾ f �Ǵ� F�̸�,

         //printf("Your Key = ");

         //scanf("%d", &key);

         //depthFS();

         //break;// ���ǹ� Ż��



      //case 'b': case 'B': // // �Էµ� ��ɾ b �Ǵ� B�̸�,

         //breadthFS();

         //break;// ���ǹ� Ż��



      case 't': case 'T': // �Էµ� ��ɾ t �Ǵ� T�̸�,

         destoryGraph(Graph); // �׷����� �Ҵ�� �޸𸮸� �����Ѵ�

         break;// ���ǹ� Ż��



      case 'q': case 'Q': // �Էµ� ��ɾ q �Ǵ� Q�̸�,

         destoryGraph(Graph); // �׷����� �Ҵ�� ��� �޸𸮸� ������ �� ���α׷� ����

         break;// ���ǹ� Ż��



      default: // ���� ��ɾ� �ܿ� �ٸ� ������ �Է��ϸ�

         printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // �ش� �ȳ� ���� ���

         break;// ���ǹ� Ż��

      }

   } while (command != 'q' && command != 'Q'); // ����ڰ� q �Ǵ� Q�� �Է��ϸ� �ݺ��� ����



   return 1;

}



Graph* createGraph(Graph* G) // �׷����� ���� �����ϴ� �Լ�

{

   Graph* g = (VertexHead*)malloc(sizeof(VertexHead) * MAX_VERTEX);// �׷��� ������ ������ vertexhead ũ�⸸ŭ�� �迭�� �Ҵ�޴´�



   for (int i = 0; i < MAX_VERTEX; i++)

   {

      g[i].vlist = NULL; // �ε��� 0������ 19�������� vlist ���� NULL�� �ʱ�ȭ�Ѵ�

      vflag[i] = 0; // vflag�� �ش� �ε������� 0���� �����Ѵ�

   }



   return g; // ������ g ����

}



int destoryGraph(Graph* G) // �׷����� �Ҵ�� �޸𸮸� �����ϴ� �Լ�

{

   VertexHead* p = NULL; // ����带 ����ų ������

   Vertex* temp = NULL;

   Vertex* prev = NULL;



   for (int i = 0; i < MAX_VERTEX; i++)

   {

      if (vflag[i] == 1) // ���� i���� ���� ������ �����Ǿ��ִٸ�

      {

         p = G[i].vlist; // G[i].vlist�� �ּҸ� p�� �����Ѵ�

         temp = p->head; // temp�� p�� ����带 ����Ű���� �Ѵ�



         while (temp != NULL) // temp�� NULL�� �ٸ��ٸ� �ݺ��� ����

         {

            prev = temp; // prev�� temp�� �ڸ� �������� �Ѵ�

            temp = temp->link; // temp�� temp�� �������� �̵���Ų��

            free(prev); // prev�� ����Ű�� ����� �޸𸮸� �����Ѵ�

         }

         free(p); // p�� ����Ű�� ����� �޸𸮸� �����Ѵ�

      }

   }

   free(G); // G�� ����Ű�� ����� �޸𸮸� �����Ѵ�(�迭)





   return 0; // �Լ� ����

}



int insertVertex(Graph* G, int num) // �׷����� ������ �����ϴ� �Լ�

{

   VertexHead* head = (VertexHead*)malloc(sizeof(VertexHead)); // ����带 ����ų ������ ����

   head->head = NULL; // head����� ���� NULL�� �ʱ�ȭ�Ѵ�



   if (vflag[num] == 1) // ���� ����ڿ��� �Է¹��� NUM�� ���� ������ �����Ѵٸ�,

      printf("�̹� �ش� Vertex�� �����մϴ�.\n"); // �̹� �����Ѵٴ� ���� ���



   else // �Է¹��� NUM�� ���� ������ �׷����� ���ٸ�

   {

      G[num].vlist = head; // G[num]�迭�� �޸𸮸� �Ҵ���� ������� �ּҸ� �����Ѵ�

      vflag[num] = 1; // vflag[num]���� 1�� ���� (������ ����ٴ� ��)

   }



   return 0; // ����

}



int deleteVertex(Graph* G, int num) // ������ �����ϴ� �Լ�

{

   VertexHead* p = NULL; // ����� �����͸� NULL�� �ʱ�ȭ

   Vertex* temp = NULL; // ������ ����ų ������ ����

   Vertex* prev = NULL; // temp������ ��带 ����ų ������ ����



   p = G[num].vlist; // G[num].vlist�� �ּҸ� p�� �����Ѵ�

   temp = p->head; // temp�� p->head�� �ּҸ� �����Ͽ� �ʱ�ȭ

   prev = p->head; // prev�� p->head�� �ּҸ� �����Ͽ� �ʱ�ȭ



   if (vflag[num]==0) // ���� ���� num�� �������� �ʴ´ٸ�

   {

      printf("�̹� Vertex�� �������� �ʽ��ϴ�.\n"); // �̹� �������� �ʴ´ٴ� ���� ���

      return 0;

   }



   else // ���� num�� �����Ѵٸ�

   {

      while (temp != NULL) // temp�� NULL�� �ٸ��ٸ� �ݺ��� ����

      {

         prev = temp; // prev�� temp�� �ڸ� �������� �Ѵ�

         temp = temp->link; // temp�� temp���� ��带 ����Ű���� �Ѵ�

         free(prev); // prev�� ����Ű�� ����� �޸𸮸� �����Ѵ�

      }



      for (int i = 0; i < MAX_VERTEX; i++) // �� �迭 0������ 19���������� num�� vertex ����

      {

         if (vflag[i] == 1) // ������ ��������ִ��� Ȯ��, ������� �ִ� ���������� ã�´�

         {

            p = G[i].vlist; // G[i].vlist�� �ּҸ� p�� �����Ѵ�

            temp = p->head; // p->head�� �ּҸ� temp�� �����Ͽ� �ʱ�ȭ

            prev = p->head; // p->head�� �ּҸ� prev�� �����Ͽ� �ʱ�ȭ



            while (temp != NULL) // ���� temp�� NULL�� �ٸ��ٸ� ��� �ݺ�

            {

               if (temp->num == num) // temp�� ����Ű�� ����� num�� �Է¹��� num�� ���ٸ�

               {

                  if (temp == p->head) // ���� temp�� p->head�� ���ٸ�

                  {

                     p->head = temp->link;// ����尡 ����Ű�� �ּҸ� temp���� ���� �����Ѵ�

                  }

                  else // ���� temp�� p->head�� �ٸ��ٸ� (������ � �����Ѵٸ�)

                  {

                     prev->link = temp->link; // temp���� ��尡 temp ���� ��带 ����Ű���� �Ѵ�

                  }

                  free(temp); // temp�� ����Ű�� ����� �޸𸮸� �����Ѵ�



               }

               else // temp�� ����Ű�� ����� num�� �Է¹��� num�� �ٸ��ٸ�

               {

                  prev = temp; // prev�� temp�� �ڵ������� �Ѵ�

                  temp = temp->link; // temp�� �� ���� ���� �̵���Ų��

               }

            }



         }

         free(p); // p�� ����Ű�� ����� �޸𸮸� �����Ѵ�

         vflag[num] = 0; // ���� num�� ���ٴ� �ǹ̷� 0�� ����

      }

   }

   return 0; // �Լ� ����

}



int insertEdge(Graph* G, int u, int v) // ������ �����ϴ� �Լ�

{

   Vertex* vertex = (Vertex*)malloc(sizeof(Vertex)); // ���Ḯ��Ʈ�� ������ vertex ����

   Vertex* temp = NULL; // ������ ����ų ������ �����

   Vertex* prev = NULL; // ������ ����ų ������ ����





   if (vflag[u] == 1 && vflag[v] == 1) // ���� u�� v�� ������ �� �� �����Ѵٸ�

   {

      temp = G[u].vlist->head; // G[u]�迭�� ������� �ּҸ� temp�� �����Ѵ�

      prev = G[u].vlist->head; // G[u]�迭�� ������� �ּҸ� prev�� �����Ѵ�

      vertex->num = v; // vertex�� ����Ű�� ����� num���� v�� �����Ѵ�



      if (temp == NULL) // ���� �ƹ��� ������ �����Ǿ����� �ʴٸ�

      {

         G[u].vlist->head = vertex; // G[u]�迭�� ����忡 vertex�� �ּ� ����

         vertex->link = NULL; // vertex��尡 ���Ḯ��Ʈ���� �������� �ǵ��� �Ѵ�

      }



      else if (temp != NULL) // ���� ������ ���� �Ǿ��ִٸ�

      {

         while (temp != NULL) // temp�� NULL�� �ٸ��� ��� �ݺ�

         {

            if ((temp->num) > v) // ���� temp�� ����Ű�� ����� num���� �Է¹��� v���� ũ�ٸ�

            {

               if (temp == G[u].vlist->head) // ���� temp�� ���Ḯ��Ʈ���� ù��° ���Ҷ��

               {

                  G[u].vlist->head = vertex; // G[u]�迭 ������� ���Ḯ��Ʈ���� ù��° ���Ҹ� vertex�� ���Ѵ�

                  vertex->link = G[u].vlist->head->link; // vertex�� ���� ���� G[u]�迭 ����尡 ����Ű�� ��带 ����Ű���� �Ѵ�

               }

               else

               {

                  vertex->link = temp; // vertex�� ������尡 temp�� ����Ű���� �Ѵ�

                  prev->link = vertex; // temp������ ����� ������ vertex�� �ǵ��� �Ѵ�

                  break; // �ݺ��� Ż��

               }



            } // ���� temp�� ����Ű�� ����� num���� �Է¹��� v���� ũ�ٸ�

            prev = temp; //  temp�� prev�� �ڵ������� �Ѵ�

            temp = temp->link; // temp�� temp���� ���� �̵���Ų��

         }

      }



      temp = G[v].vlist->head; // G[v]�迭�� ������� �ּҸ� temp�� �����Ѵ�

      prev = G[v].vlist->head; // G[u]�迭�� ������� �ּҸ� prev�� �����Ѵ�

      vertex->num = u; // vertex�� ����Ű�� ����� num���� u�� �����Ѵ�



      if (temp == NULL) // ���� �ƹ��� ������ �����Ǿ����� �ʴٸ�

      {

         G[v].vlist->head = vertex; // G[v]�迭�� ����忡 vertex�� �ּ� ����

         vertex->link = NULL; // vertex��尡 ���Ḯ��Ʈ���� �������� �ǵ��� �Ѵ�

      }



      else if (temp != NULL) // ���� ������ ���� �Ǿ��ִٸ�

      {

         while (temp != NULL)  // temp�� NULL�� �ٸ��� ��� �ݺ�

         {

            if ((temp->num) > u) // ���� temp�� ����Ű�� ����� num���� �Է¹��� u���� ũ�ٸ�

            {

               if (temp == G[v].vlist->head) // ���� temp�� ���Ḯ��Ʈ���� ù��° ���Ҷ��

               {

                  G[v].vlist->head = vertex; // G[u]�迭 ������� ���Ḯ��Ʈ���� ù��° ���Ҹ� vertex�� ���Ѵ�

                  vertex->link = G[v].vlist->head->link;// vertex�� ���� ���� G[v]�迭 ����尡 ����Ű�� ��带 ����Ű���� �Ѵ�

               }

               else

               {

                  vertex->link = temp; // vertex�� ������尡 temp�� ����Ű���� �Ѵ�

                  prev->link = vertex; // temp������ ����� ������ vertex�� �ǵ��� �Ѵ�

                  break; // �ݺ��� Ż��

               }



            }

            prev = temp; // prev�� temp�� �ڵ������� �Ѵ�

            temp = temp->link; // temp�� temp ���� ���ҷ� �̵���Ų��

         }

      }



   }

   else

      printf("�ش� ������ �������� �ʾҽ��ϴ�. vertex�� ���� ������ �ֽʽÿ�.\n"); // vflag[u],vflag[v]�� ���� 1�� �ƴ϶�� ������ ���� �����϶�� ���� ���



   return 0; // �Լ� ����

}



int deleteEdge(Graph* G, int u, int v) // ������ �����ϴ� �Լ�

{

   Vertex* temp = NULL;

   Vertex* prev = NULL;



   if (vflag[u] == 1 && vflag[v] == 1) // ���� u�� v�� ���� ���� ������ �����Ѵٸ�

   {

      temp = G[u].vlist->head; // G[u].vlist->head���� temp�� �����Ѵ� (������� �ּ�)

      prev = G[u].vlist->head; // G[u].vlist->head���� prev�� �����Ѵ� (������� �ּ�)



      while (temp != NULL) // temp�� NULL���� �ٸ��ٸ� �ݺ��� ����

      {

         if (temp->num == v) // temp�� ����Ű�� ����� num���� v���� ���ٸ�(������ ����)

         {

            if (temp == G[u].vlist->head) // temp�� ���Ḯ��Ʈ�� ù��°�϶�

            {

               free(temp); // temp�� ����Ű�� ����� �޸𸮸� �����Ѵ�

               G[u].vlist = NULL; // G[u].vlist�� NULL�� �ʱ�ȭ

               vflag[u] = 0; // ���� U�� �������� �ʾҴ�(�����Ǿ���)��� ���� ǥ���ϱ� ���� �迭�� 0 ����



            }

            else if (temp->link == NULL) // temp�� ���Ḯ��Ʈ�� �������϶�

            {

               free(temp); // temp�� ����Ű�� ����� �޸𸮸� �����Ѵ�

               prev->link = NULL; // temp������ ���, �� prev�� ���Ḯ��Ʈ���� ������ ��尡 �ǵ��� �Ѵ�

               vflag[u] = 0; // ���� U�� �������� �ʾҴ�(�����Ǿ���)��� ���� ǥ���ϱ� ���� �迭�� 0 ����



            }

            else // temp�� ����Ʈ�� �߰��϶�

            {

               prev->link = temp->link; // temp���� ����� ���� ��尡 temp�� ������尡 �ǵ��� �Ѵ�

               //  prev temp temp����  ->  prev temp����  (temp�»���)



               free(temp);// temp�� ����Ű�� ����� �޸𸮸� �����Ѵ�

               vflag[u] = 0;// ���� U�� �������� �ʾҴ�(�����Ǿ���)��� ���� ǥ���ϱ� ���� �迭�� 0 ����



            }

         }

         else // temp�� ����Ű�� ����� num���� v���� �ٸ��ٸ�

         {

            prev = temp; // prev�� temp�� �ڵ������� �Ѵ�

            temp = temp->link; // temp�� temp�� ����Ű�� ���� ���� �̵���Ų��

         }

      }



      //temp = NULL; prev = NULL;



      temp = G[v].vlist->head; // G[v].vlist->head���� temp�� �����Ѵ� (������� �ּ�)

      prev = G[v].vlist->head; // G[v].vlist->head���� prev�� �����Ѵ� (������� �ּ�)



      while (temp != NULL) // temp�� NULL���� �ٸ��ٸ� �ݺ��� ����

      {

         if (temp->num == u) // temp�� ����Ű�� ����� num���� u���� ���ٸ�(������ ����)

         {

            if (temp == G[v].vlist->head) // temp�� ���Ḯ��Ʈ�� ù��°�϶�

            {

               free(temp); // temp�� ����Ű�� ����� �޸𸮸� �����Ѵ�

               G[v].vlist = NULL; // G[v].vlist�� NULL�� �ʱ�ȭ

               vflag[v] = 0; // ���� v�� �������� �ʾҴ�(�����Ǿ���)��� ���� ǥ���ϱ� ���� �迭�� 0 ����

            }

            else if (temp->link == NULL) // temp�� ���Ḯ��Ʈ�� �������϶�

            {

               free(temp); // temp�� ����Ű�� ����� �޸𸮸� �����Ѵ�

               prev->link = NULL; // temp������ ���, �� prev�� ���Ḯ��Ʈ���� ������ ��尡 �ǵ��� �Ѵ�

               vflag[v] = 0; // ���� v�� �������� �ʾҴ�(�����Ǿ���)��� ���� ǥ���ϱ� ���� �迭�� 0 ����

            }

            else // temp�� ����Ʈ�� �߰��϶�

            {

               prev->link = temp->link;// temp���� ����� ���� ��尡 temp�� ������尡 �ǵ��� �Ѵ�

               //  prev temp temp����  ->  prev temp����  (temp�»���)



               free(temp); // temp�� ����Ű�� ����� �޸𸮸� �����Ѵ�

               vflag[v] = 0; // ���� v�� �������� �ʾҴ�(�����Ǿ���)��� ���� ǥ���ϱ� ���� �迭�� 0 ����

            }

         }

         else // temp�� ����Ű�� ����� num���� u���� �ٸ��ٸ�

         {

            prev = temp; // prev�� temp�� �ڵ������� �Ѵ�

            temp = temp->link;  // temp�� temp�� ����Ű�� ���� ���� �̵���Ų��

         }

      }



   }

   else // ���� u�� v�� ���� ���� ������ �������� �ʴ´ٸ�

      printf("�ش� ������ �������� �ʾҽ��ϴ�. vertex�� ���� ������ �ֽʽÿ�.\n"); // ������ ���� �����϶�� ���� ���



   return 0; // �Լ� ����



}



int printGraph(Graph* G) // �׷����� ���� �� ������ ����ϴ� �Լ�

{

   //VertexHead* p = NULL; // ����带 ����ų ������ ����

   Vertex* temp; // ������ ����ų ������ ����



   for (int i = 0; i < MAX_VERTEX; i++) // 0���� 19���� ��� �ݺ�

   {

      if (vflag[i] == 1) // ���� i���� ���� ������ �����Ѵٸ�

      {

         //p = G[i].vlist; // �迭 G[i].vlist�� �ּҸ� p�� �����Ѵ�

         temp = G[i].vlist->head; // ������� �ּҸ� temp�� �����Ѵ�

         printf("\n\t���� %d�� ���� ����Ʈ", i); // ������ �����ϴ� ��������Ʈ�� ���ڸ� ���



         while (temp != NULL) // temp�� NULL�� �ٸ��ٸ� ��� �ݺ��Ѵ�

         {

            printf(" -> [%d]", temp->num); // temp->num ���� ����Ѵ�

            temp = temp->link; // temp�� ���� ���Ḯ��Ʈ�� �̵�

         }

      }

   }

   printf("\n"); // �ٹٲ� ���� ���

   return 0; // �Լ� ����

}
