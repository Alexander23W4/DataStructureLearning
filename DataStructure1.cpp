#include "BasicToolkit.h"
#include "DataStructureFunc.h"



 
// ★ 全创 全删  填入数据(创造, 已有)  增 删 改 查(data->position position->data)   获取长度  输出数据

// 上述功能的实现, 都要注重     算法  安全性  周到性(所有的可能)

//  随机存取  顺序存取  索引存取  散列存取



// Gragh  顶点 边    Vertex  Edge 
   
// 有向图  无向图   (): 无向边   <>: 有向边     度   入度  出度
// 简单图 (无 自回路 & 重边)
// 完全图  无向完全图  有向完全图

// 连通图(无向图)  强连通图(有向图)
// 子图 (V 和 E 都是子集)
// 无向图的极大联通子图 (拥有最多顶点的联通子图): 连通分量    有向图的极大强联通子图: 强连通分量

// Gragh的储存方法: 1.邻阶矩阵: 连1 不连0     (无向图一定为对称矩阵)   无向图: [1数: 度]  有向图: [横1数: 出度  纵1数: 入度]
//                邻接矩阵存储连接关系, 数组存储vertex数据

//                2.邻接表: 链表array    也可以加一个逆邻接表来储存入度

// Graph的遍历:  1.深度优先搜索(traverse): 
//              2.广度优先搜索(traverse):                

// 无向图的极小连通子图(拥有最少边的极大联通子图)  

// 原图本身就是连通图: 其极小联通子图必定是n - 1条边, 不可能有回路. 可以看作是一个树, 生成树
// 原图本身不连通: 多个连通分量  --> 生成森林(其中树的数量为连通分量的数量)

// 最小生成树: 如果边edge有权重, 留下的边权重之和最小的生成树
//			  *Prim 算法    *Kruskal 算法

// 单源最短路径 (从一个给定的顶点出发, 到其他所有顶点的路径之和的最小值) (APPLICATION: 交通等)
// 
//            *Dijkstra 算法(distance path表格)  每个节点看全部通路(除去回头路, 即其path), 看通路时更新distance/ 简单distance相加
//                                   填完表格之后, path倒推可知路径, distance可知距离

// 顶点之间最短路径: *Floyd 算法 (APPLICATION: 交通等)
// 
//            从邻接矩阵开始, 每轮(第k轮)更新 除主对角线 与 k行和k列 以外的其他数值, (如: 更新(i, j), 就与(i, k) + (k, j)比较), 更新n轮即可

// 拓扑排序: 将"有向无环图" 排序--> 有序线性序列  (APPLICATION: 大学课程存在前置课程, 想要求所有可能的课程修学顺序)
//         
//         用queue  pull入度为0点--> offer(print) 并 在graph上去掉offer掉的点 --> 再pull入度为0点

// 关键路径计算: AOE图(边edge的数值代表节点时间间隔)  (APPLICATION: 同上, 考虑两个课程之间必要的时间间隔)
//             
//             1.计算每个节点开始和整个流程完成至少所需时间 以及 2.每个节点在流程最短时间的情况下, 可以摇摆的最晚时间 (倒推)


// Graph广度优先搜索遍历

/*
int main(void) 
{
	Graphs* graph = CreateGraphs();
	AddVertexs(graph, 56);
	AddVertexs(graph, 77);
	AddVertexs(graph, 66);
	AddVertexs(graph, 10);
	AddVertexs(graph, 35);
	AddEdges(graph, 0, 2);
	AddEdges(graph, 1, 2);
	AddEdges(graph, 1, 4);
	AddEdges(graph, 2, 3);
	AddEdges(graph, 4, 1);
	AddEdges(graph, 3, 1);

	int record[MAXVERTEX];
	for (size_t index = 0; index < MAXVERTEX; index++)
	{
		record[index] = 0;
	}
	Queue queue;
	CreateQueue(&queue, 6);
	TraverseGraphsWide(graph, 0, record, &queue);
//	DisruptQueue(&queue);
	return 0;
}
*/

// Graph深度有限搜索遍历 (一条路走到底, 但是不能走回头路)

/*
int main(void)
{
	Graphs* graph = CreateGraphs();
	AddVertexs(graph, 56);
	AddVertexs(graph, 77);
	AddVertexs(graph, 66);
	AddVertexs(graph, 10);
	AddVertexs(graph, 35);
	AddEdges(graph, 0, 2);
	AddEdges(graph, 1, 2);
	AddEdges(graph, 1, 4);
	AddEdges(graph, 2, 3);
	AddEdges(graph, 4, 1);
	AddEdges(graph, 3, 1);

	int record[MAXVERTEX];
	for (size_t index = 0; index < MAXVERTEX; index++)
	{
		record[index] = 0;
	}
	TraverseGraphsDeep(graph, 1, record);
	return 0;
}
*/

// 邻接表储存Graph
/*
int main(void) {

	MatrixGraphp graph;
	graph.AddVertex(45);
	graph.AddVertex(36);
	graph.AddEdge(0, 1);
	graph.AddVertex(20);
	graph.AddEdge(2, 1);

	return 0;
}
*/
// 邻接矩阵储存Graph
/*
int main(void)
{
	Graph* graph = CreateMatrixGragh();
	AddVertex(graph, GetRandomNumber(10));   // 构建顶点
	AddVertex(graph, GetRandomNumber(10));
	AddVertex(graph, GetRandomNumber(10));
	AddVertex(graph, GetRandomNumber(10));

	AddEdge(graph, 0, 1);					 // 构建边
	AddEdge(graph, 1, 2);
	AddEdge(graph, 2, 0);
	AddEdge(graph, 2, 3);
	AddEdge(graph, 3, 0);

	DisruptGraph(graph);

	return 0;

}
*/



// Hash Table  散列表(哈希表)   Intention: 极致的压缩和快速的查找

// Keys <---> Hash function(很多种) <---> Hash keys <---> Find Hash keys in Hash Table
//  👆													     👆
//  丨--------------------------------------------------------丨

// 哈希冲突: Solution: 开放地址法 线性探测法 平方探测法 双散列法 

/*
int main(void)
{
	HashTable hash;
	CreateHashTable(&hash);
	hash.table[HashFunc(14)] = 14;
	hash.table[HashFunc(35)] = 35;
	hash.table[HashFunc(27)] = 27;
	InsertHashTable1(&hash, 23);
	InsertHashTable1(&hash, 32);
	InsertHashTable1(&hash, 41);	
	InsertHashTable1(&hash, 50);
	InsertHashTable1(&hash, 59);

	cout << endl << FindHashTable(&hash, 23);
	cout << endl << FindHashTable(&hash, 32);
	cout << endl << FindHashTable(&hash, 41);
	cout << endl << FindHashTable(&hash, 50);
	cout << endl << FindHashTable(&hash, 59);

	cout << endl << "The 35 in hash function: " << hash.table[HashFunc(35)] << endl;

	DisruptHashTable(&hash);

	return 0;

}
*/





// Tree   root degree subtree level depth child parent sibling ancestor  forest

// (Binary) Tree  二叉树 满二叉树(每层都塞满) 完全二叉树(上层都塞满, 最下层可不满但是有顺序) 
//			    树->二叉树: child left, sibling right  森林->二叉树: 树->二叉树 + right chain
//              节点数量 变数  n = n0 + n1 + n2 = n1 + 2n2 + 1     n0 = n2 + 1
//              一颗具有n个节点的完全二叉树层数 l = [log2(n)] + 1
//              从上到下从左到右标号, left child 2i right child 2i + 1, parent[i / 2], 2i > n no child  > n + 1 no right child

//              前序遍历 中序遍历 后序遍历  层序遍历   
//             ^前序遍历结果ABCDE 中序遍历结果BADCE 问后序遍历结果


// Heap  堆   小根堆(小顶堆)   大根堆(大顶堆)    必须是完全二叉树
//            堆化, 父子节点交换
/*
int main(void)
{
	Heap* heap = CreateHeap(30);

	InsertHeap(heap, 23);
	InsertHeap(heap, 25);
	InsertHeap(heap, 46);
	InsertHeap(heap, 11);
	InsertHeap(heap, 56);
	InsertHeap(heap, 90);
	InsertHeap(heap, 22);
	InsertHeap(heap, 10);
	InsertHeap(heap, 80);
	InsertHeap(heap, 20); 
	InsertHeap(heap, 12);
	InsertHeap(heap, 98);
	InsertHeap(heap, 92);
	InsertHeap(heap, 57);

	PrintHeap(heap);

	int max = DeleteHeapMaxPro(heap);

	PrintHeap(heap);

	DisruptHeap(heap);


	return 0;

}
*/
// Huffman Tree   越大的值越靠近根节点, 值只在叶子节点, 其他节点没有值    
			// Application: 对数据进行压缩, 现代压缩算法的基础
			// 数据-> Huffman code (路径表示)
/*
int main(void)
{
	LinearList list = CreateLinearList(10);
	OrderedLinearListInsert(list, 35);
	OrderedLinearListInsert(list, 24);
	OrderedLinearListInsert(list, 9);
	OrderedLinearListInsert(list, 55);
	OrderedLinearListInsert(list, 18);



	return 0;

}
*/


// B Tree
// 专门为磁盘数据读取设计的查找树(多用于数据库), 基于BS-Tree     // order  degree
// B-Tree 也是平衡树, 但是和AVL和BLACK-RED-Tree的保持平衡的底层逻辑不同, 代码逻辑也不同.
/*
Rules of a B-tree:

The maximum number of children a node can have is M (where M is the "Order" of the tree).
The minimum number of children (except for the root) is ⌈M/2⌉.

Each node can contain at most M - 1 keys.
Each node (except the root) must have at least ⌈M/2⌉ - 1 keys.

The root node must have at least 1 key, but less than M - 1 keys. (it can have fewer than ⌈M/2⌉ keys).
If the root is not a leaf, it must have at least two children.

The keys inside a node are always stored in sorted order.

All leaf nodes must be at the same depth (ensuring the tree remains balanced).

If a node gets full (M-1 keys), it splits into two nodes, and a middle key moves up to the parent.
If a node gets too few keys (<⌈M/2⌉ - 1 keys), it borrows from siblings or merges with a sibling.

常用操作有 借(向父和兄),同层分裂,同层合并,浮,降
*/




// Balance Binary Tree                    // [目的: 提升BS-Tree的查找效率] 充分利用每一层的空间, 避免极端"一边倒"情况而降低查找效率
//              Balance Factor
/*
int main(void)
{
	BalanceTreeNode* root = InsertTreeNode_BB(nullptr, 15);

	root = InsertTreeNode_BB(root, 10);            // AVL的每次插入新节点root都要更新
	root = InsertTreeNode_BB(root, 20);
	root = InsertTreeNode_BB(root, 7);
	root = InsertTreeNode_BB(root, 5);
	root = InsertTreeNode_BB(root, 22);
	root = InsertTreeNode_BB(root, 35);
	root = InsertTreeNode_BB(root, 1);
	root = InsertTreeNode_BB(root, 2);
	root = InsertTreeNode_BB(root, 99);
	root = InsertTreeNode_BB(root, 57);
	cout << "Height of the tree: " << GetHeight(root) << endl;

	FreeBalanceTree(root);

	return 0;

}
*/
// Binary Search Tree

//              左子树中所有节点的值, 均小于根节点
//              右子树...大于
//              二叉搜索树的子树也是二叉搜索树

//              查找效率增高
/*
int main(void)
{
	TreeNode* root = InsertTreeNode_BS(nullptr, 15);

	InsertTreeNode_BS(root, 10);
	InsertTreeNode_BS(root, 20);
	InsertTreeNode_BS(root, 7);
	InsertTreeNode_BS(root, 22);
	InsertTreeNode_BS(root, 5);
	InsertTreeNode_BS(root, 35);
	InsertTreeNode_BS(root, 1);
	InsertTreeNode_BS(root, 2);
	InsertTreeNode_BS(root, 99);
	InsertTreeNode_BS(root, 57);

	cout << endl;
	InTraverseBinaryTree(root);

	TreeNode* tempNode = FindTreeNode_BS(root, 35);

	if (tempNode) {
		cout << endl << tempNode->datai << endl;
	}


	return 0;

}
*/


// Threaded Binary Tree

/*
extern ThreadedTreeNode* pre;

int main(void)
{
	ThreadedTreeNode* A = CreateThreadedTreeNode();
	ThreadedTreeNode* B = CreateThreadedTreeNode();
	ThreadedTreeNode* C = CreateThreadedTreeNode();
	ThreadedTreeNode* D = CreateThreadedTreeNode();
	ThreadedTreeNode* E = CreateThreadedTreeNode();
	ThreadedTreeNode* F = CreateThreadedTreeNode();

	A->left = B;
	A->right = C;
	B->left = D;
	D->left = E;
	B->right = F;

	CreateFrontThreadedBinaryTree(A);

	FillFrontTraverseThreadedBinaryTree(A);

	cout << endl;

	PrintFrontTraverseThreadedBinaryTree(A);

	DisruptThreadedBinaryTree(A);


	return 0;

}
*/

// Junior Binary Tree

/*
int main(void)
{
	TreeNode* root = CreateFullJuniorBinaryTree(5);
	FillLetterJuniorBinaryTree(root);
	cout << endl;

	FrontTraverseBinaryTree(root);

	DisruptJuniorBinaryTree(root);

	return 0;

}
*/

// Queue  环形的数据结构  只能尾进头出

/*
int main(void)
{
	Queue queue;
	CreateQueue(&queue, 20);
	FillRandomQueue(&queue, 50);
	PrintQueue(&queue);

	OfferQueue(&queue, 34);
	
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		temp = PullQueue(&queue);

	}
	PrintQueue(&queue);

	for (int i = 0; i < 5; i++)
	{
		OfferQueue(&queue, GetRandomNumber(10));

	}
	PrintQueue(&queue);

	cout << endl;

	while (!IsEmptyQueue(&queue)) {
		temp = PullQueue(&queue);
		cout << temp << " ";

	}
	cout << endl;


	DisruptQueue(&queue);


	return 0;

}
*/

// Stack  连续的内存空间  能查到全部数据(改查), 但是只能操作(增删)最顶部数据        共享栈

/*
int main(void)
{

	return 0;

}
*/

// Linear List   需要连续且完整的内存空间  包括了容量和长度的信息   可 增删改, 长度可变  随机存取

/*
int main(void)
{
	LinearList list = CreateLinearList(40);

	list = FillRandomDataLinearList(list, 100);

	PrintDataLinearList(list);

	list = ExpandLinearList(list, 25, 10);

	PrintDataLinearList(list);

	list = DeleteLinearList(list, 15);

	PrintDataLinearList(list);

	list = DeleteLinearList(list, 20);

	PrintDataLinearList(list);

	list = ModifyLinearList(list, 45, 10);

	PrintDataLinearList(list);

	int index = GetIndexLinearList(list, 45);

	cout << endl << "The position of number 45 is: " << index << endl;

	int number = GetDataLinearList(list, 33);

	cout << "The number hold the position 33 is: " << number << endl;


	DisruptLinearList(&list);


	return 0;

}
*/


