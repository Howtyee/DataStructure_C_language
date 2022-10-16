// 链式栈
// Created by 42516 on 2022/10/16.
//

#ifndef HTY_MYSTACK_H
#define HTY_MYSTACK_H

#include <cstdlib>
#include <cstdio>

#define Status int

/*************   数据结构   ****************/
typedef int Elemtype;

typedef struct LinkNode{
    Elemtype data;
    LinkNode* next;
}*Listack;


/*************   定义   ****************/
Status InitStack(Listack &S);
bool StackEmpty(Listack S);
Status Push(Listack &S, Elemtype x);
Status Pop(Listack &S, Elemtype &x);
Status GetTop(Listack S, Elemtype &x);
Status DestroyStack(Listack &S);

void buildStack(Listack &S);
void printStack(Listack S);


/*************   实现   ****************/
Status InitStack(Listack &S) {
    S = (Listack)malloc(sizeof(LinkNode));
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

Status Push(Listack &S, Elemtype x) {
    LinkNode * New_node = (LinkNode*) malloc(sizeof(LinkNode));
    New_node->data = x;
    New_node->next = S->next;
    S->next = New_node;
    return 0;
}

Status Pop(Listack &S, Elemtype &x) {
    if(StackEmpty(S))
        return 1;
    LinkNode *Tobe_pop = S->next;
    S->next = S->next->next;
    x = Tobe_pop->data;
    free(Tobe_pop);
    return 0;
}

Status GetTop(Listack S, Elemtype &x) {
    if(StackEmpty(S))
        return 1;
    x = S->next->data;
    return 0;
}

Status DestroyStack(Listack &S) {
    while(S->next!= nullptr){
        LinkNode * p = S;
        S = S->next;
        free(p);
    }
    free(S);
    return 0;
}

void buildStack(Listack &S) {
    Elemtype temp;
    printf("Input:");
    scanf("%d",&temp);
    while(temp!=-9999){
        Push(S,temp);
        printf("Input:");
        scanf("%d",&temp);
    }
}

void printStack(Listack S) {
    LinkNode * ir = S;
    while(ir->next!= nullptr){
        ir = ir->next;
        printf("%d ",ir->data);
    }
    printf("\nOK.");
}


#endif //HTY_MYSTACK_H
