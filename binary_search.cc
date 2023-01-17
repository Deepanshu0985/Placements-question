#include <iostream>
using namespace std ;

int binarysearch(int *arr,int low ,int high,int key ){
    while (low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==key){
            return mid ;
        }
        else if (arr[mid]<key){
            low =mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main (){
    int arr[8]={10,20,30,40,50,60,70,80};

    cout <<"element is at  "<<binarysearch(arr,0,7,100);
}