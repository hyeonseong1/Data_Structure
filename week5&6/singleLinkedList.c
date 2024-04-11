#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int coef;
	int exp;
	struct _Node *next;
} Node;

Node *getNode() {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->coef = 0;
	newNode->exp = 0;
	newNode->next = NULL;

	return newNode;
}

void putNode(Node *h) {
	free(h);
}

void appendTerm(Node *k, int c, int e) {
	Node *temp = getNode();
	temp->coef = c;
	temp->exp = e;
	temp->next = NULL;
	while (k->next != NULL) {
		k = k->next;
	}
	k->next = temp;
}

Node *addPoly(Node *x, Node *y) {
	Node *result = getNode();
	result->next = NULL;
	Node *i = x->next, *j = y->next;
	Node *k = result;
	k->next = NULL;

	int sum;

	while ((i != NULL) & (j != NULL)) {
		if (i->exp > j->exp) {
			appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(k, j->coef, j->exp);
			j = j->next;
		}
		else {
			sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(k, sum, i->exp);
			}
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(k, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		appendTerm(k, j->coef, j->exp);
		j = j->next;
	}

	return result;
}

void print(Node *h) {
	Node *ptr = h->next;
	while (ptr != NULL) {
		printf(" %d %d", ptr->coef, ptr->exp);
		ptr = ptr->next;
	}
	printf("\n");
}

void freeNode(Node *h) {
	Node *ptr = h;
	while (ptr != NULL) {
		h = h->next;
		putNode(ptr);
		ptr = h;
	}
}

int main() {
	Node *h1 = getNode(), *h2 = getNode();
	h1->coef = NULL;
	h1->exp = NULL;
	h1->next = NULL;

	h2->next = NULL;
	h2->coef = NULL;
	h2->exp = NULL;

	Node *result;
	int n1, n2;
	int coef, exp;

	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(h1, coef, exp);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(h2, coef, exp);
	}
	
	result = addPoly(h1, h2);
	print(result);
	freeNode(result);
	freeNode(h2);
	freeNode(h1);

	return 0;
}
