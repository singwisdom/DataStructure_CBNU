// 소프트웨어학과 2018038029 신지혜 //

/*
 * hw5-sorting.c
 *
 *  Created on: May 22, 2019
 *
 *  Homework 5: Sorting & Hashing
 *  Department of Computer Science at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE            13    /* prime number */
#define MAX_HASH_TABLE_SIZE     MAX_ARRAY_SIZE

 /* 필요에 따라 함수 추가 가능 */
int initialize(int** a); // 초기화 하는 함수
int freeArray(int* a); // 배열의 메모리를 해제하는 함수
void printArray(int* a); // 배열의 원소들을 출력하는 함수

int selectionSort(int* a); // 선택정렬 함수
int insertionSort(int* a); // 삽입정렬 함수
int bubbleSort(int* a); // 버블정렬 함수
int shellSort(int* a); // 셸정렬 함수

/* recursive function으로 구현 */
int quickSort(int* a, int n); // 퀵 정렬 함수

/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a에대 한 hash table을 만든다. */
int hashing(int* a, int** ht);

/* hash table에서 key를 찾아 hash table의 index return */
int search(int* ht, int key);


int main()

{
	char command; // 명령어를 입력받을 문자열 변수 선언
	int* array = NULL; // 배열 포인터 변수 선언
	int* hashtable = NULL; // 해쉬테이블 포인터 변수 선언
	int key = -1; // key 변수를 -1로 초기화
	int index = -1; // index 변수를 -1로 초기화

	srand(time(NULL)); // 난수를 랜덤으로 생성하기 위한 srand 함수 (똑같은 난수가 계속 발생하지 않게 해준다)

	do {
		printf("----------------------------------------------------------------\n"); // 메뉴 출력 
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = "); // 명령어를 입력하라는 문구 출력
		scanf(" %c", &command); // 사용자에게 명령어를 입력받는다

		switch (command) // 입력받은 명령어에 따라 조건문 실행 
		{ 
		case 'z': case 'Z': // 사용자에게 Z를 입력받으면
			initialize(&array); // 배열을 초기화 하는 함수 출력
			break; // 조건문 탈출

		case 'q': case 'Q': // 사용자에게 Q를 입력받으면
			freeArray(array); // 배열의 메모리를 해제하는 함수 출력
			break; // 조건문 탈출

		case 's': case 'S': // 사용자에게 S를 입력받으면
			selectionSort(array); // 선택정렬 함수 호출
			break; // 조건문 탈출

		case 'i': case 'I': // 사용자에게 I를 입력받으면
			insertionSort(array); // 삽입정렬 함수 호출
			break; // 조건문 탈출

		case 'b': case 'B': // 사용자에게 B를 입력받으면
			bubbleSort(array); // 버블정렬 함수 호출
			break; // 조건문 탈출

		case 'l': case 'L': // 사용자에게 L을 입력받으면
			shellSort(array); // 셸 정렬 함수 호출
			break; // 조건문 탈출

		case 'k': case 'K': // 사용자에게 K를 입력받으면
			printf("Quick Sort: \n"); // 퀵 정렬 문구 출력
			printf("----------------------------------------------------------------\n");
			printArray(array); // 배열의 원소들을 출력한다
			quickSort(array, MAX_ARRAY_SIZE); // 배열에 있는 원소들을 퀵정렬 방식으로 정렬한다
			printf("----------------------------------------------------------------\n");
			printArray(array); // 정렬된 배열의 원소들 다시 출력
			break; // 조건문 탈출

		case 'h': case 'H': // 사용자에게 H를 입력받으면
			printf("Hashing: \n"); // 해싱 문구 출력
			printf("----------------------------------------------------------------\n");
			printArray(array); // 배열의 원소들을 출력한다
			hashing(array, &hashtable); // 해싱 함수 호출
			printArray(hashtable); // 해쉬테이블의 원소 출력
			break; // 조건문 탈출


		case 'e': case 'E': // 사용자에게 E를 입력받으면
			printf("Your Key = "); // KEY를 입력하라는 문구 출력
			scanf("%d", &key); // 사용자에게 KEY값을 입력받는다
			printArray(hashtable); // 해쉬테이블의 원소 출력
			index = search(hashtable, key); // 해쉬테이블에서 KEY값을 찾아 index에 대입
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]); 
			// 사용자가 입력한 key, index, 해쉬테이블 몇번째 배열에 있는지 출력
			break; // 조건문 탈출

		case 'p': case 'P': // 사용자에게 P를 입력받으면
			printArray(array); // 배열의 원소 출력
			break; // 조건문 탈출

		default: // 위의 명령어 외에 다른 명령어를 입력하게 되면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // 해당 문구 출력
			break; // 조건문 탈출

		}

	} while (command != 'q' && command != 'Q'); // 사용자가 Q를 입력하기 전까지 반복문을 계속 실행한다

	return 1;
}


int initialize(int** a) // 초기화 하는 함수 
{
	int* temp = NULL;

	/* array가 NULL인 경우 메모리 할당 */
	if (*a == NULL) 
	{
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); // 배열의 최대 사이즈만큼의 메모리를 temp에 할당한다
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	}

	else // array가 NULL이 아닌 경우
		temp = *a; // a가 가리키는 주소의 값(주소에 해당하는 값)을 temp에 대입


	/* 랜덤값을 배열의 값으로 저장 */
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;

	return 0; // 함수 종료

}


int freeArray(int* a) // 배열의 메모리를 해제하는 함수
{
	if (a != NULL) // 만약 a가 NULL과 다르다면
		free(a); // a의 메모리 해제

	return 0; // 함수 종료
}

 
void printArray(int* a) // 배열의 원소들을 출력하는 함수
{
	if (a == NULL) // 만약 a가 NULL이라면 
	{
		printf("nothing to print.\n"); // 출력할것이 없다는 문구 출력
		return;
	}

	for (int i = 0; i < MAX_ARRAY_SIZE; i++) // 0부터 배열의 최대 사이즈 전 까지(12까지) i를 1씩 증가하며 반복
		printf("a[%02d] ", i); // 배열의 인덱스 번호 출력
	printf("\n"); // 반복문이 끝나면 줄바꿈 문자 출력

	for (int i = 0; i < MAX_ARRAY_SIZE; i++) // 0부터 배열의 최대 사이즈 전 까지(12까지) i를 1씩 증가하며 반복
		printf("%5d ", a[i]); // 배열의 인덱스에 해당하는 원소 출력 
	printf("\n"); // 반복문이 끝나면 줄바꿈 문자 출력

}


int selectionSort(int* a) // 선택정렬 방식으로 정렬하는 함수 
{
	int min; // 주어진 리스트 중 최솟값을 저장할 변수 선언
	int minindex; // 최솟값을 가진 배열의 인덱스 번호를 저장할 변수 선언
	int i, j; // 반복문에 필요한 변수 선언 

	printf("Selection Sort: \n"); // 선택정렬 문구 출력 
	printf("----------------------------------------------------------------\n");
	printArray(a); // 배열에 있는 원소들을 출력한다

	for (i = 0; i < MAX_ARRAY_SIZE; i++) // i는 0부터 배열의 최대 사이즈 전 까지(12까지) 1씩 증가하며 반복문 실행
	{
		minindex = i; // i를 minindex에 대입 (처음에는 첫번째 인덱스 번호를 대입)
		min = a[i]; // a[i]에 해당하는 원소를 min에 대입 (처음에는 첫번째 배열의 원소가 최솟값이라 가정)
		for (j = i + 1; j < MAX_ARRAY_SIZE; j++) // j는 i+1번부터 배열의 최대 사이즈까지 1씩 증가하며 반복문 실행
		{
			if (min > a[j]) // 만약 a[j]가 현재 min값보다 작다면
			{
				min = a[j]; // a[j] 원소를 min으로 설정한다
				minindex = j; // mimindex를 j로 바꾼다
			}
		}

		// i번째 인덱스까지를 뺀 나머지 리스트를 교체하기 위함
		a[minindex] = a[i]; // a[i]의 원소를 a[minindex]에 대입한다
		a[i] = min; // min값을 a[i]에 대입한다
		// -> a[i] 이후에  최솟값이 나왔다면, a[i]와 해당 배열의 원소를 서로 교환
	}

	printf("----------------------------------------------------------------\n"); // 정렬이 끝난 후
	printArray(a); // 정렬 된 배열의 원소 출력
	return 0; // 함수 종료
}

 
int insertionSort(int* a) // 삽입정렬 방식으로 정렬하는 함수
{
	int i, j, t; // 필요한 변수 선언

	printf("Insertion Sort: \n"); // 삽입정렬 문구 출력
	printf("----------------------------------------------------------------\n");
	printArray(a); // 현재 배열의 원소들을 출력한다
	// 인덱스 0은 이미 정렬된 것이라고 가정, 

	for (i = 1; i < MAX_ARRAY_SIZE; i++) // i는 1부터 배열의 최대 사이즈 전까지(12까지) 1씩 증가하며 반복문 실행
	{
		t = a[i]; // 배열의 a[i] 원소를 t에 대입한다
		j = i; // i의 값을 j에 대입한다

		while (a[j - 1] > t&& j > 0) // a[j-1]이 t보다 크고, j가 0보다 크면 반복문 실행
		{
			a[j] = a[j - 1]; // a[j-1]번째 원소를 a[j]번째 원소에 대입 
			j--; // j를 1만큼 감소시킨다
		}

		a[j] = t; // t를 a[j]번째 원소에 대입한다
		// -> 두번째 원소는 첫번째와 비교, 세번째 원소는 두번째,첫번째 원소와 비교, 네번째원소는 세번째,두번째,첫번째 원소와 비교 ...  
		// 이런식으로 계속 인덱스 번호를 줄여가면서 비교를 하여 원소의 위치를 찾아 삽입한다

	}

	printf("----------------------------------------------------------------\n"); // 정렬이 끝난 후
	printArray(a); // 정렬 된 배열의 원소들을 출력한다

	return 0; // 함수 종료
}


int bubbleSort(int* a) // 버블정렬 방식을 이용하여 정렬하는 함수 
{
	int i, j, t; // 필요한 변수 선언

	printf("Bubble Sort: \n"); // 버블정렬 문구 출력
	printf("----------------------------------------------------------------\n");
	printArray(a); // 현재 배열의 원소들을 출력한다 


	/* 인접한 배열의 요소를 비교, 교환하여 최댓값을 배열의 제일 뒤로 보내는것을 반복*/
	for (i = 0; i < MAX_ARRAY_SIZE; i++) // i는 0부터 배열의 최대 사이즈 전까지(12까지) 1씩 증가하며 반복문 실행
	{
		for (j = 1; j < MAX_ARRAY_SIZE; j++) // j는 1부터 배열의 최대 사이즈 전까지(12까지) 1씩 증가하며 반복문 실행
		{
			if (a[j - 1] > a[j]) // 만약 a[j-1]번째 원소가 a[j]보다 크다면 서로 교체한다 (swap a[j-1] <-> a[j])
			{
				t = a[j - 1]; // a[j-1]번째 원소를 t에 대입한다
				a[j - 1] = a[j]; // a[j]번째 원소를 a[j-1]에 대입한다
				a[j] = t; // t를 a[j]에 대입한다
			}
		}
	}

	printf("----------------------------------------------------------------\n"); // 정렬이 끝난 후 
	printArray(a); // 정렬 된 배열의 원소들을 출력한다

	return 0; // 함수 종료

}


int shellSort(int* a) // 셸 정렬 방식을 이용하여 정렬하는 함수
{
	int i, j, k, h, v; // 필요한 변수 선언

	printf("Shell Sort: \n"); // 셸 정렬 문구 출력
	printf("----------------------------------------------------------------\n");
	printArray(a); // 현재 배열의 원소들을 출력한다 


	for (h = MAX_ARRAY_SIZE / 2; h > 0; h /= 2) // h=MAX_ARRAY_SIZE/2 부터 h가 0보다 클때까지 h를 2로 계속 나누면서 반복문 실행
	{
		for (i = 0; i < h; i++) // i는 0부터 h보다 작을때까지 i를 1씩 증가시키면서 반복문 실행
		{
			for (j = i + h; j < MAX_ARRAY_SIZE; j += h) // j는 i+h부터 j가 MAX_ARRAY_SIZE보다 작을때까지 j=j+h를 수행하면서 반복문 실행
			{
				v = a[j]; // a[j]의 원소를 v에 대입한다
				k = j; // j를 k에 대입한다

				while (k > h - 1 && a[k - h] > v) // k가 h-1보다 크고, a[k-h]의 원소가 v보다 크면 반복문 실행
				{
					a[k] = a[k - h]; // a[k-h]의 원소를 a[k]에 대입한다
					k -= h; // k=k-h 
				}
				a[k] = v; //v를 a[k]에 대입한다
			}
		}
	} // h만큼의 간격으로 떨어진 레코드를 삽입정렬한다 (어느정도 정렬 후 삽입정렬 적용)
	
	printf("----------------------------------------------------------------\n"); // 정렬이 끝난 후 
	printArray(a); // 정렬 된 배열의 원소들을 출력한다

	return 0; // 함수 종료

}

 
int quickSort(int* a, int n) // 퀵 정렬 방식을 이용하여 정렬하는 함수
{
	int v, t; // 필요한 변수 선언
	int i, j; 

	if (n > 1) // 만약 n이 1보다 크다면
	{
		v = a[n - 1]; // a[n-1]번째의 원소를 v에 대입한다 (피봇) -> 맨 처음 피봇은 배열의 맨 오른쪽 원소로 임의지정
		i = -1; // i를 -1로 초기화한다
		j = n - 1; //j에 n-1을 대입한다 

		while (1)
		{
			while (a[++i] < v); // i를 1씩 증가시키면서 a[++i]의 원소가 v보다 작으면 계속 반복한다
			// 왼쪽 정렬에서 기준(pivot)보다 큰 수를 찾는 것

			while (a[--j] > v); // j를 1씩 감소시키면서 a[--j]의 원소가 b보다 크면 계속 반복한다
			// 오른쪽 정렬에서 기준(pivot)보다 작은수를 찾는 것

			if (i >= j) break; // 만약 i가 j보다 크거나 같아지는 순간 반복문을 탈출한다

			t = a[i]; // a[i]번째 원소를 t에 대입한다
			a[i] = a[j]; // a[j]번째 원소를 a[i]번째에 대입한다
			a[j] = t; // t값을 a[j]에 대입한다
			// 즉, a[i] <-> a[j]을 서로 바꾼다

		}

		t = a[i]; // a[i]번째 원소를 t에 대입한다
		a[i] = a[n - 1]; // a[n-1]번째 원소를 a[i]에 대입한다
		a[n - 1] = t; // t값을 a[n-1]에 대입한다
		// 즉, a[i] <-> a[n-1]을 서로 바꾼다

		quickSort(a, i); // a부터 i까지 (pivot 바로 앞) 앞쪽 부분 리스트를 정렬한다
		quickSort(a + i + 1, n - i - 1); // a+i+1부터 n-i-1까지 (pivot 바로 뒤부터~ n-i-1까지) 뒤쪽 부분 리스트를 정렬한다
	
    }// 기준값(피봇값)을 중심으로 왼쪽 부분집합과 오른쪽 부분집합으로 분할하여 정렬한다 

	return 0; // 함수 종료
}


int hashCode(int key) // hashcode를 만드는 함수
{
	return key % MAX_HASH_TABLE_SIZE; // key값과 MAX_HASH_TABLE_SIZE를 나눈 나머지 값을 리턴한다
}

 
int hashing(int* a, int** ht) // 배열 a에 대한 hashtable을 만드는 함수
{
	int* hashtable = NULL; // hash table을 NULL로 초기화한다
	/* hash table이 NULL인 경우 메모리 할당 */

	if (*ht == NULL) 
    {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); // MAX_ARRAY_SIZE만큼의 메모리를 hastable에 할당한다
		*ht = hashtable;  // 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 한다.
	}

	else 
    {
		hashtable = *ht; // hash table이 NULL이 아닌경우, table 재활용, reset to 
	}

	for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++) // i는 0부터 MAX_HASH_TABLE_SIZE 전까지(12까지) 1씩 증가하며 반복문 실행
		hashtable[i] = -1; // hashtable 배열의 원소들에 -1 값을 대입

	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1; // key값을 -1로 초기화
	int hashcode = -1; //  hashcode값을 -1로 초기화
	int index = -1; // index 값을 -1로 초기화

	for (int i = 0; i < MAX_ARRAY_SIZE; i++) // i는 0부터 MAX_HASH_TABLE_SIZE 전까지(12까지) 1씩 증가하며 반복문 실행
	{
		key = a[i]; // a[i]번째 배열의 원소를 key에 대입한다
		hashcode = hashCode(key); // hashcode 함수를 호출하여 반환된 값을 hashcode 변수에 대입한다

		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/

		if (hashtable[hashcode] == -1) // 만약 배열 hashtable[hashcode]번째 원소가 아직 -1이라면
		{
			hashtable[hashcode] = key; // key값을 hashtable[hascode]번째 배열에 대입한다
		} 

		else // 만약 hashtable[hashcode]번째 원소가 -1이 아니라면
		{
			index = hashcode; // hascode의 값을 index에 대입한다

			while (hashtable[index] != -1) // 만약 hashtable[index]번째 원소가 -1과 다르다면 반복문을 계속 실행한다
				// key값을 넣을 테이블을 찾는 것 
			{
				index = (++index) % MAX_HASH_TABLE_SIZE; // index를 1만큼 증가 한 값과 MAX_HASH_TABLE_SIZE를 나눈 나머지 값을 index에 대입한다
				/*printf("index = %d\n", index);*/

			}
			hashtable[index] = key; // hashtable[index]번째 배열에 key값을 대입한다

        }

	}
	return 0; // 함수 종료

}


int search(int* ht, int key) // hash table에서 key를 찾아 hash table의 index를 리턴하는 함수
{
	int index = hashCode(key); // hashCode함수를 호출하여 결과값을 index에 저장

	if (ht[index] == key) // 만약 ht[index]의 원소가 key값과 같다면
		return index; // index를 리턴한다

	
	while (ht[++index] != key) // ht[++index]가 key와 다르다면 반복문 실행 (index는 1씩 계속 증가)
	{
		index = index % MAX_HASH_TABLE_SIZE; // index와 MAX_HASH_TABLE_SIZE를 나눈 나머지 값을 index에 대입
	}

	return index; // index를 리턴한다
}
