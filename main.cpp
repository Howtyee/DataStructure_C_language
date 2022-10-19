#include<cstdio>
//#include "MyList.h"
//#include "Mysorts.h"
//#include "MyLinklist.h"
//#include "MyStack.h"
#include "HBiTree.h"
//#include"MyQueue.h"
#include<iostream>
using namespace std;




int main()
{

    BiTree t;
//    Create_Level(t);

    Create_first(t);
    Print_Level(t);
    cout<<endl;

    Print_first(t);
    cout<<endl;
    Print_middle(t);
    cout<<endl;

    Print_after(t);
    return 0;

}
