//
// Created by 42516 on 2022/10/24.
//

#ifndef HTY_MYGRAPH_TABLE_H
#define HTY_MYGRAPH_TABLE_H

#define MaxVertexNum 100
typedef int VerTexType;



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




#endif //HTY_MYGRAPH_TABLE_H
