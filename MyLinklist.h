// 链表
// Created by 42516 on 2022/10/14.
//

#ifndef HTY_MYLINKLIST_H
#define HTY_MYLINKLIST_H
#include <cstdlib>
#include <cstdio>

#define Status int


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



/*************   定义   ****************/


Status Init_linklist(Linklist &Head) {
    Head = (Linklist) malloc(sizeof(Lnode));
    Head->data = 0;
    Head->next = NULL;
}

Lnode *LocateElem_linklist(Linklist Head, int e) {
    Lnode* p = Head;
    while(p->next!=NULL){
        if(p->data == e){
            return p;
        }
        else{
            p = p->next;
        }
    }
    return NULL;
}

int Length_linklist(Linklist Head){
    Lnode *p = Head;
    int length = 0;
    while (p->next != NULL){

        length++;
        p = p->next;
    }
    return length;
}


int GetElem_linklist(Linklist Head, int i){
    Lnode* p = Head;
    if(i> Length_linklist(Head))
        return -1;
    for(int k = 0; k<i;k++){
        p = p->next;
    }
    return p->data;

}

Status ListInsert_linklist(Linklist& Head,int i,int e){
    Lnode *p = Head;
    if(i> Length_linklist(Head))
        return -1;
    for(int k = 0; k<i;k++){
        p = p->next;
    }
    Lnode *q = (Lnode *) malloc(sizeof(Lnode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

Status ListDelete_linklist(Linklist& Head,int i,int & e){
    Lnode *p = Head;
    if(i > Length_linklist(Head))
        return -1;
    for(int k = 0; k<i;k++){
        p = p->next;
    }
    Lnode *q = p->next;
    p->next = p->next->next;
    e = q->data;
    free(q);
    return 0;
}

Status PrintList_linklist(Linklist Head){
    Lnode* p;
    p = Head;
    while(p->next != NULL){
        p = p->next;
        printf("%d ",p->data);
    }
    printf("ok.");
    return 0;

}

bool Empty_linklist(Linklist Head){
    if(Head->next == NULL){
        return true;
    }
    else
        return false;
}

Status DestroyList_linklist(Linklist& Head){
    Lnode *p = Head;
    Lnode *q;
    while(p->next != NULL){
        q = p;
        p = p->next;
        free(q);
    }
    free(p);
    return 0;
}

Status Create_linklist(Linklist& Head){
    Lnode *p = Head;
    int data;
    printf("input the number:");
    scanf("%d",&data);
    while(data!=-9999){
        Lnode *q = (Lnode*) malloc(sizeof(Lnode));
        p->next = q;
        p = p->next;
        p->data = data;
        p->next = NULL;
        printf("input the number:");
        scanf("%d",&data);
    }


    return 0;
}






#endif //HTY_MYLINKLIST_H
