#include <stdio.h>
#include <stdlib.h>

#define true 1

typedef struct {
    int key, value;
} Vertex;

typedef struct {
    Vertex* M;
    int top, cap;
} vector;

Vertex* VerctorSearch(vector* list, int k) {
    for (int i = 0; i < list->top; i++) {
        if (k == list->M[i].key) {
            return &list->M[i];
        }
    }
    return 0;
}

void VectorPushback(vector* list, int k, int v) {
    if (list->cap == list->top) {
        list->M = realloc(list->M, (list->cap + 1) * sizeof(Vertex));
        list->cap++;
    }
    list->M[list->top].key = k;
    list->M[list->top].value = v;
    list->top++;
}

int mod(int a, int b) {
    return (((a % b) + b) % b);
}

int main() {
    int m;
    vector* HashTable;

    scanf("%d", &m);

    HashTable = malloc(m * sizeof(vector));
    for (int i = 0; i < m; i++) {
        HashTable[i].M = calloc(1, sizeof(Vertex));
        HashTable[i].top = 0;
        HashTable[i].cap = 1;
    }

    char* type;
    while (true) {
        scanf("%ms", &type);

        if (type[0] == 'E') {
            free(type);
            for (int i = 0; i < m; ++i) {
                free(HashTable[i].M);
            }
            free(HashTable);
            return 0;
        }

        if (type[1] == 'S') {
            int index;
            int value;
            scanf("%d %d", &index, &value);
            //HashTableInsert(index, value);
            vector* list = &HashTable[mod(index, m)];
            Vertex* node = VerctorSearch(list, index);
            (!node ? VectorPushback(list, index, value) : (node->value = value));
        }

        if (type[1] == 'T') {
            int index;
            scanf("%d", &index);
            Vertex* v = VerctorSearch(&HashTable[mod(index, m)], index);
            printf("%d\n", (v ? v->value : 0));
        }

        free(type);
    }
}
