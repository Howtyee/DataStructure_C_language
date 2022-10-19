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

    Create_front(t);
    Print_Level(t);
    cout<<endl;

    Print_front_stack(t);
    cout<<endl;
    Print_middle_stack(t);
    cout<<endl;

    Print_after_stack(t);
    return 0;

}
