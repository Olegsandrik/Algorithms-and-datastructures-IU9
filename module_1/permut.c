#include <stdio.h>
int main(int argc, char **argv) {
    int A[8], B[8], C[8], x;
    for (int i=0; i<8; i++){
        scanf("%d", &x);
        A[i]=x;
    }
    for (int j=0; j<8; j++){
        scanf("%d", &x);
        B[j]=x;
    }
    for (int k=0; k<8; k++){
        C[k]=1;
    }
    for (int g=0; g<8; g++){
        for (int q=0; q<8; q++) {
            if (A[g] == B[q]) {
                C[g] -= 1;
                B[q] = 1000000;
                break;
            }
        }
    }
    int flag=1;
    for (int t=0; t<8; t++){
        if(C[t]!=0){
            flag=0;
        }
    }
    if (flag){
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}
