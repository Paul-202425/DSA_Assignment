/* Question 3: EV Charging Station Power Network - adjacency matrix + Kruskal MST */
#include <stdio.h>

#define V 7
#define E 10

typedef struct { int u, v, w; } Edge;

static int parent[V], rnk[V];

static int find(int x) { return parent[x] == x ? x : (parent[x] = find(parent[x])); }

static int unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return 0;                 /* same set -> would create a cycle */
    if (rnk[ra] < rnk[rb]) { int t = ra; ra = rb; rb = t; }
    parent[rb] = ra;
    if (rnk[ra] == rnk[rb]) rnk[ra]++;
    return 1;
}

int main(void) {
    /* A=0 B=1 C=2 D=3 E=4 F=5 G=6 */
    Edge edges[E] = {
        {0,1,6}, {0,3,12}, {1,3,5}, {1,2,11}, {2,3,17},
        {2,6,25}, {3,4,22}, {3,5,15}, {4,5,10}, {5,6,22}
    };
    int m[V][V] = {{0}};
    for (int i = 0; i < E; i++) { m[edges[i].u][edges[i].v] = edges[i].w; m[edges[i].v][edges[i].u] = edges[i].w; }

    printf("=== Task 1: Adjacency matrix (cost in thousand $, 0 = no connection) ===\n     ");
    for (int j = 0; j < V; j++) printf("%4c", 'A' + j);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("  %c  ", 'A' + i);
        for (int j = 0; j < V; j++) printf("%4d", m[i][j]);
        printf("\n");
    }

    /* stable insertion sort by cost */
    Edge s[E];
    for (int i = 0; i < E; i++) s[i] = edges[i];
    for (int i = 1; i < E; i++) {
        Edge k = s[i]; int j = i - 1;
        while (j >= 0 && s[j].w > k.w) { s[j + 1] = s[j]; j--; }
        s[j + 1] = k;
    }

    printf("\n=== Task 2: Kruskal's Algorithm ===\n");
    for (int i = 0; i < V; i++) { parent[i] = i; rnk[i] = 0; }
    Edge mst[V - 1]; int cnt = 0, total = 0;
    for (int i = 0; i < E && cnt < V - 1; i++) {
        int ok = unite(s[i].u, s[i].v);
        printf("  %c - %c  cost %2d  -> %s\n", 'A' + s[i].u, 'A' + s[i].v, s[i].w,
               ok ? "ACCEPT" : "REJECT (creates a cycle)");
        if (ok) { mst[cnt++] = s[i]; total += s[i].w; }
    }

    printf("\n=== Task 3 & 4: Result ===\nSelected Connections:\n");
    for (int i = 0; i < cnt; i++)
        printf("  Station %c - Station %c : %d\n", 'A' + mst[i].u, 'A' + mst[i].v, mst[i].w);
    printf("\nEdges selected: %d (V-1 = %d)\n", cnt, V - 1);
    printf("Total Installation Cost: %d thousand dollars\n", total);
    return 0;
}
