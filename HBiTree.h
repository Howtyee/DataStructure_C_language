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

/*************   声明   ****************/
Status InitQueue(LinkQueue &Q);
bool QueueEmpty(LinkQueue Q);
Status EnQueue(LinkQueue &Q, BiTreeNode* x);
Status DeQueue(LinkQueue &Q, BiTreeNode* &x);


BiTreeNode * Create_first();
Status Create_Level(BiTree &T);
Status Print_Level(BiTree T);

/*************   定义   ****************/
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
BiTreeNode * Create_first(){
    BiTree T;
    int a;
    scanf("%d", &a);
    if (a == '.') return nullptr;//当输入.时表示这个结点为空，而且没有左右子树。
    else {
        T = (BiTree) malloc(sizeof(BiTree));//动态分配内存
        T->data = a;
        T->lchild = Create_first();//创建左子树
        T->rchild = Create_first();//创建右子树
    }
    return T;
}

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





#endif //HTY_HBITREE_H
