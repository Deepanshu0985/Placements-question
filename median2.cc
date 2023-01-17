#include<iostream>
#include <vector>
#include <climits>
using namespace std;

double findmedian(vector<int> &v1 , vector<int> &v2){
    int n1 = v1.size();
    int n2 = v2.size();
    int low =0,high=n1;
    while(low<=high){
        int cut1 = (low+high)/2;
        int cut2 = (n1+n2+1)/2 - cut1;

        int l1 = cut1==0?INT_MIN : v1[cut1-1];
        int l2 = cut2==0?INT_MIN : v2[cut2-1];
        int r1 = cut1==n1 ? INT_MAX:v1[cut1];
        int r2 = cut2==n2 ? INT_MAX:v1[cut2];

        if (l1<=r2 && l2<=r1){
            if((n1 +n2)%2==0)
                return (max(l1,l2)+min(r1,r2))/2.0;
            else
                return max(l1,l2);
        }
        else if(l1>r2){
            high = cut1 -1;
        }
        else{
            low = cut2 + 1;
        }

    }
    return 0.0;
}

int main (){
    vector<int> v1 = {1 , 3};
    vector <int> v2 = {2};
     cout <<"median of v1 and v2 is : "<<findmedian(v1,v2);
}
