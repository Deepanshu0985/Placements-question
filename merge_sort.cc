#include <iostream>
using namespace std;

void merge(int *arr,int l,int h,int mid){
    int a = mid-l+1;
    int b = h-mid;

    int *first = new int[a];
    int *second = new int [b];
    int k=l;
    for (int i=0;i<a;i++){
        first[i] = arr[l+i];
    }
    
    for (int i=0;i<b;i++){
        second[i] = arr[mid+1+i];
    }

    int in1 = 0;
    int in2 = 0;
    k =l;

    while (in1<a && in2<b){
        if (first[in1]<second[in2]){
            arr[k]=first[in1];
            in1++;
            k++;
        }
        else{
            arr[k]=second[in2];
            in2++;
            k++;
        }
    }
    while(in1<a){
        arr[k]=first[in1];
        in1++;
        k++;
    }
    while(in2<b){
        arr[k]=second[in2];
        in2++;
        k++;
    }
}

void mergesort(int *arr,int l,int h){
    if(l<h){
        int mid = l + (h-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);

        merge(arr,l,h,mid);
    }
}

int main (){
    int arr[10] = {6,8,7,3,1,4,9,5,10,2};

    mergesort(arr,0,9);

    for (int i=0;i<10;i++){
        cout<<arr[i]<<"  ";
    }
}