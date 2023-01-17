#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef struct node{
    char data;
    int freq;
    node *left,*right;
    
    node(char x,char y):
        data(x),freq(y),left(NULL),right(NULL){}
}node;

struct compare {
    bool operator()(node *x,node *y){
        return x->freq > y->freq;
    }
};

void display(node *pq, string str){
    if(pq){
        if(pq->data!='#')cout<<pq->data<<<": "<<str;
        display(pq->left,str+'0');
        display(pq->right,str+'1');
    }
}



void hc (char data[] , int freq[],int n){
    priority_queue<node*,vector<node*,node*>,compare> pq;

    for (int i=0;i<n;i++){
        node *t = new node(data[i],freq[i]);
        pq.push(t);
    }
    
    while(pq.size()!=1){
        node *l = pq.top();
        pq.pop();
        node *r = pq.top();
        pq.pop();
        
        node *t=new node('#',l->freq + r->freq);
        t->left = l;
        t->right =r;
        pq.push(t);
        
    }
    
    display(pq.top(),"");
}

int main(){
    int n;
    cin>>n;
    char data[n];
    int freq[n];
    for (auto &x:data)cin>>x;
    for (auto &x :freq)cin>>x;

    hc(data,freq,n);
    return 0;
}