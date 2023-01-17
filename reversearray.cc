#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v,int l,int r){
    
    if (l>=r) return;
    swap(v[l],v[r]);
    l++;
    r--;
    reverse(v,l,r);
}


int main(){
    vector<int> v = {5,4,3,2,1};

    reverse(v,0,v.size()-1);

    for (auto x:v){
        cout<<x<<"  ";
    }
}