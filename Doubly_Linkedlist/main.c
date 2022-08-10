#include <stdio.h>
#include <stdlib.h>



typedef struct _NODE {
	int data;
	struct _NODE* prev;
	struct _NODE* next;
}Node;


//연결리스트의 기준점이 될 head 노드와 tail 노드를 전역변수로 선언

Node* head, *tail;


void front_insert(int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	if (head->next == NULL) {
		tmp->next = NULL;
		tmp->prev = head;
		head->next = tmp;
		tail->prev = tmp;
	}
	else {
		tmp->next = head->next;
		tmp->prev = head;
		head->next = tmp;
		tail->prev = tmp;
	}
}


void front_delete() {
	if (head->next == NULL) {
		return 0;
	}
	else {
		Node* tmp = head->next;
		head->next = tmp->next;
		Node* next_tmp = tmp->next;
		next_tmp->prev = head;
		free(tmp);
	}
}

void view() {
	Node* tmp = head->next;
	while (tmp != tail) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

int main() {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	front_insert(3); 
	front_insert(2);
	front_insert(1);
	front_delete();
	view();

}	