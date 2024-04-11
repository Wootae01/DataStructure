#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
#define MAX_COL 100
#define MAX_ROW 100

typedef struct _Term_ {
	int row;
	int col;
	int value;
} Term;

Term sparseMatrix[100];


void smTranspose(Term* a, Term* b) {
	int m, n, v, i, j, p;
	m = a[0].row;
	n = a[0].col;
	v = a[0].value;

	b[0].row = n;
	b[0].col = m;
	b[0].value = v;
	if (v > 0) {
		p = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < v; j++) {
				if (i == a[j].col) {
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}
		}
	}
}

void fastTranspose(Term* a, Term* b) {
	int rowTerm[MAX_COL], startingPos[MAX_COL];
	
	int numCols = a[0].col;
	int numTerms = a[0].value;
	
	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0) {
		for (int i = 0; i < numCols; i++) {
			rowTerm[i] = 0;
		}
		for (int i = 1; i <= numTerms; i++) {
			rowTerm[a[i].col]++;
		}

		startingPos[0] = 1;
		for (int i = 1; i <= numCols; i++) {
			startingPos[i] = startingPos[i - 1] + rowTerm[i - 1];
		}

		for (int i = 1; i <= numTerms; i++) {
			int j = startingPos[a[i].col]++;
			b[j].col = a[i].row;
			b[j].row = a[i].col;
			b[j].value = a[i].value;
		}
	}

}


