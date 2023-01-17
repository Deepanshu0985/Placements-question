#include <iostream>
#include<vector>
using namespace std;
void percolatingup(vector<int>&v,int i){
    int count=0;
    while(i>0){ 
        if(i%2==0){
            if(v[i]<v[(i-2)/2]){
            swap(v[i],v[(i-2)/2]);
            // print(v);
            i=(i-2)/2;
            }
        }
        else{
            if(v[i]<v[(i-1)/2]){
            swap(v[i],v[(i-1)/2]);
            //print(v);
            i=(i-1)/2;
            }
        }
    }    
}

void heapify(vector<int>&v,int n,int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int min=i;

    if(l<n && v[l]<v[min]){
        min=l;
    }
    if(r<n && v[r]<v[min]){
        min=r;
    }
    if(min!=i){
        swap(v[i],v[min]);
        heapify(v,n,min);
    }
}
void buildmaxheap(vector<int>&v,int n){
    for (int i=n/2;i>=0;i--){
        heapify(v,n,i);
    }
}
int main (){
    int n;
    vector<int> v={5,4,3,2,1};
    buildmaxheap(v,v.size());
    for(auto it:v){
        cout<<it<<"  ";
    }

    cout <<"enter element to insert  ";cin>>n;
    cout<<endl;
    


}