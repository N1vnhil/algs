#include<vector>
#include<iostream>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;

// graph: s_v[(e_v, edge)]
vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start, int end){
    vector<int> edgeTo(graph.size(), -1), distTo(graph.size(), INT_MAX), isMarked(graph.size(), 0);
    isMarked[start] = 1;
    distTo[start] = 0;
    vector<int> arr;
    pair<int, int> stV;
    int node = start;

    while(node!=-1){
        isMarked[node] = 1;
        arr.push_back(node);
        if(node==end){
            cout << "SP: " << distTo[node] << endl;
            return arr;
        }

        pair<int,int> stV(-1, INT_MAX);
        bool allMarked = true;
        for(pair<int,int> i: graph[node]){
            if(!isMarked[i.first]){
                allMarked = false;
                if(i.second<stV.second) stV = i;
                if(distTo[node]+i.second < distTo[i.first]){
                    distTo[i.first] = distTo[node]+i.second;
                    edgeTo[i.first] = node;
                }
            }
        }
        if(allMarked){
            arr.pop_back();
            if(!arr.empty()) node = arr.back();
            else node = -1;
        }else node = stV.first;
    }

    arr.push_back(-1);
    return arr;
}


int main(){
    vector<vector<pair<int, int>>> g = {
        {make_pair(1,7),make_pair(2,1)},
        {make_pair(3,4),make_pair(5,1)},
        {make_pair(1,6),make_pair(4,2),make_pair(5,7)},
        {},
        {make_pair(1,3),make_pair(3,5)},
        {make_pair(4,3)}
    };

    for(int i:dijkstra(g,0,3)) cout << i << " ";
    cout << endl;
    for(int i:dijkstra(g,1,3)) cout << i << " ";
    cout << endl;
    for(int i:dijkstra(g,5,3)) cout << i << " ";
    cout << endl;
    for(int i:dijkstra(g,3,0)) cout << i << " ";
}
