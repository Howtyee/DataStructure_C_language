//
// Created by 42516 on 2022/10/14.
//

#ifndef HTY_HBITREE_H
#define HTY_HBITREE_H
#define Status int

#include <cstdio>
#include <cstdlib>

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

/*************   辅助定义   ****************/
Status visit(BiTreeNode* Node){
    printf("%d ",Node->data);
    return 0;
}

Status InitStack(Listack &S) {
    S = (Listack)malloc(sizeof(StackNode));
    S->data = 0;
    S->next = nullptr;
    return 0;
}
bool StackEmpty(Listack S) {
    if(S->next == nullptr){
        return true;
    }
    else
        return false;
}

Status Push(Listack &S, BiTreeNode* x) {
    StackNode * New_node = (StackNode*) malloc(sizeof(StackNode));
    New_node->data = x;
    New_node->next = S->next;
    S->next = New_node;
    return 0;
}

Status Pop(Listack &S, BiTreeNode* &x) {
    if(StackEmpty(S))
        return 1;
    StackNode *Tobe_pop = S->next;
    S->next = S->next->next;
    x = Tobe_pop->data;
    free(Tobe_pop);
    return 0;
}

Status GetTop(Listack S, BiTreeNode* &x) {
    if(StackEmpty(S))
        return 1;
    x = S->next->data;
    return 0;
}


Status InitQueue(LinkQueue &Q) {
    Q.front = (LinkNode*)malloc(sizeof(LinkNode));
    Q.rear = Q.front;
    Q.front->next = nullptr;
    return 0;
}

bool QueueEmpty(LinkQueue Q) {
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}
Status EnQueue(LinkQueue &Q, BiTreeNode* x) {
    LinkNode * new_one = (LinkNode*) malloc(sizeof(LinkNode));
    new_one->data = x;
    new_one->next = nullptr;
    Q.rear->next = new_one;
    Q.rear = new_one;
    return 0;
}

Status DeQueue(LinkQueue &Q, BiTreeNode* &x) {
    if(QueueEmpty(Q))
        return 1;
    LinkNode * temp = Q.front->next;
    if(temp == Q.rear){
        Q.rear = Q.front;
    }
    Q.front->next = Q.front->next->next;
    x = temp->data;
    free(temp);
    return 0;
}

/*************   定义   ****************/

Status Create_Level(BiTree &T) {
    LinkQueue Q;
    InitQueue(Q);
    int data = 0;
    T = (BiTreeNode*) malloc(sizeof(BiTreeNode));
    BiTreeNode * temp_node = 0;
    T->lchild = nullptr;
    T->rchild = nullptr;
    printf("data:");
    scanf("%d",&data);
    if(data){

        T->data =data;

        EnQueue(Q,T);
    }
    else return 1;
    while (!QueueEmpty(Q)){
        DeQueue(Q,temp_node);
        printf("ldata:");
        scanf("%d",&data);
        if(data){
            temp_node->lchild = (BiTreeNode*) malloc(sizeof(BiTreeNode));
            temp_node->lchild->data = data;
            EnQueue(Q,temp_node->lchild);
        }
        else
            temp_node->lchild = nullptr;

        printf("rdata:");
        scanf("%d",&data);
        if(data){
            temp_node->rchild = (BiTreeNode*) malloc(sizeof(BiTreeNode));
            temp_node->rchild->data = data;
            EnQueue(Q,temp_node->rchild);
        }
        else
            temp_node->rchild = nullptr;
    }

    return 0;
}

Status Print_Level(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    if(T->data) {
        EnQueue(Q, T);
    }
    while(!QueueEmpty(Q)){
        DeQueue(Q,T);
        printf("%d ",T->data);
        if(T->lchild != nullptr){
            EnQueue(Q,T->lchild);
        }
        if(T->rchild != nullptr){
            EnQueue(Q,T->rchild);
        }
    }
    return 0;
}

Status Create_front(BiTree &T){

    int a;
    printf("input:");
    scanf("%d", &a);
    if (a == 0) {
        T = nullptr;
    } //当输入.时表示这个结点为空，而且没有左右子树。
    else {
        T = (BiTree) malloc(sizeof(BiTree));//动态分配内存
        T->data = a;
        Create_front(T->lchild);//创建左子树
        Create_front(T->rchild);//创建右子树
    }
    return 0;
}

Status Print_front(BiTree T) {
    if(T!= nullptr){
        visit(T);
        Print_front(T->lchild);
        Print_front(T->rchild);
    }
    return 0;
}
Status Print_middle(BiTree T) {
    if(T!= nullptr){
        Print_middle(T->lchild);
        visit(T);
        Print_middle(T->rchild);
    }
    return 0;
}
Status Print_after(BiTree T) {
    if(T!= nullptr){
        Print_after(T->lchild);
        Print_after(T->rchild);
        visit(T);
    }
    return 0;
}
Status Print_front_stack(BiTree T) {
    Listack S;
    InitStack(S);
    BiTreeNode* p = T;
    while(p || !StackEmpty(S)){
        if(p){
            visit(p);
            Push(S,p);
            p = p->lchild;
        }
        else{
            Pop(S,p);
            p = p->rchild;
        }
    }
    return 0;
}

Status Print_middle_stack(BiTree T) {
    Listack S;
    InitStack(S);
    BiTreeNode* p = T;
    while(p || !StackEmpty(S)){
        if(p){
            Push(S,p);
            p = p->lchild;
        }
        else{
            Pop(S,p);
            visit(p);
            p = p->rchild;
        }
    }
    return 0;
}

Status Print_after_stack(BiTree T) {
    Listack S;
    InitStack(S);
    BiTreeNode* p = T;
    BiTreeNode* r = nullptr;  //记录上一次访问的节点
    while(p || !StackEmpty(S)){
        if(p){
            Push(S,p);
            p = p->lchild;
        }
        else{
            GetTop(S,p);
            if(p->rchild && p->rchild != r){ //右存在且未被访问过
                p = p->rchild;
            }
            else{
                Pop(S,p);
                visit(p);
                r = p;
                p = nullptr; //遍历完以该节点为根的子树，置空p
            }
        }
    }
    return 0;
}

#endif //HTY_HBITREE_H
