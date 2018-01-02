
typedef struct graphRep * Graph;
typedef struct edge * Edge;

struct graphRep {
    int nV;       // #vertices
    int nE;       // #edges
    int **adj;    // matrix of booleans (0 or 1)
};

struct graphRep {
    int nV; // #vertices
    int nE; // #edges VList
    VList *adj; // array of lists
};

struct edge {
    Vertex v;
    Vertex w;
};

bool isValidEdge(Graph g, Vertex v) {
   if (v > g->nV || v < 0) {
      return 0;
   }
   return 1;
}

// adjacency list
int isEdgeInGraph (Graph g, Edge e) {
   assert(g != NULL);
   if (isValidEdge(e->v) && isValidEdge(e->w)) {
      VList curr = g->adj[e->v];
      while (curr) {
         if (curr->v == e->w) {
            return 1;
         }
         curr = curr->next;
      }
   }

   return 0;
}

// with matrix
int isEdgeInGraph (Graph G, Edge e) {
   assert(g != NULL);
   if (isValidEdge(e->v) && isValidEdge(e->w)) {
      if (g->adj[e->v][e->w]) {
         return 1;
      }
   }
   return 0;
}
