#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    int chislitel[N];
    int znamenatel[N];
    for(int i=0; i < N; i++) {
        scanf("%d/%d", &chislitel[i], &znamenatel[i]);
    }
    float sum=1;
    float maxproizvedeine=((float)chislitel[0]/(float)znamenatel[0]);
    int nachalo=0, konec=0, start=0;
    int j=0;
    while(j<N){
        sum=sum*((float)chislitel[j]/(float)znamenatel[j]);
        if (sum>maxproizvedeine){
            maxproizvedeine=sum;
            nachalo=start;
            konec=j;
        }
        j++;
        if (sum<1){
            sum=1;
            start=j;
        }
    }
    printf("%d %d", nachalo, konec);
    
}
