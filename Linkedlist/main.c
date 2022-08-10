#include <stdio.h>
#include <stdlib.h>




typedef struct _NODE{
	struct _NODE* link;
	int data;
}node;


//전체 연결리스트 출력

void listVIew(node* head) {
	node* tmp;
	for (tmp = head->link; tmp != NULL; tmp = tmp->link) // 노드가 NULL일때까지 돌아감 (연결리스트의 끝까지 돌아감)
		printf("%d ", tmp->data);
	printf("\n");
}

// Insert

void frist_Insert(node* head, int data) {
	node* tmp = malloc(sizeof(node));
	if (head->link == NULL) {
		tmp->data = data;
		tmp->link = NULL;
		head->link = tmp;
	}
	else {
		tmp->data = data;
		tmp->link = head->link;
		head->link = tmp;
	}
}

void last_Insert(node* head, int data) {
	node* tmp = malloc(sizeof(node));
	node* rear = malloc(sizeof(node));
	if ( head->link == NULL) {
		tmp->data = data; 
		tmp->link = NULL; 
		head->link = tmp; 
	}
	else {
		for (rear = head->link; rear->link != NULL; rear = rear->link)
			tmp->data = data;
		tmp->link = NULL; // 맨뒤
		rear->link = tmp;
	}
}


// Delte

void frist_Delete(node* head) {
	if (head->link == NULL) {
		return 0;
	}
	else {
		node* tmp = head->link;
		head->link = tmp->link;
		free(tmp);
	}
}
void last_Delete(node* head) { //이해 불가 그냥 따라적음

	if (head->link == NULL) {
		head = NULL;
	}
	else {
		node* tmp = head;
		while (tmp->link->link != NULL) {
			tmp = tmp->link;
		}
		node* lasttmp = tmp->link;
		tmp->link = NULL;
		free(lasttmp);

	}

}


void linkedlist(node* head) {
	node* tmp = malloc(sizeof(node));
	head->link = NULL;
	int n;

	int input_data;
	while (1)
	{
		printf("1.Insert Front 2.Insert Last 3.Delete Front 4.Delete Last 5.View 6.Exit\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("Insert Vaule\n");
			scanf_s("%d", &input_data);
			frist_Insert(head, input_data);
			break;
		case 2:
			printf("Insert Vaule\n");
			scanf_s("%d", &input_data);
			last_Insert(head, input_data);
			break;
		case 3:
			printf("Delete\n");
			frist_Delete(head);
			break;
		case 4:
			printf("Delete\n");
			last_Delete(head);
			break;
		case 5:
			listVIew(head, tmp);
			break;
		case 6:
			printf("Exit\n");
			exit(1);
		default:
			printf("Error !/n");
			break;
		}
	}
}
void queue(node* head) {
	node* tmp = malloc(sizeof(node));
	head->link = NULL;
	int n;

	int input_data;
	while (1)
	{
		printf("1.Enqueue 2.Dequeue 3.View 4.Exit\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("Insert Vaule\n");
			scanf_s("%d", &input_data);
			last_Insert(head, input_data);
			break;
		case 2:
			printf("Delete\n");
			frist_Delete(head);
			break;
		case 3:
			listVIew(head, tmp);
			break;
		case 4:
			printf("Exit\n");
			exit(1);
		default:
			printf("Error !/n");
			break;
		}
	}
}
void stack(node* head) {
	node* tmp = malloc(sizeof(node));
	head->link = NULL;
	int n;

	int input_data;
	while (1)
	{
		printf("1.Push 2.Pop 3.View 4.Exit\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("Insert Vaule\n");
			scanf_s("%d", &input_data);
			last_Insert(head, input_data);
			break;
		case 2:
			printf("Delete\n");
			last_Delete(head);
			break;
		case 3:
			listVIew(head, tmp);
			break;
		case 4:
			printf("Exit\n");
			exit(1);
		default:
			printf("Error !/n");
			break;
		}
	}
}




int main() {

	node* head = (node*)malloc(sizeof(node)); // head 기준점이 되는 node
	head->link= NULL;
	int n;
	printf("1.LinkedLIst 2.Stack 3. Queue");
	scanf_s("%d", &n);
	switch (n) {
	case 1:
		linkedlist(head);
	case 2:
		stack(head);
	case 3:
		queue(head);
	case -1:
		return 0;
	}

}



//test code



//int main() {
//
//	node* head = malloc(sizeof(node));
//	head->link = NULL;
//	node* main_tmp = malloc(sizeof(node));
//	frist_Insert(head,2);
//	frist_Insert(head,3);
//	frist_Insert(head,4);
//	last_Insert(head,1);
//	frist_Delete(head);
//	last_Delete(head);
//	listVIew(head,main_tmp);
//
//}