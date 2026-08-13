#include<bits/stdc++.h>
using namespace std;

int main(){
    int V = 4;

    int reach[4][4]={
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,0,0,0},
    };

    for(int k =0;k<V;k++)
    {
        for (int i = 0; i<V; i++)
        {
            for(int j = 0; j<V; j++){
                reach[i][j] = reach[i][j] ||

                (reach[i][k] && reach[k][i]);
            }
        }
    }

    cout<<"Transitive Closure Matrix\n";
    for (int i = 0; i < V; i++){
        for(int j = 0; j <V;j++)
            cout<<reach[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}