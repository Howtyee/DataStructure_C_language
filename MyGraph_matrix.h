//
// Created by 42516 on 2022/10/16.
//

#ifndef HTY_MYGRAPH_MATRIX_H
#define HTY_MYGRAPH_MATRIX_H

#include <cstdio>

#define MaxVertexNum 100

#define Status int
/*************   数据结构   ****************/

typedef char VerTexType;
typedef struct {
    VerTexType Vex[MaxVertexNum] = {};
    int Edge[MaxVertexNum][MaxVertexNum] = {0};
    int vexnum,arcnum;
}MGraph;
/*************   定义   ****************/
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



/*************   声明   ****************/
int LocateVex(MGraph G,char vex) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == vex)
            return i;
    }
    return -1;
}

Status Creat_MGraph(MGraph &G,bool Dir = false,bool Kon = false) {  //Dir:有向图 Kon:权重
    char tempa,tempb;
    int qz = 0;
    printf("input vex num:");
    scanf("%d",&G.vexnum);
    for(int i = 0;i< G.vexnum;i++){
        printf("input no:%d ",i);
        printf("vex:");
        scanf(" %c",&G.Vex[i]);
    }
    printf("input EDGE num:");
    scanf("%d",&G.arcnum);
    for(int i = 0;i< G.arcnum;i++){
        printf("input no:%d ",i);

        if(!Kon){
            if(!Dir){
                printf("EDGE(xx,xx):");
                scanf(" %c,%c",&tempa,&tempb);
                int a_num = LocateVex(G,tempa);
                int b_num = LocateVex(G,tempb);
                G.Edge[a_num][b_num] = 1;
                G.Edge[b_num][a_num] = 1;
            }
            else{
                printf("EDGE(xx,xx):");
                scanf(" %c,%c",&tempa,&tempb);
                int a_num = LocateVex(G,tempa);
                int b_num = LocateVex(G,tempb);
                G.Edge[a_num][b_num] = 1;
            }
        }
        else{
            if(!Dir){
                printf("EDGE(xx,xx,k):");
                scanf(" %c,%c,%d",&tempa,&tempb,&qz);
                int a_num = LocateVex(G,tempa);
                int b_num = LocateVex(G,tempb);
                G.Edge[a_num][b_num] = qz;
                G.Edge[b_num][a_num] = qz;
            }
            else{
                printf("EDGE(xx,xx,k):");
                scanf(" %c,%c,%d",&tempa,&tempb,&qz);
                int a_num = LocateVex(G,tempa);
                int b_num = LocateVex(G,tempb);
                G.Edge[a_num][b_num] = qz;
            }
        }
    }
    printf("Creat complete.\n");
    return 0;
}


bool Adjacent(MGraph G, char x, char y) {
    int a = LocateVex(G,x);
    int b = LocateVex(G,y);
    int aim = G.Edge[a][b];
    if(aim){
        return true;
    }
    else
        return false;
}



void Neighbors(MGraph G, char x) {
    int loc = LocateVex(G,x);
    for(int i = 0; i<G.vexnum;i++){
        if(G.Edge[loc][i]){
            printf("%c",G.Vex[i]);
        }
    }
}

void Print_MGraph(MGraph G) {
    printf("\t");
    for(int i = 0;i < G.vexnum; i++){
        printf("%c\t",G.Vex[i]);
    }
    printf("\n");
    for(int i = 0;i < G.vexnum; i++){
        printf("%c\t",G.Vex[i]);
        for (int j = 0; j < G.vexnum; j++) {
            printf("%d\t",G.Edge[i][j]);
        }
        printf("\n");
    }
}

Status InsertVertex(MGraph &G, char x) {
    G.Vex[G.vexnum] = x;
    G.vexnum++;
    return 0;
}

Status DeleteVertex(MGraph &G, char x,bool Dir = false) {
    int vex_count = 0;
    int loc = LocateVex(G,x);
    for(int i = loc;i<G.vexnum;i++){
        G.Vex[i] = G.Vex[i+1];
    }
    for(int i = 0;i<G.vexnum;i++){
        if(G.Edge[loc][i])
            vex_count++;
        if(G.Edge[i][loc])
            vex_count++;
    }
    for(int i = 0;i<=loc;i++){
        for(int j = loc;j<=G.vexnum;j++){
            G.Edge[i][j] = G.Edge[i][j+1];
            G.Edge[j][i] = G.Edge[j+1][i];
        }
    }
    for(int i = loc;i<=G.vexnum;i++){
        for(int j = loc;j<=G.vexnum;j++){
            G.Edge[i][j] = G.Edge[i+1][j+1];
        }
    }
    G.vexnum--;
    if(!Dir)
        G.arcnum = G.arcnum-(vex_count/2);
    else
        G.arcnum = G.arcnum-vex_count;
    return 0;
}

Status AddEdge(MGraph &G, char a, char b,bool Dir,int k=1) {
    if(a > G.vexnum||b > G.vexnum)
        return 1;
    if(!Dir){
        G.Edge[a][b] = k;
        G.Edge[b][a] = k;
    }
    else{
        G.Edge[a][b] = k;
    }
    G.arcnum++;
    return 0;
}

Status RemoveEdge(MGraph &G, char a, char b,bool Dir) {
    if(a > G.vexnum||b > G.vexnum)
        return 1;
    if(!Dir){
        if(G.Edge[a][b]==0 && G.Edge[b][a]==0){
            return 1;
        }
        G.Edge[a][b] = 0;
        G.Edge[b][a] = 0;
    }
    else{
        if(G.Edge[a][b]==0){
            return 1;
        }
        G.Edge[a][b] = 0;
    }
    G.arcnum --;
    return 0;
}

int FirstNeighbor(MGraph G, char x) {
    int loc = LocateVex(G,x);
    for(int i = 0;i<G.vexnum;i++){
        if(G.Edge[loc][i])
            return G.Vex[i];
    }
    return -1;
}

int NextNeighbor(MGraph G, char x, char y) {
    int locx = LocateVex(G,x);
    int locy = LocateVex(G,y);
    if(G.Edge[locx][locy] == 0)
        return -1;
    else
        for(int i = locy+1;i < G.vexnum;i++){
            if(G.Edge[locx][i])
                return G.Vex[i];
        }
    return -1;
}

int Get_edge_value(MGraph &G, char x, char y) {
    int locx = LocateVex(G,x);
    int locy = LocateVex(G,y);
    return G.Edge[locx][locy];

}

Status Set_edge_value(MGraph &G, char x, char y, int v, bool Dir) {
    int locx = LocateVex(G,x);
    int locy = LocateVex(G,y);
    if(!Dir){
        G.Edge[locx][locy] = v;
        G.Edge[locy][locx] = v;
    }
    else
        G.Edge[locx][locy] = v;
    return 0;
}


#endif //HTY_MYGRAPH_MATRIX_H
