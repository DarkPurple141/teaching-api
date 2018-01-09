// courtesy of UNSW
#include "../../libs/Graph/Graph.h"

void dfs (Graph g, Edge e) {
    int i;
    Stack s = newStack();
    StackPush (s,e);
    while (!StackIsEmpty(s)) {
        e = StackPop(s);
        if (pre[e.w] == -1) {
           pre[e.w] = count++;
           st[e.w] = e.v;
           printf("%d\n",e.w);
           for (i = 0; i < g->nV; i++) {
              if ((g->edges[e.w][i] == 1)&&(pre[i] == -1)) {
		    StackPush (s,mkEdge(g,e.w,i));
              }
           }
        }
    }
}
