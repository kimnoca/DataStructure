#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* rchild;
	struct Node* lchild;
	int data;
}Node;

Node* root; //Tree�� Root node �� ���� �Լ��� ����.

Node* insert(Node* root ,int data) {
	if (!root) { //root�� Null �̶�� root node �� ������
		root = (Node*)malloc(sizeof(Node));
		root->rchild = root->lchild = NULL;
		root->data = data;
		return root;
	}
	else { //root node �� !Null
		if (data < root->data) { 
			root->lchild = insert(root->lchild, data);
		}
		else {
			root->rchild = insert(root->rchild, data);
		}
	}
	return root;
}
//���� ��ȸ
void preorder(Node * root){
	if (root) { //root �� Null�� �ƴ϶��
		printf("%d -> ", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
//���� ��ȸ
void inorder(Node* root){
	if (root) { 
		inorder(root->lchild);
		printf("%d -> ", root->data);
		inorder(root->rchild);
	}
}
//���� ��ȸ
void postorder(Node* root){
	if (root) { 
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d -> ", root->data);
	}
}
//��� ��ȸ�� ���
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
				printf("Root Node�� Data ���� �Է��Ͻÿ� : ");
				scanf_s("%d", &data);
				root = insert(root, data);
				break;
			}
			else {
				printf("������ Child Node�� Data ���� �Է��Ͻÿ� : ");
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