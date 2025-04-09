#ifndef DATA_STRUCTURE_FUNC_H

#include "BasicToolkit.h"
#include "AlgorithmFunc.h"

extern int orderedArray[50];

// ★ 全创 全删  增 删 改 查(data->position position->data)   获取长度


// Linear List

typedef struct LinearList{
	int* array;
	int size;
	int capacity;

} LinearList;

LinearList CreateLinearList(int capacity);

void DisruptLinearList(LinearList* list);

LinearList FillRandomDataLinearList(LinearList list, int range);

LinearList FillOrderedDataLinearList(LinearList list);

LinearList ExpandLinearList(LinearList list, int element, int index);

LinearList OrderedLinearListInsert(LinearList list, int element);

LinearList DeleteLinearList(LinearList list, int index);

LinearList ModifyLinearList(LinearList list, int element, int index);

int GetIndexLinearList(LinearList list, int element);

int GetDataLinearList(LinearList list, int index);

void PrintDataLinearList(LinearList list);


// Stack

typedef struct {
	int* array;
	int top;
	int capacity;

} Stack;

void CreateStack(Stack* stack, int length);

void DisruptStack(Stack* stack);

void FillRandomStack(Stack* stack, int range);

void PushStack(Stack* stack, int element);

void PopStack(Stack* stack);

void PrintStack(Stack* stack);


// Queue

typedef struct {
	int* array;
	int front;
	int rear;
	int capacity;

} Queue;

void CreateQueue(Queue* queue, int length);//

void DisruptQueue(Queue* queue);

void FillRandomQueue(Queue* queue, int range);

void OfferQueue(Queue* queue, int element);//

int PullQueue(Queue* queue);//

bool IsEmptyQueue(Queue* queue);

void PrintQueue(Queue* queue);


// Junior Binary Tree

typedef struct TreeNode{
	char data;
	int datai;
	TreeNode* left;
	TreeNode* right;

}TreeNode;

TreeNode* CreateFullJuniorBinaryTree(int layerAmount);

TreeNode* CreateTreeNode(int datai);

void DisruptJuniorBinaryTree(TreeNode* root);

void FillLetterJuniorBinaryTree(TreeNode* root);

void FrontTraverseBinaryTree(TreeNode* root);

void InTraverseBinaryTree(TreeNode* root);

void FrontTraverseBinaryTree_c(TreeNode* root);


// Threaded Binary Tree  (easy to scan)

typedef struct ThreadedTreeNode {

	int data;
	ThreadedTreeNode* left;
	ThreadedTreeNode* right;
	int leftTag;
	int rightTag;

} ThreadedTreeNode;

ThreadedTreeNode* CreateThreadedTreeNode();

void CreateFrontThreadedBinaryTree(ThreadedTreeNode* root);

void FillFrontTraverseThreadedBinaryTree(ThreadedTreeNode* root);

void PrintFrontTraverseThreadedBinaryTree(ThreadedTreeNode* root);


// Binary Search Tree   (easy to search certain node)

TreeNode* InsertTreeNode_BS(TreeNode* root, int datai);

TreeNode* FindTreeNode_BS(TreeNode* root, int datai);

// Balance Binary Tree    (base on Binary Search Tree)

typedef struct BalanceTreeNode {
	int data;
	BalanceTreeNode* left;
	BalanceTreeNode* right;
	int height;

}BalanceTreeNode;

int GetHeight(BalanceTreeNode* node);

BalanceTreeNode* CreateBalanceTreeNode(int datum);

BalanceTreeNode* RightRotation(BalanceTreeNode* root);

BalanceTreeNode* LeftRotation(BalanceTreeNode* root);

BalanceTreeNode* RightLeftRotation(BalanceTreeNode* root);

BalanceTreeNode* LeftRightRotation(BalanceTreeNode* root);

BalanceTreeNode* InsertTreeNode_BB(BalanceTreeNode* root, int datum);

void FreeBalanceTree(BalanceTreeNode* root);


// Huffman Tree

typedef struct HTreeNode {
	int data;
	HTreeNode* left;
	HTreeNode* right;
	int weight;
} HTreeNode;

HTreeNode* CreateHTreeNode(int value, int weight);


// Heap

typedef struct Heap {

	int* array;
	int size;
	int capacity;
} Heap;

Heap* CreateHeap(int capacity);

void InsertHeap(Heap* heap, int element);

int DeleteHeapMax(Heap* heap);

int DeleteHeapMaxPro(Heap* heap);

void DisruptHeap(Heap* heap);

void PrintHeap(Heap* heap);


// Hash Table

typedef struct HashTable {
	int* table;
} HashTable;

#define SIZE 9

void CreateHashTable(HashTable* hash);

int HashFunc(int key);

void InsertHashTable1(HashTable* hash, int element);

typedef struct HashListNode {
	int data;
	int position;
	HashListNode* next;
} HashListNode;

typedef struct HashListTable {
	HashListNode* table;
} HashListTable;

//void InsertHashTable2(HashListTable* hash, int element);

int FindHashTable(HashTable* hash, int element);

void DisruptHashTable(HashTable* hash);

// Gragh

#define MAXVERTEX 5

typedef struct MatrixGraph {
	int vertexCount, edgeCount;
	int matrix[MAXVERTEX][MAXVERTEX];
	int data[MAXVERTEX];

} Graph;

Graph* CreateMatrixGragh();

void AddVertex(Graph* graph, int data);

void AddEdge(Graph* graph, int a, int b);

void DisruptGraph(Graph* graph);


class Node {

private:
	int data;
	Node* next;
public:
	Node(int data);
	void SetNext(Node* next);
	void SetData(int data);
	Node* GetNext();
	int GetData();
};

class MatrixGraphp {

private:
	Node* datalist[MAXVERTEX];
	int vertexAmount;
public:
	MatrixGraphp();
	~MatrixGraphp();
	void AddVertex(int data);
	void AddEdge(int vertex1, int vertex2);
};
typedef struct Gnode {
	int index;
	Gnode* next;
};

typedef struct Gheadnode {
	int data;
	Gnode* next;
};

typedef struct Graphs {
	int vertexAmount;
	int edgeAmount;
	Gheadnode array[MAXVERTEX];
};

Graphs* CreateGraphs();
void AddVertexs(Graphs* graph, int data);
void AddEdges(Graphs* graph, int vertex1, int vertex2);
void TraverseGraphsDeep(Graphs* graph, int start, int* record);
void TraverseGraphsWide(Graphs* graph, int start, int* record, Queue* queue);

#endif // !DATA_STRUCTURE_FUNC_H


