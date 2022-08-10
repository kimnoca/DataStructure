#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* rchild;
	struct Node* lchild;
	int data;
}Node;

Node* root; //Tree의 Root node 를 전역 함수로 선언. 

Node* insert(Node* root ,int data) {
	if (!root) { //root가 Null 이라면 root node 가 없을때
		root = (Node*)malloc(sizeof(Node));
		root->rchild = root->lchild = NULL;
		root->data = data;
		return root;
	}
	else { //root node 가 !Null
		if (data < root->data) { 
			root->lchild = insert(root->lchild, data);
		}
		else {
			root->rchild = insert(root->rchild, data);
		}
	}
	return root;
}
//전위 순회
void preorder(Node * root){
	if (root) { //root 가 Null이 아니라면
		printf("%d -> ", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
//중위 순회
void inorder(Node* root){
	if (root) { 
		inorder(root->lchild);
		printf("%d -> ", root->data);
		inorder(root->rchild);
	}
}
//후위 순회
void postorder(Node* root){
	if (root) { 
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d -> ", root->data);
	}
}
//모든 순회를 출력
void veiw() {
	printf("Preorder\n");
	preorder(root);
	printf("\nInorder\n");
	inorder(root);
	printf("\nPostorder\n");
	postorder(root);
	printf("\n");
}
void tree_menu(){
	int op, data;
	while (1) {
		printf("1.Insert 2. View");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			if (!root) {
				printf("Root Node의 Data 값을 입력하시오 : ");
				scanf_s("%d", &data);
				root = insert(root, data);
				break;
			}
			else {
				printf("삽입할 Child Node의 Data 값을 입력하시오 : ");
				scanf_s("%d", &data);
				root = insert(root, data);
				break;
			}
		case 2:
			veiw();
			break;
		default:
			printf("Error!\n");
		}
	}
}

int main() {
	tree_menu();
}
