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
BiTreeNode * Create_first();
Status Create_Level(BiTree &T);

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
    printf("data:");
    scanf("%d",&data);
    if(data){
        EnQueue(Q,T);
        T->data =data;
        T->lchild = nullptr;
        T->rchild = nullptr;
    }
    else return 1;
    while (!QueueEmpty(Q)){
        DeQueue(Q,T);
        printf("ldata:");
        scanf("%d",&data);
        if(data){
            T->lchild = (BiTreeNode*) malloc(sizeof(BiTreeNode));
            T->lchild->data = data;
            EnQueue(Q,T->lchild);
        }
        else
            T->lchild = nullptr;

        printf("rdata:");
        scanf("%d",&data);
        if(data){
            T->rchild = (BiTreeNode*) malloc(sizeof(BiTreeNode));
            T->rchild->data = data;
            EnQueue(Q,T->rchild);
        }
        else
            T->rchild = nullptr;

    }











    return 0;
}


#endif //HTY_HBITREE_H
