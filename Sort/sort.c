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

//大顶堆，排序可得升序排列
void HeapAdjust(ElemType A[],int s,int n){
    ElemType temp=A[s];
    int lchild=2*s+1;//索引从0开始的话其左孩子为2s+1
    while(lchild<n){
        if(lchild+1<n && A[lchild+1]>A[lchild])
            lchild++;
        if(A[lchild]>A[s]){
            A[s]=A[lchild];
            s=lchild;
            lchild=2*s+1;
        }else{
            break;
        }
        A[s]=temp;
    }

}
void BuildHeap(ElemType A[],int n){
    for(int i=(n-1)/2;i>=0;i--)
        HeapAdjust(A,i,n);
}
void HeapSort(ElemType A[],int n){
    BuildHeap(A,n);
    //不断交换最后一个元素与大顶堆堆顶元素可得到升序排列，再调整堆
    for(int i=n-1;i>0;i--){
        ElemType temp=A[i];
        A[i]=A[0];
        A[0]=temp;
        HeapAdjust(A,0,i);
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

//其他类型
//将A1归并排序至A2,再根据A2修改A1即可
void Merge(ElemType A[],int s,int m,int t,ElemType Temp[]){
    int i=s;
    int j=m+1;
    int k=0;
    while(i<=m && j<=t){
        if(A[i]<=A[j]) Temp[k++]=A[i++];
        else Temp[k++]=A[j++];
    }
    while(i<=m) Temp[k++]=A[i++];
    while(j<=t) Temp[k++]=A[j++];
    for(int i=0;i<k;i++)
        A[s+i]=Temp[i];//重新调整A
}
void MergeSort(ElemType A[],int s,int t,ElemType Temp[]){
    if(s<t){
        int mid=(s+t)/2;
        MergeSort(A,s,mid,Temp);
        MergeSort(A,mid+1,t,Temp);
        Merge(A,s,mid,t,Temp);
    }
}
void MergeSortWrapper(ElemType A[],int n){
   //此处需要根据n来动态创建辅助数组
    ElemType *Temp=(ElemType *)malloc(n*sizeof(ElemType));
    MergeSort(A,0,n-1,Temp);
    free(Temp);
}

void BucketSort(ElemType A[],int n){
    ElemType bucket[Maxsize];
    for(int i=0;i<Maxsize;i++)
        bucket[i]=0;//-1 表示该桶未放入元素
    //将各个元素映射到桶
    for(int i=0;i<n;i++)
        ++bucket[A[i]];
    //遍历各个桶，将所有数一次写入A
    for(int i=0,j=0;i<Maxsize;i++)
        for(int k=bucket[i];k>0;k--)
            A[j++]=i;//bucket的下标为数组元素A[j]
}
#endif