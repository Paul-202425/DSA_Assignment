/* Question 1: Airport Baggage Handling - array-based Max-Heap */
#include <stdio.h>

#define MAX 32

typedef struct { char id; int pri; } Container;

static Container heap[MAX];
static int n = 0;

static void swap_nodes(int i, int j) {
    printf("    swap %c(%d) <-> %c(%d)\n", heap[i].id, heap[i].pri, heap[j].id, heap[j].pri);
    Container t = heap[i]; heap[i] = heap[j]; heap[j] = t;   /* ID and priority move together */
}

/* heapify down: used for construction and after removal */
static void sift_down(int i) {
    for (;;) {
        int l = 2 * i + 1, r = 2 * i + 2, m = i;
        if (l < n && heap[l].pri > heap[m].pri) m = l;
        if (r < n && heap[r].pri > heap[m].pri) m = r;
        if (m == i) break;
        swap_nodes(i, m);
        i = m;
    }
}

/* heapify up: used after insertion */
static void sift_up(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].pri >= heap[i].pri) break;
        swap_nodes(p, i);
        i = p;
    }
}

static void build_max_heap(void) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        printf("  heapify node at index %d (%c:%d)\n", i, heap[i].id, heap[i].pri);
        sift_down(i);
    }
}

static void insert(Container c) {
    heap[n] = c;
    n++;
    sift_up(n - 1);
}

static int find_index(char id) {
    for (int i = 0; i < n; i++) if (heap[i].id == id) return i;
    return -1;
}

static void remove_id(char id) {
    int i = find_index(id);
    if (i < 0) { printf("  container %c not found\n", id); return; }
    printf("  replace %c with last element %c(%d)\n", id, heap[n - 1].id, heap[n - 1].pri);
    heap[i] = heap[n - 1];
    n--;
    if (i < n) { sift_up(i); sift_down(i); }
}

static int is_max_heap(void) {
    for (int i = 1; i < n; i++) if (heap[(i - 1) / 2].pri < heap[i].pri) return 0;
    return 1;
}

static void print_heap(const char *title) {
    printf("\n=== %s ===\nArray: ", title);
    for (int i = 0; i < n; i++) printf("[%d]%c:%d  ", i, heap[i].id, heap[i].pri);
    printf("\nTree (level by level):\n");
    int start = 0, level = 0;
    while (start < n) {
        int cnt = 1 << level;
        printf("  Level %d: ", level);
        for (int i = start; i < start + cnt && i < n; i++) printf("%c(%d)  ", heap[i].id, heap[i].pri);
        printf("\n");
        start += cnt; level++;
    }
    printf("Max-Heap property valid: %s\n", is_max_heap() ? "YES" : "NO");
}

int main(void) {
    int P[] = {56, 23, 91, 34, 72, 48, 85, 17, 63, 79, 42};
    n = (int)(sizeof P / sizeof P[0]);
    for (int i = 0; i < n; i++) { heap[i].id = (char)('A' + i); heap[i].pri = P[i]; }

    print_heap("Initial binary tree (array order, before heapify)");

    printf("\n--- Task 1: Build Max-Heap ---\n");
    build_max_heap();
    print_heap("Max-Heap after construction");

    printf("\n--- Task 2: Insert urgent container X (100) ---\n");
    Container x = {'X', 100};
    insert(x);
    print_heap("Max-Heap after inserting X(100)");

    printf("\n--- Task 3: Remove container X ---\n");
    remove_id('X');
    print_heap("Max-Heap after removing X");
    return 0;
}
