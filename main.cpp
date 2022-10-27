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
    Creat_MGraph(t,1,1);
    Print_MGraph(t,1);
    cout << t.arcnum << " " << t.vexnum << endl;



    return 0;
}
