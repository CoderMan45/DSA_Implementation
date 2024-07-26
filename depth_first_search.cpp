#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void DFS(vector< vector<int>>& , stack<int>& , vector<bool>& );

void addNode(vector <vector<int> >& adjList, int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);    
}

int main(){
    int node = 7;
    vector <vector<int> > adjList(node);
    // Bidirectional graph
    addNode(adjList,0,1);
    addNode(adjList,0,4);
    addNode(adjList,1,2);
    addNode(adjList,1,5);
    addNode(adjList,1,6);
    addNode(adjList,4,3);
    addNode(adjList,4,2);
    addNode(adjList,4,5);
    addNode(adjList,3,6);
    addNode(adjList,2,6);
    addNode(adjList,5,6);

    int startnode = 2;

    //DFS Logic
    vector<bool> visited(node,false);
    stack<int> dfs;
    visited[startnode]=true;
    dfs.push(startnode);

    DFS( adjList, dfs, visited );

}

void DFS(vector< vector<int>>& adjList, stack<int>& dfs, vector<bool>& visited ){
    while(!dfs.empty()){
        int curNode = dfs.top();
        cout<<dfs.top()<<" ";
        dfs.pop();
        for(int var: adjList[curNode]){
            if(!visited[var]){
                visited[var]=true;
                dfs.push(var);
                DFS(adjList, dfs, visited);
            }
        }

    }


}