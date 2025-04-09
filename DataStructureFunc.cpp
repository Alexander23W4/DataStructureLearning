#include "DataStructureFunc.h"

// Linear List

LinearList CreateLinearList(int capacity) {

	LinearList list;
	list.array = new int[capacity];
	list.size = 0;
	list.capacity = capacity;

	return list;

}

void DisruptLinearList(LinearList* list) {

	delete[]list->array;
	list->capacity = 0;
	list->size = 0;

}

LinearList FillRandomDataLinearList(LinearList list, int range) {

	for (int index = 0; index < list.capacity; index++)
	{
		list.array[index] = GetRandomNumber(range);
	}
	list.size = list.capacity;

	return list;

}

LinearList FillOrderedDataLinearList(LinearList list) {

	for (int index = 0; index < list.capacity; index++)
	{
		list.array[index] = orderedArray[index];

	}
	list.size = list.capacity;

	return list;

}

LinearList ExpandLinearList(LinearList list, int element, int index) {

	if (list.size >= list.capacity) {
		int* newarray = Renew(list.array, list.capacity, list.capacity + 10);
		list.array = newarray;
		list.capacity += 10;

	}
	if (index > list.size + 1 || index < 0) {
		perror("Error");
		return list;

	}
	for (int i = list.size; i >= index; i--)
	{
		list.array[i + 1] = list.array[i];

	}
	list.array[index] = element;
	list.size++;

	return list;
}

LinearList OrderedLinearListInsert(LinearList list, int element) {

	if (list.size >= list.capacity) {
		int* newarray = Renew(list.array, list.capacity, list.capacity + 10);
		list.array = newarray;
		list.capacity += 10;

	}
	for (int index = 0; index < list.size; index++)
	{
		if (list.array[index] <= element) {
			for (int i = list.size; i >= index; i--)
			{
				list.array[i + 1] = list.array[i];

			}
			list.array[index] = element;
		}
	}

	list.size++;

	return list;
}


LinearList DeleteLinearList(LinearList list, int index) {

	if (list.size > list.capacity || list.capacity < index || index < 0) {
		perror("Error");
		return list;

	}

	for (int i = index; i < list.size - 1; i++)
	{
		list.array[i] = list.array[i + 1];

	}
	list.size--;

	return list;

}

LinearList ModifyLinearList(LinearList list, int element, int index) {

	if (index > list.size || index < 0) {
		perror("Error");
		return list;

	}
	list.array[index] = element;

	return list;


}

int GetIndexLinearList(LinearList list, int element) {

	for (int index = 0; index < list.size; index++)
	{
		if (list.array[index] == element) {
			return index;

		}
	}

	return -1;

}

int GetDataLinearList(LinearList list, int index) {

	if (index < 0 || index > list.size) {
		return -1;

	}
	return list.array[index];

}

void PrintDataLinearList(LinearList list) {

	PrintLinearArray(list.array, list.size);

}


// Stack 

void CreateStack(Stack* stack, int length) {

	int* stackArray = new int[length];
	stack->array = stackArray;
	stack->capacity = length;
	stack->top = -1;       // The top of the stack should be originated as -1

}

void DisruptStack(Stack* stack) {

	delete[]stack->array;
	stack->top = -1;
	stack->capacity = 0;

}

void FillRandomStack(Stack* stack, int range) {

	for (int index = 0; index < stack->capacity; index++)
	{
		stack->array[index] = GetRandomNumber(range);

	}
	stack->top = stack->capacity - 1;

}

void PushStack(Stack* stack, int element) {

	if (stack->top >= stack->capacity - 1) {

		int* newarrayStack = Renew(stack->array, stack->capacity, (stack->capacity) + 5);
		stack->array = newarrayStack;

	}
	stack->array[++stack->top] = element;

}

void PopStack(Stack* stack) {

	if (stack->top == -1) {
		cout << endl << "The stack is empty." << endl;

	}
	else {
		stack->top--;
	}

}

void PrintStack(Stack* stack) {
	
	if (stack->top == -1) {
		cout << endl << "The stack is empty." << endl;

	}
	else {
		PrintLinearArray(stack->array, stack->top + 1);

	}

}


// Queue

void CreateQueue(Queue* queue, int length) {

	if (length > 0) {
		int* arrayQueue = new int[length];
		queue->array = arrayQueue;
		queue->capacity = length;
		queue->front = queue->rear = 0;

	}
	else {
		cout << endl << "Error creating queue." << endl;

	}

}

void DisruptQueue(Queue* queue) {

	delete[]queue->array;
	queue->capacity = 0;
	queue->front = queue->rear = 0;

}

void FillRandomQueue(Queue* queue, int range) {

	for (int index = 0; index < queue->capacity; index++)
	{
		queue->array[index] = GetRandomNumber(range);
	}
	queue->rear = queue->capacity - 1;

}

void OfferQueue(Queue* queue, int element) {

	if ((queue->rear + 1) % queue->capacity == queue->front) {
		cout << endl << "Error offering queue." << endl;

	}
	else {
		queue->rear = (queue->rear + 1) % (queue->capacity);  // ★
		queue->array[queue->rear] = element;

	}

}

int PullQueue(Queue* queue) {
	int temp = queue->array[queue->front];
	queue->array[queue->front] = -1;

	queue->front = (queue->front + 1) % (queue->capacity);
	return temp;

}

bool IsEmptyQueue(Queue* queue) {
	if (queue->front == queue->rear) {
		return 1;
	}
	else {
		return 0;

	}
}

void PrintQueue(Queue* queue) {

	int length = (queue->rear + queue->capacity - queue->front) % (queue->capacity);
	if (length <= 0) {
		cout << endl << "Error printing queue." << endl;

	}
	else {
		cout << endl;

		for (int index = 0; index < length; index++)
		{
			cout << queue->array[(queue->front + index) % (queue->capacity)] << " ";

			if (index % 10 == 9) {
				cout << endl;

			}
		}
	}
}


// Tree

// Junior Binary Tree 四种遍历方式


TreeNode* CreateFullJuniorBinaryTree(int layerAmount) {           // ★ 递归生成满二叉树

	TreeNode* root = new TreeNode;
	root->left = nullptr;                                         // 避免空指针悬挂
	root->right = nullptr; 
	if (layerAmount > 0) {										  // 递归条件
		root->left = CreateFullJuniorBinaryTree(layerAmount - 1);      // 一生二 二生四...
		root->right = CreateFullJuniorBinaryTree(layerAmount - 1);
	}

	return root;

}

TreeNode* CreateTreeNode(int datai){
	
	TreeNode* node = new TreeNode;
	node->datai = datai;
	node->left = node->right = nullptr;
	return node;

}


void DisruptJuniorBinaryTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	DisruptJuniorBinaryTree(root->left);
	DisruptJuniorBinaryTree(root->right);
	delete root;

}

void FillLetterJuniorBinaryTree(TreeNode* root) {

	root->data = 'A' + GetRandomNumber(26) - 1;
	if (root->left != NULL) {
		FillLetterJuniorBinaryTree(root->left);
	}
	if (root->right != NULL) {
		FillLetterJuniorBinaryTree(root->right);
	}
}

void FrontTraverseBinaryTree(TreeNode* root) {     // 递归实现的前序遍历二叉树

	if (root == nullptr) {
		return;
	}
	cout << root->data << " ";
	FrontTraverseBinaryTree(root->left);
	FrontTraverseBinaryTree(root->right);

}

void InTraverseBinaryTree(TreeNode* root) {     // 递归实现的前序遍历二叉树

	if (root == nullptr) {
		return;
	}
	InTraverseBinaryTree(root->left);
	cout << root->datai << " ";
	InTraverseBinaryTree(root->right);

}


void FrontTraverseBinaryTree_c(TreeNode* root) {     // 循环实现的前序遍历二叉树 (借助栈)


}


// Threaded Binary Tree 


ThreadedTreeNode* CreateThreadedTreeNode() {        // 创立线索化二叉树的单个节点

	ThreadedTreeNode* node = new ThreadedTreeNode;
	node->left = node->right = nullptr;
	node->leftTag = node->rightTag = 0;
	return node;

}

ThreadedTreeNode* pre = nullptr;                   // 因为这里的pre是指前序遍历按时间顺序的上一个节点, 而不是递归嵌套逻辑顺序的母节点
												   // 所以这里不能用函数传参传递pre, 而是用一个全局变量记录时间上的上一个遍历到的节点
void CreateFrontThreadedBinaryTree(ThreadedTreeNode* root) {        // 把普通二叉树链接线索

	if (root == nullptr) {
		return;

	}
	if (root->left == nullptr) {
		root->left = pre;
		root->leftTag = 1;

	}
	if (pre && pre->right == nullptr) {
		pre->right = root;
		pre->rightTag = 1;
		
	}
	pre = root;

	if (root->leftTag == 0) {                       // 这里虽然是第一次遍历链接, 但是完整保险起见还是判断
		CreateFrontThreadedBinaryTree(root->left);
	}
	if (root->rightTag == 0) {
		CreateFrontThreadedBinaryTree(root->right);
	}
}

void FillFrontTraverseThreadedBinaryTree(ThreadedTreeNode* root) {

	while (root) {
		root->data = GetRandomNumber(100);
		if (root->leftTag == 0) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}

}

void PrintFrontTraverseThreadedBinaryTree(ThreadedTreeNode* root) {

	while (root) {
		cout << root->data << " ";

		if (root->leftTag == 0) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}

}

// 线索化二叉树的全删函数, 有待补充

// ★ 全创 全删  填入数据(创造, 已有)  增 删 改 查(data->position position->data)   获取长度  输出数据

// 上述功能的实现, 都要注重     算法  安全性  周到性(所有的可能)

// Binary Search Tree

TreeNode* InsertTreeNode_BS(TreeNode* root, int datai) {         // 拿着数据 找到地方 创建节点

	if (root) {
		if (datai < root->datai) {
			root->left = InsertTreeNode_BS(root->left, datai);
		}
		else if (datai > root->datai) {
			root->right = InsertTreeNode_BS(root->right, datai);
		}
	}
	else {
		root = CreateTreeNode(datai);
	}
	return root;
}                                                             // 最终返回创建的节点的地址

TreeNode* FindTreeNode_BS(TreeNode* root, int datai) {

	if (root) {
		if (root->datai > datai) {
			FindTreeNode_BS(root->left, datai);
		}
		else if (root->datai < datai) {
			FindTreeNode_BS(root->right, datai);
		}
		else {
			return root;
		}
	}
	else {
		return nullptr;
	}
}
/*
TreeNode* DeleteTreeNode_BS(TreeNode* root) {           // 删除一个节点, 分三种情况
	                                                    // 有left或right, 向上连接   都有, 左最大上位或右最小上位
}
*/
// Balance Binary Tree

int GetHeight(BalanceTreeNode* node) {
	if (node) {
		return node->height;

	}
	else {
		return 0;
	}
}

BalanceTreeNode* CreateBalanceTreeNode(int datum) {

	BalanceTreeNode* node = new BalanceTreeNode;
	node->left = node->right = nullptr;
	node->height = 1;
	node->data = datum;
	return node;

}

BalanceTreeNode* LeftRotation(BalanceTreeNode* root) {

		BalanceTreeNode* temp = root->right;
		root->right = temp->left;
		temp->left = root;
		temp->height = GetMax2(GetHeight(temp->left), GetHeight(temp->right)) + 1;
		root->height = GetMax2(GetHeight(root->left), GetHeight(root->right)) + 1;

		return temp;
}

BalanceTreeNode* RightRotation(BalanceTreeNode* root) {

		BalanceTreeNode* temp = root->left;
		root->left = temp->right;
		temp->right = root;
		temp->height = GetMax2(GetHeight(temp->left), GetHeight(temp->right)) + 1;
		root->height = GetMax2(GetHeight(root->left), GetHeight(root->right)) + 1;

		return temp;
}

BalanceTreeNode* LeftRightRotation(BalanceTreeNode* root) {

	root->left = LeftRotation(root->left);
	return RightRotation(root);
}

BalanceTreeNode* RightLeftRotation(BalanceTreeNode* root) {

	root->right = RightRotation(root->right);
	return LeftRotation(root);
}

BalanceTreeNode* InsertTreeNode_BB(BalanceTreeNode* root, int datum) {

	if (root) {
		if (datum <= root->data) {
			root->left = InsertTreeNode_BB(root->left, datum);
			if (GetHeight(root->left) - GetHeight(root->right) > 1) {
				if (GetHeight(root->left->right) >= GetHeight(root->left->left)) {
					root = LeftRightRotation(root);  cout << endl << "LeftRightRotation";
				}
				else {
					root = RightRotation(root);  cout << endl << "RightRotation";
				}
			}
		}
		else if (datum > root->data) {
			root->right = InsertTreeNode_BB(root->right, datum);
			if (GetHeight(root->right) - GetHeight(root->left) > 1) {
				if (GetHeight(root->right->left) >= GetHeight(root->right->right)) {
					root = RightLeftRotation(root);  cout << endl << "RightLeftRotation";
				}
				else {
					root = LeftRotation(root);  cout << endl << "LeftRotation";
				}
			}
		}
	}
	else {
		root = CreateBalanceTreeNode(datum);
	}
	root->height = GetMax2(GetHeight(root->left), GetHeight(root->right)) + 1;
	return root;
}

void FreeBalanceTree(BalanceTreeNode* root) {
	if (root) {
		FreeBalanceTree(root->left);
		FreeBalanceTree(root->right);
		delete root;
	}
}


// Huffman Tree

HTreeNode* CreateHTreeNode(int value, int weight) {
	
	HTreeNode* node = new HTreeNode;
	node->data = value;
	node->left = node->right = nullptr;
	node->weight = weight;
	return node;
}

// Heap

Heap* CreateHeap(int capacity) {

	Heap* node = new Heap;
	node->array = new int[capacity];
	node->size = 0;                             // 下标从1开始
	node->capacity = capacity;
	return node;

}

void InsertHeap(Heap* heap, int element){              
	
	if (heap->size >= heap->capacity) {
		heap->array = Renew(heap->array, heap->capacity, heap->capacity + 5);
		heap->capacity += 5;
	}
	int index = ++heap->size;
	while (index > 1 && element > heap->array[index / 2]) {
		heap->array[index] = heap->array[index / 2];
		index /= 2;
	}
	heap->array[index] = element;

}


int DeleteHeapMax(Heap* heap) {

	int max = heap->array[1];
	int index = 1;
	int rmIndex = 0;
	int lastrmIndex = 1;
	while (index * 2 <= heap->size) {
		rmIndex = FindMaxIndex(heap->array, index, index * 2 - 1);
		heap->array[lastrmIndex] = heap->array[rmIndex];
		index *= 2;
		lastrmIndex = rmIndex;
	}
	rmIndex = FindMaxIndex(heap->array, index, heap->size);
	heap->array[lastrmIndex] = heap->array[rmIndex];
	for (int i = rmIndex + 1; i <= heap->size; i++)
	{
		heap->array[i - 1] = heap->array[i];
	}
	heap->size--;
	return max;

}

int DeleteHeapMaxPro(Heap* heap) {
	int max = heap->array[1];
	int index = 1;
	while (index * 2 <= heap->size) {
		int child = index * 2;
		if (child < heap->size && heap->array[child + 1] > heap->array[child]) {
			child += 1;
		}
		if (heap->array[heap->size] >= heap->array[child]) {
			break;
		}
		heap->array[index] = heap->array[child];
		index = child;
	}
	heap->array[index] = heap->array[heap->size];
	heap->size--;
	return max;
}

void PrintHeap(Heap* heap) {
	cout << endl;
	for (int i = 1; i <= heap->size; i++)
	{
		cout << heap->array[i] << " ";

	}
}

void DisruptHeap(Heap* heap) {

	delete[] heap->array;
	delete heap;
}

// Hash Table

void CreateHashTable(HashTable* hash) {
	hash->table = new int[SIZE];
	for (int index = 0; index < SIZE; index++)
	{
		hash->table[index] = NULL;
	}
}

int HashFunc(int key) {     // exemplified Hash function
	return key % SIZE;
}

void InsertHashTable1(HashTable* hash, int element) {    
	int count = 0;
	while (hash->table[(HashFunc(element) + count) % SIZE]) {            // 线性探测法解决哈希冲突
		if (count >= SIZE) return;
		count++;
	}
	hash->table[(HashFunc(element) + count) % SIZE] = element;
}

//void InsertHashTable2(HashListTable* head, int element) {
//	HashListNode* pointer = head->table[HashFunc(element)].next;
//	HashListNode* temp = new HashListNode;
//	while (pointer) {
//		temp = pointer;
//		pointer = pointer->next;
//	}
//	
//	temp->data = element;
//	temp->next = nullptr;
//	temp->position = HashFunc(element);	
//}

int FindHashTable(HashTable* hash, int element) {
	int count = 0;
	while (hash->table[(HashFunc(element) + count) % SIZE] != element) {
		if (count >= SIZE) return -1;
		count++;
	}
	return (HashFunc(element) + count) % SIZE;
}

void DisruptHashTable(HashTable* hash) {
	delete[] hash->table;

}

// Graph

Graph* CreateMatrixGragh() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));     // 如果分配一个类指针, 类里面有数组 指针等, 最好用malloc
	if (graph != nullptr) {
		graph->edgeCount = graph->vertexCount = 0;
		for (int i = 0; i < MAXVERTEX; i++)
		{
			for (int j = 0; j < MAXVERTEX; j++)
			{
				graph->matrix[i][j] = 0;
			}
		}
		return graph;
	}
}

void AddVertex(Graph* graph, int data) {
	if (graph->vertexCount >= MAXVERTEX) {
		cout << "The Graph is full" << endl;
		return;
	}
	else {
		graph->data[graph->vertexCount++] = data;
	}
}

void AddEdge(Graph* graph, int a, int b) {
	if (graph->matrix[a][b] == 0) {
		graph->matrix[a][b] = 1;
		graph->edgeCount++;
	}
}

void DisruptGraph(Graph* graph) {
	free(graph);
}

// class Node

Node::Node(int data) :data(data) {
	next = nullptr;
}
void Node::SetNext(Node* next) {
	this->next = next;
}
void Node::SetData(int data) {
	this->data = data;
}
Node* Node::GetNext() {
	return this->next;
}
int Node::GetData() {
	return this->data;
}

// class MatrixGraphp

MatrixGraphp::MatrixGraphp() {
	for (int index = 0; index < MAXVERTEX; index++)
	{
		datalist[index] = nullptr;
	}
	vertexAmount = 0;
}
MatrixGraphp::~MatrixGraphp() {
	for (int i = 0; i < MAXVERTEX; ++i) {
		Node* current = datalist[i];
		while (current != nullptr) {
			Node* temp = current;
			current = current->GetNext();
			delete temp;
		}
	}
}
void MatrixGraphp::AddVertex(int data) {
	if (vertexAmount < MAXVERTEX) {
		Node* temp = new Node(data);
		datalist[vertexAmount] = temp;
		vertexAmount++;
	}
}
/// <summary>
/// vertex1: the primary node   vertex2: the pointing node
/// </summary>
/// <param name="vertex1"></param>
/// <param name="vertex2"></param>

void MatrixGraphp::AddEdge(int vertex1, int vertex2) {
	Node* temp = new Node(vertex2);
	Node* post = datalist[vertex1];
	while (post->GetNext() != nullptr) {
		post = post->GetNext();
	}
	post->SetNext(temp);
}



Graphs* CreateGraphs() {
	Graphs* graph = (Graphs*)malloc(sizeof(Graphs));
	if (graph != nullptr) {
		graph->vertexAmount = 0;
		graph->edgeAmount = 0;
		return graph;
	}
	else {
		return nullptr;
	}
}

void AddVertexs(Graphs* graph, int data) {
	graph->array[graph->vertexAmount].data = data;
	graph->array[graph->vertexAmount++].next = nullptr;
}

void AddEdges(Graphs* graph, int vertex1, int vertex2) {
	Gnode* temp = (graph->array[vertex1]).next;
	Gnode* post = temp;
	Gnode* newnode = new Gnode;
	newnode->index = vertex2;
	newnode->next = nullptr;
	if (temp == nullptr) {
		graph->array[vertex1].next = newnode;
	}
	else {
		while (temp != nullptr) {
			if (temp->index == vertex2) {
				return;
			}
			post = temp;
			temp = temp->next;
		}
		post->next = newnode;
	}
	graph->edgeAmount++;
}

// 递归方法, 设置一个起点, 通过路径进行遍历, 一次性只认准一条路
void TraverseGraphsDeep(Graphs* graph, int start, int* record) {
	cout << graph->array[start].data << " " << start << endl;
	record[start] = 1;
	Gnode* temp = graph->array[start].next;
	while (temp) {
		if (!record[temp->index]) {
			TraverseGraphsDeep(graph, temp->index, record);
		}
		temp = temp->next;
	}
}

void TraverseGraphsWide(Graphs* graph, int start, int* record, Queue* queue) {
	OfferQueue(queue, start);
	record[start] = 1;
	while (!IsEmptyQueue(queue)) {
		int post = PullQueue(queue);
		cout << graph->array[post].data << " ";
		Gnode* temp = graph->array[post].next;
		while (temp != nullptr) {
			if (!record[temp->index]) {
				OfferQueue(queue, temp->index);
				record[temp->index] = 1;
			}
			temp = temp->next;
		}
	}
}





























































