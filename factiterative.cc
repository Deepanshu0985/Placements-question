#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int i=n,fact=1;

    while (i>=1){
        fact = fact*i;
        i--;
    }
    cout << "factorial of "<<n<<" is = "<<fact<<endl;
    
}