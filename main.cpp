#include<cstdio>
//#include "MyList.h"
//#include "Mysorts.h"
//#include "MyLinklist.h"
//#include "MyStack.h"
//#include "HBiTree.h"
//#include"MyQueue.h"
//#include "ThreadBitree.h"
//#include "MyGraph_matrix.h"
#include "MyGraph_table.h"
#include<iostream>
using namespace std;




int main()
{
    setbuf(stdout, 0);
    ALGraph t;
    Creat_MGraph(t);
    Print_MGraph(t);
    cout << t.arcnum << " " << t.vexnum << endl;
    InsertVertex(t,'D');
    Print_MGraph(t);
    cout << t.arcnum << " " << t.vexnum << endl;
    DeleteVertex(t,'B');
    Print_MGraph(t);
    cout << t.arcnum << " " << t.vexnum << endl;
    AddEdge(t,'A','C');
    Print_MGraph(t);
    cout << t.arcnum << " " << t.vexnum << endl;
    AddEdge(t,'A','D');
    Print_MGraph(t);
    cout << t.arcnum << " " << t.vexnum << endl;

    char x = FirstNeighbor(t,'A');
    char y = NextNeighbor(t,'A','C');
    Set_edge_value(t,'A','C',100);
    cout << x << y;



    return 0;
}
