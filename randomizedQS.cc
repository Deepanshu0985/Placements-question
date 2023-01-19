#include <iostream>
#include <cstdlib>
using namespace std;
void swap (int *arr,int a ,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(int *arr,int l,int h){
    int pivot = arr[h];
    int i=l-1;
    for (int j=l;j<h;j++){
        if (arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,h);
    return i+1;
}
int randpartition(int *arr,int l ,int h){
    int i = l+rand()%(h-l+1);

    int temp = arr[i];
    arr[i]=arr[h];
    arr[h]=temp;

    return partition(arr,l,h);
}
void quicksort(int *arr,int l, int h){
    if (l<h){
        int p = randpartition(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
    }
}
int main (){
    int arr[10] = {5,2,7,3,9,10,1,8,4,6};
    quicksort(arr,0,9);
    for (int i=0;i<10;i++){
        cout<<arr[i]<<"  ";
    }
}