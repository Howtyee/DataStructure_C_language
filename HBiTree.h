//
// Created by 42516 on 2022/10/14.
//

#ifndef HTY_HBITREE_H
#define HTY_HBITREE_H
#define Status int

#include <cstdio>
#include <cstdlib>

typedef struct BiTreeNode{
    int data;
    struct BiTreeNode *lchild,*rchild;
}BiTreeNode,*BiTree;


BiTreeNode * create(){
    BiTree T;
    int a;
    scanf("%d", &a);
    if (a == '.') return nullptr;//当输入.时表示这个结点为空，而且没有左右子树。
    else {
        T = (BiTree) malloc(sizeof(BiTree));//动态分配内存
        T->data = a;
        T->lchild = create();//创建左子树
        T->rchild = create();//创建右子树
    }
    return T;
}











#endif //HTY_HBITREE_H
