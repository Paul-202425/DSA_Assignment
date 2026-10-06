/* Question 5: Cloud Service Data Routing Analyzer - Bellman-Ford */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define V 10            /* A..J */
#define E 15
#define INF INT_MAX

typedef struct { int u, v, w; } Edge;

static int pred[V];

static void print_path(int v) {
    if (pred[v] != -1) { print_path(pred[v]); printf(" -> "); }
    printf("%c", 'A' + v);
}

int main(void) {
    Edge edges[E] = {
        {'A'-'A','B'-'A',6},  {'A'-'A','D'-'A',16}, {'B'-'A','C'-'A',6},  {'B'-'A','D'-'A',6},
        {'B'-'A','J'-'A',7},  {'C'-'A','G'-'A',-9}, {'D'-'A','E'-'A',7},  {'D'-'A','J'-'A',8},
        {'E'-'A','F'-'A',10}, {'E'-'A','I'-'A',-2}, {'F'-'A','G'-'A',4},  {'F'-'A','I'-'A',2},
        {'G'-'A','H'-'A',13}, {'I'-'A','F'-'A',2},  {'J'-'A','E'-'A',3}
    };

    char buf[64];
    printf("Enter source data center (A-J): ");
    if (scanf("%63s", buf) != 1) { printf("No input received.\n"); return 1; }
    if (strlen(buf) != 1 || !isalpha((unsigned char)buf[0]) ||
        toupper((unsigned char)buf[0]) - 'A' >= V) {
        printf("Invalid data center '%s'. Valid names are A to J.\n", buf);
        return 1;
    }
    int src = toupper((unsigned char)buf[0]) - 'A';

    int dist[V];
    for (int i = 0; i < V; i++) { dist[i] = INF; pred[i] = -1; }
    dist[src] = 0;

    /* V-1 relaxation passes (negative weights handled: no positivity assumption) */
    for (int pass = 1; pass <= V - 1; pass++) {
        int changed = 0;
        for (int i = 0; i < E; i++) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; pred[v] = u; changed = 1;
            }
        }
        if (!changed) break;
    }

    /* extra pass: any further improvement means a reachable negative cycle */
    int neg_cycle = 0;
    for (int i = 0; i < E; i++)
        if (dist[edges[i].u] != INF && dist[edges[i].u] + edges[i].w < dist[edges[i].v]) neg_cycle = 1;

    if (neg_cycle) {
        printf("\nNegative-weight cycle detected.\nShortest-path results may be undefined.\n");
        return 0;
    }
    printf("\nNo negative-weight cycle detected.\n");

    printf("\nSource: %c\n\n%-12s %-14s %s\n", 'A' + src, "Destination", "Shortest Cost", "Path");
    for (int v = 0; v < V; v++) {
        if (v == src) continue;
        if (dist[v] == INF) { printf("%-12c %-14s %s\n", 'A' + v, "unreachable", "-"); continue; }
        printf("%-12c %-14d ", 'A' + v, dist[v]);
        print_path(v);
        printf("\n");
    }
    return 0;
}
