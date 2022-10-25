#include<cstdio>
//#include "MyList.h"
//#include "Mysorts.h"
//#include "MyLinklist.h"
//#include "MyStack.h"
//#include "HBiTree.h"
//#include"MyQueue.h"
//#include "ThreadBitree.h"
#include "MyGraph_matrix.h"
#include<iostream>
using namespace std;




int main()
{
    MGraph t;
    Creat_MGraph(t);
    cout << t.arcnum << " " << t.vexnum << endl;
    Print_MGraph(t);



    int x = FirstNeighbor(t,'A');
    cout << x;

    return 0;
}
