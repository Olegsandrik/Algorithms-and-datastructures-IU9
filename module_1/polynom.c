#include <stdio.h>
int main(int argc, char **argv){
    long n, x0, k, result1, result2;
    scanf("%ld", &n);
    scanf("%ld", &x0);
    long arr[100000];
    for (int g=0; g<100000; g++){
        arr[g]=0;
    }
    for (int i=0; i<n+1; i++){
        scanf("%ld", &k);
        arr[i]=k;
    }
    result1=arr[0]*x0+arr[1];
    for (int j=2; j<n+1; j++){
        result1=result1*x0+arr[j];
    }
    for (int i=0; i<n+1; i++){
        arr[i]=arr[i]*(n-i);
        //printf("%ld", arr[i]);
    }
    result2=arr[0]*x0+arr[1];
    for (int j=2; j<n; j++){
        result2=result2*x0+arr[j];
    }
    printf("%ld ", result1);
    printf("%ld", result2);
    return 0;
}
