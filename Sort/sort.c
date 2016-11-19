#ifndef _SORT_C
#define _SORT_C
#include "../custom_define.h"

//插入型
void InsertSort(ElemType A[],int n){
    //索引从0开始
    ElemType temp;
    for(int i=1;i<n;i++){
        temp=A[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(temp<A[j])
                A[j+1]=A[j];
            else
                break;
        }
        A[j+1]=temp;
    }
}

void ShellSort(ElemType A[],int n){
   for(int gap=n/2;gap>0;gap/=2){
       //分组插入排序 gap组
       for(int i=0;i<gap;i++){
           for(int j=i+gap;j<n;j+=gap){
               //组内插入排序
               ElemType temp=A[j];
               int k;
               for(k=j-gap;k>=0;k-=gap){
                   if(temp<A[k])
                       A[k+gap]=A[k];
                   else
                       break;
               }
               A[k+gap]=temp;
           }
       }
   }
}

//选择型
void SimpleSelectSort(ElemType A[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(A[min]>A[j])
                min=j;
        int temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}

//交换型
void BubbleSort(ElemType A[],int n){
    //大数往后
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int QuickPartition(ElemType A[],int low,int high){
    ElemType key=A[low];
    while(low<high){
        while(low<high && A[high]>=key) --high;
        int temp=A[low];A[low]=A[high];A[high]=temp;
        while(low<high && A[low]<=key) ++low;
        int temp2=A[high];A[high]=A[low];A[low]=temp2;
    }
    return low;
}
void QuickSort(ElemType A[],int low,int high){
    if(low<high){
        int part_loc=QuickPartition(A,low,high);
        QuickSort(A,low,part_loc-1);
        QuickSort(A,part_loc+1,high);
    }
}
void QuickSortWrapper(ElemType A[],int n){
    QuickSort(A,0,n-1);
}




#endif