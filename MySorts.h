//
// Created by 42516 on 2022/10/13.
//

#ifndef CAOGAO_MYSORTS_H
#define CAOGAO_MYSORTS_H
int bublesort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    return 0;
}

int insertsort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1]=temp;
    }
    return 0;
}

int quiksort(int a[],int low,int high)
{
    int i=low,j=high;
    int temp=a[low];
    if(low>=high)
        return 0;
    while(i<j)
    {
        while(i<j&&a[j]>=temp)
            j--;
        a[i]=a[j];
        while(i<j&&a[i]<=temp)
            i++;
        a[j]=a[i];
    }
    a[i]=temp;
    quiksort(a,low,i-1);
    quiksort(a,i+1,high);
    return 0;
}
#endif //CAOGAO_MYSORTS_H
