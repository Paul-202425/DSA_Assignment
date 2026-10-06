Data Structures Assignment: Heaps and Graph Algorithms

Five C programs implementing array-based Max-Heaps, Kruskal’s MST algorithm, BFS and Bellman-Ford

Files
File Question Topic
q1_baggage_heap.c Q1 (3 pts) Airport baggage Max-Heap
q2_hospital_triage.c Q2 (4 pts) Hospital triage Max-Heap
q3_ev_kruskal.c Q3 (4 pts) EV charging network, Kruskal’s MST
q4_iot_bfs.c Q4 (3 pts) IoT gateway BFS
q5_bellman_ford.c Q5 (4 pts) Cloud routing, Bellman-Ford
Build and Run

Each program is standalone, no dependencies. All that is needed is a C compiler such as

bash
gcc -Wall -Wextra q1_baggage_heap.c -o q1 && ./q1
gcc -Wall -Wextra q2_hospital_triage.c -o q2 && ./q2
gcc -Wall -Wextra q3_ev_kruskal.c -o q3 && ./q3
gcc -Wall -Wextra q4_iot_bfs.c -o q4 && ./q4   # prompts: enter D
gcc -Wall -Wextra q5_bellman_ford.c -o q5 && ./q5 # prompts: enter A
Design Decisions Common to All Problems
Heaps (Q1, Q2): implemented as arrays. For any element at index i, its parent is at (i-1)/2 and children are at 2i+1, 2i+2. Each element is a struct, so that ID/name and priority are stored together and cannot be separated.
Graphs (Q3, Q4): implemented as adjacency matrices (0 means no edge, since the graph is undirected). Q5 uses edge list because Bellman-Ford algorithm needs to iterate over edges.
Vertex labels (letters) are converted to integers (A=0, B=1, etc.) for convenience.# DSA_Assignment
