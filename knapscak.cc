#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

float knapsack(vector<vector<float>>&arr , int n , int bag){
    
    float profit =0 ;
    
    for (int i =0;i<n;i++){
        for (int j=0;j<n-1-i;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for (int i=0;i<n;i++){
        if(bag>0){
            
            if(arr[i][2]<=bag){
                profit+=arr[i][1];
                bag-=arr[i][2];
            }
            else{
                profit += (bag/arr[i][2])*arr[i][1];
                bag =0;
            }
            
        }
        else{
            break;
        }
        
    }
    return profit;
}

int main(){
    int n ;
    cout<<"enter no. of object";
    cin>>n;
    vector<vector<float>>arr(n) ;
    cout<<"enter the profit and weight";
    for (int i=0;i<n;i++){
        float w,p;
        cin>>p>>w;
        arr[i].push_back(p/w);
        arr[i].push_back(p);
        arr[i].push_back(w);
        
    }
    

    cout<<"profit = "<<knapsack(arr,n,20);
}