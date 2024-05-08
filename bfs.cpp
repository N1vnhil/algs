#include<vector>
#include<queue>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
vector<int> bfs(vector<vector<int>> graph, int start, int end){
    vector<int> parent(graph.size(), -1);
    vector<int> arr;
    queue<int> Q;
    Q.push(start);
    parent[start] = INT_MAX;

    while(!Q.empty()){
        for(int i=0; i<Q.size(); i++){
            int node = Q.front();
            Q.pop();

            if(node==end){
                arr.push_back(node);
                while(node!=start){
                    node = parent[node];
                    arr.push_back(node);
                }
                reverse(arr.begin(), arr.end());
                return arr;
            };

            for(int i:graph[node]){
                if(parent[i]==-1){
                    Q.push(i);
                    parent[i] = node;
                }
            }
        }
    }

    vector<int> nopath(1,-1);
    return nopath;
}

int main(){
    vector<vector<int>> g = {{1,2},{2,3},{4},{},{0,3}};
    for(int i: bfs(g,0,4)) cout << i << " "; cout << endl;
    for(int i: bfs(g,2,4)) cout << i << " "; cout << endl;
    for(int i: bfs(g,0,2)) cout << i << " "; cout << endl;
}