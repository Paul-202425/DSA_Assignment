Q3: EV Charging Network (Kruskal’s MST)

The objective was to find the minimum total cost of building the charging network that connects all the 7 charging stations. The initial step was to build the symmetric adjacency matrix. Then, all edges were sorted in ascending order of cost using a stable insertion sort. The edges were then processed one by one in this sorted order. A union-find data structure with path compression and union by rank was used to add edges to the MST only if they connected two different components. The process stopped when the MST had V-1 = 6 edges.

Edge From To Cost Rejected
B–D 5 Accept
A–B 6 Accept
E–F 10 Accept
B–C 11 Accept
A–D 12 Reject
D–F 15 Accept
C–D 17 Reject
D–E 22 Reject
F–G 22 Accept

The total installation cost is 69 thousand dollars.
