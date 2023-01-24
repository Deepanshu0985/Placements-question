#include <iostream>
#include <vector>
using namespace std;
// #define b 10000INFINITY

int main(){
    // int n , m,src;
    // cin>>n>>m;
    vector <vector<double>> graph{ {0,5,1e9,10},
                                {1e9,0,3,1e9},
                                {1e9,1e9,0,1},
                                {1e9,1e9,1e9,0}
                                };

    int n= graph.size();
    vector<vector<double>>dist = graph;
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (dist[i][k]+dist[j][k]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
       for (int j=0;j<n;j++){
            if(dist[i][j]==1e9){
                cout<<"INF ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
       } 
       cout<<"\n";
    }

    
}
