#include "BasicToolkit.h"
#include "DataStructureFunc.h"

int AddTreeRange(TreeNode* root, int low, int high) {
	if (root == nullptr) {
		return 0;
	}
	if (root->datai < low) {
		return AddTreeRange(root->left, low, high);
	}
	else if (root->datai > high) {
		return AddTreeRange(root->right, low, high);
	}
	else {
		return root->datai + AddTreeRange(root->left, low, high) + AddTreeRange(root->right, low, high);
	}
}


int AddTreeData(TreeNode* root, int pre) {    // 递归类function, 正常时只能小传大从里向外传, 如果想要把大的部分结果传到小的里面, 就只能多加参数
	if (root == nullptr) {
		return 0;
	}
	int sum = root->datai + pre * 10;
	if (root->left == nullptr && root->right == nullptr) {
		return pre;
	}
	return AddTreeData(root->left, sum) + AddTreeData(root->right, sum);

 }

int ArrayMax(int* array, int* end) {
	int* temp = array;
	int max = *array;
	while (temp != end) {
		if (*temp > max) {
			max = *temp;
		}
		temp++;
	}
	return max;
}

int MaxTrace(TreeNode* root, int pre) {
	static int* array = new int[128];
	static int* pointer = array;
	if (root == nullptr) {
		*pointer = pre;
		pointer++;
	}
	if (root) {
		int sum = root->datai + pre;
		MaxTrace(root->left, sum);
		MaxTrace(root->right, sum);
	}
	return ArrayMax(array, pointer);
}

/*
int main(void)
{
	TreeNode* root = InsertTreeNode_BS(nullptr, 15);

	InsertTreeNode_BS(root, 10);
	InsertTreeNode_BS(root, 17);
	InsertTreeNode_BS(root, 7);
	InsertTreeNode_BS(root, 11);
	InsertTreeNode_BS(root, 5);
	InsertTreeNode_BS(root, 16);
	InsertTreeNode_BS(root, 2);
	InsertTreeNode_BS(root, 8);
	InsertTreeNode_BS(root, 9);
	InsertTreeNode_BS(root, 6);

	cout << endl;
	InTraverseBinaryTree(root);

	TreeNode* tempNode = FindTreeNode_BS(root, 35);

	if (tempNode) {
		cout << endl << tempNode->datai << endl;
	}
	cout << endl;

	int result = MaxTrace(root, 0);
	cout << "The result is " << result << endl;


	return 0;

}
*/