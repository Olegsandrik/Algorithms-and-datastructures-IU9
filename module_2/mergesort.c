#include <stdio.h>
#include <math.h>
int compare(int a, int b){
    return (fabs(a) - fabs(b));
}
void Merge(int (*compare)(int a, int b), int k, int l, int m, int *base) {
    int t[m - k + 1];
    int i = k;
    int j = l + 1;
    int h=0;
    while (h < m - k + 1){
        if (j <= m && (i == l + 1 || (compare(base[j], base[i]) < 0))){
            t[h] = base[j];
            j++;
        }else{
            t[h] = base[i];
            i++;
        }
        h++;
    }
    int q=0;
    for (int i=k; i<=m; i++){
        base[i]=t[q];
        q++;
    }
}
void MergeSortRec(int (*compare)(int a, int b), int low, int high, int *base){
    if (low<high){
        int med = (low + high) / 2;
        MergeSortRec(compare, low, med, base);
        MergeSortRec(compare, med + 1, high, base);
        Merge( compare, low, med, high, base);
    }
}
void InsertSort(int *base, int nel, int (*compare)(int a, int b)) {
    int i=1, elem;
    while (i < nel) {
        elem = base[i];
        int loc=i-1;
        while(loc>=0 && (compare(base[loc], elem) > 0)){
            base[loc + 1] = base[loc];
            loc-=1;
        }
        base[loc+1] = elem;
        i++;
    }
}
void MergeSort(int (*compare)(int a, int b), int n, int *base){
    if(n<5){
        MergeSortRec(compare, 0, n-1, base);
    }
    else{
        InsertSort(base, n, compare);
    }
}
int main(int argc, char **argv){
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    MergeSort(compare, n, array);
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
