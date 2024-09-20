#include<vector>
#include<iostream>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;

// graph: s_v[(e_v, edge)]
vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start, int end){
    vector<int> distTo(graph.size(),INT_MAX), edgeTo(graph.size(),-1), isMarked(graph.size(),0);
    distTo[start] = 0;
    bool allMarked=false;
    int node = start;
    while(node!=end){
        isMarked[node] = 1;
        for(pair<int,int> i:graph[node]){
            if(distTo[node]+i.second<distTo[i.first]){
                distTo[i.first] = distTo[node]+i.second;
                edgeTo[i.first] = node;
            }
        }

        int next = -1, dist = INT_MAX;
        for(int i=0; i<graph.size(); i++){
            if(!isMarked[i] && distTo[i]<dist){
                next = i;
                dist =  distTo[i];
            }
        }

        if(next==-1){
            cout << start << " and " << end << " not connected." << endl;
            return {};
        }
        node = next;
    }

    vector<int> arr;
    cout << "dist: " << distTo[end] << endl;
    while(end!=-1){
        arr.push_back(end);
        end = edgeTo[end];
    }
    reverse(arr.begin(),arr.end());
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
    for(int i:dijkstra(g,0,1)) cout << i << " ";
    cout << endl;
    for(int i:dijkstra(g,3,0)) cout << i << " ";
}
