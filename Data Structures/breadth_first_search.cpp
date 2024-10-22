#include <iostream>
#include <vector>
#include<queue>

using namespace std;

void addNode(vector <vector<int> >& adjList, int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);    
}

int main(){
    int node = 7;
    vector <vector<int> > adjList(node);
    // Bidirectional graph
    addNode(adjList,0,1);
    addNode(adjList,0,6);
    addNode(adjList,1,4);
    addNode(adjList,1,2);
    addNode(adjList,6,2);
    addNode(adjList,6,3);
    addNode(adjList,4,5);
    addNode(adjList,2,5);
    addNode(adjList,3,5);

    int startnode = 3;

    //BFS Logic
    vector<bool> visited(node,false);
    queue<int> bfs;
    visited[startnode]=true;
    bfs.push(startnode);
        
    while(!bfs.empty()){
        for (int num : adjList[bfs.front()]){
            if (!visited[num]){
                bfs.push(num);
                visited[num]=true;
            }
        }
        cout<<bfs.front()<<" ";
        bfs.pop();
    }

}