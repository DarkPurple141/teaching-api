// courtesy of UNSW
#include "../../libs/Graph/Graph.h"

void bfs (Graph g, Edge e) {
    int i;
    Queue q = newQueue();
    QueueJoin (q,e);
    while (!QueueIsEmpty(q)) {
        e = QueueLeave(q);
        if (pre[e.w] == -1) {
           pre[e.w] = count++;
           st[e.w] = e.v;
           printf("%d\n",e.w);
           for (i = 0; i < g->nV; i++) {
              if ((g->edges[e.w][i] == 1)&&(pre[i] == -1)){
		    QueueJoin (s,mkEdge(g,e.w,i));
              }
           }
        }
    }
}
