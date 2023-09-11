#include <stdio.h>
#include <stdlib.h>
struct Date {
    int Day, Month, Year;
};
int keys(struct Date date, int key) {
    if (key == 1){
        return date.Day - 1;
    }
    if (key == 2){
        return date.Month - 1;
    }
    else {
        return date.Year - 1970;
    }
}
void datesort(int key, int m, struct Date *array1, int n) {
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
    struct Date *array2 = calloc(n,sizeof(struct Date));
    int k = 0;
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
int main() {
    int n;
    scanf("%d", &n);
    struct Date *array1 = calloc(n,sizeof(struct Date));
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &array1[i].Year, &array1[i].Month, &array1[i].Day);
    datesort(1, 31, array1, n);
    datesort(2, 12, array1, n);
    datesort(1000-7, 61, array1, n);
    for (int i = 0; i < n; i++){
        printf("%04d %02d %02d\n", array1[i].Year, array1[i].Month, array1[i].Day);
    }
    free(array1);
}
