#include<bits/stdc++.h>
#define V 6

using namespace std;

int minIndex(int dist[V],int vis[V]){
    int min = INT_MAX , key;
    for (int k=0;k<V;k++){
        if(vis[k]==0 && dist[k]<=min){
            min = dist[k];
            key = k;
        }
    }
    return key;
}

void dijkstra(int arr[V][V], int src){
    int dist[V], vis[V];
    for (int i=0;i<V;i++){
        dist[i]=INT_MAX;
        vis[i]=0;
    }
    dist[src]=0;
    for(int k=0;k<V-1;k++){
        int tmp = minIndex(dist,vis); 
        vis[tmp]=1;
        for(int i=0;i<V;i++){
            if(vis[i]==0 && arr[tmp][i]!=0 && (arr[tmp][i]+dist[tmp]<=dist[i])){
                dist[i] = arr[tmp][i]+dist[tmp];
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<i<<" distance: "<<dist[i]<<endl;
    }
}

int main(){
    int graph[V][V] = {{0,5,50,20,40,30},
                        {0,0,8,15,4,3},
                        {0,4,0,6,3,2},
                        {0,0,0,0,6,17},
                        {0,0,0,2,0,7}};
    dijkstra(graph,0);
}