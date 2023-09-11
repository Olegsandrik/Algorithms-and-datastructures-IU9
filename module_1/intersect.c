#include <stdio.h>
int main(int argc, char **argv) {
    int n1, A=0, a;
    scanf("%d", &n1);
    for (int i=0; i<n1; i++){
        scanf("%d",&a);
        A|=(1<<a);
    }
    int n2, B=0, b;
    scanf("%d", &n2);
    for (int i=0; i<n2; i++){
        scanf("%d",&b);
        B|=(1<<b);
    }
    int C=(A&B);
    for (int i=0; i<32; i++){
        if (C&(1<<i)){
            printf("%d ", i);
        }
    }
    return 0;
}
