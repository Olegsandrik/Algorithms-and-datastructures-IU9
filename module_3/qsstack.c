#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int low, high;
} Task;

typedef struct {
    Task* data;
    int cap, top;
} TStack;

TStack* InitStack() {
    TStack* stack;
    stack = (TStack*)malloc(sizeof(TStack));
    stack->data = malloc(2 * sizeof(Task));
    stack->cap = 2;
    stack->top = 0;

    return stack;
}

void Assign(TStack* stack, int low, int high) {
    stack->data[stack->top].low = low;
    stack->data[stack->top].high = high;
    stack->top++;
}

void Push(TStack* stack, int low, int high) {
    if (stack->top == stack->cap) {
        stack->data = realloc(stack->data, (stack->cap + 1) * sizeof(Task));
        stack->cap++;
    }
    Assign(stack, low, high);
}

Task Top(TStack* stack) {
    return stack->data[stack->top - 1];
}

Task Pop(TStack* stack) {
    Task a = Top(stack);
    stack->top--;
    return a;
}

int Empty(TStack* stack) {
    return stack->top == 0;
}

void CleanStack(TStack* stack) {
    free(stack->data);
    free(stack);
}

void Swap(int* a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int Partition(int* a, int l, int r)  {
    int v = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < v) {
            i++;
        }
        while (a[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        Swap(a, i++, j--);
    }
    return j;
}

void Sorting(TStack* stack, int* a, int n) {
    //a[0] = 80;
    Push(stack, 0, n-1);
    while (!Empty(stack)) {
        Task borders = Pop(stack);
        if (borders.high <= borders.low) {
            continue;
        }
        int i = Partition(a, borders.low, borders.high);
        if (i - borders.low > borders.high - i) {
            Push(stack, borders.low, i );
            Push(stack, i + 1, borders.high);
        }
        else {
            Push(stack, i + 1, borders.high);
            Push(stack, borders.low, i);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    TStack* stack = InitStack();
    Sorting(stack, a, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    CleanStack(stack);
    free(a);

    return 0;
}
