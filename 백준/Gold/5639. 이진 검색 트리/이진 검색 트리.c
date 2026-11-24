#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct
{
	int data;
	struct NodeStruct *left, *right;
}Node;

Node* root = NULL;

Node* instert_Node(Node* root, int data)
{
	if (root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->left = root->right = NULL;
		root->data = data;
		return root;
	}
	else
	{
		if (root->data > data)
			root->left = instert_Node(root->left, data);/*재귀함수를 이용해서 값을 배치하는것이다. 그 이유는 받은 값과 원래 있던값을 비교해서 원래 값보다
														작으면 왼쪽, 크면 오른쪽으로 또 배치를 해야 하기 때문이다.*/
		else
			root->right = instert_Node(root->right, data);
	}
	return root;
}


void Print(Node* root)
{
	if (root == NULL)
		return;

	// 왼쪽 하위 트리 출력
	Print(root->left);/*재귀함수를 이용하여 일단 처음으로 왼쪽 맨 아래로 내려가서 확인한후 더이상 밑에 자식이 없으면 다시 올라오면서 출력하고*/

	// 오른쪽 하위 트리 출력
	Print(root->right);/*옆에 자식이 또 있으며 재귀함수를 이용하여 다시 맨밑으로 내려갓다가 더이상 밑에 자식이 없으면 다시 올라오면 출력하고
					   마지막에 맨위 루트값을 출력하는 것이다*/

	printf("%d\n", root->data);
}

int main()
{
	int a;
	while (scanf("%d", &a) != EOF) {
		root = instert_Node(root, a);
	}
	Print(root);
	return 0;
}