/*
 * postfix.c
 *
 *  2020 Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10 // MAX_STACK_SIZX를 10으로 지정
#define MAX_EXPRESSION_SIZE 20 // MAX_EXPRESSION_SIZE를 20으로 지정

 
 /* stack 내에서 우선순위, lparen = 0 가장 낮음 */

typedef enum 
{
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */

} precedence;


char infixExp[MAX_EXPRESSION_SIZE];    // infix expression을 저장하는 배열 
char postfixExp[MAX_EXPRESSION_SIZE]; // postfix로 변경된 문자열을 저장하는 배열 
char postfixStack[MAX_STACK_SIZE];   // postfix로 변환을 위해 필요한 스택 
int evalStack[MAX_STACK_SIZE];       // 계산을 위해 필요한 스택 


int postfixStackTop = -1;  // postfixStack용 top을 -1로 초기화
int evalStackTop = -1;    // evalStack용 top을 -1로 초기화
int evalResult = 0;      // 계산 결과를 저장 


void postfixPush(char x) // postfix 스택에 값을 집어 넣는 함수

{
	postfixStack[++postfixStackTop] = x; // 입력받은 x값을 top변수 1 증가 후 postfix스택에 집어 넣는다

}
char postfixPop() // postfix 스택의 값을 빼는 함수

{
	char x; 
	if (postfixStackTop == -1) // 만약 postfix 스택의 top값이 -1이라면

		return '\0'; // 널문자를 리턴한다

	else 
	{
		x = postfixStack[postfixStackTop--]; // 스택의 값을 x에 대입한 후 top변수를 1만큼 감소 시킨다

	}
	return x; // x값 리턴
}

void evalPush(int x) // eval 스택에 값을 집어 넣는 함수

{
	evalStack[++evalStackTop] = x; // x값을 top 변수 1만큼 증가 후 eval 스택에 대입 한다

}
int evalPop() //eval 스택의 값을 빼는 함수

{

	if (evalStackTop == -1) // 만약 eval 스택의 top값이 -1이라면

		return -1; // -1을 리턴한다

	else
		return evalStack[evalStackTop--]; 
		// top값이 -1이 아니라면 eval 스택의 탑 인덱스값을 리턴한 후 top 변수를 1만큼 감소시킨다

}

/**

 * infix expression을 입력받는다.

 * infixExp에는 입력된 값을 저장한다.

 */

void getInfix() // 중위 표기법을 입력받는 함수

{
	printf("Type the expression >>> ");
	scanf("%s", infixExp); // 사용자에게 수식을 입력받는다
}

precedence getToken(char symbol) // 입력받은 수식을 판단해주는 함수

{
	switch (symbol) 
    {
    case '(': return lparen; // 입력받은 문자가 왼쪽괄호이면 lparen 리턴
	case ')': return rparen; // 입력받은 문자가 오른쪽괄호이면 rparen 리턴
	case '+': return plus; // 입력받은 문자가 더하기이면 plus 리턴
	case '-': return minus; // 입력받은 문자가 빼기이면 minus 리턴
	case '/': return divide; // 입력받은 문자가 나누기이면 divide 리턴
	case '*': return times; // 입력받은 문자가 곱하기이면 times 리턴
	default: return operand; // 그 외 다른문자이면 operand 리턴
	}
}

 
precedence getPriority(char x) // 입력받은 수식의 우선수위를 결정하는 함수
{
    return getToken(x); // getToken함수를 호출한 후 해당 결과값을 리턴
}

void charCat(char* c) // 문자하나를 전달받아, postfixExp에 추가
 
{
    if (postfixExp == '\0') // 만약 배열이 끝이라면, 
		strncpy(postfixExp, c, 1); // c의 문자를 postfixExp에 복사한다

	else // 배열 끝이 아니라면, 
		strncat(postfixExp, c, 1); // c의 문자를 postfixExp에 덧붙인다

}
/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */

void toPostfix()

{

	char* exp = infixExp; /* infixExp의 문자 하나씩을 읽기위한 포인터 */
	//char x; /* 문자하나를 임시로 저장하기 위한 변수 */
	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */

	while (*exp != '\0') // 문자열의 끝을 알리는 널문자가 나오기 전까지 계속 반복한다
	{
		int j = 0;
		for (int i = 0; strlen(infixExp); i++) // i는 0부터 배열의 길이만큼 i값을 1씩 증가하며 반복한다
		{

			if (infixExp[i] == operand) // 만약 해당 배열의 값이 피연산자라면, 

				postfixExp[j++] = infixExp[i]; // 그 값을 postfix배열에 대입한 후 인덱스를 1만큼 증가시킨다
			else // 만약 연산자라면, 
			{
				if (infixExp[i] == '(') // 해당 infixExp[i]의 값과 왼쪽 괄호와 동일하다면

				{
					postfixPush(infixExp[i]); // 그 값을 postfix 스택에 집어넣는다
				}
				else if (infixExp[i] == ')') // 만약 infixExp[i]의 값이 오른쪽 괄호라면

					while (postfixStack[postfixStackTop] != lparen) // postfix 스택에서 왼쪽괄호가 나올때까지 반복

					{
						postfixExp[j++] = postfixPop(); 
						// 스택의 값을 빼낸 후 postfix배열에 대입 한 후 인덱스를 1만큼 증가시킨다

					}

				else // 왼쪽 괄호도 아니고 오른쪽 괄호도 아닌 다른 피 연산자라면, 

				{
					if (strlen(postfixStack) == 0) 
					// postfix스택 배열의 길이가 0이라면 (아직 아무 값도 입력되지 않았다면)

						postfixPush(infixExp[i]); // 해당 연산자를 postfix 스택에 집어넣는다.

					else // 이미 다른 연산자가 스택에 있다면
					{
						while (getPriority(postfixStack[postfixStackTop]) >= getPriority(postfixExp[i]))
						// postfixExp[i]의 우선순위와 postfix스택 탑의 우선순위를 비교하여 postfixExp[i]가 더 작거나 같으면 반복
						{

							postfixExp[j++] = postfixPop(); 
							// // 스택의 값을 빼낸 후 postfix배열에 대입 한 후 인덱스를 1만큼 증가시킨다

						}postfixPush(infixExp[i]); // infixExp[i]의 값을 스택에서 빼낸다
					}

				}
			}
		}
	}
}

void debug() // 디버그 함수 

{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp); // infixExp 배열의 원소들 출력
	printf("postExp =  %s\n", postfixExp); // postfixExp 배열의 원소들 출력
	printf("eval result = %d\n", evalResult); // evalResult값 출력

	printf("postfixStack : ");

	for (int i = 0; i < MAX_STACK_SIZE; i++) // i는 0부터 9까지 1씩 증가하면서 반복

		printf("%c  ", postfixStack[i]); // postfixStack의 배열 원소들을 출력한다

	printf("\n");

}


void reset() // 초기화 하는 함수

{
	infixExp[0] = '\0'; // infixExp 배열의 인덱스 0번에 문자열의 끝값을 대입
	postfixExp[0] = '\0'; // postfixExp 배열의 인덱스 0번에 문자열의 끝값을 대입

	for (int i = 0; i < MAX_STACK_SIZE; i++) // i는 0부터 9까지 1씩 증가하면서 반복

		postfixStack[i] = '\0'; // 해당 인덱스의 값에 널문자를 대입한다

	postfixStackTop = -1; // postfix 스택의 top값을 -1로 초기화
	evalStackTop = -1; // eval 스택의 top값을 -1로 초기화
	evalResult = 0; // evalResult값을 -1로 초기화
}

void evaluation() // postfix로 바꾼 표기식을 계산하는 함수
{
	char symbol;
	int op1, op2;
	int n = 0;
	int top = -1;

	for(int i=0;postfixExp[i]!=0;i++) // i는 0부터 postfixExp 원소의 값이 0과 같지 않는 한 계속 반복

	{

		symbol = postfixExp[i]; // postfixExp[i]의 값을 변수 symbol에 대입

		if (symbol == operand) // 만약 symbol이 피연산자라면

			evalPush(symbol - '0'); // eval 스택에 symbol-'0'값을 집어 넣는다.

		else // symbol이 연산자라면
		{
			op2 = evalPop(); // eval 스택에서 값을 빼낸 후 op2에 대입
			op1 = evalPop(); // eval 스택에서 값을 빼낸 후 op1에 대입
			switch (symbol)
			{
			case plus: evalPush(op1 + op2); break; // 연산자가 더하기라면, op1+op2값을 eval스택에 집어넣는다
			case minus: evalPush(op1 - op2); break; // 연산자가 빼기라면, op1-op2값을 eval스택에 집어넣는다
			case times: evalPush(op1 * op2); break; // 연산자가 곱하기라면, op1*op2값을 eval스택에 집어넣는다
			case divide: evalPush(op1 / op2); break; // 연산자가 나누기라면, op1/op2값을 eval스택에 집어넣는다
			}
		}
	}
	printf("%d", evalPop()); // evalPop함수를 호출하여 결과값을 출력한다
}

int main() // 메인 함수
{
	char command;
		printf("--------------[신지혜]------------------[2018038029]-------------\n"); // 학번과 이름 출력
	do {
		// 메뉴 출력 //
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); // 사용자로부터 명령어를 입력받는다

		switch (command) 
		{
		case 'i': case 'I': // 만약 입력받은 명령어가 i 혹은 I 라면
			getInfix(); // 수식을 입력받는 함수 호출
			break;

		case 'p': case 'P': // 만약 입력받은 명령어가 p 혹은 P 라면
			toPostfix(); // 후위 표기법으로 전환하는 함수 호출
			break;

		case 'e': case 'E': // 만약 입력받은 명령어가 e 혹은 E 라면
			evaluation(); // 값을 계산하는 함수 호출
			break;

		case 'd': case 'D': // 만약 입력받은 명령어가 d 혹은 D 라면
			debug(); // 디버그 하는 함수 호출
			break;

		case 'r': case 'R': // 만약 입력받은 명령어가 r 혹은 R 라면
			reset(); // 초기화하는 함수 호출
			break;

		case 'q': case 'Q': // 만약 입력받은 명령어가 q 혹은 Q 라면
			break; // 반복문 탈출

		default: // 그 외의 값을 입력받는 다면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // 해당 문구 출력
			break;
		}
	} while (command != 'q' && command != 'Q'); // 사용자에게 q 그리고 Q를 입력받기 전까지 계속 반복한다
	return 0;
}
