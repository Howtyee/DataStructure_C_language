//
// Created by 42516 on 2022/10/13.
//

#ifndef CAOGAO_MYDATASTRUCTURE_H
#define CAOGAO_MYDATASTRUCTURE_H
#define MAXSIZE 30
#define STATUS int



typedef struct Seqlist{
    int data[MAXSIZE];
    int top = 0;
}Seqlist;


bool Is_full(Seqlist List);

STATUS InitList(Seqlist &List){
    List.top = 0;
}

STATUS AddList(Seqlist &List){
    int a;
    if(Is_full(List)){
        printf("FULL!");
        return false;
    }
    printf("input:");
    scanf("%d",&a);
    while(a != -9999){
        List.top++;
        List.data[List.top] = a;
        if(Is_full(List))
            return false;
        printf("input:");
        scanf("%d",&a);
    }
    return true;
}

void PrintList(Seqlist List){
    for(int i = 0;i<List.top;i++){
        printf("%d ",List.data[i+1]);

    }
}

bool Is_full(Seqlist List){
    if(List.top == MAXSIZE){
        printf("FULL!");
        return true;
    }

    else
        return false;
}

int Pop_num(Seqlist &List){

    return List.data[List.top--];
}

#endif //CAOGAO_MYDATASTRUCTURE_H
