#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef int element;
element stack[MAX_SIZE];

int top = -1;

int isEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull() {
	if (top == MAX_SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(element item) {
	if (isFull()) {
		printf("stack이 꽉 차있습니다.");
		return;
	}
	stack[++top] = item;
}

element pop() {
	if (isEmpty()) {
		printf("stack이 비어있습니다.");
		return;
	}
	return stack[top--];
}

element peak() {
	if (isEmpty()) {
		printf("스택이 비어있습니다.");
		return;
	}
	return stack[top];
}

void printStack() {
	printf("[");
	for (int i = 0; i <= top; i++) {
		printf("%d", stack[i]);
		if (i != top) {
			printf(", ");
		}
	}
	printf("]\n");
}

int testfair(char* exp) {
	top = -1;
	for (int i = 0; i < strlen(exp); i++) {
		char symbol = exp[i];
		switch(symbol) {
			case '(':
			case '{':
			case '[':
				push(symbol); break;

			case ')':
			case '}':
			case ']':
				if (top == -1) {
					return 0;
				}
				else {
					element openPair = pop();
					if (symbol == ')' && openPair != '(' ||
						symbol == '}' && openPair != '{' ||
						symbol == ']' && openPair != '[') 
					{
						return 0;
					}
					else break;
				}
		}
		
	}
	if (isEmpty()) {
		return 1;
	}
	else {
		return 0;
	}
}

/*연산자 우선순위 별고 괄호가 있는경우
  중위 표기식을 후위 표기식으로 변경*/
void infix_to_postfixV1(char* exp) {
	top = -1;
	for (int i = 0; i < strlen(exp); i++) {
		char symbol = exp[i];
		switch (symbol) {
			case ')':
				while (top >= 0) {
					printf("%c", pop());
				}
				break;

			case '(':
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
				push(symbol);
				break;
			default:
				printf("%c", symbol);
		}
	}
}
/*lparen, rparen, plus, minus, times, divied, mod, eos 우선순위 */
static char oper[] = { '(', ')', '+', '-', '*', '/', '%', '\0' };
static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

int isOperator(char c) {
	for (int i = 0; i < 8; i++) {
		if (oper[i] == c) {
			return 1;
		}
	}
	return 0;
}
int findIndex(char c) {
	for (int i = 0; i < 8; i++) {
		if (c == oper[i]) {
			return i;
		}
	}
	return -1;
}
void infix_to_postfixV2(char* exp) {
	top = 0;
	stack[0] = 7;
	for (int i = 0; i < strlen(exp); i++) {
		char token = exp[i];
		if (token == ')') {
			while (1) {
				char tmp = oper[pop()];
				if (tmp == '(')
					break;
				else {
					printf("%c", tmp);
				}
			}
			
		} 
		else if (isOperator(token)) {
			int idx = findIndex(token);
			while (isp[stack[top]] >= icp[idx] && isp[stack[top]] != '\0') {
				printf("%c", oper[pop()]);
			}
			push(idx);
		}
		else {
			printf("%c", token);
		}
	}
	while (top > 0) {
		printf("%c", oper[pop()]);
	}
}

int main(void) {
	char str[] = "(a/(b-c+d))*(e-a)*c";
	infix_to_postfixV2(str);
	
}
