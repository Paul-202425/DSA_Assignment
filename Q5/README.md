Q5: Cloud Data Routing (Bellman-Ford)
What is it about?

Finding minimum cost and path from a source (A) to all other data centers located in a directed graph with negative edges.
How?

Relaxing: At most V-1 = 9 passes over all edges with an early exit possibility if during a pass no changes occur. Initializing distances to INF and only relaxing an edge (u → v) if the source is reachable to u.
Paths: Using a pred[] array that stores predecessors and rebuilding the path recursively for each node.
Negative cycle check: An extra pass is made. If any distance can be improved, there is a reachable negative cycle.
Unreachable nodes: They are reported as such.
Input: If an invalid source is given, it shows an error and exits nicely.

Results (source = A): There is no negative cycle.

Dest	Cost	Path
B	6	A → B
C	12	A → B → C
D	12	A → B → D
E	16	A → B → J → E
F	16	A → B → J → E → I → F
G	3	A → B → C → G
H	16	A → B → C → G → H
I	14	A → B → J → E → I
J	13	A → B → J
