#include<bits/stdc++.h>
#define V 4

using namespace std;

void bellmanFord(int graph[V][V],int src){
    int dist[V];
    for (int i=0;i<V;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    for(int k =1;k<=V-1;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(graph[i][j]!=0 && dist[i]!=INT_MAX && dist[j]>graph[i][j]+dist[i]){
                    dist[j]=graph[i][j]+dist[i];    
                }
            }
        }
    }
    for(int k=0;k<V;k++){
        cout<<k<<" min distance is "<<dist[k]<<endl;
    }
}

int main(){
    int graph[V][V]={{0,10,50,0},
                     {0,0,60,7},
                     {0,-45,0,9},
                     {0,0,0,0}};
    bellmanFord(graph,0);
}