# **DataStructure_C_language**
## C语言版数据结构

1. ### 线性表

   - #### 数组

     ```c++
     /*************   数据结构   ****************/
     typedef struct Seqlist{
         int data[MAXSIZE];
         int top = 0;
     }Seqlist;
     
     /*************   声明   ****************/
     bool Is_full(Seqlist List);
     STATUS InitList(Seqlist &List);
     void PrintList(Seqlist List);
     int Pop_num(Seqlist &List);
     ```

     

   - #### 单链表

     ```c++
     /*************   数据结构   ****************/
     typedef struct Lnode{
         int data;
         Lnode *next;
     
     }Lnode,*Linklist;
     
     
     /*************   声明   ****************/
     
     Status Init_linklist(Linklist& Head);
     Lnode * LocateElem_linklist(Linklist Head, int e);
     int Length_linklist(Linklist Head);
     int GetElem_linklist(Linklist Head, int i);
     Status ListInsert_linklist(Linklist& Head,int i,int e);
     Status ListDelete_linklist(Linklist& Head,int i,int & e);
     Status PrintList_linklist(Linklist Head);
     bool Empty_linklist(Linklist Head);
     Status DestroyList_linklist(Linklist& Head);
     Status Create_linklist(Linklist& Head);
     ```

     

2. ### 栈

   - #### 链栈

     ```c++
     /*************   数据结构   ****************/
     typedef int Elemtype;
     
     typedef struct LinkNode{
         Elemtype data;
         LinkNode* next;
     }*Listack;
     
     
     /*************   声明   ****************/
     Status InitStack(Listack &S);
     bool StackEmpty(Listack S);
     Status Push(Listack &S, Elemtype x);
     Status Pop(Listack &S, Elemtype &x);
     Status GetTop(Listack S, Elemtype &x);
     Status DestroyStack(Listack &S);
     
     void buildStack(Listack &S);
     void printStack(Listack S);
     
     ```

     

3. ### 队列

   - #### 链式队列

     ```c++
     /*************   数据结构   ****************/
     typedef struct LinkNode{
         Elemtype data;
         LinkNode *next;
     }LinkNode;
     
     typedef struct{
         LinkNode *front,*rear;
     }LinkQueue;
     /*************   声明   ****************/
     Status InitQueue(LinkQueue &Q);
     bool QueueEmpty(LinkQueue Q);
     Status EnQueue(LinkQueue &Q,Elemtype x);
     Status DeQueue(LinkQueue &Q,Elemtype &x);
     Status GetHead(LinkQueue Q,Elemtype &x);
     Status DestroyQueue(LinkQueue &Q);
     
     void buildQueue(LinkQueue &Q);
     void printQueue(LinkQueue Q);
     
     ```

     

4. ### 串（ing）

5. ### 树

   - #### 二叉树

     ```c++
     /*************   数据结构   ****************/
     
     typedef struct BiTreeNode{
         int data;
         struct BiTreeNode *lchild,*rchild;
     }BiTreeNode,*BiTree;
     
     typedef struct LinkNode{
         BiTreeNode * data;
         LinkNode *next;
     }LinkNode;
     
     typedef struct{
         LinkNode *front,*rear;
     }LinkQueue;
     
     typedef struct StackNode{
         BiTreeNode * data;
         StackNode* next;
     }*Listack;
     
     /*************   辅助声明   ****************/
     Status InitQueue(LinkQueue &Q);
     bool QueueEmpty(LinkQueue Q);
     Status EnQueue(LinkQueue &Q, BiTreeNode* x);
     Status DeQueue(LinkQueue &Q, BiTreeNode* &x);
     
     Status InitStack(Listack &S);
     bool StackEmpty(Listack S);
     Status Push(Listack &S, BiTreeNode* x);
     Status Pop(Listack &S, BiTreeNode* &x);
     Status GetTop(Listack S, BiTreeNode* &x);
     
     /*************   声明   ****************/
     
     Status Create_front(BiTree &T);   //先序建立
     Status Create_Level(BiTree &T);   //层次建立
     
     Status Print_front(BiTree T);     //先序遍历
     Status Print_middle(BiTree T);     //中序遍历
     Status Print_after(BiTree T);     //后序遍历
     Status Print_Level(BiTree T);     //层次遍历
     Status visit(BiTreeNode* Node);   //访问节点函数
     
     Status Print_front_stack(BiTree T);     //先序遍历非递归
     Status Print_middle_stack(BiTree T);     //中序遍历非递归
     Status Print_after_stack(BiTree T);     //后序遍历非递归
     
     
     ```

     

   - #### 线索二叉树

     ```c++
     /*************   数据结构   ****************/
     typedef struct ThreadBiTreeNode{
         int data;
         struct ThreadBiTreeNode *lchild,*rchild;
         int ltag = 0,rtag = 0;
     }ThreadBiTreeNode,*ThreadBiTree;
     
     typedef struct LinkNode{
         ThreadBiTreeNode * data;
         LinkNode *next;
     }LinkNode;
     
     typedef struct{
         LinkNode *front,*rear;
     }LinkQueue;
     
     /*************   辅助声明   ****************/
     Status InitQueue(LinkQueue &Q);
     bool QueueEmpty(LinkQueue Q);
     Status EnQueue(LinkQueue &Q, ThreadBiTreeNode* x);
     Status DeQueue(LinkQueue &Q, ThreadBiTreeNode* &x);
     
     ```

     

6. ### 图

   - #### 邻接矩阵

     ```c++
     /*************   数据结构   ****************/
     
     typedef char VerTexType;
     typedef struct {
         VerTexType Vex[MaxVertexNum] = {};
         int Edge[MaxVertexNum][MaxVertexNum] = {0};
         int vexnum,arcnum;
     }MGraph;
     /*************   声明   ****************/
     int LocateVex(MGraph G,char vex);
     Status Creat_MGraph(MGraph &G,bool Dir,bool Kon); //Dir:是有向图 Kon:带权重
     bool Adjacent(MGraph G,char x,char y);
     void Neighbors(MGraph G, char x);
     void Print_MGraph(MGraph G);
     
     Status InsertVertex(MGraph &G,char x);
     Status DeleteVertex(MGraph &G,char x,bool Dir);
     Status AddEdge(MGraph &G,char a,char b,bool Dir,int k);
     Status RemoveEdge(MGraph &G,char a,char b,bool Dir);
     int FirstNeighbor(MGraph G,char x);
     int NextNeighbor(MGraph G,char x,char y);
     int Get_edge_value(MGraph &G,char x,char y);
     Status Set_edge_value(MGraph &G,char x,char y,int v,bool Dir);
     
     ```

     

   - #### 邻接表

     ```c++
     /*************   数据结构   ****************/
     //Link table
     typedef struct ArcNode{ //串起来的每条边
         int adjvex;
         int k = 1;             //kon
         ArcNode* next;
     }ArcNode;
     
     typedef struct VNode{ //每个点
         char data;
         ArcNode *first;
     }VNode,AdjList[MaxVertexNum];
     
     typedef struct ALGraph{//整个图
         AdjList vertices;
         int vexnum,arcnum;
     }ALGraph;
     
     /*************   声明   ****************/
     int LocateVex(ALGraph G,char vex);
     Status Creat_MGraph(ALGraph &G,bool Dir,bool Kon);  //Dir:是有向图 Kon:带权重
     bool Adjacent(ALGraph G,char x,char y);
     void Neighbors(ALGraph G, char x);
     void Print_MGraph(ALGraph G,bool Kon);
     
     Status InsertVertex(ALGraph &G,char x);
     Status DeleteVertex(ALGraph &G,char x);
     Status AddEdge(ALGraph &G,char a,char b,bool Dir,int k); //k 权重
     Status RemoveEdge(ALGraph &G,char a,char b,bool Dir);
     int FirstNeighbor(ALGraph G,char x);
     int NextNeighbor(ALGraph G,char x,char y);
     int Get_edge_value(ALGraph &G,char x,char y);
     Status Set_edge_value(ALGraph &G,char x,char y,int v,bool Dir);
     
     ```

     

7. ### 查找（ing）

8. ### 排序（ing）

   - #### 已实现的排序

     ```c++
     /*************   声明   ****************/
     int bublesort(int a[],int n);
     int insertsort(int a[],int n);
     int quiksort(int a[],int low,int high);
     
     ```

     

