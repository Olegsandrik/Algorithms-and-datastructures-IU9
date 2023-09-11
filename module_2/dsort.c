#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int keys(char arr) {
    char alf[26]="abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++){
        if(arr==alf[i]){
            return i;
        }
    }
    return -100;
}
void distributionort(int m, char *array1, int n) {
    int *counter = calloc(m , sizeof(int));
    int i = 0;
    while ( i < n){
        counter[keys(array1[i])]+=1;
        i++;
    }
    int j = 1;
    while (j < m){
        counter[j] += counter[j - 1];
        j++;
    }
    char *array2 = calloc(n,sizeof(char));
    int k = 0;
    while (k < n){
        array2[k] = array1[k];
        k++;
    }
    int q = n - 1;
    while ( q >= 0) {
        int k = keys(array2[q]);
        counter[k]-=1;
        array1[counter[k]] = array2[q];
        q--;
    }
    free(counter);
    free(array2);
}
int main(int argc, char **argv) {
    char str[1000002];
    gets(str);
    int n=strlen(str);
    distributionort(26, str, n);
    printf("%s", str);
}
