//
// Created by 42516 on 2022/10/16.
//

#ifndef HTY_MYGRAPH_MATRIX_H
#define HTY_MYGRAPH_MATRIX_H
#define MaxVertexNum 100

/*************   数据结构   ****************/

typedef char VerTexType;
typedef int EdgeType;
typedef struct {
    VerTexType Vex[MaxVertexNum] = {};
    EdgeType Edge[MaxVertexNum][MaxVertexNum] = {0};
    int vexnum,arcnum;
}MGraph;
/*************   定义   ****************/







/*************   声明   ****************/







#endif //HTY_MYGRAPH_MATRIX_H
