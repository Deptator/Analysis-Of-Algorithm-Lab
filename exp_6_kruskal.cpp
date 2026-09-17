#include<bits/stdc++.h>
using namespace std;


int Parent[100];


class Edge{
    public:
        int u, v, weight;

};


int comparater(Edge a, Edge b){
    return a.weight<b.weight;
}


int findParent(int x){
    if (Parent[x]==x){
        return x;
    }
    return Parent[x]= findParent(Parent[x]);
}


void unite(int u, int v){
    u = findParent(u);
    v = findParent(v);
    Parent[u]=v;
}


int main(){

        int V = 4;

        vector<Edge> edges = {
            {0,1,10},
            {0,2,6},
            {0,3,5},
            {1,3,4},
            {2,3,3},
            
        };

        for (int i=0;i<4;i++){
            Parent[i]=i;
        }

        sort(edges.begin(),edges.end(),comparater);

        int cost = 0;
        int count = 0;

        for (Edge e:edges){
            if(findParent(e.u) != findParent(e.v)){
                cout<<e.u<<" - "<<e.v<<" : "<<e.weight<<endl;
                cost+=e.weight;
                unite(e.u,e.v);
                count++;

                if (count == V-1){
                    break;
                }
            }
        }
        
        cout<<"Minimum Cost of Spanning Tree is :"<<cost;
    return 0;
}


