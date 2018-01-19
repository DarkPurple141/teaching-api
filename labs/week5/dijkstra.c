
#include "../../libs/Graph/Graph.h"

void dijkstra(Graph g,Vertex s){
    int v,t;
    PriQ pq = initPriQ(g->nV);
    //insert each vertex into the pq
    for(v=0;v< g->nV;v++){
        insert(pq, newItem(dist[v], v));
    }
    dist[s] = 0.0; //set start veretex dist to 0
    increasePriority(pq,s,dist[s]); // update pq
    while(!isEmpty(pq)){
         v = value(delMin(pq));
         if(dist[v] != NO_EDGE)
             for(t = 0;t < g->nV;t++){
                 if(g->adj[v][t] != NO_EDGE){
                     if(dist[v] + g->adj[v][t] < dist[t]){
                         dist[t] = dist[v] + g->adj[v][t];
                         increasePriority(pq,t,dist[t]);
                         st[t] = v;
                     }
             }
         }
    }
}
