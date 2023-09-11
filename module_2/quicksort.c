#include <stdio.h>
#include <stdlib.h>
int Compare(int a, int b){
    return (a - b);
}
void Change(int *a, int *b) {
    int krash = *a;
    *a = *b;
    *b = krash;
}
void SelectSort(int (*compare)(int a, int b), int low, int high,int *arr) {
    int i = high;
    while(i > low) {
        int k = i;
        int j = i - 1;
        while( j >= low) {
            if (compare(arr[j], arr[k]) > 0) {
                k = j;
            }
            j--;
        }
        Change(&arr[i], &arr[k]);
        i--;
    }
}
int Partition(int (*compare)(int a, int b), int low, int high, int *arr) {
    int i=low;
    int j=low;
    while(j<high){
        if(compare(arr[j], arr[high])<0){
            Change(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    Change(&arr[i], &arr[high]);
    return i;
}
void quicksort(int (*compare)(int a, int b), int low, int high, int m, int *arr) {
    if(compare(high - low, m) <= 0){
        SelectSort(compare, low,high, arr);
    }
    else{
        while(low < high){
            int q = Partition(compare,  low, high, arr);
            if(compare (q - low, high - q)<0){
                quicksort(compare, low, q - 1, m, arr);
                low = q + 1;
            }
            else {
                quicksort(compare, q + 1, high, m, arr);
                high = q - 1;
            }
        }
    }
}
int main(int argc, char **argv) {
    int n, m;
    scanf("%d%d", &n, &m);
    int *arr = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(Compare, 0, n - 1, m, arr);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
