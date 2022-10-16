#include<cstdio>
//#include "MyList.h"
//#include "Mysorts.h"
#include "MyLinklist.h"



int main()
{



    Linklist list;
    Init_linklist(list);
    Create_linklist(list);

    int a;
    ListInsert_linklist(list,3,1);
    ListDelete_linklist(list,3,a);
    printf("%d\n",a);




    PrintList_linklist(list);
    DestroyList_linklist(list);
    return 0;

}
