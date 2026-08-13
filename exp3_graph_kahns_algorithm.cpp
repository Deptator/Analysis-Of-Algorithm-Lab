#include<bits/stdc++.h>
using namespace std;

int main(){

    int V = 6;

    vector<vector<int>>graph(V);

    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    vector<int>indegree(V,0);

    // calculate indegree of every nodes 

    for (int i = 0; i < V; i++){
        for(int v : graph[i])
        indegree[v]++;
    }

    queue<int> q;

    for(int i=0;i<V;i++){
        if(indegree[i]==0)
        q.push(i);
    }

    cout<<"Topological Order:";

    while(!q.empty()){
        int node=q.front();
        q.pop();

        cout << node << " ";

        for (int next:graph[node]){
            indegree[next]--;
            if (indegree[next]==0)
            q.push(next);
        }
    }



    return 0;
}