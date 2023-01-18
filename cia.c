Prims:

#include<stdio.h>
int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main() {
  printf("Prim's Algorithm");
  printf("\nEnter the number of nodes:");
  scanf("%d", & n);
  printf("\nEnter the adjacency matrix:\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", & cost[i][j]);
      if (cost[i][j] == 0)
        cost[i][j] = 999;
    }
  }
  visited[1] = 1;
  printf("\n");
  while (ne < n) {
    for (i = 1, min = 999; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (cost[i][j] < min) {
          if (visited[i] != 0) {
            min = cost[i][j];
            a = u = i;
            b = v = j;
          }
        }
      }
    }
    if (visited[u] == 0 || visited[v] == 0) {
      printf("\nEdge %d:(%d %d), Cost = %d", ne++, a, b, min);
      mincost += min;
      visited[b] = 1;
    }
    cost[a][b] = cost[b][a] = 999;
  }
  printf("\n\nMinimum cost=%d", mincost);
}


dijskrats:

class Edge:
def __init__(self):
self.src = 0
self.dest = 0
self.weight = 0
class Graph:
def __init__(self):
self.V = 0
self.E = 0
self.edge = []

def createGraph(V, E):
graph = Graph();
graph.V = V;
graph.E = E;
graph.edge = [Edge() for i in range(graph.E)]
return graph;
def NegCycleBellmanFord(graph, src):
V = graph.V;
E = graph.E;
dist =[1000000 for i in range(V)]
parent =[-1 for i in range(V)]
dist[src] = 0;
for i in range(1, V):
for j in range(E):
u = graph.edge[j].src;
v = graph.edge[j].dest;
weight = graph.edge[j].weight;
if (dist[u] != 1000000 and
dist[u] + weight < dist[v]):
dist[v] = dist[u] + weight;
parent[v] = u;
C = -1; 
for i in range(E): 
u = graph.edge[i].src;
v = graph.edge[i].dest;
weight = graph.edge[i].weight;
if (dist[u] != 1000000 and
dist[u] + weight < dist[v]):
C = v;
break;
if (C != -1): 
for i in range(V): 
C = parent[C];
cycle = [] 
v = C
while (True):
cycle.append(v)
if (v == C and len(cycle) > 1):
break;
v = parent[v]
cycle.reverse()
for v in cycle:
print(v, end = " ")
print() 
else:
print(-1);
if __name__=='__main__':
V = 5;
E = 5; 
graph = createGraph(V, E);
graph.edge[0].src = 0;
graph.edge[0].weight = 1;
graph.edge[1].src = 1;
graph.edge[1].dest = 2;
graph.edge[1].weight = 2;
graph.edge[2].src = 2;
graph.edge[2].dest = 3;
graph.edge[2].weight = 3;
graph.edge[3].src = 3;
graph.edge[3].dest = 4;
graph.edge[4].src = 4;
graph.edge[4].dest = 1;
graph.edge[4].weight = -3;
NegCycleBellmanFord(graph, 0);

kruskals:


#include <stdlib.h>
#include <stdio.h>
int cycle(int a,int parent[]){
    while(parent[a]) a=parent[a];
    return a;
}
void kruskal(int n,int arr[][n]){
    int parent[n],itr=1,cost=0;
    while(itr<n){
        int min=99999,a,b,c,d;
        for(int i=0;i<n;i++){
            parent[i]=0;
            for(int j=0;j<n;j++){
                if(arr[i][j]<min){
                    min=arr[i][j];
                    a=c=i;b=d=j;
                }
            }
        }
        c=cycle(c,parent);
        d=cycle(d,parent);
        if(c!=d){
            parent[c]=d;
            printf("%d - %d  %d\n",b,a,min);
            cost+=min;
            itr++;
        }
        arr[a][b]=arr[b][a]=99999;
    }
    printf("total cost:%d\n",cost);
}
int main(){
    int n=5;
    int arr[5][5]={ { 0, 3, 0, 6, 0 },
                    { 2, 0, 3, 6, 5 },
                    { 0, 1, 0, 0, 7 },
                    { 6, 8, 0, 0, 9 },
                    { 0, 5, 7, 9, 0 } };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0) arr[i][j]=99999;
        }
    }
    kruskal(n,arr);
    return 0;
}
