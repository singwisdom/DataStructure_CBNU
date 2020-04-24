#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 

int** create_matrix(int row, int column); // 배열에 동적 할당을 받아 행렬 생성하는 함수
int free_matrix(int** matrix, int row, int col); // 동적 할당을 받은 배열의 메모리를 해제하는 함수
int fill_data(int** matrix, int row, int col); // 동적 할당을 받은 배열에 임의의 값을 채워넣는 함수
void print_matrix(int** matrix, int row, int col); // 임의의 값을 채워넣은 행렬을 출력하는 함수
int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col); // 각각의 행렬을 더하는 함수
int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col); // 각각의 행렬을 빼는 함수
int transpose_matrix(int** matrix, int** matrix_t, int row, int col); // 특정 행렬을 전치행렬로 변환하는 함수
int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row, int col); // 각각의 행렬을 곱하는 함수


int main() 

{

	int row, column; // 사용자에게 입력받을 행과 열의 변수 선언

	int ** matrix_a, ** matrix_b, ** matrix_sum, **matrix_sub, ** matrix_axt, **matrix_t; // 이중포인터 변수 선언

	

	printf("\n-----[신지혜]-----[2018038029]-----\n\n");

	printf("< 행렬 연산 프로그램 >\n\n");

	while (1)  // 정상적인 행과 열의 값을 입력받을때까지 반복하는 반복문

	{

		printf("행렬의 행을 입력하세요 : "); // 사용자에게 행의 값을 입력받는다

		scanf("%d", &row);

		printf("행렬의 열을 입력하세요 : "); // 사용자에게 열의 값을 입력받는다

		scanf("%d", &column);

		printf("\n\n");

		if (row <= 0 || column <= 0) // 행과 열이 0 이하의 값으로 입력이 되면, 다시 입력하라는 문구가 뜬다. (전처리검사)

			printf("행과 열을 0 이상의 값으로 다시 입력해주세요\n\n");

		else

			break; // 반복문 탈출

	}

	

	// 동적 메모리를 할당 받아 행렬 생성 //
    matrix_a = create_matrix(row, column); // 행렬 A 생성

	matrix_b = create_matrix(row, column); // 행렬 B 생성

	matrix_t = create_matrix(column, row); // 전치행렬 T 생성

	matrix_sum = create_matrix(row, column); // 행렬 A+B 생성

	matrix_sub = create_matrix(row, column); // 행렬 A-B 생성

	matrix_axt = create_matrix(row, row); // 행렬의 곱을 나타내는 행렬 생성

 

	srand((unsigned int)time(NULL)); // 난수를 생성하기 위해 seed의 값을 계속 바꿔 srand의 인자로 time(NULL) 전달

	
	printf("<A 행렬>\n"); // A행렬 문구 출력

	fill_data(matrix_a, row, column); // A행렬에 값을 채워넣는 함수 호출

	print_matrix(matrix_a, row, column); // 값을 채워넣은 A행렬을 출력하는 함수 호출

	

	printf("<B 행렬>\n"); // B행렬 문구 출력 

	fill_data(matrix_b,row,column); // B행렬에 값을 채워넣는 함수 호출

	print_matrix(matrix_b, row, column); // 값을 채워넣은 B행렬을 출력하는 함수 호출

 

	printf("<A+B 행렬>\n"); // A+B 행렬 문구 출력

	addition_matrix(matrix_a, matrix_b, matrix_sum, row, column); // A와 B행렬을 더하는 함수 호출

	print_matrix(matrix_sum, row, column); // 더한 A와 B행렬을 출력하는 함수 호출

 

	printf("<A-B 행렬>\n"); // A-B 행렬 문구 출력

	subtraction_matrix(matrix_a, matrix_b, matrix_sub, row, column);// A와 B행렬을 빼는 함수 호출

	print_matrix(matrix_sub, row, column); // A-B 행렬을 출력하는 함수 호출

 

	printf("<A의 전치행렬 T>\n"); // A의 전치행렬 T 문구 출력

	transpose_matrix(matrix_a, matrix_t, column, row); // A의 행과 열을 각각 바꾸는 전치행렬을 구하는 함수 호출

	print_matrix(matrix_t, column,row); // A의 전치행렬을 출력하는 함수 호출

 

	printf("<A*T의 행렬>\n"); // A*T 행렬 문구 출력

	multiply_matrix(matrix_a, matrix_t, matrix_axt,row, column); // 행렬 A와 전치행렬T를 곱하는 함수 호출

	print_matrix(matrix_axt,row, row); // 행렬 A와 전치행렬T를 곱한 새로운 행렬(AXT)을 출력하는 함수 

 

	// 할당 받은 메모리 해제//

	free_matrix(matrix_a,row,column); 
    
	free_matrix(matrix_b, row, column);
    
	free_matrix(matrix_sum, row, column);

	free_matrix(matrix_sub, row, column);
   
	free_matrix(matrix_t, column,row);

	free_matrix(matrix_axt, row, row);
    
return 0;
}

 

int** create_matrix(int row, int col) // 행렬을 생성하는 함수

{

	int **arr; // 이중포인터 변수 arr 선언

	int i; // 변수 i 선언

 

	arr = (int**)malloc(sizeof(int*) * row); // 이중 포인터 arr에 (int 포인터 크기 * row)만큼의 동적 메모리 할당. 배열의 세로

 

	for (i = 0; i < row; i++) // row의 크기만큼 반복

	{

		arr[i] = (int*)malloc(sizeof(int) * col); // (int 크기 * coulmn)만큼의 동적 메모리 할당, 배열의 가로

	}

 

	// 후처리 검사 arr에 메모리 할당이 제대로 되지 않았다면

	if (arr == NULL)

		return NULL; // NULL값을 반환 

	else

		return arr;

 

}

 

int free_matrix(int** matrix, int row, int col) // 동적 할당받은 메모리를 해제하는 함수

{

	int i;

	for (i = 0; i < row; i++) // row의 크기만큼 반복

	{

		free(matrix[i]); // 1차원 배열안의 1차원 배열에 할당된 메모리를 해제한다. (2차원 배열의 가로 공간 메모리 해제)

	}

 

	free(matrix); // 2차원 배열의 세로 공간 메모리 해제

 

	matrix = NULL; // 행렬에 null값으로 초기화한다

	

	if (matrix == NULL) // 행렬의 값이 null이면 리턴값을 1로 반환

		return 1;

	else // null이 아니면 리턴값을 -1로 반환

		return -1;

}

 

int fill_data(int** matrix, int row, int col) // 생성된 배열에 값을 채워 넣는 함수

{

	// 전처리 검사 // 입력받은 행 또는 열의 값이 0보다 작으면 -1 반환

	if (row <= 0 || col <= 0)

	{

		printf("Check the sizes of row and col!\n");

		return -1;

	}

	

	

	int i, k;

	

	for (i = 0; i < row; i++) // row의 크기 만큼 반복

	{

		for (k = 0; k < col; k++) // col의 크기 만큼 반복

			matrix[i][k] = rand() % 20; // 난수를 생성하여 2차원배열에 차례대로 랜덤값을 대입한다.

	}

 

	// 후처리 검사, matrix의 값이 NULL이면, -1을 반환한다.

	if (matrix == NULL)  

		return -1;

	else // 그렇지 않으면 (정상적으로 값이 입력되었다면), 1을 반환한다.

		return 1;

 

}

 

void print_matrix(int** matrix, int row, int col) // 생성된 행렬을 출력하는 함수

{

	int i, k;

 

	for (i = 0; i < row; i++) // row의 크기 만큼 반복

	{

		for (k = 0; k < col; k++) // col의 크기 만큼 반복

		{

			printf("%2d ", matrix[i][k]); // 자리수는 2자리씩 맞춘다. 2차원 배열의 값 출력

			if (k+1==col) // 입력받은 열의 숫자까지 배열의 열 인덱스에 값이 생성된다면, 줄바꿈 문자 출력

				printf("\n");

		}

	}

	printf("\n");

}

 

int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col) // 두 행렬을 더하는 함수 

{

	// 전처리 검사 , 입력받은 행 또는 열의 값이 0보다 작으면 -1 리턴 

	if (row <= 0 || col <= 0)

	{

		printf("Check the sizes of row and col!\n");

		return -1;

	}

	

	int i, k;

 

	for (i = 0; i < row; i++) // row의 크기 만큼 반복

	{

		for (k = 0; k < col; k++) // col의 크기 만큼 반복

			matrix_sum[i][k] = matrix_a[i][k] + matrix_b[i][k]; // 행렬 A와 B의 원소들을 각각 더한 후 SUM 배열에 대입

	}

 

	// 후처리 검사,matrix_sum에 값이 제대로 입력되지 않았다면 -1 리턴

	if (matrix_sum == NULL)

		return -1;

	else // 제대로 입력되었다면 1 리턴

		return 1;

}

 

int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col)

{

	// 전처리 검사 , 입력받은 행 또는 열의 값이 0보다 작으면 -1 리턴 

	if (row <= 0 || col <= 0) 

	{

		printf("Check the sizes of row and col!\n");

		return -1;

	}

	

	int i, k;

 

	for (i = 0; i < row; i++) // row의 크기 만큼 반복

	{

		for (k = 0; k < col; k++) // col의 크기 만큼 반복

			matrix_sub[i][k] = matrix_a[i][k] - matrix_b[i][k]; // 행렬 A와 B의 원소들을 각각 뺀 후 SUB 배열에 값 대입

	}

	

	// 후처리 검사, martrix_sub에 값이 제대로 입력되지 않았다면 -1 리턴

	if (matrix_sub == NULL)

		return -1;

	else // 제대로 입력 되었다면 1 리턴

		return 1;

}

 

int transpose_matrix(int** matrix, int** matrix_t, int row, int col) // 전치행렬을 구하는 함수

{

	// 전처리 검사 , 입력받은 행 또는 열의 값이 0보다 작으면 -1 리턴

	if (row <= 0 || col <= 0)

	{

		printf("Check the sizes of row and col!\n");

		return -1;

	} 

 

	int i, k;

 

	for (i = 0; i <col; i++) // col의 크기 만큼 반복

	{

		for (k = 0; k < row; k++) // row의 크기 만큼 반복

			matrix_t[k][i] = matrix[i][k]; // matrix의 행들의값이  matrix_t의 열들의 값에 대입되고, matrix의 열들의 값이 matrix의 행들의 값에 대입된다.

	}

 

	// 후처리 검사, martrix_t에 값이 제대로 입력되지 않았다면 -1 리턴

	if (matrix_t == NULL)

		return -1;

	else

		return 1;

}

 

 

int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row,int col)

{

	int i, k, j, sum = 0;

	

	// 전처리 검사 , 입력받은 행 또는 열의 값이 0보다 작으면 -1 리턴

	if (row <= 0||col==0)

	{

		printf("Check the sizes of row and col!\n");

		return -1;

	}

 

	

	for (i = 0; i < row; i++) // row의 크기 만큼 반복

	{

		

		for (j = 0; j < row; j++) // row의 크기 만큼 반복

		{

			sum = 0; // j의 값이 바뀔때마다 sum을 0으로 초기화 해주어야 한다. (더한 값이 누적되지 않도록)

			for (k = 0; k < col; k++) 

				// 행렬 A*T의 행렬은 A의 행 * T의 열들의 합이다.(T행렬이 A행렬보다 반복문을 좀 더 돌아야 함) ,변수 sum에 값을 누적해서 더한다

			sum += matrix_a[i][k] * matrix_t[k][j]; 

				matrix_axt[i][j] = sum; // sum에 더해진 값들을 axt배열에 대입한다.

			

		}

		

	}

	// 후처리 검사, martrix_axt에 값이 제대로 입력되지 않았다면 -1 리턴

	if (matrix_axt == NULL)

		return -1;

	else // 제대로 입력 되었다면 1 리턴

		return 1;

}