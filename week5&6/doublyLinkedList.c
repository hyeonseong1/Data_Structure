#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct __Node__ {
	char e;
	struct __Node__ *prev;
	struct __Node__ *next;
} Node;

Node *getNode() {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void putNode(Node *p) {
	free(p);
}

Node *init(Node **H, Node **T) {
	*H = getNode();
	*T = getNode();
	(*H)->next = *T;
	(*T)->prev = *H;

	return *H;
}

char get(Node *H, int r, int n) {
	if ((r < 1) || (r > (n))) {
		printf("invalid position\n");
		return '1';
	}

	Node *p = H->next;
	for (int i = 1; i < r; i++)
		p = p->next;
	printf("%c", p->e);

	return p->e;
}

void addNodeBefore(Node *p, char e) {
	Node *newNode = getNode();
	newNode->e = e;
	newNode->next = p;
	newNode->prev = p->prev;

	(p->prev)->next = newNode;
	p->prev = newNode;
}

char add(Node *H, int r, char e, int *n) {
	if ((r < 1) || (r > (*n) + 1)) {
		printf("invalid position\n");
		return '0';
	}

	Node *p = H->next;
	for (int i = 1; i < r; i++)
		p = p->next;
	addNodeBefore(p, e);

	*n += 1;
	return e;
}

char addLast(Node *T, char e, int *n) {
	addNodeBefore(T, e);
	*n += 1;
	return e;
}


void print(Node *H) {
	Node *p = H->next;
	while (p->next != NULL) {
		printf("%c", p->e);
		p = p->next;
	}
	printf("\n");
}

char RemoveNode(Node *p) {
	char e = p->e;
	(p->prev)->next = p->next;
	(p->next)->prev = p->prev;
	putNode(p);

	return e;
}
char Remove(Node *H, int r, int *n) {
	if ((r < 1) || (r > (*n))) {
		printf("invalid position\n");
		return '0';
	}

	Node *p = H->next;
	for (int i = 1; i < r; i++)
		p = p->next;
	char e = RemoveNode(p);

	*n -= 1;
	return e;
}

char RemoveLast(Node *T, int *n) {
	char e = RemoveNode(T->prev);
	*n -= 1;
	return e;
}


int main() {
	Node *H; // Head
	Node *T; // Trailer
	Node *L = init(&H, &T);
	int n = 0;

	int k;
	scanf("%d", &k);
	getchar();
	char cal, e, tmp;
	int r;

	for (int i = 0; i < k; i++) {
		scanf("%c", &cal);
		getchar();
		if(cal == 'A') {
			scanf("%d", &r);
			getchar();
			scanf("%c", &e);
			getchar();
			add(L, r, e, &n);
		}
		else if (cal == 'D') {
			scanf("%d", &r);
			getchar();
			Remove(L, r, &n);
		}
		else if (cal == 'G') {
			scanf("%d", &r);
			getchar();
			get(L, r, n);
		}
		else if (cal == 'P') {
			print(L);
		}
	}

	return 0;
}
