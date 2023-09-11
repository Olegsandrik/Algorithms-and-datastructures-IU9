#include <stdio.h>
#include <malloc.h>
union Int32 {int x; unsigned char bytes[4]; };
int keys(union Int32 num, int key) {
    if (key!=3) {
        return (int)num.bytes[key];
    }
    else{
        if (num.x >= 0){
            return (int)num.bytes[key] + 128;
        }
        else{
            return (int)num.bytes[key] - 128;
        }
    }
}
void DistributionSort(int key, int m, union Int32 *array1, int n) {
    int *counter = calloc(m , sizeof(int));
    int i = 0;
    while ( i < n){
        counter[keys(array1[i], key)]+=1;
        i++;
    }
    int j = 1;
    while (j < m){
        counter[j] += counter[j - 1];
        j++;
    }
    union Int32 *array2 = calloc(n, sizeof(union Int32));
    int k=0;
    while (k < n){
        array2[k] = array1[k];
        k++;
    }
    int q = n - 1;
    while ( q >= 0) {
        int k = keys(array2[q], key);
        counter[k]-=1;
        array1[counter[k]] = array2[q];
        q--;
    }
    free(counter);
    free(array2);
}
void RadixSort(int q, int m, union Int32 *array1, int n){
    int i = 0;
    while (i <= q-1){
        DistributionSort(i, m, array1, n);
        i++;
    }
}
int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    union Int32 *array = calloc(n,sizeof(union Int32));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i].x);
    }
    RadixSort(4, 256, array, n);
    for (int i = 0; i < n; i++){
        printf("%d ", array[i].x);
    }
    free(array);
}
