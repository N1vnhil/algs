#include<queue>
#include<vector>
#include<iostream>
#include<stack>
#include <algorithm>
using namespace std;

int bfs(vector<vector<int>> graph, int start, int end){
    vector<int> isMarked(graph.size(), 0);
    int node, c=0;
    queue<int> Q;
    node = start;
    Q.push(node);

    while(!Q.empty()){
        int layerSize = Q.size();
        for(int i=0; i<layerSize; i++){
            node = Q.front();
            Q.pop();
            if(node==end) return c;
            for(int j: graph[node]){
                if(!isMarked[j]) Q.push(j);
            } 
        }
        c++;
    }
    return -1;
}

vector<int> pbfs(vector<vector<int>> graph, int start, int end){
    vector<int> arr;
    vector<int> isMarked(graph.size(), 0);
    int node = start;
    queue<int> Q;
    Q.push(node);
    int c = 0;
    bool found = false;  // 用于标记是否找到目标节点

    while (!Q.empty() && !found) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            node = Q.front();
            Q.pop();
            if (node == end) {
                found = true;
                break;
            }
            for (int j : graph[node]) {
                if (!isMarked[j]) {
                    Q.push(j);
                    isMarked[j] = node;  
                }
            }
        }
        c++;
    }

    if (found) {
        // 构建路径
        vector<int> path;
        int curr = end;
        while (curr != start) {
            path.push_back(curr);
            curr = isMarked[curr];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        
        cout << "Path length: " << c << endl;
        return path;
    } else {
        arr.clear();
        cout << "No path found" << endl;
        return arr;
    }
}

int main(){
    vector<vector<int>> g = {{1,2},{2,3},{4},{},{0,3}};
    vector<int> arr = pbfs(g,0,4);
    for(int i:arr) cout << i << " ";
}