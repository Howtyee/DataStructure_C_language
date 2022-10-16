// 队列
// Created by 42516 on 2022/10/16.
//

#ifndef HTY_MYQUEUE_H
#define HTY_MYQUEUE_H

#include <cstdlib>

#define Status int

typedef int Elemtype;

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

Status EnQueue(LinkQueue &Q, Elemtype x) {
    LinkNode * new_one = (LinkNode*) malloc(sizeof(LinkNode));
    new_one->data = x;
    new_one->next = nullptr;
    Q.rear->next = new_one;
    Q.rear = new_one;
    return 0;
}

Status DeQueue(LinkQueue &Q, Elemtype &x) {
    if(QueueEmpty(Q))
        return 1;
    LinkNode * temp = Q.front->next;
    Q.front->next = Q.front->next->next;
    x = temp->data;
    free(temp);
    return 0;
}

Status GetHead(LinkQueue Q, Elemtype &x) {
    if(QueueEmpty(Q))
        return 1;
    x = Q.front->data;
    return 0;
}

Status DestroyQueue(LinkQueue &Q) {
    while (Q.front->next!= nullptr){
        LinkNode *p = Q.front;
        Q.front = Q.front->next;
        free(p);
    }
    return 0;
}

void buildQueue(LinkQueue &Q) {
    Elemtype temp;
    printf("Input:");
    scanf("%d",&temp);
    while(temp!=-9999){
        EnQueue(Q,temp);
        printf("Input:");
        scanf("%d",&temp);
    }
}

void printQueue(LinkQueue Q) {
    LinkNode * ir = Q.front;
    while(ir->next!= nullptr){
        ir = ir->next;
        printf("%d ",ir->data);
    }
    printf("\nOK.");
}


#endif //HTY_MYQUEUE_H
