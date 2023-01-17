#include <iostream>
using namespace std;
int jump_search(int *arr,int size,int key){
    int jump;
    cout<<"enter jump size : ";cin>>jump;
    int low,j=0,high;
    int flag =1;
    low =0;
    high=jump-1;
    int t=1;
    while (flag ==1){
        
        if (arr[low]==key){
            return low;
            flag =0;
        }
        if (arr[low]==key){
            return low;
            flag =0;
        }
        if (arr[low]<key&&arr[high]>key){
            while (low<high){
                if(arr[low+1]==key){
                    return low+1;
                }
                low++;
            }
            flag =0;
        }
        if(high>size){
             while (low<=size){
                if(arr[low+1]==key){
                    return low;
                }
                low++;
            }
            flag =0;
        }
        low =high;
        high +=jump;
        t++;
        
    }
    
    return -1;

}

int main (){
    int arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int found = jump_search(arr,11,12);
    cout << "element found at index : "<<found;
}