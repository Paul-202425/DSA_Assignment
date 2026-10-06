/* Question 2: Hospital Emergency Triage - array-based Max-Heap */
#include <stdio.h>
#include <string.h>

#define MAX 32

typedef struct { char id[8]; char name[16]; int pri; } Patient;
typedef struct { Patient a[MAX]; int n; } Heap;

static void swap_p(Patient *x, Patient *y) { Patient t = *x; *x = *y; *y = t; }

static void sift_down(Heap *h, int i) {
    for (;;) {
        int l = 2 * i + 1, r = 2 * i + 2, m = i;
        if (l < h->n && h->a[l].pri > h->a[m].pri) m = l;
        if (r < h->n && h->a[r].pri > h->a[m].pri) m = r;
        if (m == i) break;
        swap_p(&h->a[i], &h->a[m]);
        i = m;
    }
}

static void sift_up(Heap *h, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->a[p].pri >= h->a[i].pri) break;
        swap_p(&h->a[p], &h->a[i]);
        i = p;
    }
}

static void build_heap(Heap *h) { for (int i = h->n / 2 - 1; i >= 0; i--) sift_down(h, i); }

static void insert(Heap *h, Patient p) { h->a[h->n++] = p; sift_up(h, h->n - 1); }

static Patient extract_max(Heap *h) {
    Patient top = h->a[0];
    h->a[0] = h->a[--h->n];
    if (h->n > 0) sift_down(h, 0);
    return top;
}

static int delete_id(Heap *h, const char *id) {
    for (int i = 0; i < h->n; i++) {
        if (strcmp(h->a[i].id, id) == 0) {
            h->a[i] = h->a[--h->n];
            if (i < h->n) { sift_up(h, i); sift_down(h, i); }
            return 1;
        }
    }
    return 0;
}

static int valid(const Heap *h) {
    for (int i = 1; i < h->n; i++) if (h->a[(i - 1) / 2].pri < h->a[i].pri) return 0;
    return 1;
}

static void print_heap(const Heap *h, const char *title) {
    printf("\n=== %s ===\nArray:\n", title);
    for (int i = 0; i < h->n; i++)
        printf("  [%d] %s  %-7s priority %d\n", i, h->a[i].id, h->a[i].name, h->a[i].pri);
    printf("Tree (level by level):\n");
    int start = 0, level = 0;
    while (start < h->n) {
        int cnt = 1 << level;
        printf("  Level %d: ", level);
        for (int i = start; i < start + cnt && i < h->n; i++)
            printf("%s %s(%d)  ", h->a[i].id, h->a[i].name, h->a[i].pri);
        printf("\n");
        start += cnt; level++;
    }
    printf("Max-Heap property valid: %s\n", valid(h) ? "YES" : "NO");
}

int main(void) {
    Heap h = { .n = 7 };
    Patient init[7] = {
        {"P01", "Amina", 72}, {"P02", "Daniel", 45}, {"P03", "Eric", 91}, {"P04", "Grace", 63},
        {"P05", "Hassan", 88}, {"P06", "Irene", 54}, {"P07", "Jean", 76}
    };
    for (int i = 0; i < 7; i++) h.a[i] = init[i];

    print_heap(&h, "Initial binary tree (before heapify)");

    printf("\n--- Task 1: Build Max-Heap ---\n");
    build_heap(&h);
    print_heap(&h, "Max-Heap after construction");

    printf("\n--- Task 2: Treatment order (extract on a copy of the heap) ---\n");
    Heap copy = h;
    while (copy.n > 0) {
        Patient p = extract_max(&copy);
        printf("Patient %s (%s) - Priority %d\n", p.id, p.name, p.pri);
    }

    printf("\n--- Task 3: New emergency patient Kofi (P08, 98) ---\n");
    Patient kofi = {"P08", "Kofi", 98};
    insert(&h, kofi);
    print_heap(&h, "Max-Heap after inserting P08");

    printf("\n--- Task 4: Patient P08 cleared ---\n");
    if (!delete_id(&h, "P08")) printf("P08 not found\n");
    print_heap(&h, "Max-Heap after removing P08");
    return 0;
}
