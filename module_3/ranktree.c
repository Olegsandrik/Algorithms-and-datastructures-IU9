#include <stdio.h>
#include <stdlib.h>

#define true 1

typedef struct node {
    int k;
    char* v;
    struct node* left;
    struct node* right;
    struct node* parent;
    long long count;
} Vertex;

Vertex** BuildBST() {
    Vertex** BST;
    BST = malloc(sizeof(Vertex*));
    *BST = NULL;

    return BST;
}

void BSTInsert(Vertex** BST, int k, char* v) {
    // инициализируем нашу новую вершину, как пустую
    Vertex* new_node = malloc(sizeof(Vertex));
    new_node->k = k; new_node->v = v; new_node->count = 0;
    new_node->left = NULL;
    new_node->right = NULL;

    if (!*BST) {
        *BST = new_node;
        new_node->parent = NULL;
        return;
    }

    Vertex* current = *BST;
    while (true) {
        if (k < current->k) {
            if (!current->left) {
                ++current->count;
                current->left = new_node;
                new_node->parent = current;
                break;
            }
            ++current->count;
            current = current->left;
        } else {
            if (!current->right) {
                current->right = new_node;
                new_node->parent = current;
                break;
            }
            current = current->right;
        }
    }
}

Vertex* BSTLookup(Vertex** BST, int k) {
    Vertex* current = *BST;

    while (current) {
        if (current->k == k) {
            return current;
        }

        if (k > current->k) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return NULL;
}

char* BSTSearch(Vertex** BST, int k) {
    Vertex* current = *BST;

    while (k != current->count) {
        if (k <= current->count) {
            current = current->left;
        }
        else {
            k -= current->count + 1;
            current = current->right;
        }
    }

    return current->v;
}

void BSTRecalculate(Vertex* current) {
    for (; current && current->parent; current = current->parent) {
        if (current->parent->left == current) {
            current->parent->count--;
        }
    }
}

void BSTNodeReplacement(Vertex** BST, Vertex* old, Vertex* new) {
    // если удаляется корень нашего дерева
    if (*BST == old) {
        *BST = new;
        if (new) {
            new->parent = NULL;
        }
        return;
    }

    if (old->parent->right == old) {
        old->parent->right = new;
    } else {
        old->parent->left = new;
    }
    if (new) {
        new->parent = old->parent;
    }
}

Vertex* tree_get_next(Vertex* node) {
    node = node->right;
    while (node->left) {
        node = node->left;
    }
    return node;
}

void BSTDelete(Vertex** BST, int k) {
    Vertex *removed = BSTLookup(BST, k);

    if (!removed->left && !removed->right) {
        BSTRecalculate(removed);
        BSTNodeReplacement(BST,removed, NULL);

        free(removed->v);
        free(removed);
        return;
    }

    if (!removed->left) {
        BSTRecalculate(removed);
        BSTNodeReplacement(BST, removed, removed->right);

        free(removed->v);
        free(removed);
        return;
    }

    if (!removed->right) {
        BSTRecalculate(removed);
        BSTNodeReplacement(BST, removed, removed->left);

        free(removed->v);
        free(removed);
        return;
    }

    Vertex *next = tree_get_next(removed);

    BSTRecalculate(next);
    BSTNodeReplacement(BST, next, next->right);
    BSTNodeReplacement(BST, removed, next);
    next->count = removed->count;
    next->left = removed->left;
    next->left->parent = next;
    if (removed->right) {
        next->right = removed->right;
        next->right->parent = next;
    }

    free(removed->v);
    free(removed);
}

void CleanMemory(Vertex* tmp) {
    if (tmp) {
        CleanMemory(tmp->left);
        CleanMemory(tmp->right);
        free(tmp->v);
        free(tmp);
    }
}

int main() {
    // указатель на корень нашего дерева поиска
    Vertex** BST = BuildBST();

    char* type;
    while (true) {
        scanf("%ms", &type);

        // INSERT k v
        if (type[0] == 'I') {
            int k;
            char* v;

            scanf("%d%ms", &k, &v);
            BSTInsert(BST, k, v);
        }

        //LOOKUP k
        if (type[0] == 'L') {
            int k;
            scanf("%d", &k);
            printf("%s\n", BSTLookup(BST, k)->v);
        }

        // DELETE k
        if (type[0] == 'D') {
            int k;
            scanf("%d", &k);

            //DELETE
            BSTDelete(BST, k);
        }

        // SEARCH
        if (type[0] == 'S') {
            int x;
            scanf("%d", &x);
            printf("%s\n", BSTSearch(BST, x));
        }

        // END
        if (type[0] == 'E') {
            free(type);
            break;
        }

        free(type);
    }

    // очистка BST
    CleanMemory(*BST);
    free(BST);

    return 0;
}
