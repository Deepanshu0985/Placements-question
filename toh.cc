
#include <iostream>
using namespace std;
int a=0 ;
void towerOfHanoi(int n, char from_rod, char to_rod,char aux_rod){
    
    a++;
	if (n == 0) {
		return;
	}
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout << "Move disk " << n << " from rod " << from_rod
		<< " to rod " << to_rod << endl;
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}


int main()
{
	int N = 5;

	
	towerOfHanoi(N, 'A', 'C', 'B');
    cout <<"no. of calls "<<a;
	return 0;
}

