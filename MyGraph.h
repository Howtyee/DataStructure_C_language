//
// Created by 42516 on 2022/10/16.
//

#ifndef HTY_MYGRAPH_H
#define HTY_MYGRAPH_H
#define MaxVertexNum 100

typedef char VerTexType;
typedef int EdgeType;
typedef struct {
    VerTexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;


//Link table
typedef struct ArcNode{ //串起来的每条边
    int adjvex;
    ArcNode* next;
}ArcNode;

typedef struct VNode{ //每个点
    VerTexType data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];

typedef struct {//整个图
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;



#endif //HTY_MYGRAPH_H
