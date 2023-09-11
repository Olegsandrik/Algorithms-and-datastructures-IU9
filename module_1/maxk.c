#include <stdio.h>
int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    long long arr[1000000]={0};
    for (int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    long long summ=0;
    for (int j=0; j<k; j++){
        summ+=arr[j];
    }
    long maxsumm=summ;
    for (int i=k; i<n; i++){
        summ=summ+arr[i]-arr[i-k];
        if (summ>maxsumm){
            maxsumm=summ;
        }
    }
    printf("%lld", maxsumm);
    return 0;
}
