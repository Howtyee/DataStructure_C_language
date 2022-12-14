//
// Created by 42516 on 2022/10/20.
//

#ifndef HTY_THREADBITREE_H
#define HTY_THREADBITREE_H

#include <cstdlib>
#include <cstdio>

#define Status int
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


/*************   声明   ****************/


Status Create_Level(ThreadBiTree &T);   //层次建立
Status Print_Level(ThreadBiTree T);     //层次遍历
Status CreatInThread(ThreadBiTree &T);
Status Print_Thread(ThreadBiTree T);




/*************   辅助定义   ****************/
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
Status EnQueue(LinkQueue &Q, ThreadBiTreeNode* x) {
    LinkNode * new_one = (LinkNode*) malloc(sizeof(LinkNode));
    new_one->data = x;
    new_one->next = nullptr;
    Q.rear->next = new_one;
    Q.rear = new_one;
    return 0;
}

Status DeQueue(LinkQueue &Q, ThreadBiTreeNode* &x) {
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
Status Create_Level(ThreadBiTree &T) {
    LinkQueue Q;
    InitQueue(Q);
    int data = 0;
    T = (ThreadBiTreeNode*) malloc(sizeof(ThreadBiTreeNode));
    ThreadBiTreeNode * temp_node = 0;
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
            temp_node->lchild = (ThreadBiTreeNode*) malloc(sizeof(ThreadBiTreeNode));
            temp_node->lchild->data = data;
            EnQueue(Q,temp_node->lchild);
        }
        else
            temp_node->lchild = nullptr;

        printf("rdata:");
        scanf("%d",&data);
        if(data){
            temp_node->rchild = (ThreadBiTreeNode*) malloc(sizeof(ThreadBiTreeNode));
            temp_node->rchild->data = data;
            EnQueue(Q,temp_node->rchild);
        }
        else
            temp_node->rchild = nullptr;
    }
    return 0;
}



Status Print_Level(ThreadBiTree T) {
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

void InThread(ThreadBiTree &T, ThreadBiTree &pre){
    if(T != nullptr){
        InThread(T->lchild,pre);
        if(T->lchild == nullptr){
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre!= nullptr && pre->rchild == nullptr){
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
        InThread(T->rchild,pre);
    }
}

Status CreatInThread(ThreadBiTree &T) {
    ThreadBiTree pre = nullptr;
    if(T != nullptr){
        InThread(T,pre);
        pre->rchild = nullptr;
        pre->rtag = 1;
    }

    return 0;
}

ThreadBiTreeNode *Firstnode(ThreadBiTreeNode *p){
    while(p->ltag==0){
        p = p->lchild;
    }
    return p;
}

ThreadBiTreeNode *Nextnode(ThreadBiTreeNode *p){
    if(p->rtag==0){
        return Firstnode(p->rchild);
    }
    else
        return p->rchild;
}

Status Print_Thread(ThreadBiTreeNode *T) {
    for(ThreadBiTreeNode *p = Firstnode(T);p!= nullptr;p= Nextnode(p)){
        printf("%d",p->data);
    }

    return 0;
}

#endif //HTY_THREADBITREE_H
