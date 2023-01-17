#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>v){
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}
void heapify(vector<int> &arr,int n ,int i){
    int c1=2*i +1;
    int c2=2*i +2;
    int maximum=i;
    if(c1<n && arr[c1]>arr[maximum]){
        maximum=c1;
    }
    if(c2<n && arr[c2]>arr[maximum]){
        maximum=c2;
    }
    if(maximum!= i){
        swap(arr[i],arr[maximum]);
        heapify(arr,n,maximum);
    }
}
void percolatingup(vector<int>&v,int i){
    int count=0;
    while(i>0){ 
        if(i%2==0){
            if(v[i]>v[(i-2)/2]){
            swap(v[i],v[(i-2)/2]);
            print(v);
            i=(i-2)/2;
            }
        }
        else{
            if(v[i]>v[(i-1)/2]){
            swap(v[i],v[(i-1)/2]);
            print(v);
            i=(i-1)/2;
            }
        }
    }    
}
void buildheap(vector<int> &v,int n){
    for (int i=(n/2);i>=0;i--){
        heapify(v,n,i);
    }
}

int main(){
    vector<int> v ={1,2,3,4,5};
    buildheap(v,v.size());
    cout<<"MAX HEAP\n";
    for(auto it :v){
        cout<<it<<"  ";
    }
    cout<<"\n after extracting max\n";
    swap(v[0],v[v.size()-1]);
    heapify(v,v.size()-1,0);
    v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }
    cout<<"\nafter inserting 0 in heap\n";

    v.push_back(25);

    percolatingup(v,v.size()-1);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }

}