//
// Created by 42516 on 2022/10/24.
//

#ifndef HTY_MYGRAPH_TABLE_H
#define HTY_MYGRAPH_TABLE_H

#include <cstdio>
#include <cstdlib>

#define MaxVertexNum 100
#define Status int


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


/*************   定义   ****************/
int LocateVex(ALGraph G,char vex){
    for(int i = 0;i<G.vexnum;i++){
        if(G.vertices[i].data == vex)
            return i;
    }
    return -1;
}
Status Creat_MGraph(ALGraph &G, bool Dir = false, bool Kon = false) {
    char tempa,tempb;
    int qz = 0; //临时存储权重
    G.vexnum = 0;
    G.arcnum = 0;
    int edgeNum = 0;
    printf("input vex num:");
    scanf("%d",&G.vexnum);
    for(int i = 0;i < G.vexnum;i++){
        printf("input no:%d ",i);
        printf("vex:");
        scanf(" %c",&G.vertices[i].data);
        G.vertices[i].first = nullptr;
    }
    printf("input EDGE num:");
    scanf("%d",&edgeNum);
    for(int i = 0;i< edgeNum;i++) {
        printf("input no:%d ", i);
        if (!Kon) {
            if (!Dir) {
                printf("EDGE(xx,xx):");
                scanf(" %c,%c", &tempa, &tempb);
                int a_num = LocateVex(G, tempa);
                int b_num = LocateVex(G, tempb);

                ArcNode * new_one = (ArcNode *)malloc(sizeof(ArcNode));
                new_one->adjvex = b_num;
                new_one->k = 1;
                new_one->next = G.vertices[a_num].first;
                G.vertices[a_num].first = new_one;
                G.arcnum++;

                ArcNode * new_two = (ArcNode *)malloc(sizeof(ArcNode));
                new_two->adjvex = a_num;
                new_two->k = 1;
                new_two->next = G.vertices[b_num].first;
                G.vertices[b_num].first = new_two;
                G.arcnum++;
            }
            else{
                printf("EDGE(xx,xx):");
                scanf(" %c,%c", &tempa, &tempb);
                int a_num = LocateVex(G, tempa);
                int b_num = LocateVex(G, tempb);

                ArcNode * new_one = (ArcNode *)malloc(sizeof(ArcNode));
                new_one->adjvex = b_num;
                new_one->k = 1;
                new_one->next = G.vertices[a_num].first;
                G.vertices[a_num].first = new_one;
                G.arcnum++;

            }
        }
        else{
            if (!Dir) {
                printf("EDGE(xx,xx,k):");
                scanf(" %c,%c,%d",&tempa,&tempb,&qz);
                int a_num = LocateVex(G, tempa);
                int b_num = LocateVex(G, tempb);

                ArcNode * new_one = (ArcNode *)malloc(sizeof(ArcNode));
                new_one->adjvex = b_num;
                new_one->k = qz;
                new_one->next = G.vertices[a_num].first;
                G.vertices[a_num].first = new_one;
                G.arcnum++;

                ArcNode * new_two = (ArcNode *)malloc(sizeof(ArcNode));
                new_two->adjvex = a_num;
                new_two->k = qz;
                new_two->next = G.vertices[b_num].first;
                G.vertices[b_num].first = new_two;
                G.arcnum++;
            }
            else{
                printf("EDGE(xx,xx,k):");
                scanf(" %c,%c,%d",&tempa,&tempb,&qz);
                int a_num = LocateVex(G, tempa);
                int b_num = LocateVex(G, tempb);

                ArcNode * new_one = (ArcNode *)malloc(sizeof(ArcNode));
                new_one->adjvex = b_num;
                new_one->k = qz;
                new_one->next = G.vertices[a_num].first;
                G.vertices[a_num].first = new_one;
                G.arcnum++;

            }
        }
    }
    return 0;
}

bool Adjacent(ALGraph G, char x, char y) {
    int num1 = LocateVex(G,x);
    int num2 = LocateVex(G,y);
    ArcNode* temp = G.vertices[num1].first;
    while (temp!= nullptr){
        if(temp->adjvex == num2)
            return true;
        temp = temp->next;
    }
    return false;
}

void Neighbors(ALGraph G, char x) {
    int num = LocateVex(G,x);
    ArcNode* temp = G.vertices[num].first;
    while(temp!= nullptr){
        printf("%c ",temp->adjvex);
        temp = temp->next;
    }
}


void Print_MGraph(ALGraph G, bool Kon=false) {
    if(!Kon){
        for(int i = 0;i<G.vexnum;i++){
            printf("%c",G.vertices[i].data);
            printf("->");
            ArcNode * edge = G.vertices[i].first;
            while(edge != nullptr){
                printf("%c",G.vertices[edge->adjvex].data);
                printf("->");
                edge = edge->next;
            }
            printf("^\n");
        }
    }
    else{
        for(int i = 0;i<G.vexnum;i++){
            printf("%c",G.vertices[i].data);
            printf("->");
            ArcNode * edge = G.vertices[i].first;
            while(edge != nullptr){
                printf("%c",G.vertices[edge->adjvex].data);
                printf("(");
                printf("%d",edge->k);
                printf(")->");
                edge = edge->next;
            }
            printf("^\n");
        }
    }
}

Status InsertVertex(ALGraph &G, char x) {
    G.vertices[G.vexnum].data = x;
    G.vertices[G.vexnum].first = nullptr;
    G.vexnum++;
    return 0;
}

Status DeleteVertex(ALGraph &G, char x) {
    int del_num = LocateVex(G,x);
    ArcNode * del_arc = G.vertices[del_num].first;
    while (del_arc!= nullptr){
        ArcNode *p = del_arc;
        del_arc = del_arc->next;
        free(p);
        G.arcnum--;
    }
    G.vertices[del_num].first = del_arc;
    for(int i = del_num;i<G.vexnum;i++){
        G.vertices[i] = G.vertices[i+1];
    }
    G.vexnum--;
    for(int i = 0;i<G.vexnum;i++){
        ArcNode * edge = G.vertices[i].first;
        while(edge!= nullptr && edge->adjvex == del_num){ //如果有第一个节点且第一个节点要被删，删第一个
            ArcNode * p = edge;
            G.vertices[i].first = edge->next;
            edge = edge->next;
            free(p);
            G.arcnum--;
        }
        edge = G.vertices[i].first;
        while(edge!= nullptr && edge->next!= nullptr){//如果有第一个节点但第一个节点不用被删，检查之后的节点
            if(edge->next->adjvex == del_num){
                ArcNode * p = edge->next;
                edge->next = edge->next->next;
                free(p);
                G.arcnum--;
            }
            else
                edge = edge->next;
        }
    }
    return 0;
}

Status AddEdge(ALGraph &G, char a, char b, bool Dir = false ,int k=1) {
    int loc_a = LocateVex(G,a);
    int loc_b = LocateVex(G,b);
    ArcNode * edge = G.vertices[loc_a].first;
    if(edge == nullptr){
        ArcNode * new_one = (ArcNode*) malloc(sizeof(ArcNode));
        new_one->adjvex =loc_b;
        new_one->next = nullptr;
        new_one->k = k;
        G.vertices[loc_a].first = new_one;
        G.arcnum++;
    }
    else{
        while(edge->next != nullptr){
            edge = edge->next;
        }
        ArcNode * new_one = (ArcNode*) malloc(sizeof(ArcNode));
        new_one->adjvex =loc_b;
        new_one->next = nullptr;
        new_one->k = k;
        edge->next = new_one;
        G.arcnum++;
    }
    if(!Dir){
        ArcNode * edge2 = G.vertices[loc_b].first;
        if(edge2 == nullptr){
            ArcNode * new_two = (ArcNode*) malloc(sizeof(ArcNode));
            new_two->adjvex =loc_a;
            new_two->next = nullptr;
            new_two->k = k;
            G.vertices[loc_b].first = new_two;
            G.arcnum++;
        }
        else{
            while(edge2!= nullptr){
                edge2 = edge2->next;
            }
            ArcNode * new_two = (ArcNode*) malloc(sizeof(ArcNode));
            new_two->adjvex =loc_a;
            new_two->next = nullptr;
            new_two->k = k;
            edge2->next = new_two;
            G.arcnum++;
        }
    }

    return 0;
}

Status RemoveEdge(ALGraph &G, char a, char b, bool Dir=false) {
    int loc_a = LocateVex(G,a);
    int loc_b = LocateVex(G,b);
    ArcNode * edge = G.vertices[loc_a].first;
    while(edge!= nullptr && edge->adjvex == loc_b){ //如果有第一个节点且第一个节点要被删，删第一个
        ArcNode * p = edge;
        G.vertices[loc_a].first = edge->next;
        edge = edge->next;
        free(p);
        G.arcnum--;
    }
    edge = G.vertices[loc_a].first;
    while(edge!= nullptr && edge->next!= nullptr){//如果有第一个节点但第一个节点不用被删，检查之后的节点
        if(edge->next->adjvex == loc_b){
            ArcNode * p = edge->next;
            edge->next = edge->next->next;
            free(p);
            G.arcnum--;
        }
        else
            edge = edge->next;
        }
    if(!Dir){
        ArcNode * edge = G.vertices[loc_b].first;
        while(edge!= nullptr && edge->adjvex == loc_a){ //如果有第一个节点且第一个节点要被删，删第一个
            ArcNode * p = edge;
            G.vertices[loc_b].first = edge->next;
            edge = edge->next;
            free(p);
            G.arcnum--;
        }
        edge = G.vertices[loc_b].first;
        while(edge!= nullptr && edge->next!= nullptr){//如果有第一个节点但第一个节点不用被删，检查之后的节点
            if(edge->next->adjvex == loc_a){
                ArcNode * p = edge->next;
                edge->next = edge->next->next;
                free(p);
                G.arcnum--;
            }
            else
                edge = edge->next;
        }
    }
    return 0;
}

int FirstNeighbor(ALGraph G, char x) {
    int loc_x = LocateVex(G,x);
    if(G.vertices[loc_x].first){
        return G.vertices[G.vertices[loc_x].first->adjvex].data;
    }
    return -1;
}

int NextNeighbor(ALGraph G, char x, char y) {
    int loc_x = LocateVex(G,x);
    int loc_y = LocateVex(G,y);
    ArcNode * edge = G.vertices[loc_x].first;
    if(edge!= nullptr){
        if(edge->adjvex == loc_y && edge->next!= nullptr){
            return G.vertices[edge->next->adjvex].data;
        }
    }
    return -1;
}

int Get_edge_value(ALGraph &G, char x, char y) {
    int loc_x = LocateVex(G,x);
    int loc_y = LocateVex(G,y);
    ArcNode * edge = G.vertices[loc_x].first;
    if(edge!= nullptr){
        if(edge->adjvex == loc_y){
            return edge->k;
        }
    }
    return 0;
}

Status Set_edge_value(ALGraph &G, char x, char y, int v, bool Dir=false) {
    int loc_x = LocateVex(G,x);
    int loc_y = LocateVex(G,y);
    ArcNode * edge = G.vertices[loc_x].first;
    if(edge!= nullptr){
        if(edge->adjvex == loc_y){
            edge->k = v;
        }
    }
    if(!Dir){
        ArcNode * edge = G.vertices[loc_y].first;
        if(edge!= nullptr){
            if(edge->adjvex == loc_x){
                edge->k = v;
            }
        }
    }
    return 0;
}



#endif //HTY_MYGRAPH_TABLE_H
