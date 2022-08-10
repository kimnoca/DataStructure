#include <stdio.h>
#include <stdlib.h>

// ����� Ÿ��
typedef struct _Poly{
	int coef;
	int expon;
	struct Poly* link;
} Poly;

// ����Ʈ ����� Ÿ��
typedef struct {
	Poly* head;
	Poly* tail;
} PolyList;


// �� ���׽� ����Ʈ ��� ���� �Լ�
PolyList* create()
{
	PolyList* plist = (PolyList*)malloc(sizeof(PolyList));
	plist->head = plist->tail = NULL;
	return  plist;
}
// plist�� ���� ����Ʈ�� ����� ����Ű�� ������, 
// coef�� ���, expon�� ����
void insert_last(PolyList* plist, int coef, int expon)
{
	Poly* tmp = (Poly*)malloc(sizeof(Poly));
	tmp->coef = coef;
	tmp->expon = expon;
	tmp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = tmp;
	}
	else {
		plist->tail->link = tmp;
		plist->tail = tmp;
	}
}
// list3 = list1 + list2
void poly_add(PolyList* plist1, PolyList* plist2, PolyList* plist3)
{
	Poly* a = plist1->head;
	Poly* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {   		
			sum = a->coef + b->coef;
			if (sum != 0) {
				insert_last(plist3, sum, a->expon);
			}
			a = a->link;
			b = b->link; 
		}
		else if (a->expon > b->expon) {  
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {				
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	for (; a != NULL; a = a->link)  
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)  
		insert_last(plist3, b->coef, b->expon);
}
// list3 = list1 - list2
void poly_sub(PolyList* plist1, PolyList* plist2, PolyList* plist3)
{
	Poly* a = plist1->head;
	Poly* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {   		
			sum = a->coef - b->coef;
			if (sum != 0) {
				insert_last(plist3, sum, a->expon);
			}
			a = a->link; 
			b = b->link;
		}
		else if (a->expon > b->expon) {  	
			insert_last(plist3, -a->coef, a->expon);
			a = a->link;
		}
		else {				
			insert_last(plist3, -b->coef, b->expon);
			b = b->link;
		}
	}
	for (; a != NULL; a = a->link)  
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)  
		insert_last(plist3, b->coef, b->expon);
}
// ����Ʈ ���
void poly_print(PolyList* plist)
{
	Poly* p;

	printf("polynomial = ");
	for (p = plist->head; p != NULL; p = p->link) {
		printf("(%dx^%d) + ", p->coef, p->expon);
	}
	printf("\b\b\n");
}
// ����
int main(void) {
	PolyList* list1, * list2, * list3, * list4;

	// ���� ����Ʈ ��� ����
	list1 = create();
	list2 = create();
	list3 = create(); 
	list4 = create();

	// ���׽� 1�� ���� 
	insert_last(list1, 3, 12); 
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);
	//(3x^12)+(2x^8)+(1^0)

	// ���׽� 2�� ���� 
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);
	//(8x^12)-(2x^10)+(10x^6)
	poly_print(list1);
	poly_print(list2);

	// ���׽� 3 = ���׽� 1 + ���׽� 2
	poly_add(list1, list2, list3);
	poly_sub(list1, list2, list4);
	poly_print(list3);
	poly_print(list4);

	free(list1); 
	free(list2); 
	free(list3); 
	free(list4);
}

