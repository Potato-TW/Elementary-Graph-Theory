#include<iostream>
#include<vector>
using namespace std;

int main(){
    int ver, edg;   cin>>ver>>edg;
    
    vector<vector<int>> g(ver, vector<int>(ver, 0));
    vector<int> in(ver, 0), 
                out(ver, 0);
    
    for(int i=0;i<edg;i++){
        int from, to, weight;  
        cin>>from>>to>>weight;
        
        g[from-1][to-1]=weight;
        in[to-1]++;
        out[from-1]++; 
    }

    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++){
            cout<<g[i][j]<<" ";
        }

        cout<<endl;
    }

    for(int i=0;i<ver;i++){
        cout<<in[i]<<" "<<out[i]<<endl;
    }

    return 0;
}