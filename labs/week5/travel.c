/**

A potential solution to the week 5 UNSW Lab
by Alexander Hinds, z3420752

**/

static
void BFS(Graph g, Vertex src, Vertex dest, int max, int prev[]) {

	// initialse our queue
	Queue q = newQueue();
	int seen[g->nV];
	int i;

	// initialise our frontier set
	for (i=0; i< g->nV; i++) {
      prev[i] = -1;
		seen[i] = 0;
	}

	seen[src] = 1;
   prev[src] = src;

	QueueJoin(q, src);

	// Essentially a basic BFS
	while (!QueueIsEmpty(q) && seen[dest] != 1) {

		Vertex next = QueueLeave(q);
		i = 0;
		while (i < g->nV) {
			if (!seen[i] && g->edges[next][i] < max) {
				prev[i] = next;
				QueueJoin(q, i);
				seen[i] = 1;
			}
			i++;
		}
	}
	dropQueue(q);
}

// find a path between two vertices using breadth-first traversal
// only allow edges whose weight is less than "max"
int findPath(Graph g, Vertex src, Vertex dest, int max, int *path)
{
	assert(g != NULL);

	int i;
	int length = 0;
	int prev[g->nV];

   // Do our BFS
	BFS(g, src, dest, max, prev);

	// check if we ended up finding our solution
	if (prev[dest] != -1) {
		int temp[g->nV]; // just in case it takes 30 hops
		length = 1;
		temp[0] = dest;

		/* Get the spanning tree into a single array -- altho reversed */
		for (i = dest; i != src;) {
			temp[length] = i;
			i = prev[i];
			length++;
		}
		i = 0;
		path[0] = src;

		/* Reverse the array and read into path */
		while (i < length) { // <-- read array
			path[i+1] = temp[length-1-i];
			i++;
		}
	}

	return length;
}
