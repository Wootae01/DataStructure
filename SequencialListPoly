#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
typedef struct _polynomial_ {
	float coef;
	int expon;
} polynomial;

polynomial terms[MAX_TERMS];


void initPoly(polynomial* p) {
	for (int i = 0; i < MAX_TERMS; i++) {
		p[i].coef = 0;
		p[i].expon = 0;
	}
}
int compare(int x, int y) {
	if (x > y) {
		return 1;
	}
	else if (x == y) {
		return 0;
	}
	else {
		return -1;
	}
}

polynomial* zeroP(int size) {
	polynomial* tmp = (polynomial*)malloc(sizeof(polynomial) * size);
	if(tmp == NULL){
		fprintf(stderr, "메모리 할당 못함");
		exit(1);
	}
	else{
		initPoly(tmp);
	}
	return tmp;
}

int isZeroP(polynomial* p) {
	for (int i = 0; i < MAX_TERMS; i++) {
		if (p[i].coef != 0) {
			return 0;
		}
	}
	return 1;
}

void attach(polynomial* p, float coef, int expon) {
	int i = 0;
	for (i = 0; i < MAX_TERMS; i++) {
		if (p[i].coef == 0) {
			p[i].coef = coef;
			p[i].expon = expon;
			return;
		}
	}

	fprintf(stderr, "다항식이 꽉 차있습니다.");
}
polynomial* addPoly(polynomial* a, polynomial* b) {
	polynomial* c = zeroP(MAX_TERMS);
	while (a->coef != 0 && b->coef != 0) {
		int com = compare(a->expon, b->expon);
		if (com == 1) {
			attach(c, a->coef, a->expon);
			a++;
		} 
		else if (com == 0) {
			int sum = a->coef + b->coef;
			attach(c, sum, a->expon);
			a++; b++;
		}
		else {
			attach(c, b->coef, b->expon);
			b++;
		}
	}
	return c;
}

void printPoly(polynomial* p) {
	for (int i = 0; i < MAX_TERMS; i++) {
		if (p[i+1].coef == 0) {
			printf("%.1f^%d\n", p[i].coef, p[i].expon);
			break;
		}
		printf("%.1f^%d + ", p[i].coef, p[i].expon);
		
	}
}

int main(void) {
	polynomial* A = zeroP(MAX_TERMS);
	attach(A, 4, 3);
	attach(A, 3, 2);
	attach(A, 2, 1);

	polynomial* B = zeroP(MAX_TERMS);
	attach(B, 3, 5);
	attach(B, 3, 2);
	attach(B, 2, 1);
	printPoly(A);
	printPoly(B);

	polynomial* C = addPoly(A, B);
	printPoly(C);

}	
