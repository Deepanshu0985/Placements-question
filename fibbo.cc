#include <iostream>
#include <vector>
using namespace std;

int fibbonaccidp(int n){
    vector<int> dp(n+1);

    dp[0]=0;
    dp[1]=1;

    for (int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];

}

int fibbonacci(int n){
    if(n<=1)return n;

    return fibbonacci(n-1)+fibbonacci(n-2);
}

int main (){
    int n = 10;
    int prev =0;
    int curr=1;

    for(int i=2;i<=n;i++){
        int temp = prev + curr;
        prev = curr;
        curr=temp;
    }
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"the "<<n<<"th fibbonacci num "<<curr<<endl<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    cout<<"fibbonacci number using recursion\n";

    cout<<"the "<<n<<"th fibbonacci num "<<fibbonacci(n)<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    cout<<"\n\n\n";
    cout<<"fibbonacci number using DP\n";
    cout<<"the "<<n<<"th fibbonacci num "<<fibbonaccidp(n);



}