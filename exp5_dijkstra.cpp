// From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:


    vector<int>Dijkstra(int V, vector<vector<int>>adj[], int S){

    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int>result(V,1e9);

    result[S] = 0;
    pq.push({0,S});



    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto &vec:adj[node]){
            int adjNode=vec[0];
            int dist = vec[1];

            if(d+dist<result[adjNode]){
                result[adjNode]=d+dist;
                pq.push({d+dist,adjNode});
            }

        }
    }
    return result;
}
};

int main(){
    int V = 3;
    int S = 2;


    vector<vector<int>>adj[V];

    adj[0].push_back({1,1});
    adj[1].push_back({0,1});
    adj[0].push_back({2,6});
    adj[2].push_back({0,6});
    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    Solution obj;

    vector<int>shortest_distance = obj.Dijkstra(V,adj,S);


    // Print the result
    cout<<"Shortest distance from Source Node"<<S<<":\n";
    cout<<"---------------------\n";

    for (int i = 0; i < V; i++){
        cout<<"To Node"<<i<<"->Distance:";
        if(shortest_distance[i]==1e9){
            cout<<"Unreachable\n";
        }else{
            cout<<shortest_distance[i]<<"\n";
        }
    }



    return 0;
}