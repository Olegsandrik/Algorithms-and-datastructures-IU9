#include <stdio.h>
int main(int argc, char **argv) {
    int n, m, flag=1, x;
    scanf("%d",&n);
    scanf("%d",&m);
    long long arr[10][10], arrmin[10], arrmax[10];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            scanf("%lld", &arr[i][j]);
            //printf("%d!", arr[i][j]);
        }
    }
    for (int q=0; q<n; q++){
        arrmax[q]=-1000000000000000000;
    }
    for (int c=0; c<m; c++){
        arrmin[c]=100000000000000000;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j]>arrmax[i]){
                arrmax[i]=arr[i][j];
            }
            if (arr[i][j]<arrmin[j]){
                arrmin[j]=arr[i][j];
            }
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (arrmax[i]==arrmin[j]){
                printf("%d %d", i, j);
                flag=0;
            }
        }
    }
    if (flag){
        printf("none");
    }
    return 0;
}
