/**
 * given graph find a s-t path
*/

#include<vector>
#include<stack>
#include<iostream>
using namespace std;

vector<int> dfs(const vector<vector<int>>& graph, int start, int end){
    vector<int> arr;
    stack<int> S;
    vector<int> isMarked(graph.size(), 0);
    S.push(start);
    int node;
    while(!S.empty()){
        node = S.top();
        isMarked[node] = true;
        bool isPath = false;
        arr.push_back(node);
        if(node==end) return arr;

        for(int i: graph[node]){
            if(!isMarked[i]) {
                isPath = true;
                S.push(i);
            }
        }
        
        if(!isPath){
            for(int i: graph[node]){
                isMarked[i] = false;
            }
            S.pop();
            arr.pop_back();
        }
    }
    arr.clear();
    return arr;
}

int main(){
    vector<vector<int>> g = {{1,2},{2,3},{4},{},{0,3}};
    vector<int> arr = dfs(g, 4, 1), arr1 = dfs(g, 1, 3), arr2 = dfs(g, 0, 4), arr3 = dfs(g, 0, 0);

    for(int i: arr) cout << i << " ";
    cout << endl;
    for(int i: arr1) cout << i << " ";
    cout << endl;
    for(int i: arr2) cout << i << " ";
    cout << endl;
    for(int i: arr3) cout << i << " ";
}
